import { times } from 'lodash'

class BufferReader {
  buf: Buffer
  pos: number

  constructor(buf: Buffer) {
    this.buf = buf
    this.pos = 0
  }

  nextInt16LE(): number {
    const num = this.buf.readInt16LE(this.pos)
    this.pos += 2
    return num
  }

  nextBuffer(length: number): Buffer {
    const buf = this.buf.slice(this.pos, this.pos + length)
    this.pos += length
    return buf
  }

  nextString(length: number): string {
    return this.nextBuffer(length).toString('utf16le')
  }

  hasNext(): boolean {
    return this.pos < this.buf.length
  }
}

export default class ScelParser {
  buf: Buffer
  pinyinTable: string[]

  constructor(buf: Buffer) {
    this.buf = buf
  }

  parseInfo(): {
    name: string
    type: string
    description: string
    example: string
  } {
    const extract = (from: number, to: number) =>
      this.buf.slice(from, to).toString('utf16le').split('\x00', 1)[0]
    return {
      name: extract(0x130, 0x338),
      type: extract(0x338, 0x554),
      description: extract(0x540, 0xd40),
      example: extract(0xd40, 0x1540),
    }
  }

  parsePinyinTable(): string[] {
    const reader = new BufferReader(this.buf.slice(0x1540, 0x2628))
    if (!reader.nextBuffer(4).compare(Buffer.from('\x9d\x01\x00\x00'))) {
      throw new Error('Invalid pinyin table')
    }
    this.pinyinTable = []
    while (reader.hasNext()) {
      const index = reader.nextInt16LE()
      const len = reader.nextInt16LE()
      this.pinyinTable[index] = reader.nextString(len)
    }
    return this.pinyinTable
  }

  parseWords(): {
    word: string
    pinyin: string[]
    frequency: number
  }[] {
    if (!this.pinyinTable) {
      this.parsePinyinTable()
    }
    const reader = new BufferReader(this.buf.slice(0x2628))
    const words: {
      word: string
      pinyin: string[]
      frequency: number
    }[] = []
    while (reader.hasNext()) {
      const homophoneNum = reader.nextInt16LE()
      const pinyinLen = reader.nextInt16LE()
      const pinyin = times(pinyinLen / 2).map(() => {
        if (!reader.hasNext()) {
          return '?'
        }
        return this.pinyinTable[reader.nextInt16LE()]
      })
      times(homophoneNum).forEach(() => {
        if (!reader.hasNext()) {
          return
        }
        const wordBytes = reader.nextInt16LE()
        const word = reader.nextString(wordBytes)
        const extBytes = reader.nextInt16LE()
        const ext = reader.nextBuffer(extBytes)
        const frequency = ext.readInt16LE(0)
        words.push({ word, pinyin, frequency })
      })
    }
    return words
  }
}

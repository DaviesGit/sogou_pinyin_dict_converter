# Scel Parser

Typescript实现的搜狗细胞词库parser

## Installation

```bash
npm i scel-parser
```

## Usage

### Command Line

```bash
# this will overwrite a example.scel.json file whihout confirm
scel-parser ./example.scel
```

### Programmatically
```javascript
import { readFile } from 'fs'
import ScelParser from 'scel-parser'

readFile(__dirname + 'example.scel', (err, data) => {
  if (err) {
    throw err
  }
  const parser = new ScelParser(data)
  console.log(parser.parseInfo())
  console.log(parser.parsePinyinTable())
  console.log(parser.parseWords())  
})
```

## Download Scel Dict
http://pinyin.sogou.com/dict/

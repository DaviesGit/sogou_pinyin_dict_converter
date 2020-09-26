#!/usr/bin/env node

import { readFile, writeFile } from 'fs'
import { resolve } from 'path'

import ScelParser from './index'

readFile(resolve(process.argv[2]), (err, data) => {
  if (err) {
    throw err
  }
  const parser = new ScelParser(data)
  console.log(parser.parseInfo())
  writeFile(resolve(process.argv[2] + '.json'), JSON.stringify(parser.parseWords(), null, 2), 'utf8', (err) => {
    if (err) {
      throw err
    }
  })
})

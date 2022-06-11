const fs = require('fs');

const filename = process.argv[2]
const word = process.argv[3]

const content = fs.readFileSync(filename, { encoding: 'utf-8', flag: 'r' })
const result = content.split("\n").reduce((acc, line) => {
    return acc += line.split(" ").reduce((acc, w) => {
        return acc += word === w ? 1 : 0
    }, 0)
}, 0)

console.log(`Word found ${result} times`)

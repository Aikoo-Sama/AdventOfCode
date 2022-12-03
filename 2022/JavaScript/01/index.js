const readline = require('readline');
const fs = require('fs');
const path = require('path');

const reader = new readline.createInterface({
    input: fs.createReadStream(path.join(__dirname, 'list.txt')),
});

const arr = [];
let add = 0;

reader.on('line', (line) => {
    if (line === '') {
        arr.push(add);
        add = 0;
    } else {
        add += parseInt(line);
    }
});

reader.on('close', () => {
    let one = Math.max(...arr);
    let two = 0;
    let three = 0;

    for (let i = 0; i < arr.length; i++) {
        if (arr[i] >= two && arr[i] < one) {
            two = arr[i];
        }

        if (arr[i] >= three && arr[i] < two) {
            three = arr[i];
        }
    }

    console.log(one);
    console.log(two);
    console.log(three);

    console.log(one + two + three);
});

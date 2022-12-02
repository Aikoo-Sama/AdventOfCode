const fs = require("fs");
const path = require("path");

const list = fs.readFileSync(path.join(__dirname, "list.txt"), "utf8");
const elvesArray = list.split("\n\n");

const elves = elvesArray.map((elf) => {
  return elf.split("\n");
});

function findMostCalories() {
  let max = 0;
  for (elve in elves) {
    const calories = sumCalories(elves[elve]);
    if (calories > max) {
      max = calories;
    }
  }

  return max;
}

function getTopThree() {
  const one = parseInt(findMostCalories());
  let two = 0;
  let three = 0;

  for (elve in elves) {
    const calories = parseInt(sumCalories(elves[elve]));

    if (calories < one && calories >= two) {
      two = calories;
    }

    if ((calories < two && calories >= three) || three == 0) {
      three = calories;
    }
  }

  return [one, two, three];
}

function sumCalories(elve) {
  let calories = 0;
  let i;
  elve.forEach((calorie) => {
    if (!isNaN(calorie) && calorie !== "") {
      calories += parseInt(calorie);
    }
  });

  return calories;
}

const topThree = getTopThree();
console.log("Top #1 : " + topThree[0] + "\nTop#2 : " + topThree[1] + "\nTop#3 : " + topThree[2] + "\nSum : " + (topThree[0] + topThree[1] + topThree[2]));

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
    let calories = 0;
    let i;
    elves[elve].forEach((calorie) => {
      if (!isNaN(calorie) && calorie !== "") {
        calories += parseInt(calorie);
      }
    });

    if (calories > max) {
      max = calories;
    }
  }

  return max;
}

console.log("Most calories: ", findMostCalories());

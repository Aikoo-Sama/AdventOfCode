package me.aikoo.adventofcode.day01;

import java.util.*;

public class Day01 {
    public void run() {
        System.out.println("Day 01");
        System.out.println("------");
        System.out.println("Part 1: " + this.partOne());
    }

    private int partOne() {
        int sum = 0;
        List<String> lines = new ArrayList<>();
        try (Scanner scanner = new Scanner(Objects.requireNonNull(getClass().getResourceAsStream("/day01/input.txt")))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                lines.add(line);
            }
        }

        for (String line : lines) {
            Line l = new Line(line);
            sum += l.getNumber();
        }
        return sum;
    }

    private static class Line {
        private final char firstChar;
        private final char lastChar;
        private final ArrayList<Integer> allNumbers = new ArrayList<>();
        private final List<String> alphabet = List.of(new String[]{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                                                                    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
                                                                    "u", "v", "w", "x", "y", "z"});
        int firstNumber = 0;
        int lastNumber = 0;

        public Line(String line) {
            firstChar = line.charAt(0);
            lastChar = line.charAt(line.length() - 1);

            this.getAllNumbersInLine(line);
            this.getDigits();
        }

        private void getDigits() {
            if (Character.isDigit(firstChar) && Character.isDigit(lastChar)) {
                firstNumber = Integer.parseInt(String.valueOf(firstChar));
                lastNumber = Integer.parseInt(String.valueOf(lastChar));
            } else {
                firstNumber = allNumbers.get(0);
                lastNumber = allNumbers.get(allNumbers.size() - 1);
            }
        }

        public int getNumber() {
            return Integer.parseInt(firstNumber + "" + lastNumber);
        }

        private void getAllNumbersInLine(String line) {
                for (int i = 0; i < line.length(); i++) {
                    try {
                        int number = Integer.parseInt(String.valueOf(line.charAt(i)));
                        allNumbers.add(number);
                    } catch (NumberFormatException e) {
                        // ignore
                    }
                }
        }
    }
}

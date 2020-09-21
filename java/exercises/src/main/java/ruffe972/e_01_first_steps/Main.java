package e_01_first_steps;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        testNumbers();
        testScanner();
    }

    private static void testNumbers() {
        int myMinInt = Integer.MIN_VALUE;
        int myMaxInt = Integer.MAX_VALUE;
        int bustedMaxInt = myMaxInt + 1;
        byte byteA = 1 + (Byte.MIN_VALUE / 2);
        long longA = 3_000_000_000L;

        byte someByte = 127;
        short someShort = 32_000;
        int someInt = -2_000_000_000;
        long someLong = 50_000L + 10L * (someByte + someShort + someInt);

        float minFloat = Float.MIN_VALUE;
        float maxFloat = Float.MAX_VALUE;
        System.out.println("Max float: " + maxFloat);

        float someFloat = 5.25f;
        double someDouble = 5.25;

        var pounds = 7d;
        var kilograms = pounds * 0.453_592_37;
    }

    // Not much validation here.
    private static void testScanner() {
        var scanner = new Scanner(System.in);
        System.out.println("Enter your year of birth:");
        if (scanner.hasNextInt()) {
            var yearOfBirth = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Enter your name:");
            var name = scanner.nextLine();
            var age = 2020 - yearOfBirth;
            System.out.printf("Your name is %s and your age is ~%d.\n", name, age);
        } else {
            System.out.println("Incorrect year of birth.");
        }
        scanner.close();
    }
}

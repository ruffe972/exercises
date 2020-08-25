package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Not much validation here.
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

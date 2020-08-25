package com.company;

public class Main {

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

    public static void main(String[] args) {
    }
}

package ruffe972.e_05_shapes_inheritance;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class RectangleTest {

    @Test
    void testAreaIfSmall() {
        testArea(5, 2.5, 2);
        testArea(0.01, 0.1, 0.1);
        testArea(0.1, 1, 0.1);
    }

    private static void testArea(double expectedArea, double width, double height) {
        var rectangle = new Rectangle("", width, height);
        assertEquals(expectedArea, rectangle.getArea(), 0.000_001);
    }

    @Test
    void testAreaIfBig() {
        testArea(1_000_000_000_000d, 1_000_000, 1_000_000);
    }

    @Test
    void testColorlessStringRepresentation() {
        testToString(
                "Rectangle (colorless; width: 2.50; height: 2.00)",
                new Rectangle("", 2.5, 2));
    }

    static private void testToString(String expected, Rectangle rectangle) {
        assertEquals(expected, rectangle.toString());
    }

    @Test
    void testColorStringRepresentation() {
        testToString(
                "Rectangle (color: blue; width: 1.00; height: 1.00)",
                new Rectangle("blue", 1, 1));
    }

    @Test
    void testToStringForLongFractions() {
        testToString(
                "Rectangle (colorless; width: 1.49; height: 1.50)",
                new Rectangle("", 1.49499, 1.494999999999999999));
    }

    @Test
    void given_nonPositiveDimension_expect_illegalArgumentException() {
        assertThrows(IllegalArgumentException.class, () -> new Rectangle("", -0.5, 3));
        assertThrows(IllegalArgumentException.class, () -> new Rectangle("", 3, -0.5));
    }

    @Test
    void given_ZeroDimension_expect_illegalArgumentException() {
        assertThrows(IllegalArgumentException.class, () -> new Rectangle("", 0, 1));
        assertThrows(IllegalArgumentException.class, () -> new Rectangle("", 1, 0));
    }

}
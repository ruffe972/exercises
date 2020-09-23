package ruffe972.e_05_shapes;

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
        String actual = new Rectangle("", 2.5, 2).toString();
        assertEquals("Rectangle (colorless; width: 2.50; height: 2.00)", actual);
    }

    @Test
    void testColorStringRepresentation() {
        String actual = new Rectangle("blue", 1, 1).toString();
        assertEquals("Rectangle (color: blue; width: 1.00; height: 1.00)", actual);
    }

    @Test
    void testToStringForLongFractions() {
        String actual = new Rectangle("", 1.49499, 1.494999999999999999).toString();
        assertEquals("Rectangle (colorless; width: 1.49; height: 1.50)", actual);
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

    @Test
    void testNoColorToString() {
        String actual = new Rectangle("", 1, 1).colorToString();
        assertEquals("colorless", actual);
    }

    @Test
    void testRedColorToString() {
        String actual = new Rectangle("red", 1, 1).colorToString();
        assertEquals("color: red", actual);
    }
}
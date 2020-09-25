package ruffe972.e_05_shapes;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class ShapeTest {

    static private class TestShape extends Shape {

        TestShape(String color) {
            super(color);
        }

        @Override
        public double getArea() {
            return 1;
        }
    }

    @Test
    void testNoColorToString() {
        String actual = new TestShape("").colorToString();
        assertEquals("colorless", actual);
    }

    @Test
    void testRedColorToString() {
        String actual = new TestShape("red").colorToString();
        assertEquals("color: red", actual);
    }

    @Test
    void testToString() {
        String actual = new TestShape("").toString();
        assertEquals("Shape (colorless; area: 1.00)", actual);
    }
}
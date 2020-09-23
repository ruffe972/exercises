package ruffe972.e_05_shapes;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SquareTest {

    @Test
    void testToString() {
        String actual = new Square("", 3).toString();
        assertEquals("Square (colorless; side: 3.00)", actual);
    }
}
package ruffe972.e_05_shapes;

// Immutable
class Square extends Rectangle {

    public Square(String color, double side) {
        super(color, side, side);
    }

    @Override
    public String toString() {
        return String.format("Square (%s; side: %.2f)", colorToString(), getWidth());
    }
}

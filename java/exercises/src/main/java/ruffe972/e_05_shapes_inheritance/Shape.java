package ruffe972.e_05_shapes_inheritance;

/** Immutable */
abstract class Shape {
    private final String color;

    public final String getColor() {
        return color;
    }

    @Override
    public String toString() {
        return String.format("Shape (%s)", colorToString());
    }

    public abstract double getArea();

    /** Empty string means colorless */
    protected Shape(String color) {
        this.color = color;
    }

    protected final String colorToString() {
        return color.isEmpty() ? "colorless" : ("color: " + color);
    }
}

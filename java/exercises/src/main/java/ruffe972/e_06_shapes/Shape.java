package ruffe972.e_06_shapes;

public interface Shape {
    String getColor();
    double getArea();

    default String colorToString() {
        return getColor().isEmpty() ? "colorless" : ("color: " + getColor());
    }
}

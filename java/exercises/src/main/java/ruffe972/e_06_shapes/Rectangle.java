package ruffe972.e_06_shapes;

public interface Rectangle extends Shape {
    double getWidth();
    double getHeight();

    @Override
    default double getArea() {
        return getWidth() * getHeight();
    }
}

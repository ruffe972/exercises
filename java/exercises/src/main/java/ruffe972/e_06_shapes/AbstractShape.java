package ruffe972.e_06_shapes;

public abstract class AbstractShape implements Shape {

    @Override
    public String toString() {
        return String.format("Shape (%s; area: %.2f)", colorToString(), getArea());
    }
}

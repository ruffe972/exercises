package ruffe972.e_06_shapes;

public class RectangleImp implements Rectangle {
    private final double width;
    private final double height;
    private final String color;

    RectangleImp(String color, double width, double height) {
        if (width <= 0 || height <= 0) {
            throw new IllegalArgumentException("Width and height should be > 0.");
        }
        this.color = color;
        this.width = width;
        this.height = height;
    }

    @Override
    public String toString() {
        return String.format("Rectangle (%s; width: %.2f; height: %.2f)", colorToString(), width, height);
    }

    @Override
    public String getColor() {
        return color;
    }

    @Override
    public double getWidth() {
        return width;
    }

    @Override
    public double getHeight() {
        return height;
    }
}

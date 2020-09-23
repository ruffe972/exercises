package ruffe972.e_05_shapes;

/** Immutable */
class Rectangle extends Shape {

    private final double width;
    private final double height;

    /** Width and height should be > 0 */
    public Rectangle(String color, double width, double height) {
        super(color);
        if (width <= 0 || height <= 0) {
            throw new IllegalArgumentException("Width and height should be > 0.");
        }
        this.width = width;
        this.height = height;
    }

    @Override
    public double getArea() {
        return width * height;
    }

    @Override
    public String toString() {
        return String.format("Rectangle (%s; width: %.2f; height: %.2f)", colorToString(), width, height);
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }
}

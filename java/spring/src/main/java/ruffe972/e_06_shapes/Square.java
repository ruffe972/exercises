package ruffe972.e_06_shapes;

class Square implements Rectangle {
    private final Rectangle rectangle;

    Square(String color, double side) {
        // TODO do I need dep. injection here?
        rectangle = new RectangleImp(color, side, side);
    }

    @Override
    public String toString() {
        return String.format("Square (%s; side: %.2f)", colorToString(), getWidth());
    }

    @Override
    public double getWidth() {
        return rectangle.getWidth();
    }

    @Override
    public double getHeight() {
        return rectangle.getHeight();
    }

    @Override
    public String getColor() {
        return rectangle.getColor();
    }
}

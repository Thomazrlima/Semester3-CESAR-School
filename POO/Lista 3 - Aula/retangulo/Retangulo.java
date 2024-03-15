package retangulo;

public class Retangulo extends Paralelogramo {
    public Retangulo(double base, double altura) {
        super(90, base, altura);
    }
    double base() {
        return lado1;
    }
    double altura() {
        return lado2;
    }
}
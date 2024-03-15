package retangulo;

public class Paralelogramo {
    double angulo;
    double lado1;
    double lado2;
    public Paralelogramo(double angulo, double lado1, double lado2) {
        this.angulo = angulo;
        this.lado1 = lado1;
        this.lado2 = lado2;
    }
    double calcularPerimetro() {
        return 2*(lado1 + lado2);
    }
    double calcularArea() {
        return lado1*lado2*Math.sin(Math.toRadians(angulo));
    }
    double calcularAnguloMaior() {
        return 180-angulo;
    }
}
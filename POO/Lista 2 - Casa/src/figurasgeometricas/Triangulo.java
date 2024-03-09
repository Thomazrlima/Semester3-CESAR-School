package figurasgeometricas;

public class Triangulo {
    double l1;
    double l2;
    double l3;

    public Triangulo(double l1, double l2, double l3) {
        this.l1 = l1;
        this.l2 = l2;
        this.l3 = l3;
    }

    double calcularPerimetro() {
        return l1 + l2 + l3;
    }
    double calcularArea() {
        double p = calcularPerimetro();
        double s = p/2;
        return Math.sqrt(s * (s - l1) *(s - l2) * (s - l3));
    }
}
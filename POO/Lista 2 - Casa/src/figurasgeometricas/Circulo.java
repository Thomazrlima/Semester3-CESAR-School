package figurasgeometricas;
import javax.swing.JOptionPane;

public class Circulo {
    double raio;

    public Circulo(double raio) {
        this.raio = raio;
    }

    public double obterDiametro() {
        return raio*2;
    }
    public double calcularArea() {
        double area = Math.PI * Math.pow(raio, 2);
        return area;
    }

    public double calcularPerimetro(){
        double perimetro = Math.PI * raio * 2;
        return perimetro;
    }

    public double calcularComprimentoArco(double anguloArco) {
        double comp = anguloArco * Math.PI * this.raio /180;
        return comp;
    }
}
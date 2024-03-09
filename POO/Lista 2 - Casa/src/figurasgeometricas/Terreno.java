package figurasgeometricas;
import figurasgeometricas.Endereco;

public class Terreno {
    double area;
    double valorPorMetroQuadrado;

    Endereco endereco;

    public Terreno(double valorPorMetroQuadrado, Endereco endereco){
        this.valorPorMetroQuadrado = valorPorMetroQuadrado;
        this.endereco = endereco;
    }

    public double calcularValorTerreno(double area, double valorPorMetroQuadrado){
        double valor = valorPorMetroQuadrado * area;
        return valor;
    }

}
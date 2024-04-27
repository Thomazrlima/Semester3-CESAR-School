package figurasgeometricas;

public class Paralelogramo {
    private double base;
    private double ladoAdjacente;
    private double angulo;

    public Paralelogramo(double base, double ladoAdjacente, double angulo){
        this.base = base;
        this.ladoAdjacente = ladoAdjacente;
        this.angulo = angulo;
    }

    public double calcularArea(){
        double h;
        h = this.ladoAdjacente * Math.sin(Math.toRadians(this.angulo));
        double areaParalela = this.base * h;
        return areaParalela;
    }

    public double calcularPerimetro(){
        double perParalelo = this.base*2 + this.ladoAdjacente*2;
        return perParalelo;
    }

    public double maiorAngulo(){
        double anguloParalelo = (360 - this.angulo*2)/2;
        return anguloParalelo;
    }

}
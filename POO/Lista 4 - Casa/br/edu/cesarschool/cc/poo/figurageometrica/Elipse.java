package br.edu.cesarschool.cc.poo.figurageometrica;

public class Elipse extends FiguraGeometrica{
    private double raioMenor;
    private double raioMaior;

    public Elipse(String descricao, double raioMenor, double raioMaior) {
        super(descricao);
        this.raioMenor = raioMenor;
        this.raioMaior = raioMaior;
    }

    public double getRaioMenor() {

        return raioMenor;
    }

    public double getRaioMaior() {

        return raioMaior;
    }

    public void setRaioMenor(double raioMenor) {
        this.raioMenor = raioMenor;
    }

    public void setRaioMaior(double raioMaior) {
        this.raioMaior = raioMaior;
    }

    public double calcularArea(){
        return (Math.PI)*(this.raioMaior)*(raioMenor);
    }
    public double calcularPerimetro(){
        return (Math.PI)*(this.raioMenor + this.raioMaior);
    }
}
package br.edu.cesarschool.cc.poo.meiotransporte.motorizado;

import br.edu.cesarschool.cc.poo.meiotransporte.MeioTransporte;

public class MeioTransporteMotorizado extends MeioTransporte {
    private double potenciaMotor;
    private double capacidadeCombustivel;
    private double consumoMedio;

    public MeioTransporteMotorizado(String nome, double cargaMaxima, double velocidadeMaxima, double potenciaMotor, double capacidadeCombustivel, double consumoMedio) {
        super(nome, cargaMaxima, velocidadeMaxima);
        this.potenciaMotor = potenciaMotor;
        this.capacidadeCombustivel = capacidadeCombustivel;
        this.consumoMedio = consumoMedio;
    }

    public double getPotenciaMotor() {
        return potenciaMotor;
    }

    public double getCapacidadeCombustivel() {
        return capacidadeCombustivel;
    }

    public double getConsumoMedio() {
        return consumoMedio;
    }

    public void setPotenciaMotor(double potenciaMotor) {
        this.potenciaMotor = potenciaMotor;
    }

    public void setCapacidadeCombustivel(double capacidadeCombustivel) {
        this.capacidadeCombustivel = capacidadeCombustivel;
    }

    public void setConsumoMedio(double consumoMedio) {
        this.consumoMedio = consumoMedio;
    }

    public double calcularAutonomia(){
        return (this.consumoMedio)*(this.capacidadeCombustivel);
    }
}

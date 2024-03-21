package br.edu.cesarschool.cc.poo.meiotransporte.motorizado;

public class Carro extends MeioTransporteMotorizado {
    public Carro(String nome, double cargaMaxima, double velocidadeMaxima, double potenciaMotor, double capacidadeCombustivel, double consumoMedio) {
        super(nome, cargaMaxima, velocidadeMaxima, potenciaMotor, capacidadeCombustivel, consumoMedio);
    }
    public double calcularEficiencia(){
        return getCargaMaxima()/getConsumoMedio();
    }
}

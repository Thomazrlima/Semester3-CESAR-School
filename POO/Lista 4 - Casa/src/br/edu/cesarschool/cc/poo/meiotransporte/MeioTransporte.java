package br.edu.cesarschool.cc.poo.meiotransporte;

public class MeioTransporte {
    private String nome;
    private double cargaMaxima;
    private double velocidadeMaxima;

    public MeioTransporte(String nome, double cargaMaxima, double velocidadeMaxima) {
        this.nome = nome;
        this.cargaMaxima = cargaMaxima;
        this.velocidadeMaxima = velocidadeMaxima;
    }

    public String getNome() {
        return nome;
    }

    public double getCargaMaxima() {
        return cargaMaxima;
    }

    public double getVelocidadeMaxima() {
        return velocidadeMaxima;
    }
}

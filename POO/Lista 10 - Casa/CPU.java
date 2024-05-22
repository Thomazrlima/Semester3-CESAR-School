package projetoum;

public class CPU {
    private String modelo;
    private double clock;

    public CPU(String modelo, double clock) {
        this.modelo = modelo;
        this.clock = clock;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public double getClock() {
        return clock;
    }

    public void setClock(double clock) {
        this.clock = clock;
    }
}
package projetoum;

public class Computador extends Eletronico implements Comparable<Computador> {
    private int memoriaRam; // em GB
    private CPU cpu; // Objeto do tipo CPU
    private String marca; // Marca do computador

    public Computador(String nome, double potencia, String fabricante, int memoriaRam, CPU cpu, String marca) {
        super(nome, potencia, fabricante); // Chama o construtor da classe base Eletronico
        this.memoriaRam = memoriaRam;
        this.cpu = cpu;
        this.marca = marca;
    }

    public int getMemoriaRam() {
        return memoriaRam;
    }

    public void setMemoriaRam(int memoriaRam) {
        this.memoriaRam = memoriaRam;
    }

    public CPU getCpu() {
        return cpu;
    }

    public void setCpu(CPU cpu) {
        this.cpu = cpu;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    @Override
    public int compareTo(Computador other) {
        return Double.compare(this.cpu.getClock(), other.getCpu().getClock());
    }
}
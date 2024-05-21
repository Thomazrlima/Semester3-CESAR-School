package projetoum;

public class Maquina {
	private String nome;
	private double potencia;
	
	public Maquina(String nome, double potencia) {
		this.nome = nome;
		this.potencia = potencia;
	}
	
	public double getPotencia() {
		return potencia;
	}
}
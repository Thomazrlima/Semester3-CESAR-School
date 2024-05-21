package projetoum;

public class Eletronico extends Maquina {
	private String fabricante;
	
	public Eletronico(String nome, double potencia, String fabricante) {
		super(nome, potencia); // Chama o construtor da classe base Maquina
		this.fabricante = fabricante;
	}
	
	public String getFabricante() {
		return fabricante;
	}
	
	public void setFabricante(String fabricante) {
		this.fabricante = fabricante;
	}
}
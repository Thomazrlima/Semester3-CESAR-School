public class Moto {
	private String modelo;
	private double preco;
	private Double potencia;
	private Integer tipoMotor;

	public Moto() {
	}

	public Moto(String modelo, double preco) {
		this.modelo = modelo;
		this.preco = preco;
	}

	public Moto(String modelo, double preco, Double potencia, Integer tipoMotor) {
		this(modelo, preco);
		this.potencia = potencia;
		this.tipoMotor = tipoMotor;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	public Double getPotencia() {
		return potencia;
	}

	public void setPotencia(Double potencia) {
		this.potencia = potencia;
	}

	public Integer getTipoMotor() {
		return tipoMotor;
	}

	public void setTipoMotor(Integer tipoMotor) {
		this.tipoMotor = tipoMotor;
	}
}
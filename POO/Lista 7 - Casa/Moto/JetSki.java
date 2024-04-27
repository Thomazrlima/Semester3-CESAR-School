class JetSki extends Moto {
	private int tipoCasco;

	public JetSki() {
		super();
	}

	public JetSki(String modelo, double preco, Double potencia, Integer tipoMotor, int tipoCasco) {
		super(modelo, preco, potencia, tipoMotor);
		this.tipoCasco = tipoCasco;
	}

	public JetSki(String modelo, double preco, int tipoCasco) {
		super(modelo, preco);
		this.tipoCasco = tipoCasco;
	}

	public JetSki(String modelo, double preco) {
		super(modelo, preco);
	}

	public int getTipoCasco() {
		return tipoCasco;
	}

	public void setTipoCasco(int tipoCasco) {
		this.tipoCasco = tipoCasco;
	}
}
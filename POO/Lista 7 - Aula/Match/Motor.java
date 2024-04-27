class Motor {
	private final long codigo;
	private String nome;
	private double potencia;
	private double vazao;

	public Motor() {
		this.codigo = 0;
	}

	public Motor(long codigo) {
		this.codigo = codigo;
	}

	public Motor(long codigo, String nome, double potencia, double vazao) {
		this.codigo = codigo;
		this.nome = nome;
		this.potencia = potencia;
		this.vazao = vazao;
	}

	public long getCodigo() {
		return codigo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getPotencia() {
		return potencia;
	}

	public void setPotencia(double potencia) {
		this.potencia = potencia;
	}

	public double getVazao() {
		return vazao;
	}

	public void setVazao(double vazao) {
		this.vazao = vazao;
	}
}

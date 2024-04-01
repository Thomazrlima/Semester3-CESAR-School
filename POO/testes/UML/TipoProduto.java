package uml.sala;

public class TipoProduto {
	private int codigo;
	private String nome;
	public TipoProduto(int codigo, String nome) {
		this.codigo = codigo;
		this.nome = nome;
	}
	public int getCodigo() {
		return codigo;
	}
	public String getNome() {
		return nome;
	}
}

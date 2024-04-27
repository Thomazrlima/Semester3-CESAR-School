package uml.sala;

public class ProdutoFornecedor {
	private Produto produto;
	private Fornecedor fornecedor; 
	private double preco;
	
	protected ProdutoFornecedor(Produto produto, Fornecedor fornecedor, double preco) {
		this.produto = produto;
		this.fornecedor = fornecedor;
		this.preco = preco;
	}

	protected Produto getProduto() {
		return produto;
	}

	protected Fornecedor getFornecedor() {
		return fornecedor;
	}

	protected double getPreco() {
		return preco;
	}

	void aumentarPreco(double valor) {
		preco += valor;
	}
	protected void reduzirPreco(double valor) {
		preco -= valor;
	}
	
}

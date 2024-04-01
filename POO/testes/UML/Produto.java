package uml.sala;

public class Produto {
	private long codigo;
	private String nome;
	private ProdutoFornecedor[] fornecedores = new ProdutoFornecedor[100];
	private TipoProduto tipo;
	private int qtdFornecedores = 0; 
	public Produto(long codigo, String nome, TipoProduto tipo) {
		this.codigo = codigo;
		this.nome = nome;
		this.tipo = tipo;
	}
	
	protected String getNome() {
		return nome;
	}

	protected void setNome(String nome) {
		this.nome = nome;
	}

	protected TipoProduto getTipo() {
		return tipo;
	}

	protected void setTipo(TipoProduto tipo) {
		this.tipo = tipo;
	}

	protected long getCodigo() {
		return codigo;
	}

	protected ProdutoFornecedor[] getFornecedores() {
		return fornecedores;
	}

	protected void adicionarFornecedor(Fornecedor forn, double preco) {
		fornecedores[qtdFornecedores] = new ProdutoFornecedor(this, forn, preco);
		qtdFornecedores++;
	}
	public Fornecedor encontrarFornecedor(String cnpj, double precoMenor) {
		for (ProdutoFornecedor produtoFornecedor : fornecedores) {
			if (produtoFornecedor == null) {
				break;
			} else {
				if (produtoFornecedor.getFornecedor().getCnpj().equals(cnpj)
						&& produtoFornecedor.getPreco() >= precoMenor) {
					return produtoFornecedor.getFornecedor();
				}
			}
		}
		return null;
	}
}

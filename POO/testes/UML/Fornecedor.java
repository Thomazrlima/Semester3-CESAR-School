package uml.sala;

import java.time.LocalDate;

public class Fornecedor {
	private String cnpj;
	private String razaoSocial;
	private LocalDate dataAbertura;
	private ProdutoFornecedor[] produtos;
	public Fornecedor(String cnpj, String razaoSocial, LocalDate dataAbertura) {
		this.cnpj = cnpj;
		this.razaoSocial = razaoSocial;
		this.dataAbertura = dataAbertura;
	}
	protected String getRazaoSocia() {
		return razaoSocial;
	}
	protected void setRazaoSocia(String razaoSocial) {
		this.razaoSocial = razaoSocial;
	}
	protected LocalDate getDataAbertura() {
		return dataAbertura;
	}
	protected void setDataAbertura(LocalDate dataAbertura) {
		this.dataAbertura = dataAbertura;
	}
	protected String getCnpj() {
		return cnpj;
	}
	protected ProdutoFornecedor[] getProdutos() {
		return produtos;
	}
	public void gerarListaProdutos(Produto[] prods, double[] precos) {
		if (validar(prods, precos)) {
			produtos = new ProdutoFornecedor[precos.length];
			int i = 0;
			for (double preco : precos) {
				produtos[i] = new ProdutoFornecedor(prods[i], this, preco);				
			}
		}
	}
	private boolean validar(Produto[] prods, double[] precos) {
		return prods != null && precos != null && 
				precos.length == prods.length;
	}
}

package uml.sala;

import java.time.LocalDate;

public class ProdutoPerecivel extends Produto {
	private static int qtdInstancias;
	private LocalDate dataFabricacao;
	private int prazoValidade;
	public ProdutoPerecivel(long codigo, String nome, TipoProduto tipo, LocalDate dataFabricacao, int prazoValidade) {
		super(codigo, nome, tipo);
		this.dataFabricacao = dataFabricacao;
		this.prazoValidade = prazoValidade;
		qtdInstancias++;
	} 
	protected boolean eValido(LocalDate dataRef) {
		return dataFabricacao.plusDays(prazoValidade).isBefore(dataRef);
	}
	static int getQtdInstancias() {
		return qtdInstancias;
	}
}

package br.edu.cesarschool.cc.poo.ac.passagem;

import br.edu.cesarschool.cc.poo.ac.utils.SuperDAO;
import br.edu.cesarschool.cc.poo.ac.utils.Registro;

public class BilheteVipDAO extends SuperDAO<BilheteVip> {

	@Override
	public Class<BilheteVip> obterTipo() {
		return BilheteVip.class;
	}

	public BilheteVip buscar(String numero) {
		return (BilheteVip) daoGenerico.buscar(numero);
	}

	public boolean incluir(BilheteVip bilhete) {
		if (buscar(bilhete.getIdUnico()) == null) {
			return daoGenerico.incluir(bilhete);
		}
		return false;
	}

	public boolean alterar(BilheteVip bilhete) {
		if (buscar(bilhete.getIdUnico()) != null) {
			return daoGenerico.alterar(bilhete);
		}
		return false;
	}

	public boolean excluir(String numero) {
		if (buscar(numero) != null) {
			return daoGenerico.excluir(numero);
		}
		return false;
	}

	public BilheteVip[] buscarTodos() {
		Registro[] registros = daoGenerico.buscarTodos();
		BilheteVip[] bilhetesVip = new BilheteVip[registros.length];
		for (int i = 0; i < registros.length; i++) {
			bilhetesVip[i] = (BilheteVip) registros[i];
		}
		return bilhetesVip;
	}
}
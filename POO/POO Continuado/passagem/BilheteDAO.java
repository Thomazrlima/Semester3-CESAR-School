package br.edu.cesarschool.cc.poo.ac.passagem;

import br.edu.cesarschool.cc.poo.ac.utils.SuperDAO;
import br.edu.cesarschool.cc.poo.ac.utils.Registro;

public class BilheteDAO extends SuperDAO<Bilhete> {

	@Override
	public Class<Bilhete> obterTipo() {
		return Bilhete.class;
	}

	public Bilhete buscar(String numero) {
		return (Bilhete) daoGenerico.buscar(numero);
	}

	public boolean incluir(Bilhete bilhete) {
		if (buscar(bilhete.getIdUnico()) == null) {
			return daoGenerico.incluir(bilhete);
		}
		return false;
	}

	public boolean alterar(Bilhete bilhete) {
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

	public Bilhete[] buscarTodos() {
		Registro[] registros = daoGenerico.buscarTodos();
		Bilhete[] bilhetes = new Bilhete[registros.length];
		for (int i = 0; i < registros.length; i++) {
			bilhetes[i] = (Bilhete) registros[i];
		}
		return bilhetes;
	}
}
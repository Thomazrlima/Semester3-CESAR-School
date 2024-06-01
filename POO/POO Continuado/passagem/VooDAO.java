package br.edu.cesarschool.cc.poo.ac.passagem;

import br.edu.cesarschool.cc.poo.ac.utils.SuperDAO;
import br.edu.cesarschool.cc.poo.ac.utils.Registro;

public class VooDAO extends SuperDAO<Voo> {

	@Override
	public Class<Voo> obterTipo() {
		return Voo.class;
	}

	public Voo buscar(String idVoo) {
		return (Voo) daoGenerico.buscar(idVoo);
	}

	public boolean incluir(Voo voo) {
		if (buscar(voo.getIdUnico()) == null) {
			return daoGenerico.incluir(voo);
		}
		return false;
	}

	public boolean alterar(Voo voo) {
		if (buscar(voo.getIdUnico()) != null) {
			return daoGenerico.alterar(voo);
		}
		return false;
	}

	public boolean excluir(String idVoo) {
		if (buscar(idVoo) != null) {
			return daoGenerico.excluir(idVoo);
		}
		return false;
	}

	public Voo[] buscarTodos() {
		Registro[] registros = daoGenerico.buscarTodos();
		Voo[] voos = new Voo[registros.length];
		for (int i = 0; i < registros.length; i++) {
			voos[i] = (Voo) registros[i];
		}
		return voos;
	}
}
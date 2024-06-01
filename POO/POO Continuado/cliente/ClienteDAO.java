package br.edu.cesarschool.cc.poo.ac.cliente;

import br.edu.cesarschool.cc.poo.ac.utils.SuperDAO;
import br.edu.cesarschool.cc.poo.ac.utils.Registro;

public class ClienteDAO extends SuperDAO<Cliente> {

	@Override
	public Class<Cliente> obterTipo() {
		return Cliente.class;
	}

	public Cliente buscar(String cpf) {
		return (Cliente) daoGenerico.buscar(cpf);
	}

	public boolean incluir(Cliente cliente) {
		if (buscar(cliente.getIdUnico()) == null) {
			return daoGenerico.incluir(cliente);
		}
		return false;
	}

	public boolean alterar(Cliente cliente) {
		if (buscar(cliente.getIdUnico()) != null) {
			return daoGenerico.alterar(cliente);
		}
		return false;
	}

	public boolean excluir(String cpf) {
		if (buscar(cpf) != null) {
			return daoGenerico.excluir(cpf);
		}
		return false;
	}

	public Cliente[] buscarTodos() {
		Registro[] registros = daoGenerico.buscarTodos();
		Cliente[] clientes = new Cliente[registros.length];
		for (int i = 0; i < registros.length; i++) {
			clientes[i] = (Cliente) registros[i];
		}
		return clientes;
	}
}

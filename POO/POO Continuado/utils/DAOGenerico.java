package br.edu.cesarschool.cc.poo.ac.utils;

import br.edu.cesarschool.next.oo.persistenciaobjetos.CadastroObjetos;

import java.io.Serializable;

public class DAOGenerico<T extends Registro & Serializable> {
    private CadastroObjetos cadastro;

    public DAOGenerico(Class<?> tipo) {
        this.cadastro = new CadastroObjetos(tipo);
    }

    public boolean incluir(T reg) {
        try {
            cadastro.incluir(reg, reg.getIdUnico());
            return true;
        } catch (RuntimeException e) {
            return false;
        }
    }

    public boolean alterar(T reg) {
        try {
            cadastro.alterar(reg, reg.getIdUnico());
            return true;
        } catch (RuntimeException e) {
            return false;
        }
    }

    public T buscar(String id) {
        try {
            return (T) cadastro.buscar(id);
        } catch (RuntimeException e) {
            return null;
        }
    }

    public T[] buscarTodos() {
        try {
            return (T[]) cadastro.buscarTodos();
        } catch (RuntimeException e) {
            return null;
        }
    }

    public boolean excluir(String id) {
        try {
            cadastro.excluir(id);
            return true;
        } catch (RuntimeException e) {
            return false;
        }
    }
}

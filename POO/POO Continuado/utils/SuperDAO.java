package br.edu.cesarschool.cc.poo.ac.utils;

import java.io.Serializable;

public abstract class SuperDAO<T extends Registro & Serializable> {
    protected DAOGenerico<T> daoGenerico;

    protected SuperDAO() {
        this.daoGenerico = new DAOGenerico<>(obterTipo());
    }

    public abstract Class<?> obterTipo();
}

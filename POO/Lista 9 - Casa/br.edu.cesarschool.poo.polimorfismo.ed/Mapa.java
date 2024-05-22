package br.edu.cesarschool.poo.polimorfismo.ed;

import java.util.HashMap;
import java.util.Map;

public class Mapa {
    private Map<String, Mapeavel> mapa;

    public Mapa() {
        this.mapa = new HashMap<>();
    }

    public boolean inserir(Mapeavel map) {
        if (map == null || existe(map.obterChave())) {
            return false;
        }
        mapa.put(map.obterChave(), map);
        return true;
    }

    public boolean trocar(Mapeavel map) {
        if (map == null || !existe(map.obterChave())) {
            return false;
        }
        mapa.put(map.obterChave(), map);
        return true;
    }

    public boolean excluir(String chave) {
        if (chave == null || !existe(chave)) {
            return false;
        }
        mapa.remove(chave);
        return true;
    }

    public Mapeavel buscar(String chave) {
        if (chave == null || !existe(chave)) {
            return null;
        }
        return mapa.get(chave);
    }

    public boolean existe(String chave) {
        return mapa.containsKey(chave);
    }
}

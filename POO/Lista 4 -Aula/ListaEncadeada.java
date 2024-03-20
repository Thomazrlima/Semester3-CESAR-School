package br.edu.cesarschool.poo.ed;

public class ListaEncadeada {
    private ElementoLista primeiro;
    private int tamanhoLista;

    private ElementoLista acharElemento(int indice) {
        int contador = 0;
        ElementoLista elemento = primeiro;
        while (elemento != null) {
            if (contador == indice) {
                return elemento;
            }
            elemento = elemento.getProximo();
            contador++;
        }
        return null;
    }
    public String obterConteudoPorIndice(int indice) {
        ElementoLista elemento = acharElemento(indice);
        if (elemento == null) {
            return null;
        } else {
            return elemento.getConteudo();
        }
    }
    public void incluirConteudo(String conteudo) {
        ElementoLista novo = new ElementoLista(conteudo, null);
        ElementoLista elemento = acharElemento(tamanhoLista - 1);
        if (elemento == null) {
            primeiro = novo;
        } else {
            elemento.setProximo(novo);
        }
        tamanhoLista++;
    }
    public String removerConteudo(int indice) {
        String conteudo = null;
        if (tamanhoLista == 0) {
            conteudo = null;
        } else if (indice == 0) {
            ElementoLista ax = primeiro;
            primeiro = primeiro.getProximo();
            ax.setProximo(null);
            conteudo = ax.getConteudo();
            tamanhoLista--;
        } else {
            ElementoLista elementoAnt = acharElemento(indice - 1);
            if (elementoAnt != null) {
                ElementoLista elementoAtu = elementoAnt.getProximo();
                if (elementoAtu != null) {
                    elementoAnt.setProximo(elementoAtu.getProximo());
                    elementoAtu.setProximo(null);
                    conteudo = elementoAtu.getConteudo();
                    tamanhoLista--;
                }
            }
        }
        return conteudo;
    }
    public int getTamanhoLista() {
        return tamanhoLista;
    }
}
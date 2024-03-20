package br.edu.cesarschool.poo.ed;

class ElementoLista {
    private String conteudo;
    private ElementoLista proximo;
    ElementoLista(String conteudo, ElementoLista proximo) {
        this.conteudo = conteudo;
        this.proximo = proximo;
    }
    String getConteudo() {
        return conteudo;
    }
    ElementoLista getProximo() {
        return proximo;
    }
    void setProximo(ElementoLista proximo) {
        this.proximo = proximo;
    }
}
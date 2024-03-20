package br.edu.cesarschool.poo.ed;

public class Pilha {
    private ListaEncadeada listaInterna;

    public Pilha(){
        listaInterna = new ListaEncadeada();
    }
    public void empilhar(String conteudo){
        listaInterna.incluirConteudo(conteudo);
    }
    public String desempilhar(){
        return listaInterna.removerConteudo(listaInterna.getTamanhoLista()-1);
    }
    public String ler(){
        return listaInterna.obterConteudoPorIndice(listaInterna.getTamanhoLista()-1);
    }
}

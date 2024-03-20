package br.edu.cesarschool.poo.ed;

public class Fila {
    private ListaEncadeada listaInterna;

    public Fila(){
        listaInterna = new ListaEncadeada();
    }
    public void enfileirar(String conteudo){
        listaInterna.incluirConteudo(conteudo);
    }
    public String desenfileirar(){
        return listaInterna.removerConteudo(0);
    }
    public String ler(){
        return listaInterna.obterConteudoPorIndice(0);
    }
}

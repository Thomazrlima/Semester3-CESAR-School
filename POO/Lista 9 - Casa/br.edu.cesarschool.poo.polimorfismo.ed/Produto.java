package br.edu.cesarschool.poo.polimorfismo.ed;

public class Produto extends Mapeavel {
    private String codigo;
    private String nome;

    public Produto(String codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }

    @Override
    public String obterChave() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }
}

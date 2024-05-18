package br.edu.cesarschool.poo.polimorfismo.ed;

public class Cliente extends Mapeavel {
    private String cpf;
    private String nome;

    public Cliente(String cpf, String nome) {
        this.cpf = cpf;
        this.nome = nome;
    }

    @Override
    public String obterChave() {
        return cpf;
    }

    public String getNome() {
        return nome;
    }
}

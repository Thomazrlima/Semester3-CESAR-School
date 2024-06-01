package br.edu.cesarschool.cc.poo.ac.utils;

public enum DiasDaSemana {
    SEGUNDA_FEIRA(1, "segunda_feira"),
    TERCA_FEIRA(2, "terca_feira"),
    QUARTA_FEIRA(3, "quarta_feira"),
    QUINTA_FEIRA(4, "quinta_feira"),
    SEXTA_FEIRA(5, "sexta_feira"),
    SABADO(6, "sabado"),
    DOMINGO(7, "domingo");

    private final int codigo;
    private final String nome;

    private DiasDaSemana(int codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public int getCodigo() {
        return codigo;
    }

    public static DiasDaSemana getDiasDaSemana(int codigo) {
        for (DiasDaSemana dia : DiasDaSemana.values()) {
            if (dia.getCodigo() == codigo) {
                return dia;
            }
        }
        return null;
    }
}

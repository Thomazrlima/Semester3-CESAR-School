package maquinas;

import maquinas.TipoCombustivel;

public class Combustao extends Maquina{
    TipoCombustivel combustivel;

    public Combustao(double potencia, String nome, TipoCombustivel combustivel){
        super(nome, potencia);
        this.combustivel = combustivel;
    }
}

package br.edu.cesarschool.cc.poo.meiotransporte.naomotorizado;

import br.edu.cesarschool.cc.poo.meiotransporte.MeioTransporte;

import br.edu.cesarschool.cc.poo.meiotransporte.TipoTracao;

public class MeioTransporteNaoMotorizado extends MeioTransporte {
    private TipoTracao tipoTracao;

    public MeioTransporteNaoMotorizado(String nome, double cargaMaxima, double velocidadeMaxima, TipoTracao tipoTracao) {
        super(nome, cargaMaxima, velocidadeMaxima);
        this.tipoTracao = tipoTracao;
    }

    public TipoTracao getTipoTracao() {
        return this.tipoTracao;
    }

    public void setTipoTracao(TipoTracao tipoTracao) {
        this.tipoTracao = tipoTracao;
    }
}
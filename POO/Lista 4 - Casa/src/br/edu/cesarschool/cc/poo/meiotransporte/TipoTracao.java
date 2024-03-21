package br.edu.cesarschool.cc.poo.meiotransporte;

public enum TipoTracao {
    ANIMAL(1, "Tração animal"),
    HUMANA(2, "Tração humana"),
    VENTO(3,"Tração por vento");
    private int codigo;
    private String descricao;
    private TipoTracao(int codigo, String descricao) {
        this.codigo = codigo;
        this.descricao = descricao;
    }
    public int getCodigo() {
        return codigo;
    }
    public String getDescricao() {
        return descricao;
    }
    public static TipoTracao obterPorCodigo(int codigo) {
        for (TipoTracao tipoTracao : TipoTracao.values()) {
            if (tipoTracao.getCodigo() == codigo) {
                return tipoTracao;
            }
        }
        return null;
    }
}

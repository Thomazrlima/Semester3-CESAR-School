package itemvenda;
import java.util.Scanner;

enum FormaPagamento{
    dinheiro, cartaoCredito, cartaoDebito, cheque,
    valeAlimentacaoPapel, valeAlimentacaoCartao,  pix;
}

public class TipoPagamento {

    int codigo;
    String descricao;
    double tarifa;

    FormaPagamento tipoPagamento;

    public TipoPagamento(int codigo, String descricao, double tarifa, FormaPagamento tipoPagamento) {
        this.codigo = codigo;
        this.descricao = descricao;
        this.tarifa = tarifa;
        this.tipoPagamento = tipoPagamento;

    }

}

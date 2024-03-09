package itemvenda;

public class ItemVenda {
    private Produto produto;
    private int quantidade;
    private boolean isento;
    private TipoPagamento tipoPagamento;

    public ItemVenda(Produto produto, int quantidade, boolean isento, TipoPagamento tipoPagamento) {
        this.produto = produto;
        this.quantidade = quantidade;
        this.isento = isento;
        this.tipoPagamento = tipoPagamento;
    }

    public double calcularImposto(double aliquota) {
        if (!isento) {
            double imposto = aliquota / 100 * (produto.preco * quantidade);
            return imposto;
        } else {
            return 0.0;
        }
    }

    public double calcularValorTotal(double aliquota) {
        double imposto = calcularImposto(aliquota);
        double valorTotal = produto.preco * quantidade + imposto;
        return valorTotal;
    }

    public double calcularLucroItem(double custoRateado, double aliquota) {
        double imposto = calcularImposto(aliquota);
        double valorTotal = calcularValorTotal(aliquota);
        double lucroItem = valorTotal - imposto - custoRateado - tipoPagamento.tarifa;
        return lucroItem;
    }
}

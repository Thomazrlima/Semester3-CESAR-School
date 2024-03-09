package itemvenda;

import java.util.Scanner;

public class MainVenda {
    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);

        System.out.println("Código:");
        long codigoProduto = entrada.nextLong();
        entrada.nextLine();

        System.out.println("Nome:");
        String nomeProduto = entrada.nextLine();

        System.out.println("Preço:");
        double precoProduto = entrada.nextDouble();

        Produto produto = new Produto(codigoProduto, nomeProduto, precoProduto);

        System.out.println("Quantidade:");
        int quantidade = entrada.nextInt();
        entrada.nextLine();

        System.out.println("Isento?:");
        boolean isento = entrada.nextBoolean();
        entrada.nextLine();

        System.out.println("Informe a alíquota do imposto:");
        double aliquota = entrada.nextDouble();
        entrada.nextLine();

        System.out.println("Forma de pagamento:");
        FormaPagamento forma = FormaPagamento.valueOf(entrada.nextLine());

        System.out.println("Código do pagamento:");
        int codigoTipoPagamento = entrada.nextInt();
        entrada.nextLine();

        System.out.println("Descrição do pagamento:");
        String descricaoTipoPagamento = entrada.nextLine();

        System.out.println("Tarifa do pagamento:");
        double tarifaTipoPagamento = entrada.nextDouble();

        TipoPagamento tipoPagamento = new TipoPagamento(codigoTipoPagamento, descricaoTipoPagamento, tarifaTipoPagamento, forma);
        ItemVenda itemVenda = new ItemVenda(produto, quantidade, isento, tipoPagamento);

        System.out.println("Imposto sobre o item: " + itemVenda.calcularImposto(aliquota));
        System.out.println("Valor total do item: " + itemVenda.calcularValorTotal(aliquota));

        System.out.println("Custo rateado:");
        double custoRateado = entrada.nextDouble();
        System.out.println("Lucro por item: " + itemVenda.calcularLucroItem(custoRateado, aliquota));

        entrada.close();
    }
}
package vendas;
import vendas.ItemVenda;
import vendas.Produto;
import java.util.Scanner;

public class CalcularProduto {
    private static final Scanner ENTRADA = new Scanner (System.in);
    public static void main (String[] args){
        ItemVenda venda;
        Produto p1;
        p1 = new Produto(ENTRADA.nextLong(), ENTRADA.toString(), ENTRADA.nextDouble());
        venda = new ItemVenda(p1, ENTRADA.nextInt(), ENTRADA.nextBoolean(), ENTRADA.nextFloat());
        double precofinal = venda.calcpreco();
        double imposto = venda.imposto();
        System.out.println(imposto);
        System.out.println(precofinal);

    }
}

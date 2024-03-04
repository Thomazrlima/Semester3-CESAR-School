package vendas;
import vendas.Produto;
import java.util.Scanner;

public class ItemVenda {
    Produto produto;
    int quantidade;
    boolean isento = false;
    float aliquota;

    public ItemVenda(Produto p1,int quantidade, boolean isento, float aliquota){
        this.produto = p1;
        this.quantidade = quantidade;
        this.isento = isento;
        this.aliquota = aliquota;
    }
    public double imposto (){
        if(isento){
            return 0;
        }
        else{
            return (aliquota / 100) * (produto.preco * quantidade);
        }
    }
    public double calcpreco(){
        double imposto = imposto();
        return imposto + quantidade * produto.preco;
    }

}

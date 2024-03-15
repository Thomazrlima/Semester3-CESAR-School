package maquinas;

import java.util.Scanner;
import maquinas.*;

public class Main {
    private static final Scanner ENTRADA = new Scanner(System.in);

    public static void main(String[] args) {
        Eletrica furadeira;
        Combustao gerador;

        furadeira = new Eletrica(400,"Furadeira", 150, false);
        gerador = new Combustao(400, "Gerador", TipoCombustivel.gasolina);

        System.out.println(String.format("A %s é movida a energia, com uma potência de %.2f Watts e uma corrente de %.2f Amperes, com uma voltagem de %.2f e a corrente %s", furadeira.nome, furadeira.potencia, furadeira.correnteUtilizada(), furadeira.voltagem, furadeira.tipoCorrente()));
        System.out.println(String.format("id do objeto: %s", furadeira.hashCode()));
        System.out.println(String.format("A %s é movida a %s, com uma potência de %.2f Watts ", gerador.nome, gerador.combustivel, gerador.potencia));
        System.out.println(String.format("id do objeto: %s", gerador.hashCode()));
    }
}

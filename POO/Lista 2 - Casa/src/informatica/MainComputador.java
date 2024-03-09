package informatica;

import informatica.*;

import java.util.Scanner;

public class MainComputador {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Informe a marca do processador: ");
        String marca = scanner.nextLine();

        System.out.println("Informe a descrição:");
        String descricao = scanner.nextLine();

        System.out.println("Informe a Clock:");
        double clockBase = scanner.nextDouble();

        System.out.println("Informe o Turbo:");
        double fatorTurbo = scanner.nextDouble();

        System.out.println("Informe a RAM:");
        int capacidadeRamEmGB = scanner.nextInt();

        System.out.println("Informe a Capacidade de Armazenamento:");
        int capacidadeDiscoEmGB = scanner.nextInt();

        System.out.println("É um notebook????:");
        boolean ehNotebook = scanner.nextBoolean();

        Modelo modelo = new Modelo(descricao, marca);
        UCP ucp = new UCP(modelo, clockBase, fatorTurbo);
        Computador computador = new Computador(ucp, modelo, capacidadeRamEmGB, capacidadeDiscoEmGB, ehNotebook);

        System.out.println("Clock Máximo: " + computador.ucp.calcularClockMaximo());
        int result = computador.obterDescricaoPormenorizada();

    }
}

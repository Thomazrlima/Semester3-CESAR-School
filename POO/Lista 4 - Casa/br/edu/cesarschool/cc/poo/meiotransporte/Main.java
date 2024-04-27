package br.edu.cesarschool.cc.poo.meiotransporte;

import br.edu.cesarschool.cc.poo.meiotransporte.motorizado.Carro;
import br.edu.cesarschool.cc.poo.meiotransporte.naomotorizado.AsaDelta;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner ENTRADA = new Scanner(System.in);

        System.out.println("Digite os dados do carro");
        System.out.print("Nome: ");
        String nomeCarro = ENTRADA.nextLine();
        System.out.print("Carga Máxima (kg): ");
        double cargaMaximaCarro = ENTRADA.nextDouble();
        System.out.print("Velocidade Máxima (km/h): ");
        double velocidadeMaximaCarro = ENTRADA.nextDouble();
        System.out.print("Potência do Motor (hp): ");
        double potenciaMotorCarro = ENTRADA.nextDouble();
        System.out.print("Capacidade do Combustível (litros): ");
        double capacidadeCombustivelCarro = ENTRADA.nextDouble();
        System.out.print("Consumo Médio (km/l): ");
        double consumoMedioCarro = ENTRADA.nextDouble();

        Carro carro = new Carro(nomeCarro, cargaMaximaCarro, velocidadeMaximaCarro, potenciaMotorCarro,
                capacidadeCombustivelCarro, consumoMedioCarro);

        System.out.println("\nDigite os dados da asa delta:");
        ENTRADA.nextLine();
        System.out.print("Nome: ");
        String nomeAsaDelta = ENTRADA.nextLine();
        System.out.print("Carga Máxima (kg): ");
        double cargaMaximaAsaDelta = ENTRADA.nextDouble();
        System.out.print("Velocidade Máxima (km/h): ");
        double velocidadeMaximaAsaDelta = ENTRADA.nextDouble();
        System.out.println("Escolha o tipo de tração para a asa delta:");
        System.out.println("1. Tração animal");
        System.out.println("2. Tração humana");
        System.out.println("3. Tração por vento");
        System.out.print("Opção: ");
        int opcaoTipoTracao = ENTRADA.nextInt();

        TipoTracao tipoTracaoAsaDelta = TipoTracao.obterPorCodigo(opcaoTipoTracao);

        AsaDelta asaDelta = new AsaDelta(nomeAsaDelta, cargaMaximaAsaDelta, velocidadeMaximaAsaDelta,
                tipoTracaoAsaDelta);

        System.out.println("\nCarro:");
        System.out.println("Nome: " + carro.getNome());
        System.out.println("Carga Máxima: " + carro.getCargaMaxima() + " kg");
        System.out.println("Velocidade Máxima: " + carro.getVelocidadeMaxima() + " km/h");
        System.out.println("Potência do Motor: " + carro.getPotenciaMotor() + " hp");
        System.out.println("Capacidade do Combustível: " + carro.getCapacidadeCombustivel() + " litros");
        System.out.println("Consumo Médio: " + carro.getConsumoMedio() + " km/l");
        System.out.println("Autonomia: " + carro.calcularAutonomia() + " km");
        System.out.println("Eficiência: " + carro.calcularEficiencia() + " kg/km");

        System.out.println("\nAsa Delta:");
        System.out.println("Nome: " + asaDelta.getNome());
        System.out.println("Carga Máxima: " + asaDelta.getCargaMaxima() + " kg");
        System.out.println("Velocidade Máxima: " + asaDelta.getVelocidadeMaxima() + " km/h");
        System.out.println("Tipo de Tração: " + asaDelta.getTipoTracao().getDescricao());

    }
}

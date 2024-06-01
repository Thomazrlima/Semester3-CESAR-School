package br.edu.cesarschool.cc.poo.ac.passagem;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
public class TelaVoo {
    private VooMediator vooMed = VooMediator.obterInstancia();
    private Scanner ENTRADA = new Scanner(System.in);
    private static final BufferedReader ENTRADA_STR = new BufferedReader(new InputStreamReader(System.in));

    public void inicializaTelasCadastroVoo() {
        while(true){
            imprimeMenuPrincipal();
            int opcao = ENTRADA.nextInt();
            switch (opcao){
                case 1:
                    processaInclusao();
                    break;
                case 2:
                    processaAlteracao();
                    break;
                case 3:
                    processaExclusao();
                    break;
                case 4:
                    processaBusca();
                    break;
                case 5:
                    System.out.println("Saindo do cadastro de Voos");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opção inválida!!");
                    break;
            }
        }
    }

    private void imprimeMenuPrincipal() {
        System.out.println("1- Incluir");
        System.out.println("2- Alterar");
        System.out.println("3- Excluir");
        System.out.println("4- Buscar");
        System.out.println("5- Sair");
        System.out.print("Digite a opção: ");
    }

    private void processaInclusao() {
        System.out.println("Insira o aeroporto de origem: ");
        String aeroportoOrigem = lerString();
        System.out.println("Insira o aeroporto de destino: ");
        String aeroportoDestino = lerString();
        System.out.println("Insira a companhia aerea: ");
        String cia =  lerString();
        System.out.println("Insira o numero do voo: ");
        int numerovoo = ENTRADA.nextInt();
        Voo voo = new Voo(aeroportoOrigem, aeroportoDestino, cia, numerovoo);
        String retorno = vooMed.incluir(voo);
        if (retorno == null) {
            System.out.println("Voo incluído com sucesso!");
        } else {
            System.out.println(retorno);
        }
    }

    private void processaAlteracao() {
        Voo vooOriginal = processaBusca();
        String cia = vooOriginal.getCompanhiaAerea();
        int numerovoo = vooOriginal.getNumeroVoo();
        System.out.println("Insira o aeroporto de origem: ");
        String aeroportoOrigem = lerString();
        System.out.println("Insira o aeroporto de destino: ");
        String aeroportoDestino = lerString();
        Voo voo = new Voo(aeroportoOrigem, aeroportoDestino, cia, numerovoo);
        String retorno = vooMed.alterar(voo);
        if (retorno == null) {
            System.out.println("Voo alterado com sucesso!");
        } else {
            System.out.println(retorno);
        }
    }

    private Voo processaBusca() {
        System.out.print("Digite a companhia aerea: ");
        String companhia = lerString();
        System.out.print("Digite o numero do voo: ");
        String numerovoo = lerString();
        Voo voo = vooMed.buscar(companhia+numerovoo);
        if (voo == null) {
            System.out.println("Voo nao encontrado");
            return null;
        } else {
            // Mostrar todos os atributos do Voo!!
            System.out.println("CIA: " + voo.getCompanhiaAerea());
            System.out.println("Aeroporto de Origem: " + voo.getAeroportoOrigem());
            System.out.println("Aeroporto de Destino: " + voo.getAeroportoDestino());
            System.out.println("Numero do Voo: " + voo.getNumeroVoo());
            return voo;
        }
    }

    private void processaExclusao() {
        String idvoo = processaBusca().obterIdVoo();
        String retorno = vooMed.excluir(idvoo);
        if (retorno == null) {
            System.out.println("Voo excluído com sucesso!");
        } else {
            System.out.println(retorno);
        }
    }

    private String lerString() {
        try {
            return ENTRADA_STR.readLine();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}

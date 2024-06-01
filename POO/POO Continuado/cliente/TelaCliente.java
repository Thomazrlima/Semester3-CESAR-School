package br.edu.cesarschool.cc.poo.ac.cliente;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class TelaCliente {
    private ClienteMediator clienteMediator = ClienteMediator.obterInstancia();
    private static final Scanner ENTRADA = new Scanner(System.in);
    private static final BufferedReader ENTRADA_STR = new BufferedReader(new InputStreamReader(System.in));

    public void inicializaTelasCadastroProduto() {
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
                    System.out.println("Saindo do cadastro de clientes");
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
        System.out.println("Insira o cpf do cliente: ");
        String cpf = lerString();
        System.out.println("Insira o nome do cliente: ");
        String nome = lerString();
        System.out.println("Insira o saldo do cliente: ");
        double saldo = ENTRADA.nextDouble();
        Cliente cliente = new Cliente(cpf, nome, saldo);
        String retorno = clienteMediator.incluir(cliente);
        if (retorno == null) {
            System.out.println("Cliente incluído com sucesso!");
        } else {
            System.out.println(retorno);
        }
    }

    private void processaAlteracao() {
        String cpf = processaBusca().getCpf();
        System.out.println("Insira o nome do cliente: ");
        String nome = lerString();
        System.out.println("Insira o saldo do cliente: ");
        double saldo = ENTRADA.nextDouble();
        Cliente cliente = new Cliente(cpf, nome, saldo);
        String retorno = clienteMediator.alterar(cliente);
        if (retorno == null) {
            System.out.println("Cliente alterado com sucesso!");
        } else {
            System.out.println(retorno);
        }
    }

    private Cliente processaBusca() {
        System.out.print("Digite o cpf do cliente: ");
        String cpf = lerString();
        Cliente cliente = clienteMediator.buscar(cpf);
        if (cliente == null) {
            System.out.println("Cliente nao encontrado");
            return null;
        } else {
            // Mostrar todos os atributos do Cliente!!
            System.out.println("Nome: " + cliente.getNome());
            System.out.println("CPF: " + cliente.getCpf());
            System.out.println("Saldo: " + cliente.getSaldoPontos());
            return cliente;
        }
    }

    private void processaExclusao() {
        System.out.print("Digite o cpf do cliente: ");
        String cpf = lerString();
        String retorno = clienteMediator.excluir(cpf);
        if (retorno == null) {
            System.out.println("Cliente excluído com sucesso!");
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
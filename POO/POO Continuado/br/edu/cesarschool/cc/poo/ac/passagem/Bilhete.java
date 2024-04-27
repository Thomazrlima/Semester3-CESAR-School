package br.edu.cesarschool.cc.poo.ac.passagem;

import br.edu.cesarschool.cc.poo.ac.utils.Registro;
import br.edu.cesarschool.cc.poo.ac.cliente.Cliente;
import java.time.LocalDateTime;

public class Bilhete extends Registro {
    private Cliente cliente;
    private Voo voo;
    private double preco;
    private double pagamentoEmPontos;
    private LocalDateTime dataHora;

    public Bilhete(Cliente cliente, Voo voo, double preco, double pagamentoEmPontos, LocalDateTime dataHora) {
        this.cliente = cliente;
        this.voo = voo;
        this.preco = preco;
        this.pagamentoEmPontos = pagamentoEmPontos;
        this.dataHora = dataHora;
    }

    public void setPagamentoEmPontos(double pagamentoEmPontos) {
        this.pagamentoEmPontos = pagamentoEmPontos;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public Voo getVoo() {
        return voo;
    }

    public double getPreco() {
        return preco;
    }

    public double getPagamentoEmPontos() {
        return pagamentoEmPontos;
    }

    public LocalDateTime getDataHora() {
        return dataHora;
    }

    public double obterValorPago() {
        return preco - pagamentoEmPontos;
    }

    public double obterValorPontuacao() {
        return pagamentoEmPontos / 20.0;
    }

    public String gerarNumero() {
        String cpfCliente = cliente.getCpf();
        String numeroVoo = voo.obterIdVoo();
        int ano = dataHora.getYear();
        int mes = dataHora.getMonthValue();
        int dia = dataHora.getDayOfMonth();
        return cpfCliente + numeroVoo + ano + mes + dia;
    }
}

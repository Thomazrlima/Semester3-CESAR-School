package br.edu.cesarschool.cc.poo.ac.passagem;

import br.edu.cesarschool.cc.poo.ac.utils.DiasDaSemana;
import br.edu.cesarschool.cc.poo.ac.utils.Registro;

import java.time.LocalTime;

public class Voo extends Registro {
	private String aeroportoOrigem;
	private String aeroportoDestino;
	private String companhiaAerea;
	private int numeroVoo;
	private DiasDaSemana[] diasDaSemana;
	private LocalTime hora;

	public Voo(String aeroportoOrigem, String aeroportoDestino, String companhiaAerea, int numeroVoo) {
		this.aeroportoOrigem = aeroportoOrigem;
		this.aeroportoDestino = aeroportoDestino;
		this.companhiaAerea = companhiaAerea;
		this.numeroVoo = numeroVoo;
	}
	public Voo(String aeroportoOrigem, String aeroportoDestino, String companhiaAerea, int numeroVoo, DiasDaSemana[] diasDaSemana, LocalTime horas) {
		this(aeroportoOrigem, aeroportoDestino, companhiaAerea, numeroVoo);
		this.diasDaSemana = diasDaSemana;
		this.hora = horas;
	}
	public String getAeroportoOrigem() {
		return aeroportoOrigem;
	}

	public String getAeroportoDestino() {
		return aeroportoDestino;
	}

	public String getCompanhiaAerea() {
		return companhiaAerea;
	}

	public int getNumeroVoo() {
		return numeroVoo;
	}

	public String obterIdVoo() {
		return companhiaAerea + numeroVoo;
	}

	public LocalTime getHora() {
		return hora;
	}

	public void setHora(LocalTime hora) {
		this.hora = hora;
	}

	public DiasDaSemana[] getDiasDaSemana() {
		return diasDaSemana;
	}

	public void setDiasDaSemana(DiasDaSemana[] diasDaSemana) {
		this.diasDaSemana = diasDaSemana;
	}

	public String getIdUnico() {
		return String.valueOf(getNumeroVoo());
	}
}
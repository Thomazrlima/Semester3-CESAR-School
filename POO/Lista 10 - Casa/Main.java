package projetoum;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Criando alguns objetos Computador
        CPU cpu1 = new CPU("Intel i7", 3.8);
        CPU cpu2 = new CPU("AMD Ryzen 5", 3.6);
        CPU cpu3 = new CPU("AMD Ryzen 5", 1.2);
        CPU cpu4 = new CPU("Intel i7", 2.5);
        Computador comp1 = new Computador("PC1", 500, "Dell", 16, cpu1, "Dell");
        Computador comp2 = new Computador("PC2", 450, "HP", 8, cpu2, "HP");
        Computador comp3 = new Computador("PC3", 300, "ACER", 8, cpu3, "ACER");
        Computador comp4 = new Computador("PC4", 780, "MacBook", 8, cpu4, "MacBook");
        

        List<Computador> listaComputadores = new ArrayList<>();
        listaComputadores.add(comp1);
        listaComputadores.add(comp2);
        listaComputadores.add(comp3);
        listaComputadores.add(comp4);

        // Ordenando computadores por clock da CPU
        OrdenacaoUtil.ordenarLista(listaComputadores);
        for (Computador comp : listaComputadores) {
            System.out.println(comp.getMarca() + " - " + comp.getCpu().getClock() + "GHz");
        }

        // Criando alguns objetos Humano
        Humano humano1 = new Humano("Homo sapiens", 30, "Curta", "Alice", "Feminino");
        Humano humano2 = new Humano("Homo sapiens", 25, "Curta", "Bob", "Masculino");
        Humano humano3 = new Humano("Homo sapiens", 28, "Curta", "Zuleide", "Feminino");
        Humano humano4 = new Humano("Homo sapiens", 56, "Curta", "Daniel", "Masculino");

        List<Humano> listaHumanos = new ArrayList<>();
        listaHumanos.add(humano1);
        listaHumanos.add(humano2);
        listaHumanos.add(humano3);
        listaHumanos.add(humano4);

        // Ordenando humanos por nome
        OrdenacaoUtil.ordenarLista(listaHumanos);
        for (Humano humano : listaHumanos) {
            System.out.println(humano.getNome());
        }
    }
}

package figurasgeometricas;

import java.util.Scanner;

public class MainFiguras {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Informe a forma do terreno:");
        System.out.println("1- Triangulo");
        System.out.println("2- Retangulo");
        System.out.println("3- Circulo");

        int forma = scanner.nextInt();

        if (forma < 1 || forma > 3) {
            System.out.println("TIPO ERRADO");
            return;
        }

        double area = 0;
        switch (forma) {
            case 1:
                System.out.println("Informe os lados do triângulo:");
                double l1 = scanner.nextDouble();
                double l2 = scanner.nextDouble();
                double l3 = scanner.nextDouble();
                Triangulo triangulo = new Triangulo(l1, l2, l3);
                area = triangulo.calcularArea();
                break;
            case 2:
                System.out.println("Informe os lados do retângulo ou quadrado:");
                double lado = scanner.nextDouble();
                area = Math.pow(lado, 2); // Área do quadrado
                break;
            case 3:
                System.out.println("Informe o raio do círculo:");
                double raio = scanner.nextDouble();
                Circulo circulo = new Circulo(raio);
                area = circulo.calcularArea();
                break;
        }

        double valorPorMetroQuadrado =

        Terreno terreno = new Terreno(valorPorMetroQuadrado, endereco);
        double valor = terreno.calcularValorTerreno(area, valorPorMetroQuadrado);

        System.out.println("Área do terreno: " + area);
        System.out.println("Valor do Terreno: " + valor);

        scanner.close();
    }
}
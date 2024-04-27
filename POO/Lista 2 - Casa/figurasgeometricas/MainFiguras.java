package figurasgeometricas;

import java.util.Scanner;

public class MainFiguras {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Informe a forma do terreno:");
        System.out.println("1- Triangulo");
        System.out.println("2- Paralelogramo");
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

                System.out.println("Informe os lados do Paralelogramo:");
                double lado = scanner.nextDouble();
                System.out.println("Informe o lado do Paralelogramo:");
                double ladoAdjacente = scanner.nextDouble();
                System.out.println("Informe o angulo do Paralelogramo:");
                double angulo = scanner.nextDouble();
                Paralelogramo paralelogramo = new Paralelogramo(lado,ladoAdjacente, angulo);
                area = paralelogramo.calcularArea();
                break;

            case 3:

                System.out.println("Informe o raio do círculo:");
                double raio = scanner.nextDouble();
                Circulo circulo = new Circulo(raio);
                area = circulo.calcularArea();
                break;

        }

        System.out.println("Informe o cep:");
        scanner.nextLine();
        int cep = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Informe o logradouro:");
        String logradouro = scanner.nextLine();

        System.out.println("Informe o numero:");
        int numero = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Informe complemento:");
        String complemento = scanner.nextLine();

        System.out.println("Informe o valor por metro quadrado:");
        double valorPorMetroQuadrado = scanner.nextDouble();

        Endereco endereco = new Endereco(cep, logradouro, numero, complemento);
        Terreno terreno = new Terreno(valorPorMetroQuadrado, endereco);
        double valor = terreno.calcularValorTerreno(area, valorPorMetroQuadrado);

        System.out.println("Área do terreno: " + area);
        System.out.println("Valor do Terreno: " + valor);

        scanner.close();
    }
}
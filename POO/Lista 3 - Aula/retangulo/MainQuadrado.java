package retangulo;

import java.util.Scanner;

public class MainQuadrado {
    private static final Scanner scanner = new Scanner(System.in);
        public static void main(String[] args) {
            double lado;
            double area;
            Quadrado quadrado;
            Scanner scanner = new Scanner(System.in);
            System.out.println("Informe os lados do Quadrado:");
            lado = scanner.nextDouble();
            quadrado = new Quadrado(lado);
            area = quadrado.calcularArea();
            System.out.println("Area do quadrado: " + area);
    }
}

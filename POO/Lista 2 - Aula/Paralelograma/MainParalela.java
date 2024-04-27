package Paralelograma;
import java.util.Scanner;

public class MainParalela {
    public static final Scanner ENTRADA  = new Scanner(System.in);
    public static void main(String[] args) {

        System.out.println("Informe a parte superior do Paralelogramo:");
        double lado = ENTRADA.nextDouble();

        System.out.println("Informe a parte lateral do Paralelogramo:");
        double ladoAdjacente = ENTRADA.nextDouble();

        System.out.println("Informe o angulo do Paralelogramo:");
        double angulo = ENTRADA.nextDouble();

        Paralelogramo paralelogramo = new Paralelogramo(lado,ladoAdjacente, angulo);
        double area = paralelogramo.calcularArea();
        double perimetro = paralelogramo.calcularPerimetro();
        double anguloMaior = paralelogramo.maiorAngulo();

        System.out.println("A área do paralelogramo é: " + area);
        System.out.println("O perimetro do paralelogramo é: " + perimetro);
        System.out.println("O maior ângulo do paralelogramo é: " + anguloMaior);

    }
}
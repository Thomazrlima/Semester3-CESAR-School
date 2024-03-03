package JavaEstruturado;

import java.util.Scanner;
public class JavaEstruturado3 {
    public static void main(String[] args) {


        Scanner ENTRADA = new Scanner(System.in);

        float x1 = ENTRADA.nextInt();
        float x2 = ENTRADA.nextInt();
        float x3 = ENTRADA.nextInt();
        float x4 = ENTRADA.nextInt();
        float x5 = ENTRADA.nextInt();

        float soma = x1 + x2 + x3 + x4 + x5;
        float x = (soma)/5;
        double xg = Math.pow(soma, 1/5);
        float mh = (5/((1/x1) + (1/x2) + (1/x3) + (1/x4) + (1/x5)));

        System.out.println(x);
        System.out.println(xg);
        System.out.println(mh);


    }

}

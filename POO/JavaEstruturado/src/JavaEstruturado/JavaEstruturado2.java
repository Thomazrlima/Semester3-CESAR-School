package JavaEstruturado;

import java.util.Scanner;
public class JavaEstruturado2 {

    public static void main(String[] args) {
        float x = 0;
        float soma = 0;
        Scanner ENTRADA = new Scanner(System.in);

        do{

            x = ENTRADA.nextFloat();

            if(x >= 5 && x <= 5000){
                soma += x;
                System.out.println(soma);
            }

        }while(x > 0);
    }

}

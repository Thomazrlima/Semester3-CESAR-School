package JavaEstruturado;

import java.util.Scanner;
public class JavaEstruturado1 {
    public static void main(String[] args) {


        Scanner ENTRADA = new Scanner(System.in);

        int x = ENTRADA.nextInt();

        if(x > 16){
            System.out.println("OVERFLOW");
        }
        else if(x >= 0) {
            for(int i = (x-1); i > 1; i--){
                x = x*i;
                System.out.println(x);

            }
        }else {
            System.out.println("MENOR QUE ZERO");
        }


    }

}

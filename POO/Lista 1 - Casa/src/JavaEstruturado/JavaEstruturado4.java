package JavaEstruturado;

import java.util.Scanner;
public class JavaEstruturado4 {
    public static void main(String[] args) {


        Scanner ENTRADA = new Scanner(System.in);

        int caso = ENTRADA.nextInt();
        float x = ENTRADA.nextInt();
        float y = ENTRADA.nextInt();
        float result;

        if(caso == 1){
            result = x+y;
            System.out.println(result);
        }
        else if(caso == 2){
            result = x-y;
            System.out.println(result);
        }
        else if(caso == 3){
            if(y == 0) {
                System.out.println("DIV ZERO");
            }else{
                result = x/y;
                System.out.println(result);
            }
        }
        else if(caso == 4){
            result = x*y;
            System.out.println(result);
        }
        else {
            System.out.println("OPC ERRADA");
        }
    }

}

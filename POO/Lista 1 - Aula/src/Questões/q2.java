package Questões;

import java.util.Scanner;

public class q2 {

	public static void main(String[] args) {
		float x = 0;
		Scanner ENTRADA = new Scanner(System.in);
		
		do{
			
			x = ENTRADA.nextFloat();
			
			if(x < 2 || x > 20) {
				System.out.println(x);
			}
			
		}while(x != 1);

	}

}

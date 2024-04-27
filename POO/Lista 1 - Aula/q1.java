package Questões;

import java.util.Scanner;

public class q1 {

	public static void main(String[] args) {
		
		
		Scanner ENTRADA = new Scanner(System.in);
		
		int x = ENTRADA.nextInt();
		
		if(x >= 0) {
			for(x= x; x >= 0; x--){
				if(x%2 == 0) {
					System.out.println(x);
				}
			}
		}else {
			System.out.println("Só positivo");
		}


	}

}

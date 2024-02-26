package Questões;

import java.util.Scanner;

public class q3 {

	public static void main(String[] args) {
		Scanner ENTRADA = new Scanner(System.in);
		
		int x = ENTRADA.nextInt();
		int y = ENTRADA.nextInt();
		
		if (x == 1) {
			System.out.println(y%2);
		}else if (x == 2) {
			System.out.println(Math.PI + y);
		}else {
			System.out.println(1/y);
		}

	}

}

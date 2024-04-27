import java.math.BigDecimal;

public class Calculadora {

	public double exponenciar(double base, double expoente) {
		return Math.pow(base, expoente);
	}

	public double exponenciar(long base, long expoente) {
		return Math.pow(base, expoente);
	}

	public double exponenciar(BigDecimal base, BigDecimal expoente) {
		return base.pow(expoente.intValue()).doubleValue();
	}

	public static void main(String[] args) {
		Calculadora calculadora = new Calculadora();

		System.out.println(calculadora.exponenciar(2, (byte) 3));

		System.out.println(calculadora.exponenciar(3L, 4));

		System.out.println(calculadora.exponenciar(2, 3.0));

		BigDecimal base = new BigDecimal("2");
		BigDecimal expoente = new BigDecimal("3");
		System.out.println(calculadora.exponenciar(base, expoente));

		BigDecimal baseDecimal = new BigDecimal("2");
		float expoenteFloat = 3.0f;
		System.out.println(calculadora.exponenciar(baseDecimal, BigDecimal.valueOf(expoenteFloat)));
	}
}
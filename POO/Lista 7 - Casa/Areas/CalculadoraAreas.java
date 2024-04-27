public class CalculadoraAreas {

	public static double calcularArea(double lado) {
		return lado * lado;
	}

	public static double calcularArea(double base, double altura) {
		return calcularArea(base, altura, 90);
	}

	public static double calcularArea(float base, float altura, float angulo) {
		double radianos = Math.toRadians(angulo);
		return base * altura * Math.sin(radianos);
	}

	public static double calcularArea(float raio) {
		return Math.PI * raio * raio;
	}
}
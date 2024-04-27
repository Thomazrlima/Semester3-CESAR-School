package distanciapontos1;

public class CalculadoraDistanciaPontos {
//	public static double calcularDistancia(PontoPlano p1, PontoPlano p2) {
//	return Math.sqrt(
//			Math.pow(p2.getX() - p1.getX(), 2) + 
//			Math.pow(p2.getY() - p1.getY(), 2));
//}	
	public static double calcularDistancia(PontoPlano p1, PontoPlano p2) {
//		PontoEspaco pe1 = new PontoEspaco(p1.getX(), p1.getY(), 0);
//		PontoEspaco pe2 = new PontoEspaco(p2.getX(), p2.getY(), 0);
		
//		PontoEspaco pe1 = new PontoEspaco(p1, 0);
//		PontoEspaco pe2 = new PontoEspaco(p2, 0);
		
		PontoEspaco pe1 = new PontoEspaco(p1);
		PontoEspaco pe2 = new PontoEspaco(p2);				
		return calcularDistancia(pe1, pe2);
	}
	public static double calcularDistancia(PontoEspaco p1, PontoEspaco p2) {
		return Math.sqrt(
				Math.pow((p2.getX() - p1.getX()), 2) +
				Math.pow((p2.getY() - p1.getY()), 2) +
				Math.pow((p2.getZ() - p1.getZ()), 2)
				);
	}
	
}

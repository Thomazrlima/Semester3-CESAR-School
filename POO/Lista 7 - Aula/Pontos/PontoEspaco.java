package distanciapontos1;

public class PontoEspaco extends PontoPlano {
	private double z;

	public PontoEspaco(double x, double y, double z) {
		super(x, y);
		this.z = z;
	}
	public PontoEspaco(PontoPlano p, double z) {
		this(p.getX(), p.getY(), z);
	}
	public PontoEspaco(PontoPlano p) {
		this(p, 0);
	}

	public double getZ() {
		return z;
	}
	

}

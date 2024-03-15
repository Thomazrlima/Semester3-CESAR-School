package maquinas;

public class Eletrica extends Maquina {
    double voltagem;
    boolean corrente; //false para alternada e true para continua

    public Eletrica(double potencia, String nome, double voltagem, boolean corrente){
        super(nome, potencia);
        this.corrente = corrente;
        this.voltagem = voltagem;
    }

    public double correnteUtilizada(){
        return this.potencia / this.voltagem;
    }

    public String tipoCorrente(){
        if(this.corrente){
            return "continua";
        }else{
            return "alternada";
        }
    }

}

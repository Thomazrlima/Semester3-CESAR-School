package figurasgeometricas;

public class Endereco {
    int cep;
    String logradouro;
    int numero;

    String complemento;

    public Endereco(int cep, String logradouro, int numero, String complemento){
        this.cep = cep;
        this.complemento = complemento;
        this.logradouro = logradouro;
        this.numero = numero;
    }

}

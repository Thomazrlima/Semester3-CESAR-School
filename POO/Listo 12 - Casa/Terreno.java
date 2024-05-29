public class Terreno {

    public double calcularPreco(double largura, double comprimento, double valorM2) throws LadoInvalidoException, ValorM2InvalidoException {
        if (largura <= 0) {
            throw new LadoInvalidoException("A largura deve ser maior que zero.");
        }
        if (comprimento <= 0) {
            throw new LadoInvalidoException("O comprimento deve ser maior que zero.");
        }
        if (valorM2 <= 0) {
            throw new ValorM2InvalidoException("O valor do metro quadrado deve ser maior que zero.");
        }

        return largura * comprimento * valorM2;
    }
}

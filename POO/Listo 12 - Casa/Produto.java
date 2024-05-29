public class Produto {

    public double calcularPrecoFinal(double PC, double MPL, double PI) throws PrecoCompraInvalidoException, MargemLucroInvalidaException, PercentualInvalidoException {
        if (PC <= 0) {
            throw new PrecoCompraInvalidoException("O preço de compra (PC) deve ser maior que zero.");
        }
        if (PI <= 0 || PI > 1) {
            throw new PercentualInvalidoException("O percentual de imposto (PI) deve estar entre 0 (exclusive) e 1 (inclusive).");
        }
        if (MPL <= 0 || MPL > 1) {
            throw new PercentualInvalidoException("A margem percentual de lucro (MPL) deve estar entre 0 (exclusive) e 1 (inclusive).");
        }
        if (MPL > 1.6 * PI) {
            throw new MargemLucroInvalidaException("A margem percentual de lucro (MPL) deve ser no máximo 1,6 vezes o percentual de imposto (PI).");
        }

        return PC * (1.05 + (PI / 100) + (MPL / 100));
    }
}

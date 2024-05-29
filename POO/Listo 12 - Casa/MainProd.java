import java.util.Scanner;

public class MainProd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Produto produto = new Produto();

        try {
            System.out.print("Digite o preço de compra (PC): ");
            double PC = scanner.nextDouble();

            System.out.print("Digite a margem percentual de lucro (MPL): ");
            double MPL = scanner.nextDouble();

            System.out.print("Digite o percentual de imposto (PI): ");
            double PI = scanner.nextDouble();

            double precoFinal = produto.calcularPrecoFinal(PC, MPL, PI);
            System.out.println("Preço final do produto: R$" + precoFinal);
        } catch (PrecoCompraInvalidoException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (PercentualInvalidoException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (MargemLucroInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Erro inesperado: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}

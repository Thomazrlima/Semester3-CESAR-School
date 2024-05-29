import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Terreno terreno = new Terreno();

        try {
            System.out.print("Digite a largura do terreno: ");
            double largura = scanner.nextDouble();

            System.out.print("Digite o comprimento do terreno: ");
            double comprimento = scanner.nextDouble();

            System.out.print("Digite o valor do metro quadrado: ");
            double valorM2 = scanner.nextDouble();

            double preco = terreno.calcularPreco(largura, comprimento, valorM2);
            System.out.println("Preço do terreno: R$" + preco);
        } catch (LadoInvalidoException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (ValorM2InvalidoException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Erro inesperado: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}

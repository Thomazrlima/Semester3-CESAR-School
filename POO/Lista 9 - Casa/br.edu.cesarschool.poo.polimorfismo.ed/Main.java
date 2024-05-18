package br.edu.cesarschool.poo.polimorfismo.ed;

public class Main {
    public static void main(String[] args) {
        Mapa mapaProdutos = new Mapa();
        Mapa mapaClientes = new Mapa();

        Produto p1 = new Produto("001", "Caneta");
        Produto p2 = new Produto("002", "Caderno");

        Cliente c1 = new Cliente("123456789", "João");
        Cliente c2 = new Cliente("987654321", "Maria");

        mapaProdutos.inserir(p1);
        mapaProdutos.inserir(p2);

        mapaClientes.inserir(c1);
        mapaClientes.inserir(c2);

        System.out.println("Produtos:");
        System.out.println(mapaProdutos.buscar("001").getNome());
        System.out.println(mapaProdutos.buscar("002").getNome());

        System.out.println("Clientes:");
        System.out.println(mapaClientes.buscar("123456789").getNome());
        System.out.println(mapaClientes.buscar("987654321").getNome());
    }
}

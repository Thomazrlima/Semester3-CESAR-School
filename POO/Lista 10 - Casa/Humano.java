package projetoum;

public class Humano extends Mamifero implements Comparable<Humano> {
    private String nome;
    private String genero;

    public Humano(String especie, int idade, String tipoPelagem, String nome, String genero) {
        super(especie, idade, tipoPelagem); // Chama o construtor da classe base Mamifero
        this.nome = nome;
        this.genero = genero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    @Override
    public int compareTo(Humano other) {
        return this.nome.compareTo(other.getNome());
    }
}
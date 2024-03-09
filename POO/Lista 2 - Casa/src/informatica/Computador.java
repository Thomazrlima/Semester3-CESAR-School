package informatica;

public class Computador {
    UCP ucp;
    Modelo modelo;
    int capacidadeRamEmGB;
    int capacidadeDiscoEmGB;
    boolean ehNotebook;

    public Computador(UCP ucp, Modelo modelo, int capacidadeRamEmGB, int capacidadeDiscoEmGB, boolean ehNotebook) {
        this.ucp = ucp;
        this.modelo = modelo;
        this.capacidadeRamEmGB = capacidadeRamEmGB;
        this.capacidadeDiscoEmGB = capacidadeDiscoEmGB;
        this.ehNotebook = ehNotebook;
    }

    public int obterDescricaoPormenorizada(){
        if (!ehNotebook){
            System.out.println("Notebook com processador " + this.ucp.modelo.marca + "," + capacidadeRamEmGB + " GB de RAM ," +capacidadeDiscoEmGB + "GB de disco");
        }else{
            System.out.println("Desktop com processador " + this.ucp.modelo.marca + "," + capacidadeRamEmGB + " GB de RAM ," +capacidadeDiscoEmGB + "GB de disco");
        }
        return 0;
    }
}

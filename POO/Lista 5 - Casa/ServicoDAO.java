package exercicioUML;

public class ServicoDAO {
    private static ServicoDAO servicoDAO = null;
    private ServicoDAO() {

    }
    public static ServicoDAO getInstancia() {
        return null;
    }
    public boolean incluir(Servico servico){
        return false;
    }
    public boolean alterar(Servico servico){
        return false;
    }
    public boolean excluir(long codigo){
        return false;
    }
    public Servico buscar(long codigo){
        return null;
    }
}

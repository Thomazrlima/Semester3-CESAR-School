public class StringUtils {
    public static String obterTextoCensurado(String textoOriginal, String[] palavrasProibidas) {
        if (textoOriginal == null){
            return null;
        }
        if (palavrasProibidas == null || palavrasProibidas.length == 0){
            return textoOriginal;
        }

        String[] palavras = textoOriginal.split("\\s+");
        StringBuilder resultado = new StringBuilder();

        for (String palavra : palavras) {
            if (!contemPalavraProibida(palavra, palavrasProibidas)) {
                resultado.append(palavra).append(" ");
            }
        }

        return resultado.toString().trim();
    }

    public static String obterMaiorPalavra(String texto) {
        if (texto == null || texto.isEmpty()) return null;

        String[] palavras = texto.split("\\s+");
        String maiorPalavra = palavras[0];

        for (String palavra : palavras) {
            if (palavra.length() > maiorPalavra.length()) {
                maiorPalavra = palavra;
            }
        }

        return maiorPalavra;
    }

    private static boolean contemPalavraProibida(String palavra, String[] palavrasProibidas) {
        for (String proibida : palavrasProibidas) {
            if (palavra.equals(proibida)) {
                return true;
            }
        }
        return false;
    }
}
public class ArrayUtils {
    public static String[] ordenar(String[] nomes) {
        if (nomes == null) return null;
        if (nomes.length == 0) return new String[0];

        String[] ordenado = nomes.clone();
        for (int i = 0; i < ordenado.length - 1; i++) {
            for (int j = 0; j < ordenado.length - i - 1; j++) {
                if (ordenado[j].compareTo(ordenado[j + 1]) > 0) {
                    String temp = ordenado[j];
                    ordenado[j] = ordenado[j + 1];
                    ordenado[j + 1] = temp;
                }
            }
        }
        return ordenado;
    }

    public static void espelhar(int[] valores) {
        if (valores == null || valores.length == 0) return;

        for (int i = 0; i < valores.length / 2; i++) {
            int temp = valores[i];
            valores[i] = valores[valores.length - i - 1];
            valores[valores.length - i - 1] = temp;
        }
    }
}
package projetoum;

import java.util.Collections;
import java.util.List;

public class OrdenacaoUtil {
    public static <T extends Comparable<T>> void ordenarLista(List<T> lista) {
        Collections.sort(lista);
    }
}

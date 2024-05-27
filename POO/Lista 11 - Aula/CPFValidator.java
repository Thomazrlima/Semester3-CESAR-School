public class CPFValidator {
    public static boolean isValid(String cpf) throws ExecaoCPFVazio, ExecaoCPFNaoNumerico, ExecaoDigitoInvalido, ExecaoFormatoInvalido{
        if(cpf.isEmpty() || cpf == null){
            throw new ExecaoCPFVazio();
        }

        if (cpf.length() != 11) throw new ExecaoFormatoInvalido();
        int i = 10;
        int soma = 0;
        int digitoVerificador = 0;
        for (char c: cpf.toCharArray()) {
            if (!Character.isDigit(c)) throw new ExecaoCPFNaoNumerico();
            if (i >= 2) {
                soma += Character.getNumericValue(c) * i;
            }
            if (i == 1) {
                digitoVerificador = Character.getNumericValue(c);
            }
            i--;
        }
        int resto = (soma * 10) % 11;
        if (resto != digitoVerificador) throw new ExecaoDigitoInvalido();
        return true;
    }
}

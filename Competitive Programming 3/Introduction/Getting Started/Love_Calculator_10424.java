
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Love_Calculator_10424 {

    static int digitos(String letra) {
        int con = 0;
        letra = letra.toLowerCase();
        String alfabeto = "abcdefghijklmnopqrstuvwxyz";

        for (int j = 0; j < letra.length(); j++) {
            int aux = alfabeto.indexOf("" + letra.charAt(j));
            if (aux != -1) {
                con = con + (aux + 1);
            }
        }
        return con;
    }

    static int suma(String palabra) {
        int con = 0;
        String suma = "" + digitos(palabra);
        if (suma.length() == 1) {
            con = Integer.parseInt(suma);
        }
        while (suma.length() != 1) {
            int con2 = 0;
            for (int i = 0; i < suma.length(); i++) {
                con2 = con2 + Integer.parseInt(suma.substring(i, i + 1));
            }
            con = con2;
            suma = "" + con;
        }
        return con;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));

        try {
            do {
                String palabra1 = tec.readLine();
                double con = suma(palabra1);
                if (palabra1.isEmpty()) {
                    break;
                }

                String palabra2 = tec.readLine();
                double con2 = suma(palabra2);

                if (con == 0 && con2 == 0) {
                    System.out.println("");
                } else {
                    if (con2 > con) {
                        double a = con;
                        con = con2;
                        con2 = a;
                    }

                    if (con != 0) {
                        String resultado = String.format("%.2f", (100 / con) * con2);
                        resultado = resultado.replace(',', '.');
                        System.out.println(resultado + " %");
                    } else {
                        System.out.println("0.00 %");
                    }
                }
            } while (true);
        } catch (Exception e) {
        }
    }
}

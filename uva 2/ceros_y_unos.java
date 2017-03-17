package uva;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ceros_y_unos {

    static String subcadena(String x, int a, int b) {
        return x.substring(a, b);
    }

    static String respuesta(String x) {
        if (x.contains("1") && x.contains("0")) {
            return "No";
        } else {
            return "Yes";
        }
    }

    public static void main(String[] args) {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int con = 0;

        try {
            do {
                con++;
                String x = tec.readLine();
                String q = tec.readLine();
                int t = Integer.parseInt(q);
                int a;
                int b;
                System.out.println("Case " + con + ":");
                for (int i = 0; i < t; i++) {
                    String w = tec.readLine();
                    String vector[] = w.split(" ");
                    a = Integer.parseInt(vector[0]);
                    b = Integer.parseInt(vector[1]);
                    if (a > b) {
                        int aux = a;
                        a = b;
                        b = aux;
                    }
                    b++;
                    String aux = subcadena(x, a, b);
                    System.out.println(respuesta(aux));
                }
            } while (true);
        } catch (Exception e) {
        }
    }
}

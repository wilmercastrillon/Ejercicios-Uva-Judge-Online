package ejercicios;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class uva_10530 {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int n;
        ArrayList<Integer> ar = new ArrayList<>();
        HashMap<Integer, String> mapa = new HashMap<>();
        String aux2;
        boolean trampa = false;

        while ((n = Integer.parseInt(tec.readLine())) != 0) {
            aux2 = tec.readLine();

            if (aux2.equals("right on")) {
                for (int i = 0; i < ar.size(); i++) {
                    if (mapa.get(ar.get(i)).equals("too high")) {
                        if (!(ar.get(i) > n)) {
                            trampa = true;
                            break;
                        }
                    } else {
                        if (!(ar.get(i) < n)) {
                            trampa = true;
                            break;
                        }
                    }
                }
                if (trampa) {
                    System.out.println("Stan is dishonest");
                } else {
                    System.out.println("Stan may be honest");
                }
                ar.clear();
                mapa.clear();
                trampa = false;
            } else {
                ar.add(n);
                mapa.put(n, aux2);
            }
        }
    }
}

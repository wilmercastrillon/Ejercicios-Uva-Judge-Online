package uva3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class word_tranformation {

    static ArrayList<String> arr = new ArrayList<>();
    static ArrayList<String> sol = new ArrayList<>();
    static ArrayList<Integer> can = new ArrayList<>();

    static boolean cambio_valido(String q, String w) {
        int con = 0;
        for (int i = 0; i < q.length(); i++) {
            if (q.charAt(i) == w.charAt(i)) {
                con++;
            }
        }
        return (con == q.length() - 1);
    }

    static void dfs(String c1, String c2) {
        if (c1.equals(c2)) {
            can.add(sol.size() - 1);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            String aux = arr.get(i);

            if (aux.length() == c2.length()) {
                if (cambio_valido(aux, c1) && !sol.contains(aux)) {
                    sol.add(aux);
                    dfs(aux, c2);
                    sol.remove(aux);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int casos = Integer.parseInt(tec.readLine());
        String h = tec.readLine(), input[];

        try {
            for (int i = 0; i < casos; i++) {
                arr.clear();
                while (!(h = tec.readLine()).equals("*")) {
                    arr.add(h);
                }
                while (!(h = tec.readLine()).equals("")) {
                    input = h.split(" ");
                    sol.clear();
                    can.clear();
                    sol.add(input[0]);
                    dfs(input[0], input[1]);

                    int menor = 900000000;
                    for (int j = 0; j < can.size(); j++) {
                        menor = Math.min(menor, can.get(j));
                    }
                    System.out.println(h + " " + menor);
                }
                System.out.println("");
            }
        } catch (Exception e) {
        }
    }
}

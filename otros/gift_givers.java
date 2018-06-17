package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class gift_givers {

    public static void main(String[] args) throws IOException {

        HashMap<String, Integer> x = new HashMap<>();
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer t, t2;
        int casos;
        casos = Integer.parseInt(tec.readLine());
        String h = tec.readLine();
        t = new StringTokenizer(h);
        t2 = new StringTokenizer(h);

        try {
            while (true) {
                for (int i = 0; i < casos; i++) {
                    x.put(t.nextToken(), 0);
                }

                for (int i = 0; i < casos; i++) {
                    t = new StringTokenizer(tec.readLine());
                    String aux = t.nextToken();
                    int dado = Integer.parseInt(t.nextToken());
                    int casos2 = Integer.parseInt(t.nextToken());

                    if (casos2 != 0) {
                        x.replace(aux, x.get(aux) - (dado - (dado % casos2)));
                        dado = dado / casos2;
                        for (int j = 0; j < casos2; j++) {
                            String aux2 = t.nextToken();
                            x.replace(aux2, x.get(aux2) + dado);
                        }
                    }
                }

                for (int i = 0; i < casos; i++) {
                    String aux3 = t2.nextToken();
                    System.out.println(aux3 + " " + x.get(aux3));
                }
                x.clear();
                
                casos = Integer.parseInt(tec.readLine());
                h = tec.readLine();
                t = new StringTokenizer(h);
                t2 = new StringTokenizer(h);
                System.out.println("");
            }
        } catch (Exception e) {
        }
    }
}

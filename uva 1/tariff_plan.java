package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class tariff_plan {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int casos = Integer.parseInt(tec.readLine()) + 1;

        for (int i = 1; i < casos; i++) {
            int subcasos = Integer.parseInt(tec.readLine());
            int m = 0, g = 0;
            String x[] = tec.readLine().split(" ");

            for (int j = 0; j < subcasos; j++) {
                int aux = Integer.parseInt(x[j]) + 1;
                m = (aux / 30) + m;
                g = (aux / 60) + g;

                if (aux % 30 != 0) {
                    m++;
                }
                if (aux % 60 != 0) {
                    g++;
                }
            }
            m = m * 10;
            g = g * 15;
            if (m > g) {
                System.out.println("Case " + i + ":" + " Juice " + g);
            } else {
                if (m < g) {
                    System.out.println("Case " + i + ":" + " Mile " + m);
                }else{
                    System.out.println("Case " + i + ":" + " Mile Juice " + m);
                }
            }
        }
    }
}

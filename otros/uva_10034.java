package uva3;

import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class uva_10034 {

    static int casos2;
    static Point2D punto[] = new Point2D[100];

    static double caminos() {
        boolean marcado[] = new boolean[100];
        double acum = 0, menor, aux, dis[] = new double[100];
        int v = 0;

        for (int i = 0; i < 100; i++) {
            dis[i] = 900000000;
        }
        dis[0] = 0;

        while (!marcado[v]) {
            marcado[v] = true;
            menor = 900000000;
            acum += dis[v];

            for (int j = 0; j < casos2; j++) {
                if (!marcado[j]) {
                    aux = punto[v].distance(punto[j]);
                    dis[j] = Math.min(dis[j], aux);
                }
            }

            for (int i = 0; i < casos2; i++) {
                if (!marcado[i]) {
                    if (menor > dis[i]) {
                        menor = dis[i];
                        v = i;
                    }
                }
            }
        }

        return acum;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int casos = Integer.parseInt(tec.readLine());
        String v, input[];

        for (int i = 0; i < casos; i++) {
            v = tec.readLine();
            casos2 = Integer.parseInt(tec.readLine());
            for (int j = 0; j < casos2; j++) {
                input = tec.readLine().split(" ");
                punto[j] = new Point2D.Double(Double.parseDouble(input[0]), Double.parseDouble(input[1]));
            }
            String result = String.format("%.2f", caminos());
            System.out.println(result.replace(",", "."));
            if (i != casos - 1) {
                System.out.println("");
            }
        }
    }
}

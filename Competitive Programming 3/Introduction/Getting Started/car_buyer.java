package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class car_buyer {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer x;
        int m, c;
        String input[];
        double pagar, total, meses[];

        try {
            while (true) {
                x = new StringTokenizer(tec.readLine());
                m = Integer.parseInt(x.nextToken());
                pagar = Double.parseDouble(x.nextToken());
                total = Double.parseDouble(x.nextToken());
                c = Integer.parseInt(x.nextToken());
                meses = new double[m + 1];
                meses[0] = 0;

                for (int i = 0; i < c; i++) {
                    input = tec.readLine().split(" ");
                    meses[Integer.parseInt(input[0])] = Double.parseDouble(input[1]);
                }
                for (int i = 0; i < m; i++) {
                    if (meses[i] == 0) {
                        meses[i] = meses[i - 1];
                    }
                }

                int con = 0, in = 0;
                double que = (int) (total / m);
                double debe = total;
                total = total + pagar;
                do {
                    total = Double.parseDouble(String.format("%.5f", total - (total * meses[in])).replace(",", "."));
                    if (debe < total) {
                        break;
                    }
                    debe -= que;
                    in++;
                    con++;
                } while (true);
                
                if (con == 1) {
                    System.out.println(con + " month");
                } else {
                    System.out.println(con + " months");
                }
            }
        } catch (Exception e) {
        }
    }
}

package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class burger_time {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int l, y, z;
        StringBuilder x;

        while ((l = Integer.parseInt(tec.readLine())) != 0) {
            x = new StringBuilder(tec.readLine());
            int p = x.indexOf("Z");

            if (p > -1) {
                System.out.println("0");
            } else {
                int menor = Integer.MAX_VALUE;
                y = -1;
                z = -1;
                for (int i = 0; i < l; i++) {
                    if (x.charAt(i) == 'R') {
                        y = i;
                    }
                    if (x.charAt(i) == 'D') {
                        z = i;
                    }
                    if (y != -1 && z != -1) {
                        menor = Math.min(Math.abs(y - z), menor);
                    }
                }
                System.out.println(menor);
            }
        }
    }
}

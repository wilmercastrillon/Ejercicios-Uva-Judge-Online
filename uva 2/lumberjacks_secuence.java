package uva3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class lumberjacks_secuence {

    static boolean mayor(StringTokenizer x, int a) {
//        System.out.println("se fue por mayor");
        int cap = x.countTokens();
        int b;
        for (int i = 0; i < cap; i++) {
            b = Integer.parseInt(x.nextToken());
            if (a > b) {
                return false;
            }
            a = b;
        }
        return true;
    }

    static boolean menor(StringTokenizer x, int a) {
//        System.out.println("se fue por menorr");
        int cap = x.countTokens();
        int b;
        for (int i = 0; i < cap; i++) {
            b = Integer.parseInt(x.nextToken());
            if (a < b) {
                return false;
            }
            a = b;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer t;
        int x = Integer.parseInt(tec.readLine());
        System.out.println("Lumberjacks:");

        for (int i = 0; i < x; i++) {
            t = new StringTokenizer(tec.readLine());
            boolean ordenado = true;
            int a = Integer.parseInt(t.nextToken());
            int can = t.countTokens();
            
            for (int j = 0; j < can; j++) {
                int b = Integer.parseInt(t.nextToken());
                if (a == b) {
                    continue;
                }
                if (a < b) {
                    ordenado = mayor(t, b);
                } else {
                    ordenado = menor(t, b);
                }
                j = can;
                a = b;
            }

            if (ordenado) {
                System.out.println("Ordered");
            } else {
                System.out.println("Unordered");
            }
        }
    }
}

package uva3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class sub_prime {

    static boolean yes(int din[], int b) {
        for (int i = 0; i < b; i++) {
            if (din[i] < 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer x;
        int b, n;
        String input[];

        while (true) {
            input = tec.readLine().split(" ");
            b = Integer.parseInt(input[0]);
            n = Integer.parseInt(input[1]);
            if (b == 0 && n == 0) {
                break;
            }
            x = new StringTokenizer(tec.readLine());
            int din[] = new int[b];

            for (int i = 0; i < b; i++) {
                din[i] = Integer.parseInt(x.nextToken());
            }
            for (int i = 0; i < n; i++) {
                input = tec.readLine().split(" ");
                int a = Integer.parseInt(input[0]) - 1;
                int b1 = Integer.parseInt(input[1]) - 1;
                int c = Integer.parseInt(input[2]);

                din[a] -= c;
                din[b1] += c;
            }
            if (yes(din, b)) {
                System.out.println("S");
            }else{
                System.out.println("N");
            }
        }
    }
}

package uva;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Stripe_10541 {

    static BigInteger memo[][] = new BigInteger[201][201];

    static BigInteger dp(int n, int k) {
        if (k == 0 || n == k) {
            return BigInteger.ONE;
        }
        if (memo[n][k] != null) {
            return memo[n][k];
        }
        return memo[n][k] = dp(n - 1, k - 1).add(dp(n - 1, k));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(tec.readLine()), n, k, s, tc;
        StringTokenizer x;

        for (int i = 0; i < t; i++) {
            x = new StringTokenizer(tec.readLine());
            n = Integer.parseInt(x.nextToken());
            k = Integer.parseInt(x.nextToken());
            if (k == 0) {
                System.out.println("1");
                continue;
            }
            s = 0;
            while (x.hasMoreTokens()) {
                s += Integer.parseInt(x.nextToken());
            }

            tc = n - (s - k);
//            System.out.println("### n: " + n + " k: " + k + " s: " + s + " tc: " + tc);
            if (tc - (k - 1) < k) {
                System.out.println("0");
            } else {
                System.out.println(dp(tc - (k - 1), k));
            }
        }
    }
}

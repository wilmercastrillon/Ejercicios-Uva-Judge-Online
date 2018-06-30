package uva;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Maximum_Sub_sequence_Product_787 {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String in;
        BigInteger arr[] = new BigInteger[101];
        boolean cero[] = new boolean[101];
        BigInteger m = BigInteger.valueOf(-999999).pow(101);

        try {
            while (!(in = tec.readLine()).isEmpty()) {
                StringTokenizer x = null;
                int index = 1, n;
                arr[0] = BigInteger.ONE;

                x = new StringTokenizer(in);
                while (true) {
                    if (!x.hasMoreTokens()) {
                        in = tec.readLine();
                        x = new StringTokenizer(in);
                    }
                    n = Integer.parseInt(x.nextToken());
                    if (n == -999999) {
                        break;
                    }
                    if (n == 0) {
                        cero[index] = true;
                        arr[index] = BigInteger.ONE;
                    } else {
                        cero[index] = false;
                        arr[index] = BigInteger.valueOf(n).multiply(arr[index - 1]);
                    }
                    index++;
                }

                BigInteger prod;
                BigInteger max = m.add(BigInteger.ZERO);
                for (int i = 0; i < index; i++) {
//                    System.out.println("arr " + i + " = " + arr[i]);
                    if (cero[i]) {
                        if (max.compareTo(BigInteger.ZERO) < 0) {
                            max = BigInteger.ZERO;
                        }
                        continue;
                    }
                    for (int j = i + 1; j < index; j++) {
                        if (cero[j]) {
                            break;
                        }
                        prod = arr[j].divide(arr[i]);
                        if (max.compareTo(prod) < 0) {
                            max = prod.add(BigInteger.ZERO);
                        }
                    }
                }

                if (max.compareTo(m) == 0) {
                    System.out.println(0);
                } else {
                    System.out.println(max);
                }
            }
        } catch (Exception e) {
        }
    }
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Very_Easy_10523 {

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int n;
        String s, in[];
        BigInteger res, a, aux;

        try {
            while (tec.ready()) {
                s = tec.readLine();
                in = s.split(" ");
                n = Integer.parseInt(in[0]);
                a = new BigInteger(in[1]);
                res = BigInteger.ZERO;

                for (int i = 1; i <= n; i++) {
                    aux = a.pow(i);
                    res = res.add(aux.multiply(BigInteger.valueOf(i)));
                }

                System.out.println(res);
            }
        } catch (Exception e) {
        }
    }
}

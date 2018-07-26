
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Find_the_ways_10219 {

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String in, input[];
        int n, k;

        try {
            while (!(in = tec.readLine()).isEmpty()) {
                input = in.split(" ");
                n = Integer.parseInt(input[0]);
                k = Integer.parseInt(input[1]);
                if (k > (n >> 1) + 1) {
                    k = n - k;
                }

                double logNum = 0, logDen = 0;
                for (int i = 0; i < k; i++) {
                    logNum += Math.log10(n - i);
                    logDen += Math.log10(i + 1);
                }

                int res = (int) (logNum - logDen);
                System.out.println(res + 1);
            }
        } catch (Exception e) {
        }
    }
}

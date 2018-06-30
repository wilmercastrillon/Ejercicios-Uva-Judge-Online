package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class event_plannig {

    static boolean camas(StringTokenizer y, int lim, int par) {
        for (int i = 0; i < lim; i++) {
            if (Integer.parseInt(y.nextToken()) >= par) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer x;
        int n, b, h, w, p;

        try {
            while (true) {
                x = new StringTokenizer(tec.readLine());
                n = Integer.parseInt(x.nextToken());
                b = Integer.parseInt(x.nextToken());
                h = Integer.parseInt(x.nextToken());
                w = Integer.parseInt(x.nextToken());
                int cos = b;

                for (int i = 0; i < h; i++) {
                    p = Integer.parseInt(tec.readLine());
                    x = new StringTokenizer(tec.readLine());

                    if ((p * n) < cos) {
                        if (camas(x, w, n)) {
                            cos = n * p;
                        }
                    }
                }

                if (cos == b) {
                    System.out.println("stay home");
                } else {
                    System.out.println(cos);
                }
            }
        } catch (Exception e) {
        }
    }
}

package uva3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class uva_11683 {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        StringTokenizer x;
        int a, b, n[] = new int[10005];

        while (true) {
            input = tec.readLine().split(" ");
            a = Integer.parseInt(input[0]);
            if (a == 0) {
                break;
            }
            b = Integer.parseInt(input[1]);
            x = new StringTokenizer(tec.readLine() + " " + a);
            int con = 0;
            n[0] = a;
            
            for (int i = 1; i < b + 2; i++) {
                n[i] = Integer.parseInt(x.nextToken());
                
                if (n[i - 1] < n[i]) {
                    con += n[i] - n[i - 1];
                }
            }
            
            System.out.println(con);
        }
    }
}

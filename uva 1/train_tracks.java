package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class train_tracks {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int casos = Integer.parseInt(tec.readLine());

        for (int i = 0; i < casos; i++) {
            String h[] = tec.readLine().split(" ");
            int M = 0, F = 0;

            if (h.length == 1) {
                M = 1;
            } else {
                for (String h1 : h) {
                    if (h1.equals("MM")) {
                        M++;
                    } else {
                        if (h1.equals("FF")) {
                            F++;
                        }
                    }
                }
            }
            if (M == F) {
                System.out.println("LOOP");
            } else {
                System.out.println("NO LOOP");
            }
        }
    }
}

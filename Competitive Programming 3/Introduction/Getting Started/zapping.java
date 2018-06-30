package uva2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class zapping {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        int res, aux, aux2;

        while (true) {
            input = tec.readLine().split(" ");

            aux = Integer.parseInt(input[1]);
            aux2 = Integer.parseInt(input[0]);
            res = Math.abs(aux - aux2);
            if (aux < 0) {
                break;
            }
            if (res > 49) {
                if (aux > aux2) {
                    res = (100 - aux) + aux2;
                }else{
                    res = (100 - aux2) + aux;
                }
            }
            System.out.println(res);
        }
    }
}

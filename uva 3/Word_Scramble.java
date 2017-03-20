package pkg11332.summing.digits;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{

    public static void main(String[] args) throws Exception {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        
        try {
            do {
                String palabra = tec.readLine();
                String[] l = palabra.split(" ");
                String res = "";

                for (int i = 0; i < l.length; i++) {
                    char[] x = l[i].toCharArray();

                    for (int j = x.length - 1; j > -1; j--) {
                        res = res + x[j];
                    }
                    res = res + " ";
                }
                System.out.println(res.substring(0, res.length()-1));
            } while (true);
        } catch (Exception e) {
        }
    }
}

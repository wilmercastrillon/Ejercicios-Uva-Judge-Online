
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Basic_Remains_10551 {

    public static void main(String[] args) throws IOException {
        //BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        Scanner tec = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String n = null, mod = null;
        String s, in[];
        int base;
        BigInteger aux, aux2;

        try {
            while (true) {
                base = tec.nextInt();
                if (base == 0) {
                    break;
                }
                n = tec.next();
                mod = tec.next();
                
                aux = new BigInteger(n, base);
                aux = aux.mod(new BigInteger(mod, base));
                
                System.out.println(aux.toString(base));
            }
        } catch (Exception e) {
        }
    }
}

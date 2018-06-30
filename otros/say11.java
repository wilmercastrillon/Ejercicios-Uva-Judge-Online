package uva;

import java.math.BigInteger;
import java.util.Scanner;

public class say11 {

    public static void main(String[] args) {

        Scanner tec = new Scanner(System.in);

        do {
            String num = tec.next();
            num.replace(" ", "");
            BigInteger x = new BigInteger(num);
            BigInteger once = new BigInteger("11");
            if (num.equals("0")) {
                break;
            }

            String modulo = "" + x.mod(once);
            if (modulo.equals("0")) {
                System.out.println(num + " is a multiple of 11.");
            } else {
                System.out.println(num + " is not a multiple of 11.");
            }
        } while (true);
    }
}

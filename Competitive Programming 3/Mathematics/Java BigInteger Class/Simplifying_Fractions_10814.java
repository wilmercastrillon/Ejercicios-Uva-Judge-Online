
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Simplifying_Fractions_10814 {

    public static void main(String[] args) {
        //BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        Scanner tec = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String s1, s2;
        int t;
        BigInteger aux, num, den;

        try {
            t = tec.nextInt();
            
            for (int i = 0; i < t; i++) {
                s1 = tec.next();
                s2 = tec.next();
                s2 = tec.next();
                
                num = new BigInteger(s1);
                den = new BigInteger(s2);
                aux = num.gcd(den);
                num = num.divide(aux);
                den = den.divide(aux);
                
                System.out.println(num + " / " + den);
            }
        } catch (Exception e) {
        }
    }
}

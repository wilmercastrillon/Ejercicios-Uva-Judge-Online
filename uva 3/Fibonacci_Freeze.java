package pkg11332.summing.digits;

import java.math.BigInteger;
import java.util.Scanner;

public class Fibonacci_Freeze {

    public static void main(String[] args) {
        
        Scanner tec = new Scanner(System.in);
        
        try {
            do {
                int x = tec.nextInt();
                BigInteger x1 = new BigInteger("0");
                BigInteger x2 = new BigInteger("1");

                for (int j = 0; j < x; j++) {
                    x2 = x2.add(x1);
                    x1 = x2.subtract(x1);
                }
                System.out.println("The Fibonacci number for " + x + " is " + x1);
            } while (true);
        } catch (Exception e) {
        }
    }
}

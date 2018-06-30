package pkg11332.summing.digits;

import java.math.BigInteger;
import java.util.Scanner;

public class Factorial_Frequencies {

    static BigInteger factorial(int x) {
        BigInteger fac = new BigInteger("1");
        BigInteger fac2 = new BigInteger("1");
        for (int i = 0; i < x; i++) {
            fac = fac.multiply(fac2);
            fac2 = fac2.add(BigInteger.ONE);
        }
        return fac;
    }

    static int[] can(int[] digitos, String h) {
        for (int i = 0; i < h.length(); i++) {
            int a = Integer.parseInt(h.substring(i, i + 1));
            digitos[a]++;
        }
        return digitos;
    }

    static void imprimir(int[] digitos, int x) {
        System.out.println(x + "! --");
        for (int i = 0; i < 5; i++) {
            System.out.print("(" + i + ")    " + digitos[i] + "    ");
        }
        System.out.println("(" + 4 + ")    " + digitos[4]);
        for (int i = 5; i < 10; i++) {
            System.out.print("(" + i + ")    " + digitos[i] + "    ");
        }
        System.out.println("(" + 9 + ")    " + digitos[9]);
    }

    public static void main(String[] args) {

        Scanner tec = new Scanner(System.in);
        int x;

        while ((x = tec.nextInt()) != 0) {
            String h = "" + factorial(x);
            int[] digitos = new int[10];
            digitos = can(digitos, h);
            imprimir(digitos, x);
        }
    }
}

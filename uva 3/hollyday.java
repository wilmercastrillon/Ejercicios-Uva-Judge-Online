package ejercicios_uva;

import java.util.Scanner;

public class hollyday {

    public static void main(String[] args) {
        
        Scanner tec = new Scanner(System.in);
        int a, l, p, t;
        t = tec.nextInt();

        for (int i = 0; i < t; i++) {
            a = tec.nextInt();
            l = tec.nextInt();
            p = tec.nextInt();
            if (a < 21 && l < 21 && p < 21) {
                System.out.println("Case " + (i + 1) + ": good");
            } else {
                System.out.println("Case " + (i + 1) + ": bad");
            }
        }
    }
}

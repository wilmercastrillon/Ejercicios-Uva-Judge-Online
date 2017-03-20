package ejercicios_2;

import java.util.Scanner;

public class raiz_digital_prima {

    static boolean primo(int a) {
        boolean primo = true;
        if (a != 2 && a != 3) {
            if (a % 2 != 0 || a == 1) {
                for (int i = 3; i <= Math.sqrt(a); i = i + 2) {
                    if (a % i == 0) {
                        primo = false;
                        break;
                    }
                }
            } else {
                primo = false;
            }
        }
        return primo;
    }

    public static void main(String[] args) {

        Scanner tec = new Scanner(System.in);
        do {
            int b = tec.nextInt();
            if (b == 0) {
                break;
            }
            
            if (primo(b) == true) {
                System.out.println(b);
            }else{
                do {
                    String x = "" + b;
                    if (x.length()==1) {
                        System.out.println("no tiene");
                        break;
                    }
                    int c = 0;
                    for (int i = 0; i < x.length(); i++) {
                        c = c + Integer.parseInt(x.substring(i, i + 1));
                    }
                    if (primo(c)== true) {
                        System.out.println(c);
                        break;
                    }else{
                        b = c;
                    }
                } while (true);
            }
        } while (true);
    }
}

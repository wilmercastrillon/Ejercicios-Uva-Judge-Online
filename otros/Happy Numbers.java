//package ejer5cicio;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner tec = new Scanner(System.in);
        int t = tec.nextInt();
        
        for (int i = 1; i <= t; i++) {
            String h = tec.next();
            String r = h;
            do {
                int x = 0;
                for (int j = 0; j < h.length(); j++) {
                    x = (int) (x + Math.pow(Integer.parseInt(h.substring(j, j+1)), 2));
                }
                h = "" + x;
                
            } while (h.length() != 1);
            if (h.equals("1")) {
                System.out.println("Case #" + i + ": " + r + " is a Happy number.");
            }else{
                System.out.println("Case #" + i + ": " + r + " is an Unhappy number.");
            }
        }
    }
}

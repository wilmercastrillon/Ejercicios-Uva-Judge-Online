package uva;

import java.util.Scanner;

public class Secret_Research {

    public static void main(String[] args) {
        
        Scanner tec = new Scanner(System.in);
        int t = tec.nextInt();
        
        for (int i = 0; i < t; i++) {
            String s = tec.next();
            if (s.equals("1") || s.equals("4") || s.equals("78")) {
                System.out.println("+");
            }else{
                if (s.substring(s.length()-2, s.length()).equals("35")) {
                    System.out.println("-");
                }else{
                    if (s.substring(0, 1).equals("9") && s.substring(s.length()-1,s.length()).equals("4")) {
                        System.out.println("*");
                    }else{
                        System.out.println("?");
                    }
                }
            }
        }
    }
}

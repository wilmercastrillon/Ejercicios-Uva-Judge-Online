package uvajudge;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Scanner;

public class High_Precision_Number_11821 {

    public static void main(String[] args) {
        //BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        Scanner tec = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String s1, s2;
        int t;
        BigDecimal aux, res;

        try {
            t = tec.nextInt();
            
            for (int i = 0; i < t; i++) {
                res = BigDecimal.ZERO;
                do{                    
                    s1 = tec.next();
                    res = res.add(new BigDecimal(s1));
                }while(!s1.equals("0"));
                
                System.out.println(res.stripTrailingZeros().toPlainString());
            }
        } catch (Exception e) {
        }
    }
}

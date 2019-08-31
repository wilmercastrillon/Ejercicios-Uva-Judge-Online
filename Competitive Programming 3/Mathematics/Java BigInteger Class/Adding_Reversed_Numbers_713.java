//package uvajudge;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Adding_Reversed_Numbers_713 {

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(tec.readLine());
        String in[];
        StringBuilder sb1, sb2, sb3;
        
        for (int i = 0; i < t; i++) {
            in = tec.readLine().split(" ");
            sb1 = new StringBuilder(in[0]);
            sb2 = new StringBuilder(in[1]);
            
            BigInteger res = new BigInteger(sb1.reverse().toString());
            res = res.add(new BigInteger(sb2.reverse().toString()));
            sb3 = new StringBuilder(res.toString());
            sb3 = sb3.reverse();
            while (sb3.charAt(0) == '0' && sb3.length() > 1) {                
                sb3.deleteCharAt(0);
            }
            
            System.out.println(sb3);
        }
    }
    
}

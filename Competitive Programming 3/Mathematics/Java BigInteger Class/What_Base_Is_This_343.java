
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class What_Base_Is_This_343 {
    
    public static int minBase(String s){
        int min = 2;
        for (int i = 0; i < s.length(); i++) {
            if(Character.isDigit(s.charAt(i)))
                min = Integer.max(min, (s.charAt(i)-'0')+1);
            else
                min = Integer.max(min, ((s.charAt(i)-'A')+10)+1);
        }
        return min;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String x = null, y = null;
        String s, in[];
        boolean res;
        BigInteger aux, aux2;

        try {
            while (true) {
                s = tec.readLine();
                in = s.trim().split(" ");
                x = in[0];
                for (int i = 1; i < in.length; i++) {
                    if (in[i].length() > 0) {
                        y = in[i];
                        break;
                    }
                }
                
                int i, j=0, ii = minBase(x), jj = minBase(y), ri = 0, rj = 0;
                res = false;

                for (i = ii; i <= 36; i++) {
                    for (j = jj; j <= 36; j++) {
                        aux = new BigInteger(x, i);
                        aux2 = new BigInteger(y, j);
//                        System.out.println(x + " base " + i + " = " + aux);
//                        System.out.println(y + " base " + j + " = " + aux2);
//                        System.out.println("iguales? " + (aux.compareTo(aux2)==0));
                        if (aux.compareTo(aux2) == 0) {
                            res = true;
                            ri = i;
                            rj = j;
                            j = i = 37;
                        }
                    }
                }

                if (res) {
                    System.out.println(x + " (base " + ri + ") = " + y + " (base " + rj + ")");
                }else{
                    System.out.println(x + " is not equal to " + y + " in any base 2..36");
                }
            }
        } catch (Exception e) {
            //System.out.println("Error con " + x + " , " + y);
        }
    }
}

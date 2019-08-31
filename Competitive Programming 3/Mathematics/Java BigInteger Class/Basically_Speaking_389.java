
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Basically_Speaking_389 {

    public static void main(String[] args) throws IOException {
        Scanner tec = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String n, x, y, out;
        long l1;

        try {
            while (tec.hasNext()) {
                n = tec.next();
                x = tec.next();
                y = tec.next();
               
                try {
                    l1 = Long.parseLong(n, Integer.parseInt(x));
                    out = Long.toString(l1, Integer.parseInt(y));
                    if (out.length() > 7) {
                        System.out.println("  ERROR");
                    }else{
                        System.out.printf("%7s\n",out.toUpperCase());
                    }
                } catch (Exception e) {
                    System.out.println("  ERROR");
                }
            }
        } catch (Exception e) {
            //System.out.println("Error con " + x + " , " + y);
        }
    }
}

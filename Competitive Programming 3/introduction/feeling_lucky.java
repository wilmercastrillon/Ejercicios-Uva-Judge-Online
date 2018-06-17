package uva;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class feeling_lucky {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        StringBuilder x;
        int casos = Integer.parseInt(tec.readLine()) + 1;
        
        for (int i = 1; i < casos; i++) {
            int rel = 0;
            x = new StringBuilder();
            
            for (int j = 0; j < 10; j++) {
                input = tec.readLine().split(" ");
                int pos = Integer.parseInt(input[1]);
                
                if (pos > rel) {
                    rel = pos;
                    x.delete(0, x.length());
                    x.append(input[0]).append("\n");
                } else {
                    if (pos == rel) {
                        x.append(input[0]).append("\n");
                    }
                }
            }
            
            System.out.println("Case #" + i + ":");
            System.out.println(x.deleteCharAt(x.length() - 1));
        }
    }    
}

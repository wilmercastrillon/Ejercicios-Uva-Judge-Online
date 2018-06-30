package pkg11332.summing.digits;

import java.io.*;

public class SummingDigits {

    static String sumadigitos(String digitos){
        String res;
        int con = 0;
        if (digitos.length()!= 1) {
            while (digitos.length() != 1) {
                con = 0;
                for (int i = 0; i < digitos.length(); i++) {
                    con = con + Integer.parseInt(digitos.substring(i, i + 1));
                }
                digitos = "" + con;
            }
        }else{
            con = Integer.parseInt(digitos);
        }
        res = "" + con;
        return res;
    }
    
    
    public static void main(String[] args) throws Exception {
        
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        
        do {
            String h = tec.readLine();
            if (h.equals("0")) {
                break;
            }
            String respuesta = sumadigitos(h);
            System.out.println(respuesta);
        } while (true);
    }
}

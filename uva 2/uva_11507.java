package uva3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class uva_11507 {

    public static void main(String[] args) throws IOException {
        
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        String h, aux;
        int n;
        StringTokenizer x;
        
        HashMap<String, HashMap<String, String>> mapa = new HashMap<>();
        mapa.put("+x", new HashMap<>());
        mapa.get("+x").put("+y", "+y");
        mapa.get("+x").put("-y", "-y");
        mapa.get("+x").put("+z", "+z");
        mapa.get("+x").put("-z", "-z");
        mapa.put("-x", new HashMap<>());
        mapa.get("-x").put("+y", "-y");
        mapa.get("-x").put("-y", "+y");
        mapa.get("-x").put("+z", "-z");
        mapa.get("-x").put("-z", "+z");
        
        mapa.put("+y", new HashMap<>());
        mapa.get("+y").put("+y", "-x");
        mapa.get("+y").put("-y", "+x");
        mapa.get("+y").put("+z", "+y");
        mapa.get("+y").put("-z", "+y");
        mapa.put("-y", new HashMap<>());
        mapa.get("-y").put("+y", "+x");
        mapa.get("-y").put("-y", "-x");
        mapa.get("-y").put("+z", "-y");
        mapa.get("-y").put("-z", "-y");
        
        mapa.put("+z", new HashMap<>());
        mapa.get("+z").put("+y", "+z");
        mapa.get("+z").put("-y", "+z");
        mapa.get("+z").put("+z", "-x");
        mapa.get("+z").put("-z", "+x");
        mapa.put("-z", new HashMap<>());
        mapa.get("-z").put("+y", "-z");
        mapa.get("-z").put("-y", "-z");
        mapa.get("-z").put("+z", "+x");
        mapa.get("-z").put("-z", "-x");
        
        while ((n = Integer.parseInt(tec.readLine())) != 0) {            
            h = "+x";
            x = new StringTokenizer(tec.readLine());
            while (x.hasMoreTokens()) {   
                aux = x.nextToken();
                if (aux.equals("No")) {
                    continue;
                }
                h = mapa.get(h).get(aux);
            }
            System.out.println(h);
        }
    }
}

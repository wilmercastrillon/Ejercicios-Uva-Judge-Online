package uvajudge;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Vector;

public class Morning_Walk_10596 {

    static int degree[] = new int[210];
    static boolean vis[] = new boolean[210];
    static Vector<Vector<Integer>> lista;
    
    static void dfs(int v){
        vis[v] = true;
        int u;
        
        for (int i = 0; i < lista.get(v).size(); i++) {
            u = lista.get(v).get(i);
            if(!vis[u]){
                dfs(u);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int n, r, x, y;
        String in[], in2[];

        try {
            while (true) {
                in = tec.readLine().split(" ");
                n = Integer.parseInt(in[0]);
                r = Integer.parseInt(in[1]);
                Arrays.fill(degree, 0);
                Arrays.fill(vis, false);
                lista = new Vector<>();
                for (int i = 0; i < n; i++) {
                    lista.add(new Vector<>());
                }
                x = n;
                lista.add(new Vector<>());

                for (int i = 0; i < r; i++) {
                    in2 = tec.readLine().split(" ");
                    x = Integer.parseInt(in2[0]);
                    y = Integer.parseInt(in2[1]);
                    lista.get(x).add(y);
                    lista.get(y).add(x);
                    degree[x]++;
                    degree[y]++;
                }
                dfs(x);

                boolean pos = true;
                int acum = 0;
                for (int i = 0; i < n && pos; i++) {
                    pos = pos && (degree[i] % 2 == 0);
                    if(vis[i]){
                        acum += lista.get(i).size();
                    }
                }

                if (pos && acum==r*2 && acum>0) {
                    System.out.print("Possible\n");
                } else {
                    System.out.print("Not Possible\n");
                }
            }
        } catch (Exception e) {
        }
    }
}

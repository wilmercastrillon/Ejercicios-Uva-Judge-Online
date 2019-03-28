package uvajudge;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Gathering_Food_11487 {

    static int mod = 20437;
    static int dis[][][] = new int[12][12][100], n, lim;
    static int memo[][][][] = new int[11][11][28][2000];
    static char tab[][] = new char[12][12], ult;
    static int mf[] = {0, 1, 0, -1}, mc[] = {1, 0, -1, 0};

    static class pair {

        int first, second;

        pair(int a, int b) {
            first = a;
            second = b;
        }
    }

    static boolean val(int f, int c) {
        return !(f < 0 || f >= n || c < 0 || c >= n || tab[f][c] == '#');
    }

    static boolean upper(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    static int dp(int fil, int col, int c, int len) {
        if (len > lim || tab[fil][col] > c + 'A') {
            return 0;
        }
        if (c + 'A' == ult) {
            return 1;
        }
        if (memo[fil][col][c][len] != -1) {
            return memo[fil][col][c][len];
        }

        int auxf, auxc, ans = 0;
        for (int i = 0; i < 4; i++) {
            auxf = fil + mf[i];
            auxc = col + mc[i];
            if (!val(auxf, auxc)) {
                continue;
            }
            if (tab[auxf][auxc] == (c + 1) + 'A') {
                ans = (ans + dp(auxf, auxc, (char) ((int) c + 1), len + 1)) % mod;
            } else {
                ans = (ans + dp(auxf, auxc, c, len + 1)) % mod;
            }
        }
        return memo[fil][col][c][len] = ans;
    }

    static int bfs(int inif, int inic) {
        Queue<pair> cola1 = new LinkedList<>();
        Queue<Character> cola2 = new LinkedList<>();
        cola1.add(new pair(inif, inic));
        cola2.add('A');
        dis[inif][inic]['A'] = 0;
        pair par1;
        int fil, col;
        char c;

        while (!cola1.isEmpty()) {
            par1 = cola1.poll();
            c = cola2.poll();
            fil = par1.first;
            col = par1.second;

            if (c == ult) {
                return dis[fil][col][c];
            }

            int auxf, auxc, aux;
            for (int i = 0; i < 4; i++) {
                auxf = fil + mf[i];
                auxc = col + mc[i];
                aux = dis[fil][col][c] + 1;
                if (!val(auxf, auxc)) {
                    continue;
                }
                if (upper(tab[auxf][auxc])) {
                    if (tab[auxf][auxc] > c + 1) {
                        continue;
                    }
                    if (tab[auxf][auxc] == c + 1 && dis[auxf][auxc][c + 1] > aux) {
                        dis[auxf][auxc][c + 1] = aux;
                        cola1.add(new pair(auxf, auxc));
                        cola2.add((char) ((int) c + 1));
                    } else if (dis[auxf][auxc][c] > aux) {
                        dis[auxf][auxc][c] = aux;
                        cola1.add(new pair(auxf, auxc));
                        cola2.add(c);
                    }
                } else {
                    if (dis[auxf][auxc][c] <= aux) {
                        continue;
                    }
                    dis[auxf][auxc][c] = aux;
                    cola1.add(new pair(auxf, auxc));
                    cola2.add(c);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int caso = 1, inif = 0, inic = 0;

        while ((n = Integer.parseInt(tec.readLine())) != 0) {
            ult = '@';

            for (int i = 0; i < n; i++) {
                tab[i] = tec.readLine().toCharArray();
                for (int j = 0; j < n; j++) {
                    if (tab[i][j] > ult) {
                        ult = tab[i][j];
                    }
                    if (tab[i][j] == 'A') {
                        inif = i;
                        inic = j;
                    }
                }
            }

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    Arrays.fill(dis[i][j], 1000000000);
                }
            }
            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11; j++) {
                    for (int k = 0; k < 28; k++) {
                        Arrays.fill(memo[i][j][k], -1);
                    }
                }
            }

            int q = bfs(inif, inic);
            if (q == -1) {
                System.out.printf("Case %d: Impossible\n", caso++);
                continue;
            }
            lim = q;//n*n + 1;
            int w = dp(inif, inic, 0, 0);
            System.out.printf("Case %d: %d %d\n", caso++, q, w);
        }
    }
}


import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

public class UvaJudge {

    static int start, target, MAX = 2000, MAX2, fil, col, mf, f;
    static int matriz[][] = new int[2000][2000], peso;
    static int _mf[] = {-1, 0, 1, 0};
    static int _mc[] = {0, 1, 0, -1};
    static char tab[][] = new char[1000][1000];
    static Vector<Integer> p = new Vector<>();
    static Vector<Vector<Integer>> grafo = new Vector<>();
    static Vector<Boolean> vis = new Vector<>();
    static Map<Character, Integer> mapa = new HashMap<>();

    static void augment(int v, int minEdge) {
        if (v == start) {
            f = minEdge;
        } else if (p.get(v) != -1) {
            augment(p.get(v), Math.min(minEdge, matriz[p.get(v)][v]));
            matriz[p.get(v)][v] -= f;
            matriz[v][p.get(v)] += f;
        }
    }

    static int EdmondsKarp() {
        mf = 0;
        while (true) {
            f = 0;
            Collections.fill(vis, false);
            vis.set(start, Boolean.TRUE);
            Queue<Integer> cola = new LinkedList<>();
            cola.add(start);
            Collections.fill(p, -1);
            while (cola.size() > 0) {
                int u = cola.poll();
                if (u == target) {
                    break;
                }

                for (int j = 0; j < grafo.get(u).size(); j++) {
                    int v = grafo.get(u).get(j);
                    if (matriz[u][v] > 0 && !vis.get(v)) {
                        vis.set(v, Boolean.TRUE);
                        cola.add(v);
                        p.set(v, u);
                    }
                }
            }
            augment(target, Integer.MAX_VALUE);
            if (f == 0) {
                break;
            }
            mf += f;
        }
        return mf;
    }

    static boolean val(int f, int c) {
        return !(f < 0 || f >= fil || c < 0 || c >= col || tab[f][c] == '~' || tab[f][c] == '*');
    }

    static void pre() {
        mapa.put('*', 1);
        mapa.put('.', 1);
        mapa.put('@', 1000);
        mapa.put('#', 1000);
    }

    static void buildGrafo() {
        int auxf, auxc;
        start = MAX - 3;
        target = MAX - 2;

        int nodo1, nodo2;
        for (int i = 0; i < fil; i++) {
            for (int j = 0; j < col; j++) {
                //printf("fil %d , col %d | caracter: %c , pos %d\n", i, j, tab[i][j], (i*col)+j);
                if (tab[i][j] == '~') {
                    continue;
                }
                
                for (int k = 0; k < 4; k++) {
                    auxf = i + _mf[k];
                    auxc = j + _mc[k];
                    //printf("probamos ir a %d , %d\n", auxf, auxc);
                    if (val(auxf, auxc)) {
                        nodo1 = (i * col) + j;
                        nodo2 = (auxf * col) + auxc;
                        //printf("conexion de %c a %c (%d -> %d) con peso %d\n", tab[i][j], tab[auxf][auxc],
                        //       nodo1,nodo2+MAX2, mapa[tab[i][j]]);
                        grafo.get(nodo1).add(nodo2+MAX2);
                        grafo.get(nodo1).add(nodo2 + MAX2);
                        grafo.get(nodo2 + MAX2).add(nodo1);
                        matriz[nodo1][nodo2 + MAX2] = mapa.get(tab[i][j]);

                        //printf("conexion de %c a %c (%d -> %d) con peso %d\n", tab[i][j], tab[auxf][auxc],
                        //       nodo2+MAX2, nodo2, mapa[tab[auxf][auxc]]);
                        grafo.get(nodo2 + MAX2).add(nodo2);
                        grafo.get(nodo2).add(nodo2 + MAX2);
                        matriz[nodo2 + MAX2][nodo2] = mapa.get(tab[auxf][auxc]);
                        //printf("Ya\n");
                    }
                }
                if (tab[i][j] == '#') {
                    //printf("## conexion de %d a %d con peso %d\n", (i*col)+j, target, peso);
                    grafo.get((i * col) + j).add(target);
                    grafo.get(target).add((i * col) + j);
                    matriz[(i * col) + j][target] = peso;
                } else if (tab[i][j] == '*') {
                    grafo.get(start).add((i * col) + j);
                    grafo.get((i * col) + j).add(start);
                    matriz[start][(i * col) + j] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        pre();
        //freopen("salida.txt", "w", stdout);
        //freopen("casos.txt", "r", stdin);
        for (int i = 0; i < MAX; i++) {
            p.add(-1);
            vis.add(false);
        }
        Scanner tec = new Scanner(System.in);
        MAX2 = 1000;
     
        while (tec.hasNext()) {
            fil = tec.nextInt();
            col = tec.nextInt();
            peso = tec.nextInt();
            
            grafo.clear();
            for (int i = 0; i < MAX; i++) {
                Arrays.fill(matriz[i], 0);
                grafo.add(new Vector<>());
            }

            for (int i = 0; i < fil; i++) {
                tab[i] = tec.next().toCharArray();
            }
            buildGrafo();
            
            System.out.printf("%d\n", EdmondsKarp());
        }
    }
}

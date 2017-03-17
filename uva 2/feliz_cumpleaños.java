package uva;

import java.util.Scanner;

public class feliz_cumpleaños {

    public static void main(String[] args) {
        Scanner tec = new Scanner(System.in);
        int p = tec.nextInt();

        String cancion[] = new String[4];
        cancion[0] = "Happy";
        cancion[1] = "birthday";
        cancion[2] = "to";
        cancion[3] = "you";

        String personas[] = new String[p];
        for (int i = 0; i < p; i++) {
            personas[i] = tec.next();
        }

        int con = 0;
        int conper = 0;
        int aux = 0;
        int lim;
        if (p > 16) {
            lim = (17 / p) + 1;
        }else{
            lim = 0;
        }
        do {
            if (conper == p) {
                conper = 0;
            }
            if (aux == 4) {
                aux = 0;
            }
            if (con == 11) {
                System.out.println(personas[conper] + ": " + "Rujia");
            } else {
                System.out.println(personas[conper] + ": " + cancion[aux]);
            }
            con++;
            conper++;
            aux++;
            if (con == 16) {
                con = 0;
                lim--;
            }
        } while (lim != -1);

    }
}

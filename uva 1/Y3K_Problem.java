package uva;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Y3K_Problem {

    static boolean biciesto(int a) {
        if (a % 4 == 0 && a % 100 != 0) {
            return true;
        }else{
            return a % 4 == 0 && a % 400 == 0;
        }
    }

    static int dias(int mes, int a) {
        if (mes == 1 || mes == 5 || mes == 3 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            return 31;
        } else {
            if (mes == 2) {
                if (biciesto(a) == true) {
                    return 29;
                } else {
                    return 28;
                }
            } else {
                return 30;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));

        try {
            do {
                String num = tec.readLine();
                String x[] = num.split(" ");
                int can = Integer.parseInt(x[0]);
                int dia = Integer.parseInt(x[1]);
                int mes = Integer.parseInt(x[2]);
                int a = Integer.parseInt(x[3]);

                if (can == 0 && dia == 0 && mes == 0 && a == 0) {
                    break;
                }

                dia = dia + can;
                while (dia > dias(mes, a)) {
                    dia = dia - dias(mes, a);
                    mes++;
                    if (mes == 13) {
                        a++;
                        mes = 1;
                    }
                }
                System.out.println(dia + " " + mes + " " + a);
            } while (true);
        } catch (Exception e) {
        }
    }
}

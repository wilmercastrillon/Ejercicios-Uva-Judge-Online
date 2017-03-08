package uva;

import java.util.Scanner;

public class division_de_nlogonia {

    public static void main(String[] args) {

        Scanner tec = new Scanner(System.in);
        int casos;

        while ((casos = tec.nextInt()) != 0) {
            int divisionx;
            int divisiony;
            int posx;
            int posy;

            divisionx = tec.nextInt();
            divisiony = tec.nextInt();

            for (int i = 0; i < casos; i++) {
                posx = tec.nextInt();
                posy = tec.nextInt();

                if (posx == divisionx || posy == divisiony) {
                    System.out.println("divisa");
                } else {
                    
                    if (posx > divisionx) {
                        if (posy > divisiony) {
                            System.out.println("NE");
                        } else {
                            System.out.println("SE");
                        }
                    } else {
                        if (posy > divisiony) {
                            System.out.println("NO");
                        } else {
                            System.out.println("SO");
                        }
                    }
                }
            }
        }
    }
}

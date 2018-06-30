
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;

class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader tec = new BufferedReader(new InputStreamReader(System.in));
        int caso, con_p, index;
        String cad2;
        StringBuilder cad1;
        ArrayList<Character> aux = new ArrayList<>();
        char x;

        while ((caso = Integer.parseInt(tec.readLine())) != -1) {
            cad1 = new StringBuilder(tec.readLine());
            cad2 = tec.readLine();
            con_p = 0;
            aux.clear();

            for (int i = 0; i < cad2.length(); i++) {
                if (!aux.contains(cad2.charAt(i))) {
                    aux.add(cad2.charAt(i));
                }
            }

            Iterator it = aux.iterator();
            while (it.hasNext()) {
                x = (char) it.next();
                index = 0;
//                System.out.println("tamaño de cad1 " + cad1.length());
                if (cad1.length() == 0) {
                    break;
                }

                index = cad1.indexOf(x + "", index);
                if (index == -1) {
                    con_p++;
                    continue;
                }

                while (true) {
                    index = cad1.indexOf(x + "", index);
                    if (index == -1) {
                        break;
                    }
                    cad1.deleteCharAt(index);
//                    System.out.println("esta el caracter " + x);
                }
            }
//            System.out.println("asi es aonp " + con_p);

            System.out.println("Round " + caso);
            if (con_p > 6) {
                System.out.println("You lose.");
            } else {
                if (cad1.length() == 0) {
                    System.out.println("You win.");
                } else {
                    System.out.println("You chickened out.");
                }
            }
        }
    }
}

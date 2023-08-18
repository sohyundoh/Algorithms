
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Main {
    static int num1;
    static int num2;
    static List<Character> forward = new ArrayList<>();
    static List<Character> backward = new ArrayList<>();
    static List<Character> ants = new ArrayList<>();
    static int maxLength;
    public static String listToStringConverter() {
        String s = "";
        for (int i = 0; i < ants.size(); i++) {
            s.concat(String.valueOf(ants.get(i)));
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        num1 = s.nextInt();
        num2 = s.nextInt();
        maxLength = Math.max(num1, num2);
        String forwardInput = s.nextLine();
        String backwardInput = s.nextLine();
        for (int i = 0; i < num1; i++) {
            forward.add(forwardInput.charAt(i));
        }
        for (int i = 0; i < num2; i++) {
            backward.add(backwardInput.charAt(i));
        }
        ants.addAll(forward);
        ants.addAll(backward);
        int T = s.nextInt();

        jump(T);
        System.out.println(listToStringConverter());
    }

    public static void jump(int sec) {
        if(sec<=0) return;

    }
}

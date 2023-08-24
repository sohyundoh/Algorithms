import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int M = s.nextInt();
        int N = s.nextInt();
        for (int i = M; i <= N; i++) {
            boolean flag = true;
            for (int j = 2; j <= i - 1; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(i);
            }
        }
    }
}

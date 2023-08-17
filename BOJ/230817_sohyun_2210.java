
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    List<String> num = new ArrayList<>();
    static int[][] array = new int[5][5];

    private void jump(int x, int y) {

    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                array[i][j] = s.nextInt();
            }
        }

    }
}

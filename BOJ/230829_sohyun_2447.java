import java.util.Scanner;

public class Main {
    public static void star(int i, int j, int num) {
        if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
            System.out.print(' ');
        } else {
            if (num / 3 == 0) {
                System.out.print('*');
            } else {
                star(i, j, num / 3);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                star(i, j, num);
            }
            System.out.println();
        }
    }
}

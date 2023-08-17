
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<String> num = new ArrayList<>();
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static String[][] str = new String[5][5];

    private static void dfs(int x, int y, int cnt, String tmp) {
        if(cnt == 6){
            if(!num.contains(tmp)){
                num.add(tmp);
            }
            return;
        }
        for(int i=0;i<4;i++) {
            int nowx = x+dx[i];
            int nowy = y+dy[i];
            if((0<=nowx&&nowx<5)&&(0<=nowy&&nowy<5)) {
                dfs(nowx, nowy, cnt+1, tmp+str[nowx][nowy]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<5; j++){
                str[i][j] = st.nextToken();
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dfs(i, j, 1,str[i][j]);
            }
        }
        System.out.println(num.size());
    }
}

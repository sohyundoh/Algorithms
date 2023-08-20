import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

import static java.util.Arrays.stream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        StringTokenizer st = new StringTokenizer(" ");
        int[] input = stream(bf.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        Map<Integer, Integer> integer = new HashMap<>();
        for(int i = 0; i< N;i++){
            int value = input[i];
            if(integer.containsKey(value)){
                integer.replace(value,integer.get(value)+1);
            }else{
                integer.put(value, 1);
            }
        }
        int K = Integer.parseInt(bf.readLine());
        if(integer.get(K) == null) {
            System.out.println("0");
            return;
        }
        System.out.println(integer.get(K));
    }
}

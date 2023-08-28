import static java.util.Arrays.*;
import static java.util.stream.Collectors.*;

import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         int[] input = stream(br.readLine().split(" "))
                  .mapToInt(Integer::parseInt).toArray();

         int n = input[0];
         int query = input[1]; 
        TreeMap<Medal, ArrayList<Integer>> ranking = new TreeMap<>();

        for(int i=0;i<n;i++){
             int[] info = stream(br.readLine().split(" "))
                      .mapToInt(Integer::parseInt).toArray();
            Medal score = new Medal(info[1],info[2],info[3]);

            if(ranking.containsKey(score)){  
                ranking.get(score).add(info[0]);
            }else{
                ArrayList<Integer> nations = new ArrayList<>(); 
                nations.add(info[0]);
                ranking.put(score,nations);
            }
        }

        int ans=0;
        
        for (var entry : ranking.entrySet()) {
            ArrayList<Integer> nations = entry.getValue();

            if(nations.contains(query)){ 
                System.out.println(ans+1);
                break;
            }else ans+=nations.size();
        }
    }
    static class Medal implements Comparable<Medal>{
        int gold,silver,bronze;

        public Medal(int gold, int silver, int bronze) {
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
        }

        @Override
        public int compareTo(Medal o) {

            if(o.gold == this.gold){
                if(o.silver==this.silver)
                    return o.bronze-this.bronze;
                return o.silver-this.silver;
            }
            return o.gold-this.gold;
        }
    }
}

import java.util.Arrays;

class Solution {
       public int solution(int[] citations) {
        int answer = citations.length + 1;
        Arrays.sort(citations);
         // 오름차순 정렬
        int n = citations.length ;
        for (int i = 0; i < citations.length ; i++) {
            if (n <= citations[i]) {
              //h가 될 수 있는 최대의 값은 citations.length
              //전체 길이를 n으로 두고 이 길이를 감소시키면서 원소끼리 비교하고 넘으면 h가 된다.
                break;
            } else {
                n--;
            }
        }
        answer = n;
        return answer;
    }
}

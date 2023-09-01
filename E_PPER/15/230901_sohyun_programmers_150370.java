class Solution {
    HashMap<String, String> term;
    public int[] solution(String today, String[] terms, String[] privacies) {
        boolean[] isExpired = {};
        int[] answer = {};
        return answer;
    }
    private void termConverter(String[] terms){
        term = new HashMap<>();
        for(int i = 0; i< terms.length; i++){
            String[] keyAndValue = terms[i].split(" ");
            term.put(keyAndValue[0], keyAndValue[1]);
        }
    }
}

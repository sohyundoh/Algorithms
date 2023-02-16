#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string T, P;
 
//pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string &N)
{
        int M = N.size();
        vector<int> pi(M, 0);
        int begin = 1, matched = 0;
        while (begin + matched < M)
        {
                 if (N[begin + matched] == N[matched])
                 {
                         matched++;
                         pi[begin + matched - 1] = matched;
                 }
                 else
                 {
                         if (matched == 0)
                                 begin++;
                         else
                         {
                                 begin += matched - pi[matched - 1];
                                 matched = pi[matched - 1];
                         }
                 }
        }
        return pi;
}
 
vector<int> kmpSearch(const string &H, const string &N)
{
        int n = H.size(), m = N.size();
 
        vector<int> result;
        vector<int> pi = getPartialMatch(N);
        int matched = 0;
        for (int i = 0; i < n; i++)
        {
                 while (matched > 0 && H[i] != N[matched])
                         matched = pi[matched - 1];
                 if (H[i] == N[matched])
                 {
                         matched++;
                         if (matched == m)
                         {
                                 result.push_back(i - m + 2);
                                 matched = pi[matched - 1];
                         }
                 }
        }
        return result;
}
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
 
        getline(cin, T);
        getline(cin, P);
 
        vector<int> result = kmpSearch(T, P);
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++)
                 cout << result[i] << "\n";
        return 0;
}

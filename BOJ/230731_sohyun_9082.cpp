#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, i, N;
	string S, mine;

	cin >> T;

	while (T)
	{
		int result = 0;
		cin >> N;
		cin >> S;
		cin >> mine;

		for (i = 0; i < N; i++)
		{
			if (i == 0)
			{
				if (S[0] != '0' && S[1] != '0')
				{
					S[0]--;
					S[1]--;
					result++;
				}
			}
			else if (i == N - 1)
			{
				if (S[N - 1] != '0' && S[N - 2] != '0')
				{
					S[N - 1]--;
					S[N - 2]--;
					result++;
				}
			}
			else
			{
				if (S[i - 1] != '0' && S[i] != '0' && S[i + 1] != '0')
				{
					S[i - 1]--;
					S[i]--;
					S[i + 1]--;
					result++;
				}
			}
		}
		cout << result << '\n';

		T--;
	}

	return 0;
}

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int symbol[110], P, N;
set<int> s;

int solve(int n)
{
	int i, cnt = 0;
	s.clear();
	for (i = 0; i < N; i++)
	{
		int t = n & symbol[i];
		if (s.count(t)) break;
		s.insert(t);
	}
	if (i == N)
	{
		for (int j = 0; j < P; j++)
			if (n & 1<<j)
				cnt++;
		return cnt;
	}
	return P+1;
}

int main(void)
{
	int kase, temp;
	cin >> kase;
	while (kase-- && cin >> P >> N)
	{
		memset(symbol, 0, sizeof(symbol));
		for (int i = 0; i < N; i++)
			for (int j = P-1; j >= 0; j--) {
				cin >> temp;
				symbol[i] |= temp<<j;
			}
		int min = P + 1;
		for (int i = 1; i < 1<<P; i++)
		{
			int n = solve(i);
			min = min<n ? min : n;
		}
		cout << min << endl;
	}
	return 0;
}
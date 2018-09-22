#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define REP(i, n) for (i = 0; i < (n); i++)
#define REP2(i, n) for (int i = 0; i < (n); i++)

const string Type[4] = { "divine", "human", "evil", "lying" };
const string Time[2] = { "day", "night" };
int n, ans[6];

struct Info {
	char talker, X;
	bool is;
	string what;
} state[60];

bool judge(int n, int* list)
{
	char ta = state[n].talker, X = state[n].X;
	bool is = state[n].is;
	string what = state[n].what;
	if (list[ta-'A']==2 || (list[ta-'A']==1 && list[5]==1) )
		is = !is;
	if (X == 'F')
	{
		if (what == Time[0]) return list[5]==0 ? is : !is;
		else if (what == Time[1]) return list[5]==1 ? is : !is;
	}
	if (what == Type[0]) return list[X-'A']==0 ? is : !is;
	if (what == Type[1]) return list[X-'A']==1 ? is : !is;
	if (what == Type[2]) return list[X-'A']==2 ? is : !is;
	if (what == Type[3]) return (list[X-'A']==2||(list[X-'A']==1&&list[5]==1)) ? is : !is;
}

int solve()
{
	int list[6], have_ans = 0;
	REP(list[0], 3) REP(list[1], 3) REP(list[2], 3)
	REP(list[3], 3) REP(list[4], 3) REP(list[5], 2)
	{
		int i;
		for (i = 0; i < n; i++)
			if (!judge(i, list))
				break;
		if (i==n && !have_ans)
		{
			memcpy(ans, list, sizeof(list));
			have_ans = 1;
		}
		else if(i == n)
		{
			for (i = 0; i < 6; i++)
			if (ans[i] != list[i]) ans[i] = -1;
			REP(i, 6) if (ans[i] != -1) break;
			if (i == 6) return -1;
		}
	}
	return have_ans;	
}

void deal(int x, string words)
{
	state[x].talker = words[0];
	if (words[8] != 'n') state[x].is = true;
	else state[x].is = false;

	if (words[4]=='t') {
		state[x].X = 'F';
		REP2(i, 2) if (words.find(Time[i]) != string::npos)
		{
			state[x].what = Time[i];
			break;
		}
	}
	else {
		if (words[3] == 'I') state[x].X = words[0];
		else state[x].X = words[3];
		REP2(i, 4) if (words.find(Type[i]) != string::npos)
		{
			state[x].what = Type[i];
			break;
		}
	}
}

int main()
{
	int kase = 1;
	while (cin >> n && n)
	{
		cin.ignore();
		cout << "Conversation #" << kase++ << endl;
		for (int i = 0; i < n; i++)
		{
			string words;
			getline(cin, words);
			deal(i, words);
		}
		int flag = solve();
		if (!flag) cout << "This is impossible." << endl;
		else if (flag == -1) cout << "No facts are deducible." << endl;
		else
		{
			REP2(i, 5) if (ans[i] != -1)
				cout << (char)(i+'A') << " is " << Type[ans[i]] << ".\n";
			if (ans[5] != -1)
				cout << "It is " << Time[ans[5]] << ".\n";
		}
		cout << endl;
	}
	return 0;
}


#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Poker {
	int num; char ch;
	bool operator < (const Poker& x) const {
		return num < x.num;
	}
} hand[5];
char *Type[] = { 
	"highest-card","one-pair","two-pairs","three-of-a-kind",
	"straight","flush","full-house","four-of-a-kind","straight-flush"
};

int convert(char ch)
{
	if (isdigit(ch)) return ch - '0';
	else if (ch == 'A') return 1;
	else if (ch == 'T') return 10;
	else if (ch == 'J') return 11;
	else if (ch == 'Q') return 12;
	else if (ch == 'K') return 13;
}

int judge()
{
	int color = 1, straight = 1;
	int cnt[5] = {0};
	for (int i = 0; i < 4; i++)
		if (hand[i].ch == hand[i+1].ch)
			color++;
	if (hand[0].num==1 && hand[1].num==10 && hand[2].num==11
		&& hand[3].num==12 && hand[4].num==13)
		straight = 5;
	else for (int i = 0; i < 4; i++)
		if (hand[i+1].num-hand[i].num == 1)
			straight++;
	for (int i = 1; i < 14; i++)
	{
		int n = 0;
		for (int j = 0; j < 5; j++)
			if (hand[j].num == i)
				n++;
		cnt[n]++;
	}
	if (straight==5 && color==5) return 8;
	else if (cnt[4]) return 7;
	else if (cnt[3] && cnt[2]) return 6;
	else if (color == 5) return 5;
	else if (straight == 5) return 4;
	else if (cnt[3]) return 3;
	else if (cnt[2] == 2) return 2;
	else if (cnt[2]) return 1;
	else return 0;
}

void choose(int n, Poker* poker)
{
	int cnt = 0, j = 5;
	for (int i = 0; i < 5; i++)
		if (n & 1<<i) hand[cnt++] = poker[i];
	while (cnt < 5) hand[cnt++] = poker[j++];
	sort(hand, hand+5);
}

int main(void)
{
	string str;
	while (cin >> str)
	{
		Poker poker[10] = {convert(str[0]), str[1]};
		cout << "Hand: " << str;
		for (int i = 1; i < 10; i++)
		{
			if (i == 5) cout << " Deck:";
			cin >> str;
			cout << ' ' << str;
			poker[i].num = convert(str[0]);
			poker[i].ch = str[1];
		}
		int best = 0;
		for (int i = 0; i < 1<<5; i++)
		{
			choose(i, poker);
			best = max(judge(), best);
		}
		cout << " Best hand: " << Type[best] << endl;
	}
	return 0;
}

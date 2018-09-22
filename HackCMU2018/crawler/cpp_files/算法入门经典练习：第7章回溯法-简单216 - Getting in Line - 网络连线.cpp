 #include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

struct Point { int x, y; };
Point p[10], ans[10], temp[10];
int vis[10], n;
double sum, Min;

double dis(Point& p1, Point& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void search(int cur)
{
	if (cur == n)
	{
		if (sum < Min || Min < 0)
		{
			Min = sum;
			memcpy(ans, temp, sizeof(ans));
		}
	}
	else for (int i = 0; i < n; i++) if (!vis[i])
	{
		temp[cur] = p[i];
		if (cur) sum += dis(temp[cur], temp[cur-1]) + 16;
		vis[i] = 1;
		search(cur+1);
		vis[i] = 0;
		if (cur) sum -= dis(temp[cur], temp[cur-1]) + 16;
	}
}

int main()
{
	int kase = 1;
	while (cin >> n && n)
	{
		cout << "**********************************************************\n";
		cout << "Network #" << kase++ << endl;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		sum = 0; Min = -1; search(0);
		for (int i = 0; i < n-1; i++)
			cout << "Cable requirement to connect ("
			<< fixed << setprecision(2)
			<< ans[i].x << ',' << ans[i].y << ") to (" 
			<< ans[i+1].x << ',' << ans[i+1].y << ") is "
			<< dis(ans[i], ans[i+1])+16 << " feet." << endl;
		cout << "Number of feet of cable required is " 
			<< fixed << setprecision(2) << Min << "." << endl;
	}
	return 0;
}


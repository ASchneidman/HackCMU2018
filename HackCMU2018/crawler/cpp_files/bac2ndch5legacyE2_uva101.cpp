#include<cstdio>
#include<stack>
using namespace std;

stack<int> block[25], buf;
int pos[25];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva101.in", "r", stdin);
  #endif
	int n, from, to;
	char cmd[2][5];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		block[i].push(i);
		pos[i] = i;
	}
	while(scanf("%s", cmd[0]) && cmd[0][0]!='q') {
		int top;
		scanf("%d%s%d", &from, cmd[1], &to);
		if(from==to || pos[from]==pos[to]) continue;
		if(cmd[1][1]=='n') {
			while((top = block[pos[to]].top()) != to) {
				block[top].push(top);
				block[pos[to]].pop();
				pos[top] = top;
			}
		}
		if(cmd[0][0]=='m') {
			while((top = block[pos[from]].top()) != from) {
				block[top].push(top);
				block[pos[from]].pop();
				pos[top] = top;
			}
			block[pos[to]].push(from);
			block[pos[from]].pop();
			pos[from] = pos[to];
		} else if(cmd[0][0]=='p') {
			while((top = block[pos[from]].top()) != from) {
				buf.push(top);
				block[pos[from]].pop();
			}
			block[pos[from]].pop();
			block[pos[to]].push(from);
			pos[from] = pos[to];
			while(!buf.empty()) {
				top = buf.top();
				block[pos[to]].push(top);
				buf.pop();
				pos[top] = pos[to];
			}
		}
	}
	for(int i=0; i<n; i++) {
		printf("%d:", i);
		while (!block[i].empty()) {
			buf.push(block[i].top());
			block[i].pop();
		}
		while(!buf.empty()) {
			printf(" %d", buf.top());
			buf.pop();
		}
		printf("\n");
	}
	return 0;
}

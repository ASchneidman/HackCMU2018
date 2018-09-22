<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF (1<<25)

typedef bool (*comp)(pair<ii,int> , pair<ii,int> );

vector<vi> grid;
vector<vi> visited;
int m,n;
int ans;

bool compare (pair<ii,int> a, pair<ii,int> b){
	return a.second > b.second;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void floodfill(){
	priority_queue<pair<ii,int> , vector<pair<ii,int> > , comp> pq(compare);
	for(int j=0;j<m;++j){
		pq.push(pair<ii,int> (ii(0,j),grid[0][j]));
	}
	for(int j=0;j<m;++j){
		pq.push(pair<ii,int> (ii(n-1,j),grid[n-1][j]));
	}
	for(int j=1;j<n-1;++j){
		pq.push(pair<ii,int> (ii(j,0),grid[j][0]));
	}
	for(int j=1;j<n-1;++j){
		pq.push(pair<ii,int> (ii(j,m-1),grid[j][m-1]));
	}
	while(!pq.empty()){
		pair<ii,int> top1 = pq.top();
		while(!pq.empty()){
			pair<ii,int> top2 = pq.top();
			if(top2.second>top1.second){
				break;
			}
			pq.pop();
			if(visited[top2.first.first][top2.first.second]++){
				continue;
			}
			ans+=top1.second-top2.second;
			for(int i=0;i<4;++i){
				int cx=top2.first.first+dx[i];
				int cy=top2.first.second+dy[i];
				if(cx>=0&&cx<n&&cy>=0&&cy<m){
					pq.push(pair<ii,int> (ii(cx,cy),grid[cx][cy]));
				}
			}
		}
	}
}

int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case){
		ans = 0;
		scanf("%d %d",&n,&m);
		grid = vector<vi> (n,vi(m,0));
		visited = vector<vi> (n,vi(m,0));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&grid[i][j]);
			}
		}
		floodfill();
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF (1<<25)

typedef bool (*comp)(pair<ii,int> , pair<ii,int> );

vector<vi> grid;
vector<vi> visited;
int m,n;
int ans;

bool compare (pair<ii,int> a, pair<ii,int> b){
	return a.second > b.second;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void floodfill(){
	priority_queue<pair<ii,int> , vector<pair<ii,int> > , comp> pq(compare);
	for(int j=0;j<m;++j){
		pq.push(pair<ii,int> (ii(0,j),grid[0][j]));
	}
	for(int j=0;j<m;++j){
		pq.push(pair<ii,int> (ii(n-1,j),grid[n-1][j]));
	}
	for(int j=1;j<n-1;++j){
		pq.push(pair<ii,int> (ii(j,0),grid[j][0]));
	}
	for(int j=1;j<n-1;++j){
		pq.push(pair<ii,int> (ii(j,m-1),grid[j][m-1]));
	}
	while(!pq.empty()){
		pair<ii,int> top1 = pq.top();
		while(!pq.empty()){
			pair<ii,int> top2 = pq.top();
			if(top2.second>top1.second){
				break;
			}
			pq.pop();
			if(visited[top2.first.first][top2.first.second]++){
				continue;
			}
			ans+=top1.second-top2.second;
			for(int i=0;i<4;++i){
				int cx=top2.first.first+dx[i];
				int cy=top2.first.second+dy[i];
				if(cx>=0&&cx<n&&cy>=0&&cy<m){
					pq.push(pair<ii,int> (ii(cx,cy),grid[cx][cy]));
				}
			}
		}
	}
}

int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case){
		ans = 0;
		scanf("%d %d",&n,&m);
		grid = vector<vi> (n,vi(m,0));
		visited = vector<vi> (n,vi(m,0));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&grid[i][j]);
			}
		}
		floodfill();
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871

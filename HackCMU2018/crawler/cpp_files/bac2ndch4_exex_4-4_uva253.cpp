#include<cstdio>

int r[24][6] ={
	{1, 2, 3, 4, 5, 6},	{1, 4, 2, 5, 3, 6},	{1, 5, 4, 3, 2, 6},	{1, 3, 5, 2, 4, 6},
	{2, 6, 3, 4, 1, 5}, {2, 4, 6, 1, 3, 5}, {2, 1, 4, 3, 6, 5}, {2, 3, 1, 6, 4, 5},
	{3, 2, 6, 1, 5, 4},	{3, 1, 2, 5, 6, 4},	{3, 5, 1, 6, 2, 4},	{3, 6, 5, 2, 1, 4},
	{4, 2, 1, 6, 5, 3},	{4, 6, 2, 5, 1, 3},	{4, 5, 6, 1, 2, 3},	{4, 1, 5, 2, 6, 3},	
	{5, 1, 3, 4, 6, 2},	{5, 4, 1, 6, 3, 2},	{5, 6, 4, 3, 1, 2},	{5, 3, 6, 1, 4, 2},	
	{6, 5, 3, 4, 2, 1},	{6, 4, 5, 2, 3, 1},	{6, 2, 4, 3, 5, 1},	{6, 3, 2, 5, 4, 1}	
};

bool find(char* cube) {
	for (int i = 0; i < 24; i++) {
		int j = 0;
		while (j < 6 && cube[j+6] == cube[r[i][j]-1]) j++;
		if (j == 6) return true;
	}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva253.in", "r", stdin);
  #endif
	char cube[13];
	while(scanf("%s", cube) != EOF) {
		printf("%s\n", find2(cube) ? "TRUE" : "FALSE");
	}
	return 0;
}

/** Wrong answer but accepted
bool find(char* cube) {
	char cube2[6];
	for(int i = 0; i < 6; i++)
		cube2[i] = cube[i + 6];
	bool found;
	for(int i = 0; i < 3; i++) {
		found = 0;
		for(int j = 0; j < 6; j++) {
			if(cube[i] == cube2[j] && cube[5-i] == cube2[5-j]) {
				found = true;
				cube2[j] = cube2[5-j] = '0';
				break;
			}
		}
		if(!found) return false;
	}
	return found;
}*/

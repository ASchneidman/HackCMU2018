#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct 
{
	char name[40];
	int points;
	int wins;
	int ties;
	int dif;
	int goals;
	int play;
	int against;
}Team;

int cmp_p(const void *_a, const void *_b)
{
	Team *a = (Team*)_a;
	Team *b = (Team*)_b;
	if(b->points - a->points)
		return b->points - a->points;
	else if(b->wins - a->wins)
		return b->wins - a->wins;
	else if(b->dif - a->dif)
		return b->dif - a->dif;
	else if(b->goals - a->goals)
		return b->goals - a->goals;
	else if(a->play - b->play)
		return a->play - b->play;
	else
	{
		char name_a[40], name_b[40];
		int l_a = strlen(a->name), l_b = strlen(b->name);
		for(int i = 0; i < l_a; i++)
			name_a[i] = tolower(a->name[i]);
		for(int i = 0; i < l_b; i++)
			name_b[i] = tolower(b->name[i]);
		return strcmp(name_a, name_b);
	}
}

int main()
{
	//freopen("data.in", "r", stdin);
	int N;
	scanf("%d", &N);
	getchar();
	while(N--)
	{
		char tournament[110];
		puts(gets(tournament));
		int T;
		scanf("%d", &T);
		getchar();
		Team team[40];
		memset(team, 0, sizeof(team));
		for(int i = 0; i < T; i++)
			gets(team[i].name);
		int G;
		scanf("%d", &G);
		getchar();
		while(G--)
		{
			char game[100];
			gets(game);
			int goal1, goal2;
			int t1, t2;
			char *p1 = strchr(game, '#');
			char *p2 = strchr(game, '@');
			char *p3 = strchr(p1+1, '#');
			*p1 = '\0';
			for(int j = 0; j < T; j++)
			{
				if(!strcmp(game, team[j].name))
				{
					t1 = j;
					team[j].play++;
				}
				if(!strcmp(p3+1, team[j].name))
				{
					t2 = j;
					team[j].play++;
				}
			}
			sscanf(p1+1, "%d", &goal1);
			sscanf(p2+1, "%d", &goal2);
			team[t1].goals += goal1;
			team[t2].goals += goal2;
			team[t1].against += goal2;
			team[t2].against += goal1;
			team[t1].dif += goal1 - goal2;
			team[t2].dif += goal2 - goal1;
			if(goal1 > goal2)
			{
				team[t1].points += 3;
				team[t1].wins++;
			}
			else if(goal1 < goal2)
			{
				team[t2].points += 3;
				team[t2].wins++;
			}
			else
			{
				team[t1].points++;
				team[t2].points++;
				team[t1].ties++;
				team[t2].ties++;
			}
		}
		qsort(team, T, sizeof(team[0]), cmp_p);
		for(int i = 0; i < T; i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, team[i].name, team[i].points, team[i].play, team[i].wins, team[i].ties, team[i].play-team[i].wins-team[i].ties, team[i].dif, team[i].goals, team[i].against);
		if(N)
			putchar(10);
	}
	return 0;
}
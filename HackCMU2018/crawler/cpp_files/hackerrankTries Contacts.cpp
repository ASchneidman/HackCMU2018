#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Trie{
    int prefixes;
    struct Trie* edges[26];
};

void initialise(struct Trie* vertex)
{
    vertex->prefixes=0;
    for(int i=0;i<26;++i)
        vertex->edges[i]=NULL;
}
struct Trie *getNode(void)
{
    struct Trie *pNode = NULL;

    pNode = (struct Trie *)malloc(sizeof(struct Trie));

    if (pNode)
    {
        for (int i = 0; i < 26; i++)
            pNode->edges[i] = NULL;
        pNode->prefixes=0;
    }

    return pNode;
}
void addWord(struct Trie* vertex, string word)
{
    if(word.length()!=0)
    {

        int k=word[0]-'a';
        if(vertex->edges[k]==NULL)
        {
            vertex->edges[k] =  getNode();
            vertex->edges[k]->prefixes=1;
        }
        else
            vertex->edges[k]->prefixes=vertex->edges[k]->prefixes+1;
        word=word.substr(1);
        addWord(vertex->edges[k],word);

    }
}
int countPrefixes(struct Trie*root,string prefix)
{
    int k=prefix[0]-'a';
    if(prefix.length()==0)
        return root->prefixes;
    else if(root->edges[k]==NULL)
        return 0;
    else
    {
        prefix=prefix.substr(1);
        return countPrefixes(root->edges[k],prefix);
    }

}
int main(){
    int n;
    cin >> n;
    struct Trie *root = getNode();
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op=="add"){
            addWord(root,contact);
        }
        else{
            cout<<countPrefixes(root,contact)<<endl;
        }
    }
    return 0;
}

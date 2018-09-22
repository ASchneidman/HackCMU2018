<<<<<<< HEAD
#include<bits/stdc++.h>
#define CASE 'a'
using namespace std;
struct Node
{
    struct Node *parent;
    struct Node *children[26];
    long long cnt;
    vector<int> occurrences;
};

void InsertWord(struct Node * trieTree, char * word, int index)
{
    struct Node * traverse = trieTree;
    while (*word != '\0') {
        if (traverse->children[*word - CASE] == NULL) {
            traverse->children[*word - CASE] = (struct Node *) calloc(1, sizeof(struct Node));
            traverse->children[*word - CASE]->parent = traverse;  // Assigning parent
            traverse->children[*word -CASE]->cnt=1;
        }
        else{//printf("%c\n",*word);
            traverse->children[*word - CASE]->cnt++;}

        traverse = traverse->children[*word - CASE];
        ++word;
        //printf("%s\n",word);
    }

    traverse->occurrences.push_back(index);
}

struct Node * SearchWord(struct Node * treeNode, char * word)
{
    while (*word != '\0') {
        if (treeNode->children[*word - CASE] != NULL) {
            treeNode = treeNode->children[*word - CASE];
            ++word;
            //printf("%s\n",word);
        } else {
            //printf("%c - exit\n",*word);
            break;
        }
    }
    if (*word == '\0') {
        return treeNode;
    } else {
        return NULL;
    }
}
int main()
{
    long long n,len;
    char word[1000006];
    scanf("%lld",&n);
    struct Node * trieTree = (struct Node *) calloc(1, sizeof(struct Node));
    while(n--)
    {
        scanf(" %s",word);
        len=strlen(word);
        for(int i=0;i<len/2;++i)
            swap(word[i],word[len-i-1]);
            InsertWord(trieTree,word,n);
    }
    scanf("%lld",&n);
    while(n--)
    {
        scanf(" %s",word);
        len=strlen(word);
        for(int i=0;i<len/2;++i)
            swap(word[i],word[len-i-1]);
        struct Node *ans=SearchWord(trieTree,word);
        if(ans==NULL)
            printf("0\n");
        else
            printf("%lld\n",ans->cnt);

    }
    return 0;
}
=======
#include<bits/stdc++.h>
#define CASE 'a'
using namespace std;
struct Node
{
    struct Node *parent;
    struct Node *children[26];
    long long cnt;
    vector<int> occurrences;
};

void InsertWord(struct Node * trieTree, char * word, int index)
{
    struct Node * traverse = trieTree;
    while (*word != '\0') {
        if (traverse->children[*word - CASE] == NULL) {
            traverse->children[*word - CASE] = (struct Node *) calloc(1, sizeof(struct Node));
            traverse->children[*word - CASE]->parent = traverse;  // Assigning parent
            traverse->children[*word -CASE]->cnt=1;
        }
        else{//printf("%c\n",*word);
            traverse->children[*word - CASE]->cnt++;}

        traverse = traverse->children[*word - CASE];
        ++word;
        //printf("%s\n",word);
    }

    traverse->occurrences.push_back(index);
}

struct Node * SearchWord(struct Node * treeNode, char * word)
{
    while (*word != '\0') {
        if (treeNode->children[*word - CASE] != NULL) {
            treeNode = treeNode->children[*word - CASE];
            ++word;
            //printf("%s\n",word);
        } else {
            //printf("%c - exit\n",*word);
            break;
        }
    }
    if (*word == '\0') {
        return treeNode;
    } else {
        return NULL;
    }
}
int main()
{
    long long n,len;
    char word[1000006];
    scanf("%lld",&n);
    struct Node * trieTree = (struct Node *) calloc(1, sizeof(struct Node));
    while(n--)
    {
        scanf(" %s",word);
        len=strlen(word);
        for(int i=0;i<len/2;++i)
            swap(word[i],word[len-i-1]);
            InsertWord(trieTree,word,n);
    }
    scanf("%lld",&n);
    while(n--)
    {
        scanf(" %s",word);
        len=strlen(word);
        for(int i=0;i<len/2;++i)
            swap(word[i],word[len-i-1]);
        struct Node *ans=SearchWord(trieTree,word);
        if(ans==NULL)
            printf("0\n");
        else
            printf("%lld\n",ans->cnt);

    }
    return 0;
}
>>>>>>> 137199fba6bf1ae89e1bd0436b0ee31d0e6c270b

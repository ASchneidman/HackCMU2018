#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
	char value;
	Node *left, *right;
	Node(char x, Node* l, Node* r)
	{ value = x; left = l; right = r; }
};

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	while(n--)
	{
		string str;
		getline(cin, str);
		stack<Node*> st;
		for(unsigned i=0; i<str.size(); i++)
		{
			if(islower(str[i]))
				st.push(new Node(str[i], NULL, NULL));
			else
			{
				Node* u = new Node(str[i], NULL, st.top()); st.pop();
				u->left = st.top(); st.pop(); st.push(u);
			}
		}
		queue<Node*> q; q.push(st.top());
		stack<char> ans;
		while(!q.empty())
		{
			Node* cur = q.front(); q.pop();
			ans.push(cur->value);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		while(!ans.empty())
		{
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}
	return 0;
}

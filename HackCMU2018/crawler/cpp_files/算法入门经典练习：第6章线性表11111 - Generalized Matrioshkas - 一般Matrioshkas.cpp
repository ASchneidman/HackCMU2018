#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

typedef struct { int value, rest; } toy;


int main()
{
	string str;
	while(getline(cin, str))
	{
		int x;
		bool ok = true;
		stack<toy> st;
		istringstream ss(str);
		while(ss >> x)
		{
			if(x < 0)
			{
				if(st.empty() || st.top().rest > -x)
					st.push((toy){x, -x});
				else
				{
					ok = false;
					break;
				}
			}
			else
			{
				if(st.empty() || st.top().value != -x)
				{
					ok = false;
					break;
				}
				else
				{
					st.pop();
					if(!st.empty())
						st.top().rest -= x;
				}
			}
		}
		if(ok && st.empty())
			cout << ":-) Matrioshka!" << endl;
		else
			cout << ":-( Try again." << endl;
	}
	return 0;
}

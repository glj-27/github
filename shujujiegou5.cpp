#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
 
int main()
{
	string s;
    int T; 
	cin>>T;
    while (T--) 
	{
        cin>>s;
        int i;
		int len = s.length();
        stack<char> k;
        for (i = 0; i < len; i++) 
		{
            if (s[i] == '(' ) k.push(s[i]);
            else if (s[i] == ')') 
			{
                if (k.empty()) break;
                char t = k.top(); k.pop();
                if ( s[i] == ')' && t == '(' ) continue;
                else break;
            }
        }
        if (i >= len && k.empty()) cout << "TRUE" << endl;
        else cout << "FLASE" << endl;
    }
    return 0;
}


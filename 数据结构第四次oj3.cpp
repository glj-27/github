#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
 
 
int main() {
    int T, n, m, k, x;
    cin >> T;
    while(T--) 
	{
        cin >> n >> m >> k;
        int cnt = 0;
        for(int i = 0; i < n; i++) 
		{
            cin >> x;
            if((x %= m) == k) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

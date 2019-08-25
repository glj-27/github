#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull p = 19260817;
const int N = 1 << 15;
ull h[N];

int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
#endif // local
    ios::sync_with_stdio(false);
    string s, t;
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> s;
            int l = s.size();
            ull tmp = 0;
            for(int j = 0; j < l; j++)
                tmp = tmp * p + s[j];
            h[i] = tmp;
        }
        for(int i = 0; i < m; i++) {
            cin >> t;
            int l = t.size(), cnt = 0;
            ull tmp = 0;
            for(int j = 0; j < l; j++)
                tmp = tmp * p + t[j];
            for(int j = 0; j < n; j++)
                if(tmp == h[j]) cnt++;
            cout << cnt << " \n"[i == m - 1];
        }
    }
    return 0;
}




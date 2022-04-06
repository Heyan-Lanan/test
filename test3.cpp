#include<bits/stdc++.h>

using namespace std;

int main() {
    int vis[25], a[25];
    int t, x, p, ans;
    char str[20];
    t = 1;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        p = ans = 0;
        while (scanf("%d",&x) != EOF) {
            p++;
            a[p] = x;
        }
        sort(a + 1, a + p + 1);
        for (int i = 1; i <= p; i++) {
            if (vis[a[i]] == 1) ans++;
            vis[2 * a[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pf push_front
#define mp make_pair
#define MAX_N 1e9
#define MIN_N -1e9
#define MAX_SIZE 1000000
#define PI 3.141592653589793238
#define pb push_back
#define sz(s) s.size()
const int mod = 1e9 + 7;
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        cin >> s;
        priority_queue<int> pq;
        map<char, int> mp;
        for (char x : s)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            pq.push(x.se);
        }
        while (n > 0)
        {
            int x = pq.top();
            pq.pop();
            x--;
            n--;
            pq.push(x);
        }
        ll ans = 0;
        while (!pq.empty())
        {
            ans += 1ll * pow(pq.top(), 2);
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
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

ll a[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<ll> st;
        int i = 0;
        ll ans = -1e18;
        while (i < n)
        {
            if (st.empty() || a[i] >= a[st.top()])
            {
                st.push(i);
                i++;
            }
            else
            {
                ll idx = st.top();
                st.pop();
                if (st.empty())
                {
                    ans = max(ans, 1ll * i * a[idx]);
                }
                else
                {
                    ans = max(ans, 1ll * (i - st.top() - 1) * a[idx]);
                }
            }
        }
        while (!st.empty())
        {
            ll idx = st.top();
            st.pop();
            if (st.empty())
            {
                ans = max(ans, 1ll * i * a[idx]);
            }
            else
            {
                ans = max(ans, 1ll * (i - st.top() - 1) * a[idx]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
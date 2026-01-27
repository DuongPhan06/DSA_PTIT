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

int k;
string s;
string ans;
void Try(int i, int cnt, string s)
{
    if (cnt == k || i >= s.size())
    {
        ans = max(ans, s);
        return;
    }
    char max_val = s[i];
    vector<int> max_pos;
    for (int j = i + 1; j < s.size(); j++)
    {
        if (s[j] > max_val)
        {
            max_val = s[j];
            max_pos.clear();
        }
        if (s[j] == max_val)
        {
            max_pos.pb(j);
        }
    }
    if (max_val > s[i])
    {
        for (int k = 0; k < max_pos.size(); k++)
        {
            string tmp = s;
            swap(tmp[i], tmp[max_pos[k]]);
            Try(i + 1, cnt + 1, tmp);
        }
    }
    else
    {
        Try(i + 1, cnt, s);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> s;
        ans = s;
        Try(0, 0, s);
        cout << ans << endl;
    }
    return 0;
}
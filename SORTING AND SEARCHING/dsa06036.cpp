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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                if (a[l] == a[i])
                {
                    l++;
                }
                else if (a[r] == a[i])
                {
                    r--;
                }
                if (a[l] + a[r] + a[i] == k)
                {
                    check = true;
                    break;
                }
                else if (a[l] + a[r] + a[i] < k)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        if (check == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
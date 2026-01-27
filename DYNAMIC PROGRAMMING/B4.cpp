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

vector<string> v;
int a[1000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string t = "Buoc 0: " + to_string(a[0]);
    v.pb(t);
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        string tmp = "Buoc " + to_string(i) + ": ";
        for (int k = 0; k <= i; k++)
        {
            tmp = tmp + to_string(a[k]) + " ";
        }
        v.pb(tmp);
    }
    reverse(v.begin(), v.end());
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}
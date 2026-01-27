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

int n;
int x[1001];
char a[2] = {'6', '8'};
set<string> se;
bool check(string &s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '8' && s[i + 1] == '8')
        {
            return false;
        }
    }
    for (int i = 0; i < s.size() - 3; i++)
    {
        if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6' && s[i + 3] == '6')
        {
            return false;
        }
    }
    return true;
}
void Try(int i, string s)
{
    if (i > n)
    {
        return;
    }
    if (i == n && s.size() >= 6 && check(s))
    {
        if (s[0] == '8' && s.back() == '6')
        {
            se.insert(s);
            return;
        }
    }
    for (int j = 0; j < 2; j++)
    {
        x[i] = j;
        Try(i + 1, s + a[j]);
    }
}
int main()
{
    cin >> n;
    Try(0, "");
    for (auto x : se)
    {
        cout << x << endl;
    }
    return 0;
}
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

int a[1000001];
int freq[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(freq, 0, sizeof(freq));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (freq[a[i]] <= freq[a[st.top()]])
            {
                st.push(i);
            }
            else if (freq[a[i]] > freq[a[st.top()]])
            {
                while (!st.empty() && freq[a[i]] > freq[a[st.top()]])
                {
                    a[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty())
        {
            a[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
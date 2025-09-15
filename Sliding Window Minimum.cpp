#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<ll> s(n);
    s[0] = x;
    for (int i = 1; i < n; i++)
    {
        s[i] = (a * s[i - 1] + b)%c;
    }
    ll xr = 0;
    deque<ll>q;
    for(int i=0;i<k;i++){
        ll new_element = s[i];
        while(!q.empty() && q.back()>new_element) q.pop_back();

        q.push_back(new_element);
    }
    xr = q.front();
    for(int i=k;i<n;i++){
        //removing
        while(!q.empty() && q.front()==s[i-k]) q.pop_front();

        // adding
        ll new_element = s[i];
        while(!q.empty() && q.back()>new_element) q.pop_back();

        q.push_back(new_element);

        xr^=q.front();
    }
    cout << xr << endl;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}
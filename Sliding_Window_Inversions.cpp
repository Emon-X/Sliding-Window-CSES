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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n,k;
    cin >> n >> k;
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    ll ans = 0;
    ll inv = 0;
    ordered_set<ll>st;
    for(int i = 0;i<k;i++){
        ll x = st.size() - st.order_of_key(s[i]+1);
        ans+=x;
        st.insert(s[i]);
    }
    cout << ans << " ";
    for(int i = k;i<n;i++){
        ll bad = st.order_of_key(s[i-k]);
        ans-=bad;
        st.erase(st.upper_bound(s[i-k]));
        st.insert(s[i]);

        ll x = st.size() - st.order_of_key(s[i]+1);
        ans+=x;

        cout << ans << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        domain_expension();
    return 0;
}
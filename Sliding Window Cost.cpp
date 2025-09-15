#include<bits/stdc++.h>
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
    ll n,k;
    cin >> n >> k;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    ordered_set<pair<ll,ll>> st ;
    for(int i=0;i<k;i++) st.insert({s[i],i});

    ll cost = 0;
    ll mid = (k%2 ? k/2 : (k-1)/2);

    for(int i=0;i<k;i++) cost+=abs(st.find_by_order(mid)->first-s[i]);

    cout << cost << " ";

    for(int i=k;i<n;i++){

        ll old_mid = st.find_by_order(mid)->first;
        st.erase({s[i-k],i-k});
        st.insert({s[i],i});
        ll new_mid = st.find_by_order(mid)->first;

        ll x = abs(new_mid - s[i])-abs(s[i-k]-old_mid);
        cost+=x;
        if(k%2==0){
            cost-=(new_mid-old_mid);
        }
        cout << cost << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}
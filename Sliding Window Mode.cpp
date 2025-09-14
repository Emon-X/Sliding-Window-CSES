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
    ll n, k;
    cin >> n >> k;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];
 
    map<ll, ll> mp; 
    map<ll, set<ll>> mp_val;
    for (int i = 0; i < k; i++) {
        ll val = s[i];
        ll old_f = mp[val];
        if (old_f > 0) mp_val[old_f].erase(val);
        mp[val]++;
        mp_val[mp[val]].insert(val);
    }
    cout << *mp_val.rbegin()->second.begin() << " ";
 
    for (int i = k; i < n; i++) {
        ll out_val = s[i - k];
        ll out_f = mp[out_val];
        mp_val[out_f].erase(out_val);
        if (mp_val[out_f].empty()) mp_val.erase(out_f);
        mp[out_val]--;
        if (mp[out_val] > 0) mp_val[mp[out_val]].insert(out_val);
        else mp.erase(out_val);
        
        ll in_val = s[i];
        ll in_f = mp[in_val];
        if (in_f > 0) mp_val[in_f].erase(in_val);
        mp[in_val]++;
        mp_val[mp[in_val]].insert(in_val);
 
        cout << *mp_val.rbegin()->second.begin() << " ";
    }
    cout << endl;
   
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}
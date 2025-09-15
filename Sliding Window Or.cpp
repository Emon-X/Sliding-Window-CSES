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
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<ll>s(n);
    s[0]=x;
    for(int i=1;i<n;i++){
        s[i]=(a*s[i-1]+b)%c;
    }

    vector<ll>prefix(n),suffix(n);
    prefix[0]=suffix[n-1]=x;
    for(int i=1;i<n;i++){
        if(i%k==0){ prefix[i]=s[i];
        }
        else{
            prefix[i]=prefix[i-1]|s[i];
        }
    }

    ll cnt = 0;
    for(int i=n-2;i>=0;i--){
        if(i%k==k-1) suffix[i]=s[i];
        else suffix[i]= suffix[i+1]|s[i];
    }

    ll l = 0, r = k - 1,ans=0;
    while (r < n) {
        if (r % k == k - 1) ans ^= prefix[r];
        else ans ^= (prefix[r] | suffix[l]);
        r++, l++;
    }

    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}
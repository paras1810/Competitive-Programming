#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    int n;
    cin >> n;
    pair<ull,ull> *p = new pair<ull,ull>[n];
    priority_queue<P<ull,ull>, V<P<ull,ull> >, greater<P<ull,ull > > q;
    for(ull i = 0,a ; i < n; ++i){
        cin >> a;
        p[i] = make_pair(a,1);
    }
    for(ull i = 0,a ; i < n; ++i){
        cin >> a;
        p[i].second = a;
    }
    V<P<ull,ull> > v[n];
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(p[j].first > p[i].first){
                v[i].pb(mp(i,j));
            }
        }
    }
    ull MIN = INT_MAX;
    if(MIN == INT_MAX)cout << "-1";
    else cout << MIN;
return 0;
}
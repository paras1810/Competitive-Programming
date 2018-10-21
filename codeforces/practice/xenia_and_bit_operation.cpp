/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

vector<vector<ll> > tree(20);

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
 
}
int main(){
    int n,m;
    ll tmp = 1;
    cin >> n >> m;
    
    vector<vector<ll> > v1(20);
    vector<vector<ll> > v2(20);
    for(int i = 0; i < (tmp << n); ++i){
        int a = readInt();
        v1[0].pb(a);
        v2[0].pb(a);
    }
    int i = 1;
    while(v1[i/2].size()!=1){
        if(i%2 == 1){
            for(int j = 0; j < v1[i/2].size(); j+=2){
                if(j+1 < v1[i/2].size())v1[i/2 + 1].pb(v[1i/2][j]|v1[i/2][j+1]);
                else v1[i/2+1].pb(v1[i/2][j]);
            }
        }
        else{
            for(int j = 0; j < v2[i-1].size(); j+=2){
                if(j+1 < v[i-1].size())v[i].pb(v[i-1][j]|v[i-1][j+1]);
                else v[i-1].pb(v[i-1][j]);
            }
        }
    }
    return 0;
}
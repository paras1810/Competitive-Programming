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

typedef pair<int,PII> node;
string s;
int t[3000000];
int c[3000000];
int o[3000000];
int n;
void build(int id = 0, int l = 0, int r = n-1){
    if(l == r){
        if(s[l] == '('){
            o[id] = 1;
        }else{
            c[id] = 1;
        }
        return ;
    }
    int mid = (l+r)/2;
    build(2*id+1,l,mid);
    build(2*id+2,mid+1,r);
    int tmp = min(o[2*id+1],c[2*id + 2]);
    t[id] = t[2*id+1] + t[2*id + 2] + tmp;
    c[id] = c[2*id+1] + c[2*id + 2] - tmp;
    o[id] = o[2*id+1] + o[2*id + 2] - tmp;
    // printf("id = %d, t[%d] = %d, c[%d] = %d, o[%d] = %d\n", id, id, t[id], id, c[id], id, o[id]);
}

node segment(int x, int y, int id = 0, int l = 0, int r = n-1){
    if(l >= y || x >= r)return node(0,PII(0,0));
    if(x <= l && y >= r)return node(t[id],PII(o[id],c[id]));
    int mid = (l+r)/2;
    node a = segment(x,y,2*id+1,l,mid), b= segment(x,y,2*id+2,mid+1,r);
    // printf("a = t[%d] = %d, c[%d] = %d, o[%d] = %d\n", 2*id+1, t[2*id+1], 2*id+1, c[2*id+1], 2*id+1, o[2*id+1]);
    // printf("b = t[%d] = %d, c[%d] = %d, o[%d] = %d\n", 2*id+2, t[2*id+2], 2*id+2, c[2*id+2], 2*id+2, o[2*id+2]);
    // printf("a = (%d,%d,%d), b = (%d,%d,%d)\n",a.first,a.second.first,a.second.second,b.first,b.second.first,b.second.second);
    int T, temp, O, C;
    temp = min(a.second.first,b.second.second);
    T = a.first + b.first + temp;
    O = a.second.first + b.second.first - temp;
    C = a.second.second + b.second.second - temp;
    // cout << T << " " << O << endl;
    return node(T,PII(O,C));
}

int main(){
    cin >> s;
    n = s.length();
    build();
    int m = readInt();
    while(m--){
        int l = readInt();
        int r = readInt();
        // l--,r--;
        cout << segment(l,r).first << endl;
    }
    return 0;
}

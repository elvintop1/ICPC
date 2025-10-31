// MPK

#pragma GCC optimize("Ofast,inline,unroll-loops,omit-frame-pointer")
#if __GNUC__ == 14 && __cplusplus > 202002L
#pragma GCC target("arch=x86-64")
#else
#pragma GCC target("arch=corei7-avx")
#endif

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef unsigned int       uint;
typedef unsigned long long ull;
typedef long long          ll;
typedef double             dbl;
typedef __int128_t         lll;
typedef __uint128_t        ulll;

typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;

typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll>    tlll;

#define mset multiset
#define mmap multimap
#define uset unordered_set
#define umap unordered_map
#define pqueue priority_queue

template <typename T, typename V = vector<T>, typename C = less<T>>
using pqueue_max = pqueue<T, V, C>;

template <typename T, typename V = vector<T>, typename C = greater<T>>
using pqueue_min = pqueue<T, V, C>;

#define endl "\n"
#define endln cout << "\n"
#define sz(x) ((ll)(x).size())

#define DBG(x) cout << #x << " = " << (x) << "\n"

#define MAX(x, y) x = max(x, y)
#define MIN(x, y) x = min(x, y)
#define elif else if

#define mpr make_pair
#define mtpl make_tuple

#define fi first
#define se second
#define tp top
#define bk back
#define fr front
#define GET(x, i) get<(i) - 1>(x)

#define ep emplace
#define epf emplace_front
#define epb emplace_back
#define psh push
#define pshf push_front
#define pshb push_back
#define pp pop
#define ppb pop_back
#define ppf pop_front

const int IMAX   = INT_MAX / 2;
const ll  LLMAX  = LLONG_MAX / 2;
const ull ULLMAX = ULLONG_MAX / 2;
const int IMIN   = INT_MIN / 2;
const ll  LLMIN  = LLONG_MIN / 2;
const ll  MOD1   = 1000000007LL;
const ll  MOD2   = 998244353LL;
const dbl EPS    = 1E-9;

int     tc = 1;
string  sinp, sout;
fstream finp, gout;

void SetIO(string fl = "", string inp = "inp", string out = "out") {
    __builtin_ia32_ldmxcsr(40896);
    cin.tie(0)->sync_with_stdio(0);
    sinp = fl + "." + inp;
    sout = fl + "." + out;
    if (fl != "") {
        finp.open(sinp, ios::in);
        gout.open(sout, ios::out);
        if (!finp.is_open()) {
            finp.close();
            finp.open(sinp, ios::out);
            finp.close();
            finp.open(sinp, ios::in);
        }
        cin.rdbuf(finp.rdbuf());
        cout.rdbuf(gout.rdbuf());
    }
    return;
}

// -------------------- [Entry Point] --------------------
const int N = 5e4 + 1e5;

int         n, m, q;
int         vis[N + 1];
vector<int> a[N + 1];

int DFS(int u, int t) {
    if (u == t) {
        return 1;
    }
    for (int v : a[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (DFS(v, t)) {
                return 1;
            }
        }
    }
    return 0;
}

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].epb(v);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int u, d;
            cin >> u >> d;
            if (d == 0) {
                a[u].epb(++n);
            } else if (d == 1) {
                a[++n].epb(u);
            }
        } else if (opt == 2) {
            int u, v;
            cin >> u >> v;
            for (int i = 1; i <= n; i++) {
                vis[i] = 0;
            }
            vis[u] = 1;
            cout << (DFS(u, v) ? "Yes\n" : "No\n");
        }
    }
    return;
}

signed Main() {
    SetIO();
    Solve();
    finp.close();
    gout.close();
    return 0;
}

signed main() {
    auto time_start = high_resolution_clock::now();
    cerr << "\n\n";

    signed ret = Main();

    auto   time_end = high_resolution_clock::now();
    double elapsed  = duration<double>(time_end - time_start).count() * 1e3;
    int    w1       = 36 - to_string(int(elapsed)).size();
    int    w2       = 25 - to_string(ret).size() - 2 * !ret;
    cerr << "\n\n-------------------- [Execution Summary] --------------------\n";
    cerr << "| Execution Time" << ": " << fixed << setprecision(4) << elapsed << " ms" << setw(w1) << "|\n";
    cerr << "| Exit Code     : " << ret << setw(w2) << "(0x" << setfill('0') << setw(8) << hex << uppercase << ret << (!ret ? ", Success) |" : ", Error) |") << "\n";
    cerr << "-------------------------------------------------------------\n\n";
    return ret;
}
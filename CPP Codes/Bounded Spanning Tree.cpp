#include <bits/stdc++.h>
using namespace std;


#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder


const long long INF = 1LL << 60;

long long op(long long a, long long b) {
    return min(a, b);
}
long long e() {
    return INF;
}

long long mapping(long long f, long long s) {
    return min(f, s);
}
long long compostion(long long a, long long b) {
    return min(a, b);
}
long long id() {
    return INF;
}

using SegmentTree = atcoder::lazy_segtree<long long, op, e, long long, mapping, compostion, id>;



class HLD {
    public:
        HLD(vector<vector<int>>& _G, int _rt = 0) : N(_G.size()), rt(_rt), graph(_G) {
            indices.clear(), indices.resize(N, {-1,-1});
            depths.clear(), depths.resize(N, 0);
            sizes.clear(), sizes.resize(N, 0);
         
            h = 0;
            while (1 << (h + 1) <= N) {
                ++h;
            }
            pars.clear(),pars.resize(N, vector<int>(h + 1, -1));
            
            ins.clear(), ins.resize(N, 0);
            outs.clear(), outs.resize(N, 0);

            int clk = 0;
            dfs0(rt, -1, 0, clk); //LCA, sizes, euler, etc.
            int pidx = 0, idx = 0;
            paths.clear();
            paths.emplace_back();
            acc.clear();
            acc.resize(N + 1, 0);
            dfsBuild(rt, -1, pidx, idx); //HLD
            acc[pidx + 1] = acc[pidx] + paths[pidx].size();
            assert(acc[pidx+1] == N);

            st = SegmentTree(N + 10);
        }

        bool isAncestor(int u, int v) {
            return ins[u] <= ins[v] && outs[v] <= outs[u];
        }
        int LCA(int u, int v) {
            if (u == -1 || v == -1) { return u == -1 ? v : u; }
            if (u == v) { return u; }
            if (depths[u] > depths[v]) { swap(u, v); }
            if (isAncestor(u, v)) { return u; }
            int diff = depths[v] - depths[u];
            for (int i = h; i >= 0; --i) {
                if ((diff >> i) & 1) {
                    v = pars[v][i];
                }
            }
            for (int i = h; i >= 0; --i) {
                if (pars[u][i] != pars[v][i]) {
                    u = pars[u][i], v = pars[v][i];
                }
            }
            return pars[u][0];
        }
        int distanceBetween(int u, int v) {
            int p = LCA(u, v);
            return depths[u] + depths[v] - 2 * depths[p];
        }
        
        //Update the value on the path between u and v excluding LCA(u, v)
        //O(logN * logN)
        void update(int u, int v, long long val, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }

            // cout << "Update " << u << ' ' << v << " " << p << " " << val << endl;
            updatePath(u, p, val);
            updatePath(v, p, val);//if LCA is included, the second parameter might need to be changed to the ancestor of v which is a direct child of LCA(if the operation is summation instead of minimization/maximization)
        }

        //Update(minimize) the value on the path from u(including) to t(excluding) with val
        //O(logN * logN)
        void updatePath(int u, int t, long long val) {
            // cout << "UPPP " << u << " " << t << " " << val << " " << paths.size() << endl;
            int cp = indices[u].first, ci = indices[u].second;
            int tp = indices[t].first, ti = indices[t].second;
            // cout << " " << cp << " " << tp << " " << ci << " " << ti <<  endl;
            while (cp != tp) {
                int l = acc[cp], r = l + ci;
                st.apply(l, r + 1, val);
                u = paths[cp][0];
                u = pars[u][0];
                cp = indices[u].first, ci = indices[u].second;
            }
            if (ci > ti) {//if t is included, chage to >=, and l below to acc[tp] + ti
                int l = acc[tp] + ti + 1, r = acc[tp] + ci;
                st.apply(l, r + 1, val);
            }
        }

        long long query(int v) {
            v = acc[indices[v].first] + indices[v].second;
            return st.get(v);
        }

        //Called after pars has been built(a.k.a., dfs0).
        //For query of edges, values[u][0] means the value on the edge from u's parent to u.
        void initSparseTable(vector<long long>& A) {
            values.clear(),values.resize(N, vector<long long>(h + 1, -INF));    
            function<void(int,int)> DFS = [&](int u, int p) {
                values[u][0] = A[u];
                for (int i = 1; i <= h; ++i) {
                    values[u][i] = values[u][i - 1];
                    if (pars[u][i - 1] >= 0) {
                        values[u][i] = max(values[u][i], values[pars[u][i - 1]][i - 1]);
                    }
                }
                for (auto v : graph[u]) {
                    if (v == p) { continue; }
                    DFS(v, u);
                }
            };
            DFS(rt, -1);
        }

        //Query (maximum)value on the path from u to its Kth ancestor. K >= 1, 1 means u itself(this is for edge query).
        //O(logN)
        long long querySparseTable(int u, int K) {
            long long res = -INF;
            for (int i = h; i >= 0; --i) {
                if (K >> i & 1) {
                    res = max(res, values[u][i]);
                    u = pars[u][i];
                } 
            }
            return res;
        }

        //Query value on path u to v excluding LCA(u, v).
        //O(logN)
        long long queryPathSparseTable(int u, int v, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }
            long long res = -INF;
            if (depths[p] < depths[u]) {
                res = max(res, querySparseTable(u, depths[u] - depths[p]));
            }
            if (depths[p] < depths[v]) {
                res = max(res, querySparseTable(v, depths[v] - depths[p]));
            }
            return res;
        }

    private:
        int N;
        int rt;
        int h;
        vector<vector<int>> graph;
        vector<pair<int,int>> indices;
        vector<int> depths;
        vector<int> sizes;
        vector<vector<int>> pars;
        vector<int> ins;
        vector<int> outs;
        vector<vector<int>> paths;
        vector<int> acc;

        vector<vector<long long>> values;
        SegmentTree st;

        //Euler tour, LCA, depth, size
        void dfs0(int u, int p, int d, int& clock) {
            ins[u] = ++clock;
            pars[u][0] = p;
            for (int i = 0; i < h; ++i) {
                if (pars[u][i] < 0) { break; }
                pars[u][i + 1] = pars[pars[u][i]][i];
            }

            depths[u] = d;
            sizes[u] = 1;
            for (auto v : graph[u]) {
                if (v == p) { continue; }
                dfs0(v, u, d + 1, clock);
                sizes[u] += sizes[v];
            }

            outs[u] = clock;
        }

        //HLD
        void dfsBuild(int u, int p, int& pidx, int& idx) {
            indices[u] = {pidx, idx};
            assert(paths[pidx].size() == idx);
            paths[pidx].push_back(u);
            int w = -1;
            for (auto v : graph[u]) {
                if (v == p) { continue; }
                if (w == -1 || sizes[w] < sizes[v]) {
                    w = v;
                }
            }
            if (w >= 0) {
                ++idx;
                dfsBuild(w, u, pidx, idx);
            }
            for (auto v : graph[u]) {
                if (v == p || v == w) { continue; }
                ++pidx;
                acc[pidx] = acc[pidx - 1] + paths[pidx - 1].size();
                idx = 0;
                paths.emplace_back();
                dfsBuild(v, u, pidx, idx);
            }
        }


};


class DisjointSet {
    public:
        DisjointSet(int n) : N(n), sz(n), pars(n, -1) {
        }
        void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }
        int find(int x) { return pars[x] < 0 ? x : pars[x] = find(pars[x]); }
        int size() { return sz; }
        int count(int x) { return -pars[find(x)]; }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) { return false; }
            --sz;
            if (pars[x] < pars[y]) { swap(x, y); }
            pars[y] += pars[x];
            pars[x] = y;
            return true;
        }
        bool isSame(int x, int y) { return find(x) == find(y); }
    private:
        int N, sz;
        vector<int> pars;
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<int> U(m), V(m), L(m), R(m);
        for (int i = 0; i < m; ++i) {
            cin >> U[i] >> V[i] >> L[i] >> R[i];
            --U[i], --V[i]; //--L[i], --R[i];
        }

        bool ok = true;
        {//E[0, n-1) forms a tree T
            DisjointSet ds(n);
            for (int i = 0; i < n - 1; ++i) {
                ds.unite(U[i], V[i]);
            }
            if (ds.size() != 1) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<vector<int>> G(n);
        for (int i = 0; i < n - 1; ++i) {
            G[U[i]].push_back(V[i]);
            G[V[i]].push_back(U[i]);
        }
        HLD hld(G);
        vector<int> LCAs(m, -1);

        //Try to assign values greedly besed on L's/R's: For a weight w, choose the edge which has L >= w and has the minimum R.
        //For e{i} = (u, v) in E[n-1, m-1), update R's of edges on path from u to v in T with R{i}-1. So e{i} will be selected after all edges on the path from u to v.
        //But edges on path u - v might have bigger L's than e{i}, so some edges might still be selected after e{i}. To avoid this, update L of e{i} with maxmimum of L's of edges on the path from u to v.
        for (int i = n - 1; i < m; ++i) {
            int u = U[i], v = V[i];
            LCAs[i] = hld.LCA(u, v);
            hld.update(u, v, R[i] - 1, LCAs[i]);
        }
        
        vector<long long> A(n, -INF);
        for (int i = 0; i < n - 1; ++i) {
            int u = U[i], v = V[i];
            if (hld.isAncestor(u, v)) {
                R[i] = min((long long)R[i], hld.query(v));
                A[v] = L[i];
            } else {
                R[i] = min((long long)R[i], hld.query(u));
                A[u] = L[i];
            }
            // cout << i << " | " << L[i] << "-" << R[i] << endl;
            if (L[i] > R[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        //For e{i} = (u, v) in E[n-1, m-1), update L{i} with maximum of L's of edges on path from u to v in T.
        hld.initSparseTable(A);
        for (int i = n - 1; i < m; ++i) {
            int u = U[i], v = V[i];
            long long l = hld.queryPathSparseTable(u, v, LCAs[i]);
            L[i] = max((long long)L[i], l);
            if (L[i] > R[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> res(m, -1);
        vector<int> ord(m, 0);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int l, int r) { return L[l] < L[r]; });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 1, j = 0; i <= m; ++i) {
            while (j < m && L[ord[j]] <= i) {
                pq.emplace(R[ord[j]], ord[j]);
                ++j;
            }
            if (pq.empty()) {
                ok = false;
                break;
            }
            auto idx = pq.top().second;
            auto r = pq.top().first;
            pq.pop();
            if (r < i) {
                ok = false;
                break;
            }
            res[idx] = i;
        }

        if (ok) {
            cout << "YES\n";
            for (auto x : res) {
                cout << x << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}

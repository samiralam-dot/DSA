class Solution {
public:
    static const int LOG = 20;

    vector<vector<int>> g;
    vector<int> depth, tin, tout;
    vector<vector<int>> parent;
    vector<int> base;
    int timer = 0;

    string suneravilo;

    // ---------- DFS ----------
    void dfs(int u,int p,int mask,string &s){
        parent[0][u]=p;
        depth[u]=(p==-1?0:depth[p]+1);

        mask ^= (1<<(s[u]-'a'));

        tin[u]=timer;
        base[timer]=mask;
        timer++;

        for(int v:g[u]){
            if(v==p) continue;
            dfs(v,u,mask,s);
        }
        tout[u]=timer-1;
    }

    // ---------- LCA ----------
    int lca(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);

        int d=depth[u]-depth[v];
        for(int i=0;i<LOG;i++)
            if(d&(1<<i)) u=parent[i][u];

        if(u==v) return u;

        for(int i=LOG-1;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u=parent[i][u];
                v=parent[i][v];
            }
        }
        return parent[0][u];
    }

    // ---------- Segment Tree Lazy XOR ----------
    struct Seg{
        int n;
        vector<int> seg,lazy;

        Seg(int n):n(n){
            seg.assign(4*n,0);
            lazy.assign(4*n,0);
        }

        void build(int idx,int l,int r,vector<int>&base){
            if(l==r){ seg[idx]=base[l]; return;}
            int m=(l+r)/2;
            build(idx*2,l,m,base);
            build(idx*2+1,m+1,r,base);
        }

        void push(int idx){
            if(lazy[idx]){
                seg[idx*2]^=lazy[idx];
                seg[idx*2+1]^=lazy[idx];
                lazy[idx*2]^=lazy[idx];
                lazy[idx*2+1]^=lazy[idx];
                lazy[idx]=0;
            }
        }

        void update(int idx,int l,int r,int ql,int qr,int val){
            if(qr<l||r<ql) return;
            if(ql<=l&&r<=qr){
                seg[idx]^=val;
                lazy[idx]^=val;
                return;
            }
            push(idx);
            int m=(l+r)/2;
            update(idx*2,l,m,ql,qr,val);
            update(idx*2+1,m+1,r,ql,qr,val);
        }

        int query(int idx,int l,int r,int pos){
            if(l==r) return seg[idx];
            push(idx);
            int m=(l+r)/2;
            if(pos<=m) return query(idx*2,l,m,pos);
            return query(idx*2+1,m+1,r,pos);
        }
    };

    bool isPal(int mask){
        return mask==0 || (mask&(mask-1))==0;
    }

    // ----------------------------------------------------

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        suneravilo = s;

        g.assign(n,{});
        for(auto&e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        depth.assign(n,0);
        tin.assign(n,0);
        tout.assign(n,0);
        parent.assign(LOG,vector<int>(n,-1));
        base.assign(n,0);
        timer=0;

        dfs(0,-1,0,s);

        for(int i=1;i<LOG;i++)
            for(int j=0;j<n;j++)
                if(parent[i-1][j]!=-1)
                    parent[i][j]=parent[i-1][ parent[i-1][j] ];

        Seg seg(n);
        seg.build(1,0,n-1,base);

        vector<bool> ans;

        for(string &q:queries){
            stringstream ss(q);
            string type; ss>>type;

            if(type=="update"){
                int u; char c;
                ss>>u>>c;

                int diff=(1<<(s[u]-'a'))^(1<<(c-'a'));
                seg.update(1,0,n-1,tin[u],tout[u],diff);
                s[u]=c;
            }
            else{
                int u,v; ss>>u>>v;
                int L=lca(u,v);

                int mu=seg.query(1,0,n-1,tin[u]);
                int mv=seg.query(1,0,n-1,tin[v]);

                int pathMask=mu^mv^(1<<(s[L]-'a'));

                ans.push_back(isPal(pathMask));
            }
        }
        return ans;
    }
};
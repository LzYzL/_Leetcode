class Solution {
public:
    int fa[100006],w[100006];
    int getf(int x) {
        return fa[x]==x?x:fa[x]=getf(fa[x]);
    }
    void pre(int n)
    {
        for (int i=0;i<n;++i) {
            fa[i]=i;
            w[i]=-1;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //memset(fa,0,sizeof(fa));
        pre(n);
        for (vector<int> edg:edges) {
            int x=getf(edg[0]),y=getf(edg[1]);
            fa[y]=x;
            w[x]=w[x]&w[y]&edg[2];
        }

        vector<int> ans;
        for (vector<int> q:query) {
            int x=getf(q[0]),y=getf(q[1]);
            if (x!=y) ans.push_back(-1);
            else {
                ans.push_back(w[x]);
            }
        }

        return ans;
    }
};
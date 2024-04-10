#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<int> ans=solve(points,-1);
        int t1=solve(points,ans[0])[2],t2=solve(points,ans[1])[2];
        return t1<t2?t1:t2;
        // return solve(points,ans[0])[2];
    }

    vector<int> solve(vector<vector<int>>& points,int avo) {
        vector<int> t;
        int smax=-2147483647,smaxi=-1,smin=2147483647,smini=-1;
        int dmax=-2147483647,dmaxi=-1,dmin=2147483647,dmini=-1;
        for (int i=0;i<(int)points.size();++i) {
            if (i==avo) continue;
            int t1=points[i][0]+points[i][1];
            int t2=points[i][0]-points[i][1];
            if (t1>smax) {
                smax=t1;
                smaxi=i;
            }
            if (t1<smin) {
                smin=t1;
                smini=i;
            }
            if (t2>dmax) {
                dmax=t2;
                dmaxi=i;
            }
            if (t2<dmin) {
                dmin=t2;
                dmini=i;
            }
        }
        if (smax-smin>dmax-dmin) {
            t.push_back(smaxi);
            t.push_back(smini);
            t.push_back(smax-smin);
        } else {
            t.push_back(dmaxi);
            t.push_back(dmini);
            t.push_back(dmax-dmin);
        }
        return t;
    }

};

int main()
{
    Solution sol;
    vector<vector<int>> points={{5,3},{4,6},{2,4},{1,8},{3,9},{1,6}};
    printf("%d\n",sol.minimumDistance(points));
    return 0;
}
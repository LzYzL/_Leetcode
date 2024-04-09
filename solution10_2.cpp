#include "solution10.h"

bool Solution::isMatch(string s, string p) 
{
    // s="cabddab",p=".ab*";
    n=1;
    st[n]="";
    for (int i=0;i<(int)p.length();++i) {
        st[n]+=p[i];
        if (i+1<(int)p.length() && p[i+1]!='*') 
            st[++n]="";
    }
    // if (st[n]=="") --n;

    // fla=0;
    return check(s);
}

bool Solution::check(string s) {
    int i,j,k;
    bool f[22][22];
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(i=0;i<=(int)s.length();++i) {
        for (j=1;j<=n;++j){
            if ((int)st[j].length()==1) {
                if (i && (s[i-1]==st[j][0] || st[j][0]=='.')) 
                    f[i][j]|=f[i-1][j-1];
            } else {
                f[i][j]|=f[i][j-1];
                for (k=i;k>0;k--) {
                    if (st[j][0]!='.' && s[k-1]!=st[j][0]) break;
                    f[i][j]|=f[k-1][j-1];
                }
            }
        }
    }
    return f[(int)s.length()][n];
}
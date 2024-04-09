#include "solution10.h"

bool Solution::isMatch(string s, string p) 
{
    // s="cabddab",p=".ab*";
    n=0;
    st[n]="";
    for (int i=0;i<(int)p.length();++i) {
        st[n]+=p[i];
        if (p[i+1]=='*') st[++n]="";
    }
    if (st[n]=="") --n;

    fla=0;
    return check(s,0,0);
}

bool Solution::check(string s,int poi1,int poi2) {
    if (fla) return 1;
    if (poi2==n+1) {
        if (st[n]!="*" && poi1!=(int)s.length()) 
            return 0;

        fla=1;
        return 1;
    }
    
    int i,j;
    if (st[poi2]=="*") {
        check(s,poi1,poi2+1);
    }
    else if (st[poi2][0]=='*') {
        for (i=poi1;i<(int)s.length()-(int)st[poi2].length()+2;++i) {
            for (j=1;j<(int)st[poi2].length();++j) {
                if (s[i+j-1]!=st[poi2][j] && st[poi2][j]!='.') {
                    break;
                } else if (j==(int)st[poi2].length()-1) {
                    check(s,i+j,poi2+1);
                }
            }
        }
    } else {
        i=poi1;
        for (j=0;j<(int)st[poi2].length();++j) {
            if (s[i+j]!=st[poi2][j] && st[poi2][j]!='.') {
                break;
            } else if (j==(int)st[poi2].length()-1) {
                check(s,i+j+1,poi2+1);
            }
        }
    }
    if (!fla) return 0;
    return 1;
}
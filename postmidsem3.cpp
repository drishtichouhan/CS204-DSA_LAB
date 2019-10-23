#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

const long long N = 1e6 + 5005;
long mat[N];
long long res[N];

long long find(long long a ) 
{
    if (a == mat[a])
        return a;
    return mat[a] = find(mat[a]);
}

void make(long long a) 
{
    mat[a] = a;
    res[a] = 1;
}

void union_sets(long long x, long long y) 
{
    x = find(x);
    y = find(y);
    if (x != y) 
    {
        if (res[x] < res[y])
            swap(x,y);
        mat[y] = x;
        res[x] += res[y];
    }
}
long long  rows,cols;
long long index(long long i,long long j)
{
    return  i+(j*rows);
}

bool compare(pair<long long,long long > x ,pair<long long,long long > y)
{
    if(x.second==y.second)
    {
        return x.first<y.first;
    }
    else
    {
        return x.second<y.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    long  x,y,z,p,q,r,k;
    long long a,b,c;
    cin>>rows>>cols;
    cin>>k;
    vector <pair<long long ,long long >> v;
    for(long long i=0;i<k;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
        make(index(x,y));
    }
    sort(v.begin(),v.end());
    for(long long i=0;i<(k-1);i++)
    {
        if(v[i].first==v[i+1].first&&((v[i].second+1)==v[i+1].second))
        {
            union_sets(index(v[i].first,v[i].second),index(v[i+1].first,v[i+1].second));
        }
    }
    sort(v.begin(),v.end(),compare);
    for(long long i=0;i<(k-1);i++)
    {
        if(((v[i].first+1)==v[i+1].first)&&(v[i].second==v[i+1].second))
        {
            union_sets(index(v[i].first,v[i].second),index(v[i+1].first,v[i+1].second));
        }
    }
    long long maximum=-1;
    for(long long i=0;i<k;i++)
    {
        long long j=find(index(v[i].first,v[i].second));
        maximum=max(maximum,res[j]);
    }
    cout<<maximum<<endl;
    return 0;
}
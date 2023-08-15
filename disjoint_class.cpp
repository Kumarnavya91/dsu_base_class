#include<bits/stdc++.h>
using namespace std;
class dsu
{
  vector<int> rank,parent;
  public:
  dsu(int n)
  {
    rank.resize(n+1);
    parent.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
  }
  int find_parent(int u)
  {
    if(parent[u]==u) return u;
    return parent[u]=find_parent(parent[u]); // with pathCompression
  }
  void unionByRank(int u,int v)
  {
    int pu=find_parent(u);
    int pv=find_parent(v);
    if(pu==pv) return ;
    else
    {
        int r1=rank[pu];
        int r2=rank[pv];
        if(r1>r2)
        {
           parent[pv]=pu; 
        }
        else if(r2>r1)
        {
           parent[pu]=pv;
        }
        else
        {
           parent[pv]=pu;
           rank[pu]++;
        }
  }
  }
};
int main()
{
    dsu ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // if 3 and 7 are same or not
    
    // done
    ds.unionByRank(3,7);
    if(ds.find_parent(3)==ds.find_parent(7)) cout<<"same"<<endl;
    else cout<<"Not same"<<endl;
}
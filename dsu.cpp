#include<bits/stdc++.h>
using namespace std;
class DSU
{
   public:
   vector<int> parent;
   DSU(int n)
   {
      parent=vector<int>(n+1,0);
      for(int i=1;i<=n;i++)
      {
        parent[i]=i;
      }

   }
   int findRoot(int x)
   {
        while(x!=parent[x])
        {
            x=parent[x];
        }
        return x;
   }
   void combine(int u,int v){
     int rx=findRoot(u);
     int ry=findRoot(v);
     if(rx==ry) return ;
     else parent[ry]=rx;
   }
};
int main()
{
  int n,q;
  cin>>n>>q;
  DSU dsu(n);
  while(q--)
  {

  }

 return 0;
}
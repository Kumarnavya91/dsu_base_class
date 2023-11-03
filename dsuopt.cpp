#include<bits/stdc++.h>
using namespace std;
class DSU
{
    public:
    vector<int>parent;
    vector<int> subtreeSize;
    int n;
    DSU(int n)
    {
        this->n=n;
        parent=vector<int>(n+1);
        subtreeSize=vector<int>(n+1,1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        
    }
    int find_parent(int x)
    {
        if(x==parent[x]) return x;
        return parent[x]=find_parent(parent[x]);
    }
    void  combine(int u,int v)
    {
        int ru=find_parent(u);
        int rv=find_parent(v);
        if(ru==rv) return ;
        if(subtreeSize[ru]>subtreeSize[rv])
        {
            parent[rv]=ru;
            subtreeSize[ru]=subtreeSize[ru]+subtreeSize[rv];
        }
        else 
        {
            parent[ru]=rv;
            subtreeSize[rv]=subtreeSize[ru]+subtreeSize[rv];
        }
        
     }

};
int main()
{
    DSU ds(7);
    ds.combine(1,2);
    ds.combine(2,3);
    ds.combine(4,5);
    ds.combine(6,7);
    ds.combine(5,6);
    if(ds.find_parent(3)==ds.find_parent(7)) cout<<"same"<<endl;
    else cout<<"Not same"<<endl;
    cout<<"This can be used as a sample for dsu"<<endl;
    return 0;
}
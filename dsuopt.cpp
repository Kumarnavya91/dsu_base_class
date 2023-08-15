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

        while(parent[x]!=x)
        {
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return x;
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
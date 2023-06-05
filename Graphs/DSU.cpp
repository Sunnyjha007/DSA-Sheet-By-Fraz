#include<bits/stdc++.h>
using namespace std;
class DisjointSetUnion{
    vector<int> rank,parent,size;
    public:
    DisjointSetUnion(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]= i;
            size[i]= i;
        }    
    }
    int findUltimateParent(int node){
        if(node==parent[node])return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void findUnionByRank(int node1,int node2){
        int ulp1 = findUltimateParent(node1);
        int ulp2 = findUltimateParent(node2);
        if(ulp1==ulp2)return;
        if(rank[ulp1]<rank[ulp2]){
            parent[ulp1] = ulp2;
        }else if(rank[ulp1]>rank[ulp2]){
            parent[ulp2] = ulp1;
        }else{
            parent[ulp2] = ulp1;
            rank[ulp1]++;
        }
    }
    void findUnionBySize(int node1,int node2){
        int ulp1 = findUltimateParent(node1);
        int ulp2 = findUltimateParent(node2);
        if(ulp1==ulp2)return;
        if(size[ulp1]<size[ulp2]){
            parent[ulp1] = ulp2;
            size[ulp2]+= size[ulp1];
        }else{
            parent[ulp2] = ulp1;
            size[ulp1]+= size[ulp2];
        }
    }
};
int main(){
    DisjointSetUnion ds1(7);
    // ds1.findUnionByRank(1,2);
    // ds1.findUnionByRank(2,3);
    // ds1.findUnionByRank(4,5);
    // ds1.findUnionByRank(6,7);
    // ds1.findUnionByRank(5,6);
    ds1.findUnionBySize(1,2);
    ds1.findUnionBySize(2,3);
    ds1.findUnionBySize(4,5);
    ds1.findUnionBySize(6,7);
    ds1.findUnionBySize(5,6);
    if(ds1.findUltimateParent(3)!=ds1.findUltimateParent(7)){
        cout<<"not same parent"<<endl;
    }else cout<<"same parent"<<endl;
    ds1.findUnionBySize(3,7);
    if(ds1.findUltimateParent(3)==ds1.findUltimateParent(7)){
        cout<<"same parent"<<endl;
    }else cout<<"not same parent"<<endl;
}

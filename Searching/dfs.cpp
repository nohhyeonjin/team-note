#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int v,e,s;  //vertex수, edge수, start vertex

//인접행렬ver
int graphM[MAX][MAX];
int visitedM[MAX];
void dfs_matrix(int x){
    visitedM[x]=1;
    for(int i=1;i<=v;i++){
        if(graphM[x][i]==1&&visitedM[i]==0) dfs_matrix(i);
    }
}

//인접리스트ver
vector<int> graphL[MAX];
int visitedL[MAX];
void dfs_list(int x){
    visitedL[x]=1;
    for(int i=0;i<graphL[x].size();i++){
        if(visitedL[graphL[x][i]]==0) dfs_list(graphL[x][i]);
    }
}
int main(){
    scanf("%d %d %d",&v,&e,&s);

    //인접행렬 초기화
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graphM[v1][v2]=graphM[v2][v1]=1;    //무방향그래프
    }
    dfs_matrix(s);
    
    //인접리스트 초기화
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graphL[v1].push_back(v2);   //무방향그래프
        graphL[v2].push_back(v1);
    }
    dfs_list(s);
}
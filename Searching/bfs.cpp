#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int v,e,s;  //vertex수, edge수, start vertex

//인접행렬ver
int graphM[MAX][MAX];
int visitedM[MAX];
void bfs_matrix(int x){
    queue<int> q;
    q.push(x);
    visitedM[x]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=1;i<=v;i++){
            if(graphM[cur][i]==1&&visitedM[i]==0){
                q.push(i);
                visitedM[i]=1;
            }
        }
    }
}

//인접리스트ver
vector<int> graphL[MAX];
int visitedL[MAX];
void bfs_list(int x){
    queue<int> q;
    q.push(x);
    visitedL[x]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<graphL[cur].size();i++){
            if(visitedL[cur]==0){
                q.push(graphL[cur][i]);
                visitedL[graphL[cur][i]]=1;
            }
        }
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
    bfs_matrix(s);
    
    //인접리스트 초기화
    for(int i=0;i<e;i++){
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graphL[v1].push_back(v2);   //무방향그래프
        graphL[v2].push_back(v1);
    }
    bfs_list(s);
}
#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int dy[4]={-1, 1, 0, 0};    //상하좌우
int dx[4]={0, 0, -1, 1};
int space[MAX][MAX], visited[MAX][MAX];
void dfs(int y, int x){
    visited[y][x]=1;
    int ny,nx;
    for(int i=0;i<4;i++){
        ny=y+dy[i];
        nx=x+dx[i];
        if(space[ny][nx]==1&&visited[ny][nx]==0) dfs(ny,nx);
    }
}
int main(){
    for(int i=1;i<=MAX;i++){
        for(int j=1;j<=MAX;j++) scanf("%d",&space[i][j]);
    }
    int component=0;
    for(int i=1;i<=MAX;i++){
        for(int j=1;j<=MAX;j++){
            if(space[i][j]==1&&visited[i][j]==0){
                component++;
                dfs(i,j);
            }
        }
    }
    printf("%d",component);
}
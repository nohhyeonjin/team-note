#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int n;
int arr[MAX];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++) arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==0) continue;
        for(int j=i*2;j<=n;j+=i) arr[j]=0;
    }
    for(int i=2;i<=n;i++) if(arr[i]!=0) printf("%d ",i);
}

//구간합 빠르게 계산하기
#include <bits/stdc++.h>
using namespace std;
int n=5;
int arr[5]={10,20,30,40,50};
int prefixSum[6];   //n+1
int main(){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        prefixSum[i+1]=sum;
    }
    int left,right;
    scanf("%d %d",&left,&right);
    printf("%d",prefixSum[right]-prefixSum[left-1]);
}
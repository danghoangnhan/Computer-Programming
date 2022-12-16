#include <iostream>
#include <cmath>

using namespace std;
long long int a[100000];
long long int dp[1000001];
//long long int dp2[1000001];
/*long long int dp(long long int current,long long int length){
if(current==length-2){
    return abs(a[length-1]-a[length-2]);
}
if(current==length-3){
    long long int numb1=abs(a[length-1]-a[length-3]);
    long long int numb2=abs(a[length-1]-a[length-2])+abs(a[length-2]-a[length-3]);

    if(numb1<numb2){
        return numb1;
    }
    else
       return numb2;
}
else{
    long long int numb1=dp(current+1,length);
    long long int numb2=dp(current+2,length);
    if(numb1<numb2){
        return abs(a[current+1]-a[current])+numb1;
    }
    else{
        return abs(a[current+2]-a[current])+numb2;
    }
}

}*/

int main()
{
    long long int length;
    cin >> length ;
    for(long long int i=0;i<length;i++){
        cin >>a[i];
    }
     dp[0]=0;
     for(int i=2;i<length;i++){
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i+1] - a[i]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(a[i+2] - a[i]));
     }
     cout<<dp[length-1]<<endl;

    //cout<<dp(0,length)<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
   
    int k; cin>>k;
    int a[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
    	a[0][i]=0;
    	a[i][0]=0;
    }
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    //initiallizing dp as summ of matrix starting at (1,1) and ending at (i,j)
    for(int i=0;i<=n;i++)
    {
    	dp[0][i]=0;
    	dp[i][0]=0;
    }

    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		dp[i][j]= dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+a[i][j];
		}
	}

    int s=1,e=n+1;
  
    while(s<e){
       
        int m=(s+e)/2;
       
        bool flag=0;
       
        for(int i=m;i<=n;i++){
            for(int j=m;j<=n;j++){
                if((dp[i][j]-dp[i-m][j]-dp[i][j-m])>=k) flag=1;
            }
        }
        if(flag){ s=m; break;}
        else e=m;
    }
    cout<<s<<endl;
    return 0;
}
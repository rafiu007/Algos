/*
 * AUTHOR:RAFIU JAMAN MOLLAH
 * CODECHEF HANDLE:portgas_d_raf
 * the code below is the implementation of matrix chain multiplication
 * from the methog given in CLRS
 */
 #include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
void magic(int ar[],int n)
{
	//int dp[n][n];
	int i,j,k,l,temp;
	
	for(i=1;i<n;i++)
	{
		dp[i][i]=0;
	}
	
	for(l=2;l<n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			dp[i][j]=INT_MAX;
			for(k=i;k<j;k++)
			{
				temp=dp[i][k]+dp[k+1][j]+(ar[i-1]*ar[k]*ar[j]);
				if(temp<dp[i][j])
				{
					dp[i][j]=temp;
				}
			}
		}
	}
	cout<<dp[1][n-1]<<endl;
	return;
}
			
int main()
{
	int ar[1000];
	int n,i,j;
	while(1)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		magic(ar,n);
	/*	for(i=0;i<n+1;i++)
		{
			for(j=0;j<n+1;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		*
		* printing the dp in case you need it
	    */
	}
	return 0;
}
		

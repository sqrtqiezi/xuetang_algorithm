#include<climits>
#include <cstdio>
#include <algorithm>
#define maxn 3100
#define min(a,b) ((a)>(b)?(b):(a))
using namespace std;


int f[maxn][maxn][2];
int a[maxn],n,x;

int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		f[i][i][0]=f[i][i][1]=abs(a[i]-x)*n;
	}
	for(int len=2;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			f[i][j][0]=f[i][j][1]=INT_MAX;
			f[i][j][0]=min(f[i][j][0],f[i+1][j][0]+(n-(j-i))*(a[i+1]-a[i]));
			f[i][j][0]=min(f[i][j][0],f[i+1][j][1]+(n-(j-i))*(a[j]-a[i]));
			f[i][j][1]=min(f[i][j][1],f[i][j-1][0]+(n-(j-i))*(a[j]-a[i]));
			f[i][j][1]=min(f[i][j][1],f[i][j-1][1]+(n-(j-i))*(a[j]-a[j-1]));
		}
	}
	printf("%d\n",min(f[1][n][0],f[1][n][1]));
}

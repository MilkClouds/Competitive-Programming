#include<stdio.h>
int f[200010],g[200010],s[200010];
int main() {
	int n,i,p,near1=-1,near2=-1;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		scanf("%d",&s[i]);
	f[1]=g[1]=1;
	for(i=2; i<=n; i++) {
		p=0,f[i]=f[i-1];
		if(s[i-1]==s[i])
			near1=i;
		if(i>2&&s[i-2]!=s[i])
			near2=i-2;
		else if(s[i]!=s[i-1]&&s[i-2]!=s[i-1])
			f[i]=(f[i]+f[i-2])%998244353,p=1;
		if(near1==-1&&near2==-1&&p==0)
			f[i]=(f[i]+f[i-2])%998244353;
		if(near1==-1&&near2!=-1)
			f[i]=(f[i]+g[near2])%998244353;
		if(near1!=-1&&near2!=-1&&near1<=near2)
			f[i]=(f[i]+(g[near2]-g[near1-1]+998244353)%998244353)%998244353;
		g[i]=(g[i-1]+f[i])%998244353;
	}
	printf("%d\n",f[n]);
	return 0;
}

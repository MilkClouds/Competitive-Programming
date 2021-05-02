#include <bits/stdc++.h>
using namespace std;
int n;
struct node{int v,l,r;};
node nodes[1000000];
int insert(int n,node& nod){
	if(nod.v>n){
		if(nod.l) insert(n,nodes[nod.l]);
		else nod.l=n;
	}
	else{
		if(nod.r) insert(n,nodes[nod.r]);
		else nod.r=n;
	}
}
void postorder(node nod){
    if(nod.l)postorder(nodes[nod.l]);
    if(nod.r)postorder(nodes[nod.r]);
    printf("%d\n",nod.v);
}
int main(){
    for(int i=0;i<1000000;i++)nodes[i].v=i;
    int root;
    scanf("%d",&root);
    if(!root)return 0;
	while(~scanf("%d",&n)){
		insert(n,nodes[root]);
	}
	postorder(nodes[root]);
}
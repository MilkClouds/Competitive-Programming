#include <stdio.h>
#include <string.h>
char word[1000005];
int main()
{
	char w;
	int i, m=0, k=0, l;
	int a[26];
	scanf("%s", word);
	for(i=0; i<26; i++){
		a[i]=0;
		}
    l=strlen(word);
	for(i=0; i<l; i++)
	{
		if(word[i]<97)
			a[word[i]-65]++;
		if(word[i]>=97)
			a[word[i]-97]++;
	}
	for(i=0; i<26; i++)
	{
		if(m<a[i]){
			m=a[i];
			w=i; }
	}
	for(i=0; i<26; i++)
	{
		if(m==a[i])
			k++;
	}
    w+=65;
	if(k>1)
		printf("?");
	else
		printf("%c", w);
	return 0;
}
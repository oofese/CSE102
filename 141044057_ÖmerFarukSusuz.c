#include <stdio.h>
void fonk(char *arr,int k);
int main()
{
	FILE *fp;
	char a[100];
	int i=0,k=0,j;
	fp=fopen("input.txt","r");
	while(fscanf(fp, "%c", &a[i]) !=EOF )
	{
        i++;
	}
	for(j=0;j<i;j++){
        printf("%c",a[j]);
	}
	printf("\n");
	fonk(a,k);
}
void fonk(char *arr,int k)
{
    int i;

	if(arr[0]=='\0')
	{
		return;
	}
	else if(arr[0]=='(')
		{
		k=k+1;
		fonk(arr+1,k);
	}
	else if(arr[0]==')')
	{
		k=k-1;
		fonk(arr+1,k--);

	}
	else if(arr[0]==','){
        fonk(arr+1,k);
	}
	if(arr[0]!=')' && arr[0]!='(' && arr[0]!=',' )
	{
		for(i=0; i<k; ++i)
		{
			printf("-");
		}
		printf("%c\n",arr[0]);
		fonk(arr+1,k);
	}


}

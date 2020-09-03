//ÖMER FARUK SUSUZ-141044057

#include <stdio.h> 
	int main()
	{
		int a,i,j,n,k,m,r,u,v;
		
		printf("Sayi giriniz :");
		scanf("%d",&a);
		n=a;
		m=1;
		r=a;
		v=1;
		
		
		for(i=0; i<(a+1)/2; i++)
		{
			for(k=0;k<(n-1)/2; k++)
			{
				printf(" ");
			}
			
			for(j=0; j<m; j++)
			{
				printf("*");
				
			}
			n=n-2;
			m=m+2;
			
			printf("\n");
		}
		for(u=0; u<(a-((a+1)/2)); u++)
		{
				for(k=0; k<v; k++)
			{
				printf(" ");
			}
			for(j=0; j<r-2; j++)
			{
				printf("*");
				
			}
			r=r-2;
			v=v+1;
			printf("\n");
			
		}
		
		return 0; 
	}

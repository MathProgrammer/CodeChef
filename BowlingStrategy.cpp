#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,k,l;
	    scanf("%d %d %d",&n,&k,&l);
	    if(k == 1)
	    {
	        if(n == 1)
	        {
	            printf("1\n");
	        }
	        else printf("-1\n");
	    }
	    else if(k > 1)
	    {
	        if(k*l < n)
	        {
	            printf("-1\n");
	        }
	        else 
	        {
	            int count = 0;
	            int i = 1;
	            while(count < n)
	            {
	                printf("%d ",i);
	                count++;
	                if( i == k)
	                {
	                    i = 0;
	                }
	                i++;
	            }
	            printf("\n");
	        }
	    }
	}
	return 0;
}


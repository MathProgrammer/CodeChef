#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	       scanf("%d",&arr[i]); 
	       sum += arr[i];
	    }
	   if(sum >= 0)
	   {
	       printf("YES\n");
	   }
	   else printf("NO\n");
	}
	return 0;
}


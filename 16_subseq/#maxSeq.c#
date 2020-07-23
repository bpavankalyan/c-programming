#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * arr, size_t n)
{

  if (n==0)
    return 0;
  int max=1,current=1;
  for(int i=1;i<n;i++)
    {
      if(arr[i-1]<arr[i])
	 current++;
	 else
	   current=1;
	 if(max<current)
	   max=current;
        }
  return max;
}
	

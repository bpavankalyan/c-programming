#include<stdio.h>
#include<stdlib.h>

void rotate(char rot[10][10])
{
  if(rot==NULL)
    return ;
  char rotma[10][10];
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      rotma[j][9-i]=rot[i][j];
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      rot[i][j]=rotma[i][j];  
}

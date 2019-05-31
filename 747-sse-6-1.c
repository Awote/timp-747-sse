#include <stdio.h>
#include <stdlib.h>

int find(int step) 
{ 
step = (int)(step / 1.247); 
if (step < 1) 
step = 1; 
return step; 
} 

void sort (int arr[], int N)
{
int step = N; 
while (1) 
{ 
step = find(step); 
int swap=0; 
for(int i = 0; i <N-step; i++) 
{ 
int j = i + step; 
if (arr[i] > arr[j])
{
int t= arr[i];
arr[i]=arr[j];
arr[j]=t;
swap=1;
}
}
if (step==1 && !swap)
break;
}}
int main()
{
int n ;
scanf("%d",&n);
int mass[n];
for (int i = 0;i < n; i ++)
{
scanf("%d",&mass[i]);
} 
sort(mass,n);
for (int i = 0 ;i <n;i++ )
{printf("%d ",(mass[i]));}
printf("\n");
}

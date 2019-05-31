#include<stdio.h>
void sorting_function(int *arr, int N)
{
int i, j, k, t ;
for (k=N/2;k>0; k=k/2)
{
for (i=k; i<N; i++)
{
for(j=i-k; j>=0; j=j-k)
{
if (arr[j+k] >= arr[j])
break;
else
{
t=arr[j];
arr[j]=arr[j+k];
arr[j+k]=t;
}
}
}
}
}
int main ()
{int n ;
scanf("%d",&n);
int mass[n];
for (int i =0 ;i<n;i++)
scanf("%d",&mass[i]);
sorting_function(mass,n);
int i =0;
while(n)
{
printf("%d ",mass[i]);
i++;
if(i ==n)break;
}
printf("\n");}

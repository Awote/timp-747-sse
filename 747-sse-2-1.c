#include <stdio.h>
int main (void )
{
int enter_num = 0,count_of_num = 0,rez = 0;
scanf("%d", &count_of_num);
for(int i =0;i<count_of_num;i++)
{
scanf("%d", &enter_num);
if (enter_num >= 0 ) rez++;
}
printf("%d\n", rez);
}

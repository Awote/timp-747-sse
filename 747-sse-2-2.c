#include <stdio.h>
int main(void)
{
    int n = 0,x = 0,y = 0,rez =-1,enter_num = 0;
    scanf("%d", &n);
    scanf("%d",&y);
    for (int i=1;i<n;i++)
        {
scanf("%d",&enter_num);
        if ((i%2)==1 && rez != 0)  
             {
             x = enter_num; if (y>=x) rez = 1; else rez = 0;
             }
        if ((i%2)==0 && rez != 0){y=enter_num; if(x>=y) rez = 1; else rez=0 ; 
             }

}
printf("%d",rez);
}

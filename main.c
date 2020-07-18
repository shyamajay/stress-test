#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int fib(int n)
{
    long long int a=0,b=1;
    long long int c=0;
    while(n>=0)
    {
        c=a+b;
        a=b;
        b=c;
        n--;
    }
    return c;
}


int fib_fast(int n)
{
    int *a;
    long long int d;
    a = (int*)malloc(sizeof(int)*(n+2));
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n+2;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    d = (long long)a[n+2];
    return d;
}

int main()
{
    while(true)
    {
        long int n;
        n = rand()%1000 + 2;
        printf("%ld\n",n);
        long long int res = fib(n);
        long long int res1 = fib_fast(n);
        printf("%lld %lld\n",res,res1);
        if(res != res1)
        {
            printf("wrong\n");
            break;
        }
        else
            printf("ok\n");
    }

}

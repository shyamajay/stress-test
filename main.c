#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int fib_fast(int n)
{
    int *a;
    long long int d;
    a = (int*)malloc(sizeof(int)*(n));
    a[0]=0;
    a[1]=1;
    for(int i=2;i<n;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    d = (long long)a[n-1];
    return d;
}
int fib(int n)
{
    int a = -1,b = 1;
    long long int c;

        while(n>0)
        {
            c = a+b;
            a = b;
            b = c;
            n--;
        }
        return c;

}

int main()
{
    while(true)
    {
        long int n;
        n = rand()%10 + 2;
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

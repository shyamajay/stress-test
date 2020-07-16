/*
This code is an example  of stress test in which I have used to test my code by
auto generating inputs for product of max elements of an array.For stress test we
have to take two methods to solve the same problem and then we have to compare the results.
*/

#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int sum(int *a,long int k)
{
    int j = 0,i = 0;
    long long int s = 0;

    for(i = 0;i < k;i++)
    {
        for(j = i+1;j < k;j++)
        {
            if(a[i]*a[j] > s)
            {
                s = a[i]*a[j];
            }
        }
    }

    return s;
}

int sum_fast(int *a,long int k)
{
    int j = 0,index = -1;;

    for(j = 0;j < k;j++)
    {
        if(index == -1 || a[j] > a[index])
        {
            index = j;
        }
    }

    int index1 = -1;

    for(j = 0;j < k;j++)
    {
        if(j != index && (index1 == -1 || a[j] > a[index1]))
        {
            index1 = j;
        }
    }

    long long int m = a[index]*a[index1];
    return m;
}

/*
The main function is the one which generates input automatically and
remember this can be used for integers and arithmetic calculation
*/
int main()
{
    int *a;
    while(true)
    {
        long int n;
        n = rand()%10 + 2;
        printf("%ld\n",n);
        a = (int*)malloc(sizeof(int)*n);
        for(int i = 0;i < n;i++)
        {
            a[i]=(rand()%1000);
        }
         for(int i = 0;i < n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        long long int res = sum(a,n);
        long long int res1 = sum_fast(a,n);

        if(res != res1)
        {
            printf("wrong\n");
            break;
        }
        else
            printf("ok\n");
    }

    return 0;
}

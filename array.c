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
        long long int res = sum(a,n);//declare any array elements coputation
        long long int res1 = sum_fast(a,n);

        if(res != res1)
        {
            printf("wrong\n");
            break;
        }
        else
            printf("ok\n");
    }


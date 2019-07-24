#include<stdio.h>
#include<stdlib.h>
/*void merge(int *arr, int start, int mid, int end)
{
    int s = end - start + 1;
    int *temp;
    temp = (int *)malloc(s * sizeof(int *));
    int l, r;
    int k = 0;
    for(l=start,r=mid+1; l<=mid, r<end;)
    {
        if (arr[l] < arr[r])
        {
            temp[k] = arr[l];
            l++;
            k++;
        }
        else if(arr[r] <= arr[l])
        {
            temp[k] = arr[r];
            r++;
            k++;
        }
    }
    if (l<=mid)
    {
        while(l<=mid)
        {
            temp[k] = arr[l];
            l++;
            k++;
        }
    }
    if (r<end)
    {
        while(r<end)
        {
            temp[k] = arr[r];
            k++;
            r++;
        }
    }
    k = 0;
    for(l=start; l<end; l++, k++)
    {
        arr[l] = temp[k];
    }
}

void mergesort(int *arr, int start, int end)
{
    if (start < end)
    {
        int m = (start + end)/2;
        mergesort(arr, start, m);
        mergesort(arr, m+1, end);
        merge(arr, start, m, end);
    }
}*/


void main()
{
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(n * sizeof(int *));
    int i=0;
    int max = 0;
    printf("Enter values\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    /*mergesort(arr, 0, n);*/
    int *count;
    count = (int *)malloc((max+1) * sizeof(int *));
    for(i=0; i<=max; i++)
    {
        count[i] = 0;
    }
    int max_f = 0;
    for(i=0; i<n; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] > max_f)
            max_f = count[arr[i]];
    }
    int k = 0;
    int j, l;
    for(i=1; i<=max_f; i++)
    {
        for(j=0; j<=max; j++)
        {
            if(count[j] == i)
            {
                for(l=0; l<i; l++)
                {
                    arr[k] = j;
                    k++;
                }
            }
        }
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
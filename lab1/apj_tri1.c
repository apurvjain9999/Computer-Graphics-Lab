#include<stdio.h>
#include<stdlib.h>
struct point
{
    float x;
    float y;
};

void main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    struct point *p;
    p = (struct point*)malloc(n*sizeof(struct point *));
    int i = 0;

    for(i=0;i<n;i++)
    {
        printf("Enter x coordinate of point %d :", i+1);
        scanf("%f", &p[i].x);
        printf("Enter y coordinate of point %d :", i+1);
        scanf("%f", &p[i].y);
        printf("\n");
    }

    float area = 0.0;
    int count = 0;
    int j,k;
    for(i=0; i<n-2; i++)
    {
        
        for(j=i+1; j<n-1; j++)
        {
            
            for(k=j+1; k<n; k++)
            {
                
                area = 0.5 * ((p[i].x * (p[j].y - p[k].y)) - (p[i].y * (p[j].x - p[k].x)) + (1 * ((p[j].x * p[k].y) - (p[k].x * p[j].y))));
                //printf("%d\n", area);
                if (area != 0)
                {
                    count++;
                }
            }
        }
    }

    printf("\nNumber of triangles possible are: %d\n", count);


}
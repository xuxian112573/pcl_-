#include <stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp = fopen("/home/xu/Desktop/pcl_ws/play_1/1.txt", "r");
    if (fp == NULL)
    {
        printf("file open error\n");
        return -1;
    }

    double xx[3];
    double yy[3];
    double zz[3];

    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%lf,%lf,%lf", &xx[i], &yy[i], &zz[i]);
        printf("%lf,%lf,%lf\n", xx[i], yy[i], zz[i]);
    }
    fclose(fp);
    system("pause");
    return 0;
}
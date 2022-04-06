#include <stdio.h>
int main()
{
    int w, i, a[365], b[365], c[365], week;
    scanf("%d", &w);
    for (i = 0; i < 365; i++) {
        a[i] = i + 1;//every day has a number from 1 to 365
        week = a[i] % 7 + w - 1;
        if (week == 0)
            b[i] = 7;
        else if (0 < week < 7)
            b[i] = week;
        else b[i] = week - 7;
        if (b[i] > 7)
            b[i] = b[i] - 7;
        if (b[i] == 5)
            c[i] = a[i];
        else c[i] = 10000;
    }
    for (i = 0; i < 365; i++) {
        if (c[i] == 13)
            printf("1\n");
        else if (c[i] == 31 + 13)
            printf("2\n");
        else if (c[i] == 31 + 28 + 13)
            printf("3\n");
        else if (c[i] == 31 + 28 + 31 + 13)
            printf("4\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 13)
            printf("5\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 13)
            printf("6\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 13)
            printf("7\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 31 + 13)
            printf("8\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 13)
            printf("9\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 13)
            printf("10\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 13)
            printf("11\n");
        else if (c[i] == 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 13)
            printf("12");
        else continue;
    }
    return 0;
}

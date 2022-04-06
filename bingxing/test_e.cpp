#include<cstdio>
#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{   /*计算10000位e(含整数2)*/

    long a=0,b=0,i=0,j=0,N=205,e[10005],c[10005];
    long k=0;

    clock_t start = clock();
    #pragma omp parallel for num_threads(8)
    for(*c=1; k<N; ){
        i++;
        j=k-1;
        for(b=0; j<N; ){
            a=b*10+c[j];
            c[j]=a/i;
            b=a%i;
            e[j]+=c[j];
            //printf("c[%d] = %d ",j,c[j]);
            j++;

        }
        //printf("\n");
        if(c[k]==0)
            ++k;
    }
    for(; --j; e[j] %= 10)
        e[j-1] += e[j] / 10;
    for(printf("2.");++j<N-5;){
        printf("%ld",e[j]);
    }
    clock_t end   = clock();
    cout << endl << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    return 0;
}
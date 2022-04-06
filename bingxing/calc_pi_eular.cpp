#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;

/**
 * @brief 用数组存储两个整型数据相除结果
 * @param result[]	结果保存数组
 * @param y			被除数
 * @param x			除数
 * @param n			结果位数
 * @return none
 */
void calc_div(int result[], int y, int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		result[i] = y / x;
		y = y % x;
		y *= 10;
	}
}
/**
 * @brief 实现两个数组的加法
 * @param b			加数1，以及结果保存数组
 * @param a			加数2
 * @param n			结果位数
 * @return none
 */
void calc_add(int b[], int a[], int n)
{
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = a[i] + b[i] + carry;
		carry = b[i] / 10;
		b[i] %= 10;
	}
}
/**
 * @brief 实现两个数组的减法
 * @param b			被减数，以及结果保存数组
 * @param a			减数
 * @param n			结果位数
 * @return none
 */
void calc_sub(int b[], int a[], int n)
{
	int carry = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = b[i] - a[i] - carry;
		carry = b[i] < 0;
		b[i] = carry ? (10 + b[i]) : b[i];
	}
}

/**
 * @brief 实现两个数组的乘法
 * @param a			乘数1，以及结果保存数组
 * @param b			乘数2
 * @param n			结果位数
 * @return none
 */
void calc_multi(int a[], int b[], int n)
{
	int* result = new int[2 * n]{ 0 };
	
	for (int i = 0; i < n; i++)
	{
		int* c = new int[2 * n]{ 0 };
		for (int j = 0; j < n; j++)
		{
			c[i + j] = a[i] * b[j];
		}
		calc_add(result, c, n + n / 10);
		delete[] c;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = result[i];
	}
	
	delete[] result;
}


#include <omp.h>


const int N = 100;			// pi的精确位数
const int TIMES = 100;		// 算法迭代次数
int b[TIMES][N] = { {0} };	// 存放bk项

int main()
{
	clock_t startTime = clock();
	
	int result[N] = { 0 }; // 存放最终结果

	int const TDN = 4;	// 处理器数量
	int x[N] = { 0 };	// 存放1/2的m次方
	int y[N] = { 0 };	// 存放1/3的m次方
	int(*x1)[N] = new int[TDN][N]{ {0} }; // 存放1/2的2k-1次方
	int(*y1)[N] = new int[TDN][N]{ {0} }; // 存放1/3的2k-1次方

	// 计算1/2的m次方
	calc_div(x, 1, (int)pow(2, 2 * TDN), N);
	// 计算1/3的m次方
	calc_div(y, 1, (int)pow(3, 2 * TDN), N);
	// 计算1/2、1/3的n次方
	for (int k = 0; k < TDN; k++) {
		calc_div(x1[k], 1, (int)pow(2, 2 * k + 1), N);
		calc_div(y1[k], 1, (int)pow(3, 2 * k + 1), N);
	}
    int factorial[TIMES][N] = {{0}};
    int div_factorial[TIMES][N] = {{0}};
    for(auto i = 0; i < TIMES; i++){
        factorial[i][0] = 1;

    }


#pragma omp parallel for num_threads(TDN)

	for (int p = 0; p < TDN; p++) {
        for(auto i = 0; i < p*TIMES/TDN; i++)
            calc_multi(factorial[1+p*TIMES/TDN], )
		for (int i = 0; i < TIMES / TDN; i++) {
			cal
		}
	}
	// 将最终结果相加/减
	for (int i = 0; i < TIMES; i++) {
		if (i % 2 == 1)
			calc_sub(result, b[i], N);
		else
			calc_add(result, b[i], N);
	}	
	printf("The run time is: %.3fs\n", (clock() - (int)startTime) / 1000.0);
	
	// 打印pi
	printf("%d.", result[0]);
	for (int i = 1; i < N; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	delete[] x1;
	delete[] y1;
}
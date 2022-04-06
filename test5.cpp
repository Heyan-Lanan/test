#include <iostream>
#include<string>
using namespace std;

int main()
{
    int num, max;
    cin >> num;
    max = 0;
    string *numofnum = new string[num];
    int shuzu[10006] = { 0 };
    for (int i = 0; i < num; i++)
    {
        cin >> numofnum[i];
        for (int j = 0; j<numofnum[i].length(); j++)
        {
            shuzu[i]++;
            if (numofnum[i][j] == '.')
            {
                if (j >= max)
                    max =j+1;//自己设置的陷阱，原先的程序是j>max。因为底下的max不是等于j而是等于j+1因此，用j>max是错误的。只能>=
                break;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = max - shuzu[i]; j > 0; j--)
        {
            cout << " ";
        }
        cout << numofnum[i] << endl;
    }

}
#include<stdio.h>
#include<math.h>

int main(){
    char eight[20];
    double sum;
    int i;

    while( scanf("%s",eight) != EOF ){
        sum = 0.0;
        for( i = 2 ; eight[i] != '\0' ; i++ ){
            sum += (eight[i] - '0') * pow(0.125 , i-1);
        }

        printf("%0.45g",sum);
    }

    return 0;
}
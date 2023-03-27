#include <stdio.h>
sum(int, int);
int main(){
    int n, m;
    printf("input two integer : ");
    scanf(" %d %d", &n, &m);
    printf("%d + %d = %d\n", n, m, sum(n,m));
    
}

int sum(int a, int b){
    int s = a+b;
    return s;
}
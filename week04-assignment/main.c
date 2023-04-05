#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0;
    double sum, avg;
    printf("과목 수 : ");
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        char ch[3] = {0,};
        printf("과목%d 학점 : ", i+1);
        scanf(" %s", ch);
        switch (ch[0]){
            case 'A':
                sum+=4.0;
                break;
            case 'B':
                sum+=3.0;
                break;
            case 'C':
                sum+=2.0;
                break;
            case 'D':
                sum+=1.0;
                break;
            case 'F':
                break;
            default:
                i--;
                printf("try again.\n");
                break;
        }
        
        if(ch[1] == '+' && ch[0]<'F' && ch[0]>='A'&& ch[0]!='E'){
            sum+=0.5;
        }
    }
    printf("학점 총합 : %.3lf\n", sum);
    printf("학점 평균 : %.3lf\n", sum/n);

}
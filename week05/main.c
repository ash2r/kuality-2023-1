#include <stdio.h>

char name[6][20]={"코카콜라", "칠성 사이다", "실론티", "밀키스", "제로 콜라", "제로 사이다"};
int price[6]={1000, 1000, 1000, 1200, 1200, 1200};
int balance[6]={100, 100, 100, 100, 100, 100};

void menu(int);
int drink(int, int);
int change_money(int);

int main(){
    int c;
    int money=0, input_money=0;
    int drink_choice=0;

    while(1){
        menu(money);
        printf("메뉴를 선택하세요: ");
        scanf("%d", &c);

        if(c==1){
            printf("금액을 투입하세요: ");
            scanf("%d", &input_money);
            printf("%d원 투입\n\n", input_money);
            money+=input_money;
        }
        else if(c==2){
            if(money==0){
                printf("투입된 금액이 없습니다.\n\n");
                continue;
            }
            money = drink(drink_choice, money);
        }
        else if(c==3){
            if(money==0){
                printf("투입된 금액이 없습니다.\n\n");
                continue;
            }
            money = change_money(money);
        }
        else if(c==4){
            printf("종료\n");
            return 0;
        }
        else{
            printf("잘못된 입력입니다.\n\n");
            continue;
        }
    }
    
    return 0;
}

void menu(int money){
    printf("1. 금액 투입\n");
    printf("2. 음료수 선택\n");
    printf("3. 잔돈 반환\n");
    printf("4. 종료\n");
    printf("금액 : %d원\n\n", money);
}

int drink(int drink_choice, int money){
    int input_name[6]={0,};
    int i=0;
    while (1)
    {
        for(int i=0;i<sizeof(price) / sizeof(int);i++){
            printf("%d. %s\t %d원\t %d개 남음\n", i+1, name[i], price[i], balance[i]);
        }
        printf("7. 종료\n");
        printf("금액 : %d원\n\n", money);

        printf("음료를 선택하세요: ");
        scanf("%d", &drink_choice);
        printf("\n");
        if(drink_choice==7){
            printf("[[최종 영수증]]\n");
            for(int i=0;i<sizeof(price) / sizeof(int);i++){
                if(input_name[i]==0){
                    continue;
                }
                printf("%s\t %d원\t %d개 구매\n", name[i], price[i], input_name[i]);
            }
            printf("\n");
            return money;
        }
        else if(price[drink_choice-1]>money){
            printf("금액이 부족합니다.\n종료 후 금액을 더 투입해 주세요\n\n");
            continue;
        }
        else if(balance[drink_choice-1]==0){
            printf("재고가 없습니다.\n\n");
            continue;
        }
        
        else if(price[drink_choice-1]<=money && balance[drink_choice-1]>0){
            printf("%d. %s %d원\n", drink_choice, name[drink_choice-1], price[drink_choice-1]);
            money = money-price[drink_choice-1];
            balance[drink_choice-1]-=1;
            input_name[drink_choice-1]+=1;
            printf("잔돈: %d원\n\n", money);
        }
        else{
            printf("잘못된 입력입니다.\n\n");
            continue;
        }
    }
}

int change_money(int money){
    int change_money=0;
    printf("금액 : %d원\n", money);
    printf("반환 잔돈 금액: ");
    scanf("%d", &change_money);
    printf("%d원 반환\n\n", change_money);
    return money-change_money;
}
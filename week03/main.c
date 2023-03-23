#include <stdio.h>
int main(){
	int a, b, c;
	char op;

	printf("input num: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("input op: ");
	scanf(" %c", &op);

	switch (op){
	case '+':
		printf("%d + %d + %d = %d\n", a, b, c, a + b + c);
		break;
	case '-':
		printf("%d - %d - %d = %d\n", a, b, c, a - b - c);
		break;
	case '*':
		printf("%d * %d * %d = %d\n", a, b, c, a * b * c);
		break;
	case '/':
		printf("%d / %d / %d = %d\n", a, b, c, a / b / c);
		break;
	default:
		printf("error\n");
		break;
	}

	return 0;
}

## call-by-value & call-by-reference

### **call-by-value**

call-by-value는 함수 호출시 함수로 넘어가는 `인자 값`이 메모리 공간(변수)에 복사 되어 함수 내에서 변수에 직접적인 데이터 조작을 가해도 인자에 전혀 영향을 주지 않는다. 

대표적인 예시는 아래와 같다.

```c
#include <stdio.h>
int fswap(int, int);

int main(){
	int a = 10, b = 20;
	printf("before    : %d %d\n", a,b);
	fswap(a, b);
	printf("after     : %d %d\n", a,b);
}

int fswap(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
	printf("in fswap  : %d %d\n", a,b);
}
```

fswap함수에 의해서 함수 안에서는 a와 b의 값이 변했지만 call-by-value로 인자를 넘겼기 때문에 fswap함수 밖의 main함수에서는 값이 바뀌지 않는다. 

<img width="60%" alt="image" src="https://user-images.githubusercontent.com/127390688/227820642-3f7ebfc6-457f-4638-b4df-5912ee5d01a2.png">

<br>

### **call-by-reference**

call-by-value는 함수 호출시 함수로 넘어가는 `인자의 주소`가 메모리 공간(변수)에 복사 되어 함수 내에서 인자의 주소에 있는 데이터 조작을 가하면 함수 밖의 인자에 영향을 준다.

```c
#include <stdio.h>
int fswap(int*, int*);

int main(){
	int a = 10, b = 20;
	printf("before    : %d %d\n", a,b);
	fswap(&a, &b);
	printf("after     : %d %d\n", a,b);
}

int fswap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	printf("in fswap  : %d %d\n", *a,*b);
}
```

위와 같이 &를 통해서 변수의 주소값을 넘겨 주소에 저장된 값 자체를 swap하면 fswap함수 밖인 main함수에서도 변수의 값이 바뀌는 것을 알 수 있다.

<img width="60%" alt="image" src="https://user-images.githubusercontent.com/127390688/227822346-c8ebbc9e-eee1-447b-8eca-55c1f10c9387.png">
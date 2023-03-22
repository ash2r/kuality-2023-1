## scanf 취약점

`scanf` 함수는 입력값에 제한이 없기 때문에 정해진 메모리 공간보다 더 많은 양의 입력값을 넣을 수 있다. 이런 취약점을 BOF(Buffer Over Flow)라고 부른다.

```c
#include <stdio.h>
int main(){
  char buf[10];
  scanf("%s", buf);
  printf("%s\n", buf);
}
```

위 코드에서는 buf배열의 크기는 10으로 정해져 있지만 scanf는 10 이상의 입력값을 받을 수 있어 BOF 취약점이 발생할 수 있다.

<img width="70%" alt="image" src="https://user-images.githubusercontent.com/127390688/226826068-6c7246a2-4afe-4914-9d4c-8b91eb4f2229.png">

위와 같이 길이가 10 이상인 문자열을 입력해 입력값이 다른 메모리 영역을 침범하여 `stack smashing detected`가 뜬 것을 볼 수 있다.

이때 아래와 같이 scanf의 포맷스트링에 ``"%9s"`를 넣어 취약점을 방지할 수 있다.

<img width="70%" alt="image" src="https://user-images.githubusercontent.com/127390688/226826182-302b94b6-46c9-4a20-841a-09fd3dde73f1.png">

길이가 10 이상인 문자열을 넣었음에도 9글자만 입력받아 출력한 것을 볼 수 있다.

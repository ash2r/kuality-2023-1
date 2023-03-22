#include <stdio.h>

int main(){
  int n;

  while (1){
    printf("user input 0x??\n");
    scanf(" %i", &n);
    if (n >= 0x20 && n <= 80){
      printf("%#x | %d | %o = %c\n", n, n, n, n);
      break;
    } else {
      printf("User input not printable.\nThe range for input is 0x20 through 0x80.\n\n");
    }
  }

  return 0;
}

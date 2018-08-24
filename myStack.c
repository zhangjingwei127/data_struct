#include<stdio.h>

struct stack
{
  int data;
  int topIndex = -1;
}



int main()
{
  push(100);
  push(200);
  printf("Top element is (should be 200): %d\n",stackRef[topIndex]);
  pop();
  printf("Top element is (should be 100): %d\n",stackRef[topIndex]);

  return 0;
}

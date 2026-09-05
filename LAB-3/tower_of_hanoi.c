#include <stdio.h>
#include <stdbool.h>

#define MAX_DISCS 50

typedef struct {
  int discs[MAX_DISCS];
  int top;
} Stack;

void initStack(Stack *s) {
  s->top = -1;
}

bool isEmpty(Stack *s) {
  return s->top == -1;
}

void push(Stack *s, int value) {
  if (s->top < MAX_DISCS - 1) {
      s->discs[++(s->top)] = value;
  }
}

int pop(Stack *s) {
  if (!isEmpty(s)) {
      return s->discs[(s->top)--];
  }
  return -1;
}

int peek(Stack *s) {
if (!isEmpty(s)) {
      return s->discs[s->top];
  }
  return -1;
}

void moveDiscs(Stack *src, Stack *dest, char srcName, char destName) {
  if (isEmpty(src)) {
    int disc = pop(dest);
    push(src, disc);
    printf("Move disc %d from %c to %c\n", disc, destName, srcName);
  } else if (isEmpty(dest)) {
    int disc = pop(src);
    push(dest, disc);
    printf("Move disc %d from %c to %c\n", disc, srcName, destName);
  } else if (peek(src) > peek(dest)) {
    int disc = pop(dest);
    push(src, disc);
    printf("Move disc %d from %c to %c\n", disc, destName, srcName);
  } else {
    int disc = pop(src);
    push(dest, disc);
    printf("Move disc %d from %c to %c\n", disc, srcName, destName);
  }
}

void towerOfHanoiIterative(int n) {
  Stack src, aux, dest;
  initStack(&src);
  initStack(&aux);
  initStack(&dest);

  int totalMoves = (1 << n) - 1;

  for (int i = n; i >= 1; i--) {
    push(&src, i);
  }

  char sName = 'S', aName = 'A', dName = 'D';
  if (n % 2 == 0) {
    aName = 'D';
    dName = 'A';
  }

  for (int i = 1; i <= totalMoves; i++) {
      if (i % 3 == 1) {
        moveDiscs(&src, &dest, sName, dName);
      } else if (i % 3 == 2) {
        moveDiscs(&src, &aux, sName, aName);
      } else {
        moveDiscs(&aux, &dest, aName, dName);
      }
  }
}

int main() {
  int n;
  printf("Enter the number of discs: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Please enter a valid positive integer.\n");
    return 1;
  }

  towerOfHanoiIterative(n);
  return 0;
}
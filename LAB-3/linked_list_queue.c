#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = value;
  newNode->next = NULL;

  if (front == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  printf("%d inserted into queue\n", value);
}

void dequeue() {
  if (front == NULL) {
    printf("Queue Underflow\n");
    return;
  }
  struct Node *temp = front;
  printf("%d deleted from queue\n", front->data);
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }
  free(temp);
}

void peek() {
  if (front == NULL) {
    printf("Queue is empty\n");
  } else {
    printf("Front element = %d\n", front->data);
  }
}

void display() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  struct Node *temp = front;
  printf("Queue elements:\n");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, value;
  while (1) {
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value: ");
        scanf("%d", &value);
        enqueue(value);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        peek();
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
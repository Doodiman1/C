// Source: https://www.digitalocean.com/community/tutorials/queue-in-c

#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = -1;
int Front = -1;
int main(void) 
{
  int ch;
  while (1)
  {
    printf("1.Enqueue Operation\n");
    printf("2.Dequeue Operation\n");
    printf("3.Display the Queue\n");
    printf("4.Exit\n");
    printf("Enter Your Choice of Operation : ");
    scanf("%d", &ch);

    switch (ch) 
    {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        show();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Incorrect choice\n");
     }
  }
}

void enqueue()
{
  int insert_item;
  if (Rear == SIZE - 1)
    printf("Overflow\n");
  else
  {
    if (Front == - 1)
      Front = 0;
      printf("Element to be inserted into the Queue:\n");
      scanf("%d", &insert_item);
      Rear++;
      inp_arr[Rear] = insert_item;
  }
}

void dequeue()
{
  if (Front == - 1 || Front > Rear)
  {
    printf("Underflow\n");
    return;
  } else {
    printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
    Front++;
  }
}

void show()
{
  if (Front == - 1)
    printf("Empty Queue\n");
  else {
    printf("Queue \n");
    for (int i = Front; i <= Rear; i++)
      printf("%d\n", inp_arr[i]);
  }
}






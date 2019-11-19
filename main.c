// Sam Baker 11/8
//Linked linkedList

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int takeInput(){
  int choice;

  printf("\nPlease make a selection: \n");
  printf("1 - Print Array \n");
  printf("2 - Add a value at end of array \n");
  printf("3 - Add a value at an index \n");
  printf("4 - Delete a value at an index \n");
  printf("5 - Search Array \n");
  printf("6 - Loop Array (note you will no longer be able to print the array) \n");
  printf("7 - Quit\n");

  scanf("%d", &choice);
  printf("\n");

  return choice;
}

//////////////////////////////////////////////////

void handleInput(struct Node *first, int *running, int *loop, int choice){
  int temp_value, temp_index;

  switch (choice){
    case 1:
      if (loop){
        printf("Cannot print looped list \n");
        break;
      }
      printf("Printing your array: \n");
      printList(first);
      break;

    case 2:
      printf("Please enter a value to add\n");
      scanf("%d", &temp_value);
      addNode(first, temp_value);
      printf("%d added to the array \n", temp_value);
      break;

    case 3:
      printf("Please enter a value to add\n");
      scanf("%d", &temp_value);
      printf("Please enter an index\n");
      scanf("%d", &temp_index);
      addAtIndex(first, temp_value, temp_index);
      printf("%d added to the array at index %d \n", temp_value, temp_index);
      break;

    case 4:
      printf("Please enter an index\n");
      scanf("%d", &temp_index);
      deleteAtIndex(first, temp_index);
      printf("The value at index %d has been deleted \n");
      break;

    case 5:
      printf("Please enter a value to search for \n");
      scanf("%d", &temp_value);
      temp_index = searchList(first, temp_value);
      if (temp_index == -1)
        break;
      printf("%d was found at index %d", temp_value, temp_index);
      break;

    case 6:
      printf("Looping List\n");
      *loop = 1;
      loopList(first);
      break;

    case 7:
      *running = 0;
      break;

    default:
      printf("Not a valid selection\n");
      break;
    }
}
//////////////////////////////////////////////////

void main(){
  struct Node *first = (struct Node*)malloc(sizeof(struct Node));
  struct Node *temp;
  int running = 1, choice, loop = 0;

  first->next = NULL;

  printf("Please enter an integer for the first value of your List \n");
  scanf("%d", &(first->value));

  while (running){
    choice = takeInput();
    handleInput(first, &running, &loop, choice);
    printf("\n\n");
  }

free(first);
free(temp);
}

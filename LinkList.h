//Sam Baker 11/8
//Linked List

struct Node{
  int value;
  struct Node *next;
};


///////////////////////////////////////////////////
void printList(struct Node *n){
  while (n != NULL){
    printf("%d \n", n->value);
    n = n->next;
  }
}

///////////////////////////////////////////////////
struct Node *getIndex(struct Node *n, int index){
  int i = 0;
  while(i < index){
      if (n == NULL)
        printf("index out of bounds");
      n = n->next;
      i++;
  }
  return n;
}

//////////////////////////////////////////////////
void addNode(struct Node *n, int value){
  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  while (n->next != NULL)
    n = n->next;
  n->next = new;
  new->value = value;
  new->next = NULL;
}

///////////////////////////////////////////////////
void addAtIndex(struct Node *n, int value, int index){
  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  int i = 0;
  while(i < index - 1){
      if (n == NULL)
        printf("index out of bounds");
        break;
      n = n->next;
      i++;
    }
  new->next = n->next;
  new->value = value;
  n->next = new;
}

//////////////////////////////////////////////////
void deleteAtIndex(struct Node *n, int index){
  struct Node *temp;
  int i = 0;
  while(i < index - 1){
      if (n == NULL)
        printf("index out of bounds");
        break;
      n = n->next;
      i++;
    }
  temp = n->next;
  n ->next = temp->next;
  free(temp);
}

////////////////////////////////////////////////////
void loopList(struct Node*n){
  struct Node *first = n;
  while (n->next != NULL){
    n = n->next;
  }
  n->next = first;
}

//////////////////////////////////////////////////
int searchList(struct Node*n, int value){
  int index = 0;
  while (n != NULL){
    if (n->value == value)
      return index;
    else
      index++;
      n = n->next;
  }
  printf("value not found \n");
  return -1;
}

//////////////////////////////////////////////////

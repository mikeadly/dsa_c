#include "linked_list.h"


/*

  ************************************
  *    LINKED LIST CORE FUNCTIONS    *
  ************************************



  ***********************
  * INSERTION FUNCTIONS *
  ***********************

*/

void append (struct ll* _lst, uint8_t _value)
{
  struct node *n = new_node(_value);
  if(_lst->length == 0)
    _lst->head = _lst->tail = n;
  else
  {
    _lst->tail->next = n;
    _lst->tail = n;
  }
  ++_lst->length;
}

void prepend (struct ll* _lst, uint8_t val)
{
  struct node *n = new_node(val); 
  
  if(_lst->length == 0)
  {
    _lst->head = _lst->tail = n;
  }
  else
  {
    n->next = _lst->head;
    _lst->head = n;
  }
  ++_lst->length;
}

/*****************************************/

/*

 ***********************
 *  DELETION FUNCTIONS *
 ***********************

*/


void del_ll (struct ll* _lst)
{
  struct node *temp = _lst->head;
  while(temp)
  {
    _lst->head = _lst->head->next;
    free(temp);
    temp = _lst->head;
  }
  _lst->head = _lst->tail = NULL;
  _lst->length = 0;
}


void delete_first(struct ll* _lst)
{
  if(_lst->length == 0)
    return;
  else if (_lst->length == 1)
  {
    free (_lst->head);
    _lst->head = _lst->tail = NULL;
  }
  else
  {
    struct node *temp = _lst->head;
    _lst->head = _lst->head->next;
    free (temp);
  }
  --_lst->length;
}


void delete_last (struct ll* _lst)
{
  if (_lst->length == 0)
    return;
  else if (_lst->length == 1)
  {
    free(_lst->head);
    _lst->head = _lst->tail = NULL;
  }
  else
  {
    struct node *temp = _lst->head;
    while (temp->next->next)
      temp = temp->next;
    free(_lst->tail);
    _lst->tail = temp; 
    _lst->tail->next = NULL;
  }
  --_lst->length;
}


void delete_index(struct ll* _lst, int8_t _index)
{
  if(_index < 0 || _index >= _lst->length)
    return;
  else if(_index == 0)
    delete_first(_lst);
  else if(_index == _lst->length-1)
    delete_last(_lst);
  else
  {
    struct node* before = get_index_address(_lst, _index-1);
    struct node* to_be_deleted = before->next;
    before->next = to_be_deleted->next;
    free(to_be_deleted);
    --_lst->length;
  }
}
/*****************************************/

/*

 ************************
 *  CREATION FUNCTIONS  *
 ************************

*/

struct node *new_node(uint8_t _value)
{
  struct node *n = (struct node*) malloc(sizeof(struct node));
  n->val = _value;
  n->next = NULL;
  return n;
}


struct ll *init_ll()
{
  struct ll *p = (struct ll*) malloc(sizeof(struct ll));
  p->head = NULL;
  p->tail = NULL;
  p->length = 0;
  return p;
}


/*****************************************/

/*

 ************************
 *  PRINTING FUNCTIONS  *
 ************************

*/

void print_length (struct ll* p)
{
  printf ("Length: %d\n", p->length);
}


void print_head (struct ll* p)
{
  printf("Head: ");
  if(p->head)
    printf("%d\n", p->head->val);
  else
    printf("NULL\n");
}


void print_tail (struct ll* p)
{
  printf("Tail: ");
  if(p->tail)
    printf("%d\n", p->tail->val);
  else
    printf("NULL\n");
}




void print_list(struct ll* _lst)
{
  struct node *temp = _lst->head;
  while (temp)
  {
    if (temp == _lst->tail)
      printf("%d\n", temp->val);
    else
    {
      printf("%d -> ", temp->val);
    }
    temp = temp->next;
  }
}


/*****************************************/

/*

 ************************
 *    OTHER FUNCTIONS   *
 ************************

*/


void reverse(struct ll* _lst)
{
  if(_lst->length == 0 || _lst->length == 1)
    return;
  else
  {
    struct node *temp, *before, *after;

     temp = _lst->head;
    _lst->head = _lst->tail;
    _lst->tail = temp;
    
    before = NULL;
    after = temp->next;

    while(temp)
    {
      temp->next = before;
      before = temp;
      temp = after;
      if(after)
        after = after->next;
    }
  }
}


int8_t get_index_value(struct ll* _lst, int8_t _index)
{
  if (_index < 0 || _index >= _lst->length)
  {
    printf("INDEX_OUT_OF_RANGE\n");
    return -1;
  }
  else if (_index == 0)
  {
    return _lst->head->val;
  }
  else
  {
    struct node *temp = _lst->head;
    while (_index--)
      temp = temp->next;
    return temp->val;
  }
}

struct node* get_index_address(struct ll* _lst, int8_t _index)
{
  if (_index < 0 || _index >= _lst->length)
  {
    printf("INDEX_OUT_OF_RANGE\n");
    return NULL;
  }
  else if (_index == 0)
  {
    return _lst->head;
  }
  else
  {
    struct node *temp = _lst->head;
    while (_index--)
      temp = temp->next;
    return temp;
  }
}


void insert_value(struct ll* _lst, int8_t _index, int8_t _value)
{
  if(_index < 0 || _index > _lst->length)
    return;
  else if(_index == 0)
    prepend(_lst, _value);
  else if(_index == _lst->length)
    append(_lst, _value);
  else
  {
    struct node *new = new_node(_value);
    struct node *temp = get_index_address(_lst,_index-1);
    new->next = temp->next;
    temp->next = new;
    ++_lst->length;
  }
}


/*****************************************/

/*

 ************************
 *   HELPER FUNCTIONS   *
 ************************

*/

uint8_t enter_value()
{
  uint8_t __val = 0;
  printf("Enter value: ");
  scanf("%hhd", &__val);
  return __val;
}


int8_t enter_index()
{
  int8_t __ind = 0;
  printf("Enter index: ");
  scanf("%hhd", &__ind);
  return __ind;
}


void lst_append(struct ll* _lst)
{
  append(_lst, enter_value());
}

void lst_prepend(struct ll* _lst)
{
  prepend(_lst, enter_value());
}




uint8_t confirm_deletion()
{
  char answer = 0;
  printf("Delete All The List? y/n: ");
  scanf(" %c", &answer);
  
  if(answer == 'y')
      return 1;
  else if(answer == 'n')
    return 0;
  else
    return 2;
}

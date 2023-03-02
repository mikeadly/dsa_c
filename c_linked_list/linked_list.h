#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define APPEND "ap" 
#define PREPEND "pre" 
#define DELETE_FIRST "df" 
#define DELETE_LAST "dl" 
#define DELETE_LIST "da"
#define PRINT_LIST "p" 
#define PRINT_HEAD "h" 
#define PRINT_TAIL "t" 
#define PRINT_LENGTH "l" 
#define PRINT_INDEX "i" 
#define REVERSE "rev"
#define GET_INDEX "get"
#define QUIT "q"

struct node
{
  uint8_t val;
  struct node *next;
};

struct ll
{
  struct node *head;
  struct node *tail;
  uint8_t length;
};


struct node * new_node(uint8_t);
struct ll* init_ll ();
void print_length (struct ll*);
void print_tail (struct ll*);
void print_head (struct ll*);
void append (struct ll*, uint8_t);
void delete_first(struct ll*);
void del_ll (struct ll*);
void prepend (struct ll*, uint8_t);
void delete_last (struct ll*);
void print_list(struct ll*);
int8_t get_index(struct ll*, int8_t);
uint8_t enter_value();
int8_t enter_index();
void lst_append(struct ll*);
void lst_prepend(struct ll*);
void reverse(struct ll*);
uint8_t confirm_deletion();

#endif //LINKED_LIST_H

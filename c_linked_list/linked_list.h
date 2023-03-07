#ifndef LINKED_LIST_H
#define LINKED_LIST_H



#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/**
 * Fuction Options
 */
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
#define INSERT "ins"
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


/**
 * Allocates and returns pointer of Node.
 */
struct node * new_node(uint8_t);


/**
 * Allocates and returns pointer to linked list.
 */
struct ll* init_ll ();


/**
 * Prints Length Value of linked list.
 */
void print_length (struct ll*);


/**
 * Prints tail value of linked list.
 */
void print_tail (struct ll*);


/**
 * Prints head value of linked list.
 */
void print_head (struct ll*);


/**
 * Creates then adds new node before head.
 */
void append (struct ll*, uint8_t);


/**
 * Creates then adds new node after tail.
 */
void prepend (struct ll*, uint8_t);


/**
 * Delete the first node.
 */
void delete_first(struct ll*);


/**
 * Delete last node.
 */
void delete_last (struct ll*);


/**
 * Delete all the nodes of the linked list.
 */
void del_ll (struct ll*);


/**
 * Prints all the nodes of the linked list.
 */
void print_list(struct ll*);


/**
 * Returns a value of a given index.
 */
int8_t get_index_value(struct ll*, int8_t);


/**
 * Return memory address of given inde.
 */

struct node* get_index_address(struct ll*, int8_t);

/**
 * insert node at given index
 */

void insert_value(struct ll*, int8_t, int8_t);


/**
 * Reverse all nodes
 */
void reverse(struct ll*);


/*******************************************/


/**************************
 *    HELPER FUNCTIONS    *
 **************************/


/**
 * Interactive fuction/ prints message
 * then takes value form end user.
 */
uint8_t enter_value();


/**
 * Interactive fuction/prints massage
 * then take index from the user.
 */
int8_t enter_index();


/**
 * Interactive function/prints message
 * then take value then append it.
 */
void lst_append(struct ll*);


/**
 * Interactive fuction/ prints message
 * the take value the prepend it.
 */
void lst_prepend(struct ll*);


/**
 * Interactive fuction/ prints confirmation
 * message and return options.
 */
uint8_t confirm_deletion();



#endif //LINKED_LIST_H

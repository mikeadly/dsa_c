#include "linked_list.h"

int main(void)
{
  
  char input[10];
  struct ll *list = init_ll();
  
  while (1)
  {
    printf("Enter func.: ");
    scanf("%s", input);
   
    /* Quit Program */
    if(!strcmp(QUIT, input))
    {
      del_ll(list);
      free(list);
      return 0;
    }

    /* Print List */
    else if(!strcmp(PRINT_LIST, input))
      print_list(list);

    /* Append Node */
    else if(!strcmp(APPEND, input))
      lst_append(list);

    else if(!strcmp(PREPEND, input))
      lst_prepend(list);

    /* Delete First Node */
    else if(!strcmp(DELETE_FIRST, input))
      delete_first(list);

    /* Delete Last Node */
    else if(!strcmp(DELETE_LAST, input))
      delete_last(list);

    /* Print Length*/
    else if(!strcmp(PRINT_LENGTH, input))
      print_length(list);

    /* Print Head */
    else if(!strcmp(PRINT_HEAD, input))
      print_head(list);

    /* Print Tail */
    else if(!strcmp(PRINT_TAIL, input))
      print_tail(list);

    /* Delete All The List */
    else if(!strcmp(DELETE_LIST, input))
      del_ll(list);

    /* Reverse The List */
    else if(!strcmp(REVERSE, input))
      reverse(list);
    else
      printf("WRONG_INPUT\n");

  }

  del_ll(list);
  free(list);
  return 0;
}

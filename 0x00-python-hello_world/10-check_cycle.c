#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if the linked list has a cycle or not
 * @list: pointer to the list
 * Return: 1 if yes, 0 if no
 */

int check_cycle(listint_t *list)
{
  listint_t *slow = list;
  listint_t *fast = list;

  while(fast & fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
	return(1)
	  }
  return (0)
    }

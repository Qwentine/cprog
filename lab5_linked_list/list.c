#include <stdio.h> /* for printf */
#include <stdlib.h> /* for malloc */


//tha data structure containing the actual data
// and the pointer to a next node
// this will be the linear one-way linked list
// all the functions count on the fact that the list representative points to the topmost node
typedef struct ns  
	{
  int data;
  struct ns *next;
} node;
 
/* adds a node to top of list */
node *list_add (node **p, int i)
{
  node *n = NULL;
  if (p) {//test if the representative  even exists (it can be empty though)
          //....it is OK to add the first node to an empty list
    n = malloc(sizeof(node));// new memory for a new node, note using sizeof
    if (n) {//test of the allocation success
      n->data = i;//writing the data to newly allocated mem
      n->next = *p;//the new node is the top node so has to point to the original top
      *p = n;// and a representative must point to our new node of course
    }
  }
  return n;//The success of the function run can be tested externally (returns NULL on fail)
}
 
/* adds a new node to the bottom of the list */
node *list_add_bottom (node **p, int i)
{
  node *n = NULL;
  if (p) {//same thing with testing the existence of representative as before,...
	  // it is legal to add the new node to the end of empty list
    n = malloc(sizeof(node));//memory for new node
    if (n) {//test of allocation success
      n->data = i;//write the data to new mem
      n->next = NULL;//new node is at the end so does not point anywhere
                     // ... has to be done, since the memory is ininitialized until now
      if (*p) {//if the list was not empty, find the tail
        node *m = *p;
        while (m->next) m = m->next;//iterate through the existing list nodes
        m->next = n;//let the last node point to our new one 
      } else {//list was empty so our new node is the first one and the last one at the same time
        *p = n;
      }
    }
  }
  return n;
}
 
/*adds a node to the i-th position of a list */
node *list_insert_at (node **p, int i, int index)
{
  node *n = NULL;
  if (p) {//test of representative 
    if (*p) {//test of emptyness
      
      node *r = NULL;
      node *s = *p;
      int idx = 0;
      while (s) {//s will be used to iterate through the list
                 // sooner or later we will reach the proper index (or the list is not long enough)
        if (idx == index) {//proper index reached
          
          n = malloc(sizeof(node));//new mem
          if (n) {//test of allocation
            n->data = i;//insert the data
            if (r) {//r do exist so there was some iteration already in the past
                    //we have to insert the new node between the r-th node and his follower
              n->next = r->next;
              r->next = n;
            } else {
              /* no iteration took place yet, but the index matches, so perhaps the mission was to insert at the beginning of the list */
              n->next = *p;//our new node points to the former starting node 
              *p = n;//let our node be the new start of the list
            }
          }
          return n;//n is null in case of any fail
        }
        idx++;//jump to the next index
        r = s;//r becomes the last iterated node "prolezenym"
        s = s->next;//s jumps to next node too
      }
      if (idx == index) {// we have reached the last node, but the index matches so the mission was to add the new node to the bottom 
                         
        n = malloc(sizeof(node));//new mem etc.
        if (n) {
          n->data = i;
          n->next = NULL;
          r->next = n;
        }          
      }
    } else {
      /* the original list was empty */
      if (!index) {//but desired index was zero
        /* inserting to the top */
        n = malloc(sizeof(node));//new mem etc...
        if (n) {
          n->data = i;
          n->next = NULL;
          *p = n; 
        }
      }
    }
  }
  return n;
}
 
/* removess the first node "celo" */
void list_remove (node **p)
{ 
  if (p && *p) {//if the list is not empty
    node *n = *p;
    *p = (*p)->next;//now the representative point to the next top node or nowhere if the removed node was the last one
                    //notice the parenthesis
                    //thats because p is not a pointer to structure but a pointer to pointer to structure
                    // *p is a pointer to structure  (so it can acceptaccept ->)
    free(n);//free the deleted node mem
  }
}
 
//finds the index of wanted node
node **list_search (node **n, int i)//Q: is the pass by reference really necessary
{
  if (n) {
    while (*n) {
      if ((*n)->data == i) return n;
      n = &(*n)->next;
    }
  }
  return NULL;
}
 

//prints the nodes content and the addresses
void list_print (node *n) //A:No it is not,just as here n may be passed by value since this function does not need to change the representative
{
  if (!n) {
    printf("list is empty\n");
    return;
  }
  while (n) {
    printf("print %p %p %d\n", n, n->next, n->data);// to the types: N is a pointer to the structure, thats why %p 
                                                    // n->next is a member of structure but is a pointer as well so %p once again
                                                    // n->data if finally an int so %d
    n = n->next;
  }
}
 
int main (void)
{
  node *n = NULL;
 
  list_add(&n, 0); /* list: 0 */
  list_add(&n, 1); /* list: 1 0 */
  list_add(&n, 2); /* list: 2 1 0 */
  list_add(&n, 3); /* list: 3 2 1 0 */
  list_add(&n, 4); /* list: 4 3 2 1 0 */
  list_print(n);
 
  puts("\n");
  /* vlozi (8) na pizici 0, list: 5 4 3 2 1 0 */
  list_insert_at(&n, 5, 0);
  /* vlozi (25) na pozici 3, list: 5 4 3 25 2 1 0 */
  list_insert_at(&n, 25, 3);
  /* vlozi (-1) na pozici 7, list: 5 4 3 25 2 1 0 -1 */
  list_insert_at(&n, -1, 7);
  list_print(n);
 
  puts("\n");
  list_remove(list_search(&n, -1)); /* removes -1 */
  list_remove(list_search(&n, 25)); /* removes 25 */
  list_remove(list_search(&n, 5));  /* remove cell containing 5 */
  list_remove(&n);            /* removes the first one (4) */
  list_remove(&n->next);      /* removes the next  (2) */
  list_remove(list_search(&n, 1)); /* removes 1  */
  list_remove(&n->next);      /* removes (0) */
  list_remove(&n);            /* removes (3) */
  list_print(n);
 
  return 0;
}
//Exercises:
//1)write a function that makes an array of integers out of the upper list
//2)write a function that converts the list to a bidirectional circular list
//3)write a function list_insert_sorted() which adds new node to a proper position in sorted list
//4)write a function which sorts the list



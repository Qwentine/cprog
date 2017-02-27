#include <stdio.h>
#include <string.h>

//the program asks the user if it should end with success or not

int main (void)
{
  char string[10];
  printf("This program ends with success if you enter \"A\",...  or with fail, if anything else entered:");
  fgets((char *) &string, 9, stdin);
  printf("You have entered: %s",string);

  if(!strcmp(string,"A\n"))
  { 
    printf("\nProgram ends with success!\n"); 
    return 0;
  }
  else
  {
    printf("\nProgram ends with fail!\n");
    return 1;
  }
  
}

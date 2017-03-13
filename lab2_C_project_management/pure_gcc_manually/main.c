/*
******************************************************
dividing the code to multiple files/headers example
******************************************************



*/

#include <stdio.h>


//include all the headers
//note „“ instead of <>, that means the files will be included from the relative path, instead of the system lib storage paths, relative to the actual pwd path

#include "module1.h"
#include "module2.h"
extern float function_from_module1_2(int param);
//now we can use the functions from above headers
// the compiler knows the prototypes
// it is simply the same as if the prototypes were written here by hand
// see the headers content 

int main(void)
{
  int a = 5;
  int b = 0;

  b = function_from_module1_1(a);
  printf("b=%d\n",b);

  b = function_from_module1_2(a);
  printf("b=%d\n",b);

  b = function_from_module2_1(a);
  printf("b=%d\n",b);

  b = function_from_module2_2(a);
  printf("b=%d\n",b);

  b = another_function_from_another_file(a);
  printf("b=%d\n",b);

}

//int i, j;    /* two wariables of type int */
//int *pi;     /* pointer to int, named pi */

//i = 1;       /* there is 1 in i variable now */
//pi = &i;     /* there is an address of i in pi (obtained by &) */
//j = *pi;     /* take the content of pi, treat it like an address,*/
		 /* jump to that address and read int (pi it pointer to int)*/
		 /* store that int to j*/
  
/*
in C parameters are always passed by value, doing so a local copy of parameter is made for a function, the function can access this copy and even change it, but it is all lost after the function ends.

if we pass a parameter which is a reference (pointer) than we get our “passing by reference”


*/


//to demonstrate the upper mentioned
//the zero_wrong() function does nothing, but "zeroes" its local copy of var (lost after the function ends) 
#include<stdio.h>

void zero_wrong(int var) {
  var = 0;
}


// zero_OK function does not get the variable value, but a reference to a place vhere the wariable resides in memory, so it can jump tp that place and write an integer there

void zero_OK(int *p_var) {
  *p_var = 0; 	//get the p_var value
			//treat that value as a memory address
			//jump to that address
			//write a 0 integer there
}

int main(void) {
  int i = 1;
  printf("\nValue of variable i=%d",i);
  zero_wrong(i);
printf("\n Value of variable is still i=%d even after zero_wrong() call",i);
  /* there is still 1 in i */

  zero_OK(&i); 	//the function does not get the "i" variable,
		 	// but a reference/pointer to the place in memory where i 
			// resides, this is obtained by & operator
                 //
  /* now I is really zeroed */
printf("\nValue of variable i=%d after zero_ok() call\n",i);

  return 0;
}




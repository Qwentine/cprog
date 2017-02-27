/*
Preprocessor preprocesses the source ans header files before actual compilation takes place:
 - removes comments
 - inserts included files
 - expands macros
 - takes care of “conditional compilation”

Preprocesor directives start with number sign #:
#include <filename> – inserts the content of filename file:
#include <stdint.h>
#include “myheader.h“

#define MACRO_NAME value – defines macro MACRO_NAME as value.

Once defined, a macro can be un-defined by #undef directive:

#define TOTAL_COUNT 5
#define ERR_5 “Error n. 5“
#define DEBUG //a macro does need to have actual value,
              //still may be defined just on its own
#undef _DEBUG //and undefined as well

****Conditional compilation****

#ifdef MACRO_NAME – following lines are taken into account during compilation only if macro was defined before. Every #ifdef must end with #endif directive:
  #ifdef _WIN32
    printf(“Were on windows bro!“);
  #endif

#ifndef – oposit of #ifdef, includes lines if macro is not defined, must end with #endif as well:
  #ifndef __x64
    #define __x64
  #endif

#if, #elif – even more complicated combinations are allowed

#if defined( _WIN32) && _MSVC_VER >= 1432
  printf(“Were on windows OS and our compiler version is sufficient!“);
#elif defined(UNIX) && !defined(__GNUC__)
  #error No suitable compiler found!
#endif


#error message – Writes the error message and stops the code processing.
*/


/*
**************************************************************
Example:
Following program tests the presence of GCC compiler
**************************************************************

*/


#include <stdio.h>

int main(viod)
{
#ifdef __GNUC__
 //the actual macro names can be found in GnuC compiler documentation,... google("gcc version macro")
	printf("\nGnuC compiler version used to compile this program was: %d.%d.%d\n",__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__);
return 0;


#elif !defined(__GNUC__)
	#error Sorry, this program needs GCC,.... stopping the compilation!.

#endif 
return 0;

}

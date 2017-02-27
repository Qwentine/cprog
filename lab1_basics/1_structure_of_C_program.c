/*basic C program structure*/

/*------------------------------------------------*/
/* Opening comment                                */
/* Program name                                   */
/* ...more info may follow here                   */
/*------------------------------------------------*/
#include <stdio.h> // preprocessor directive starts with "#"
                   // !!NOTE!! No semicolon at preprocessor directives end
		       //importing standard  stdio.h library

int main(void)	// main function
		//returns "int", better NOT use any other types
/*If main doesn't return int, then you have an ill-formed program and behavior is undefined. Anything can happen. Your program might crash, or it might run as though nothing were wrong at all.*/
		//main does not take any arguments in this case "int main(void)"
		//or "int main()"
		//Normally we would use rather:
		// "int main(int argc, char** argv)"
		// argc = number of arguments, integer 
		// argv = array of argument strings 
		
{//main body begin
    // note the offset for better readability
    // you may use <tab>
    // or a set ot white spaces
    // white spaces are better
    
    printf("Hello World\n"); // printf writes something on standard output
                             // which is a screen / consolle
                             // "printf()" can be used thanks to previous stdio.h import
                             // StdIO = Standard Input / Output
                             // '\n' is a character - char like any other 'a' or 'B'
                             // '\n' is a newline character actual content may difer depending on OS <CR><LF> DOS/UNIX (go google tofrodos)
                             

    return 0; 	//main returns int, 0 is OK
		// this is to inform the superio program (OS in this case) that our program exited happily (encountered no errors)
	        //remember: every possible branch of main function has to return sometning (there was only one in our case)
}//end of main body = no offset



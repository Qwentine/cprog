void swap(int *p_x, int *p_y){ //NOTE the parameters are pointers to int
                                
int tmp;   //auxilary swap variable
           
 
tmp = *p_x;
*p_x = *p_y;
*p_y = tmp;
}
//swap function call, NOTE "&" operator usage
int i=10,j=20;
swap(&i,&j);
//ATTENTION: not swap(i,j) nor swap(*i,*j) BOTH is WRONG

EXERCISE:
1) Write a program which swaps any two integer variables with no use of temporary variable. 
2) Revrite the program so it can swap pointers  

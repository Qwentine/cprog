//same as module1.h
// now including the example showing that it does not really matter where is the executive code of the function actually placed

//once the prototype is listed compiler has enough information about the function to continue compiling

//it is a "project managements" business, that the executive code of the function is somhow included in compilation at the end, header files has nothing to do with this

// nevertheless there is a convention saying, that the functions from header "my_own_name.h" file should have their code in "my_own_name.c" file

//but the compiler does not demand this as shown in this example
#ifndef MODULE2_H
  #define MODULE2_H
  extern int function_from_module2_1(int param);
  extern int function_from_module2_2(int param);
  extern int another_function_from_another_file(int param);
#endif

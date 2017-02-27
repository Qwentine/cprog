
//this file shows that name of the header file and the actual file with code does not have to match

//it is up to project management to ensure that this file will be included during compilation

//moreover this file shows that header may be included for constants



  #include "module1.h" //a properly written library makes sure it is never included multiple times (see module1.h)

int another_function_from_another_file(int param)
{
  return param + MY_COOL_CONSTANT;
}

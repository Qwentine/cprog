/*A structure is a collection of one or more variables, possibly of different types, grouped
together under a single name for convenient handling. (Structures are called ``records'' in
some languages, notably Pascal.) Structures help to organize complicated data, particularly in
large programs, because they permit a group of related variables to be treated as a unit instead
of as separate entities.*/

//one can imagine a structure also as an array where members are not of same size/type

//there are five ways how to define structure in C

//1) UNNAMED STRUCTURE, defines one particular variable (explicit name).... you can not derive further variables based on this one (pretty useless right?)
struct {
int height;
float weight;
}bob, tim, jack; //particular variables, may be used in program from now on but that's all
//_______________________________________________________________________________________________

//2) NAMED STRUCTURE 
struct measures {
int height;
float weight;
}john; //particular variable
//more can be defined later based on this new "measures"
struct measures bob, tim, jack; //the keyword "struct"is mandatory
//__________________________________________________________________________________________________


//3) NAMED STRUCTURE once again
//same as before but without defining a particular variable with structure definition 
struct measures {
int height;
float weight;
}
//
struct measures bob, tim, jack; //the keyword "struct"is mandatory
//________________________________________________________________________________________________

//4) DEFINING A NEW DATA TYPE
typedef struct {
int height;
float weight;
} MEASURES;
//a new data type has been defined now we can use it just like any other data type
MEASURES bob, tim, jack; //no need of the "struct" keyword
//_________________________________________________________________________________________________


//5) NAMING BOTH, THE TYPE AND STRUCTURE
typedef struct measures {
int height;
float weight;
} MEASURES;
//a new data type has been defined now we can use it just like any other data type
MIRY bob, tim, jack; //no need of the "struct" keyword
//does not make a big sense in this particular case, but is useful if the structure is "self-referential" see later
//_________________________________________________________________________________________________

//There is no real difference in those first 4 ways, it is OK to use just 4 and 5
//-----------------------------------------------------------------------------

//ACCESSING/REFERING STRUCTURE MEMBERS
//use the dot, the structure member operator

bob.height = 185;
bob.weight = 80.5;
tim.height = bob.height;

//-----------------------------------------------------------------------------
//SRUCTURES AND ARRAYS

//1) AN ARRAY OF STRUCTURES
MEASURES PEOPLE[100];
//access the members:
people[66].height=175;
// K&R-C does not allow en-block structure manipulation,  ANSI C removes this restriction:
bob = tim;
people[50] = people[66];


//2) ARRAY IN A STRUCTURE, ... as a member of structure
typedef struct {
int a[10];
}ARRAY_INT_10;

ARRAY_INT_10 array_a array_b;

array_a.a[5]=3;
array_b = array_a; //copies the structures (the content)
//if we work a lot with a fixed length arrays, it may be convenient to use structures

//---------------------------------------------------------------------------------

//STRUCTURES AND POINTERS

//structure is a data type like any else so there can be a pointer to it:

MEASURES bob, tim, jack, *p_human; //p_human is a pointer to structure of type MEASURES (structure has to be defined before)
p_human = (MEASURES *) malloc (sizeof(MEASURES));// allocate the memory to pointer p_human
//one should always use sizeof() when allocating memory, but that let us stress that twice for structures (memory alignment) never ever try to "guess" the size of structure without using sizeof

//also a new type can be defined as a pointer to structure:
typedef struct{
float consumption;
int year;
int capacity;
int somearray[10]; 
}AUTO, *P_AUTO; //two new types were defined a structure AUTO and a pointer to such  structure: P_AUTO

AUTO a;
P_AUTO p_a;
p_a = (P_AUTO) malloc(sizeof(AUTO));
//accessing the members:
//1) the old way
a.consumption = 10.5;
//2) using a pointer
(*p_a).consumption=8; 
  //ATTENTION
  // *p_a.consumption=8; //evaluates as  *(p_a.consumption)=8 which is nonsense
//3)!!!!! SPECIALITY the arrow operator  (to get rid of upper parenthesis  problem)
p_a->consumption=8;
//---------------------------------------------------------------------------------------

//SEFL-REFERENTIAL STRUCTURE

typedef struct node{
int var;
struct node *p_next;
}NODE;
//mostly used for creating linked lists
//----------------------------------------------------------------------------------------

//A STRUCT IN A STRUCT
//nothing surprising here, just a structure being a member of structure (the inner one has to be defined earlier)

typedef struct{

char street[15];
int number;
}ADDRESS;//must be defined before used in next structure

typedef struct{
char name[15];
char surname[20];
ADDRESS adress;
}HUMAN; //a new structure which has one member of type ADDRESS 

//accessing

HUMAN john;

john.name = "Otto";
john.surname = "Novak";
john.adress.street = "Technicka";
john.adress.number = 12345;
//------------------------------------------------------------------------------------------
//Structures and functions
//structure behaves just like any other data type, 
//can be passed both by value and reference (not in KR)

//1) passing by value
void print_adress_byvalue(HUMAN human){

printf("Human named:%s %s lives at:%s %d ",human.name, human.surname,human.adress.street,human.adress.number);
}

//2) passing by reference
void print_adress_byref(HUMAN *p_human){
printf("Human named:%s %s lives at%s %d"p_human->name, p_human->surname, p_human->adress.street,p_human->adress.number);
//BE AWARE, once passed by reference the external value of parameter can be accessed/altered by function
p_human->adress.number=1234;
}
//initialization
HUMAN john={"John", "Novak",{"Technicka",25}};//remember the arrays initialization?
HUMAN *p_john = &john;


//calling
print_adress_byvalue(john);
print_adress_byref(&john);
print_adress_byref(p_john);
 

//Notes
// -if passed by value a local copy of whole struct is made
// -a function can not access external struct values if passed by value
// -a structure can be returned by function as well
// -bigger structures are more often passed by ref (no local copy)
//   -it saves the stack
//------------------------------------------------------------------------------------------

//ENUM TYPES

typedef enum {
WHITE=1,//note , not ;
BLUE=2,//if not initialized explicitly than starts with 0 in most compilers
RED=3//note no ; here
}COLOUR;
//if initializing explicitly, it is wise to do so for all members

//internal representation of enum is the least "expensive" signed integer type 
//a signed char in most cases

//define a var
COLOUR b=WHITE,c=RED;

//enum may be cast to a number
printf("Value of variable c, of type COLOUR is: %d",(int)c);

//one can not get the name of member in program (enum is always just a number)
//if you need the name use the arrays and pointer

COLOUR colour=WHITE;

char *names[]={"White","Blue","Red"};
printf ("the colour is: %s",names[colour-1]); //-1 since our initialization started at 1


//UNION

typedef union {
  char c;
  int i;
  float f;

}CHAR_INT_FLOAT;
//accessing

CHAR_INT_FLOAT my_union;

my_union.c="A"; //union saves an A char
my_union.i=6; //saves int 6 now (A is lost)
my_union.f=6.5;// etc

//union does not save any information about the actual type being saved at the moment, if you desire such function enclose the union to structure to save the information by enum type

typedef enum{
CHAR,INT,FLOAT
}TYPE;

typedef struct{
TYPE type;
CHAR_INT_FLOAT value;
}BETTER_UNION;

//-----------------------------------------------------------------------

//Exercises
//---Try reading a different type from the union than the one saved previously, try to explain the results

//1) Write the functions add() and subtract() which can process(get and return) imaginary numbers (use structures) do it by passing by value
//2) do the same by passing by reference (let the functions return a pointer to a newly allocated structure)
//3) define a structure which could represent a polynomial a*x^2 + b*x +c, write a function which returns a definite integral of given polynomial on given dimensions 
//4) write a program that reads 5 lines of the std input line by line. If a number is red it is stored as int if anything else is red than store it as string (array of char) at maximum 20 characters. Doing so the program fills an array of five structures containing unions(similar as the upper example)
//5) now try to modify ex4 as a linear linked list so the program can read virtually infinite lines

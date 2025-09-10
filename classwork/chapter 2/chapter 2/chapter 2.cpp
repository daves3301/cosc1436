/*
David Petroff
classwork 2 
COSC 1436 FALL 2025

NOTES ON VARIABLES, EXPRESSIONS, AND TYPES 
*/
//PPD 

#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!" << " david petroff" << std::endl;
    std::cout << " you are " << 20 << " years old" << std::endl;
    // if you want double quotes in string literal you have to escape them;
    
    std::string name;
    name = "dave";
    std::cout << "hello " << name;


    // TIP: use namespace std rather than std:: 
    //intiger literals - one or more digits  
    //floating point literals - 1 or more digits + fraction 
    // ESCAPE SEQUENCE EX: \n (starts with \ followed by character;

     //literal - read only data

    int age;
    age = 23;
    std::cout << " you are " << age << " years old" << std::endl;

    /*
    rules for identifiers:
    start with letter or _
    followed by letters, digits, or _
    if * after () that means 0 or more.
    id:: = (letter, _) (letter, digits,-)* zero or more, + 1 more more
    *generally wont use undeerscores*
    * CANNOT BE KEYWORDS
    *MUST BE UNIQUE
    */
    //AREA OF RECTAGLE RULE CALCULATOR
    // A = lw
    //DECLARING VARIABLES 
    
    int length;
    int width;
    
     length = 10;
     width = 20;
    length = width = 100;  //assignment 
    int area;
   
    // area = length * width;
    //multiple variable declaration must be thr same type (can oly specify the type once) 
    
     // int length = 10, width = 20; //identical to the above syntax, dont list together if not related for simplicity
    
    // can declare additional variables by seperating with commas
    
   // std::cout << " area of rectangle is " << area << std::endl;

    /*  T, types so far:: = int, string;
    type defines what can be stored in the variable and in what format
        all variables must have a type and a name;
    TYPES: defines how data is stored (int, char, float, etc.) also defines the range of possible values for that type.
    IDENTIFIERS: HAVE SPECIAL MEANING TO U.
    int - for now its a whole number.
    std::string - any arbituary text you want: name, number, whatever
    INTEGRAL TYPES:
    short- 2 bytes , range: 32k
    int- 4 bytes , range: billion 
   */
    //int variables before they are read so compiler doesnt shit. such as 
   //int area = 0;
    // 2 different approaches to declaring variables 
   //BLOCK- all vaiables declared together typically at the beginning of the code. unclear, old, slow compilers/ memory, easy to find var.
    double radius;
    double diameter;
   //std::string circleName;
   // now i can use the variables;
   //INLINE- variables are declared right before their use
   //use radius, diameter
   std::string circleName;
   //use circleNames
   //assignment  E=E the left side is the left value the right side is the right value
   // only variables can be L values, must be a writable expression, readable values go on the right (string, literals, intigers)
   /*    
   PRIMITIVE DATA TYPES:
   SIGN VARIABLES:
   SIGNED CHAR , SIZE: 1, -128 - 127
        SHORT, SIZE: 2, -32768 - 32767
        INT, SIZE : 4 BYTES, +- 2 BILLION ( SAME WITH LONG) 
   FLOAT VARIABLES:
       FLOAT TYPES: SIZE: 4 BYTES , 5-7, e^38
        DOUBLE, SIZE: 8 BYTES, 12-15,
        MISC TYPES:
        BOOL, VALUES: T/F
        CHAR, SIZE: 1 BYTE 
        1.) FOR VARIABLES , YOU WILL ALWAYS LOWERCASE THE NAME, UNLESS MULTIPLE WORDS:
        *CAMEL CASING: all lowercase, CAPITALIZE on word boundaries.*(ex:firstName)
        ******
        BREAKPOINT: STOPS PROGRAM GOES TO DEBUGGER AND GIVES U CHANCE TO FIND ERROR AND EDIT, PAUSES BEFORE THAT LINE EXECUTES, SELECT LINE U WANT CARROT ON LINE PRESS F9
        (STORED LOCALLY ON YOUR MACHINE)
        AUTOS WINDOW IN DEBUG MENU WILL CONTEXTUALIZE THE CODE AROUND YOUR BREAKPOINT
        TO STEP( JUMP TO THE NEXT EXECUTABLE LINE AFTER BREAKPOINT, ON LINE OF CODE U WANT TO EXECUTE, PRESS F10)
        YOU CAN CHANGE THE VALUE OF VARIABLES */
   //EXAMPLES
  /* double pi;
   pi = 3.14159;
   */
   char letterGrade;

   letterGrade = 'A';

   bool isPassing;
   isPassing = true;

   area = length * width;
   length = width = 100;
   //std::cout << length;

  /* REMAINING ARITHMATIC OPERATORS:
   +, - , *, /
   PERCENTAGE/MODULUS/REMAINDER
    */
   //integer division (lose your fractional values)
   //expressions must be the same type, therefore the result is the same type. in this case you lose the .33333  
   int  result = 10 / 3; // = 3
   
   //MODULUS RETURNS THE REMAINDER, ONLY WORKS WITH INTEGRAL DATA TYPES   
   int remainder = 10 % 3;// = 1
   
   //urinary arithmatics 
   int negativeLength = -length;

   //SCOPE: LIIFETIME OF VARIBALE : the point of declaration to the end of the block that declared it. {} define blocks of code. variable scopes end at the curly brace. 
   {//starting new block
       int newVariable1 = 10;
       //double newVariable1 = 45.7;
   }
   //std::cout << newVariable1;
   /*BASICS OF STRINGS:
   NOT A PRIMITIVE, ASSIGN VALUE USING ASSIGNMENT OPERATOR, ONLY WORKS IN C++.
   */ 
   std::string studentName;
   studentName = "Bob";
   studentName = studentName + "Wilson";

   //LITERAL - GOOD FOR STATIC VALUES
   //VARIABLE - GREAT FOR WRITABLE VALUES
   //NAMED CONSTANT - BEHAVIOR OF A LITERAL( READ ONLY DATA), BUT HAS NAME AND TYPE LIKE A VARIABLE.(EX: PI)

   const double Pi = 3.14159;
   //A = pi * r2
   double areaCircle = Pi * (radius * radius);

   //Pi = 140;


}
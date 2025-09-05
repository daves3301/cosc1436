/*
David Petroff
classwork 2 
COSC 1436 FALL 2025

NOTES ON VARIABLES, EXPRESSIONS, AND TYPES 
*/
//PPD 

#include <iostream>

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
    std::cout << " you are " << age; " years old";

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
    
    //length = 10;
    //width = 20;
    
    int area;
   
    // area = length * width;
    //multiple variable declaration must be thr same type (can oly specify the type once) 
    
    int length = 10, width = 20; //identical to the above syntax, dont list together if not related for simplicity
    
    // can declare additional variables by seperating with commas
    
    std::cout << " area of rectangle is " << area << std::endl;

    /*  T, types so far:: = int, string;
    type defines what can be stored in the variable and in what format
        all variables must have a type and a name;
TYPES:
    int - for now its a whole number.
    std::string - any arbituary text you want: name, number, whatever
    INTEGRAL TYPES:
    short- 2 bytes , range: 32k
    int- 4 bytes , range: billion 
   */
    //int variables before they are read so compiler doesnt shit. such as 
   int area = 0;
    // 2 different approaches to declaring variables 
   //BLOCK- all vaiables declared together typically at the beginning of the code. unclear, old, slow compilers/ memory, easy to find var.
   int radius, diameter;
   std::string circleName;
   // now i can use the variables;
   //INLINE- variables are declared right before their use
   int radius, diameter;
   //use radius, diameter
   std::string circleName;
   //use circleNames
   //assignment  E=E the left side is the left value the right side is the right value
   // only variables can be L values, must be a writable expression, readable values go on the right ( string, literals, intigers)

   

}
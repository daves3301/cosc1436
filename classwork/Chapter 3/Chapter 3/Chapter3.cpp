#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    /*demo prefix postfix - increment / decrement
    std::cout << "enter a value: ";
    int number;
    std::cin >> number;
    std::cout << "prefix (++x) = "  << ++number << ", x= " << number << std::endl;
    std::cout << "prefix (--x) = " << --number << ", x= " << number << std::endl;
    std::cout << "postfix (x++) = " << number++ << ", x= " << number << std::endl;
    std::cout << "postfix (x--) = " << number-- << ", x= " << number << std::endl;
    */
    //Display main menu
    bool done = false;
    while (!done)
    {


        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

        //Validate input
        //if (choice == "A" || choice == "a")
        //{
        //    //TODO: Move add code here
        //    std::cout << "Add not implemented" << std::endl;
        //} else if (choice == "V" || choice == "v")
        //{
        //    //TODO: Movie view code here
        //    std::cout << "View not implemented" << std::endl;
        //} else if (choice == "E" || choice == "e")
        //{
        //    std::cout << "Edit Not implemented" << std::endl;
        //} else if (choice == "D" || choice == "d")
        //{
        //    std::cout << "Delete Not implemented" << std::endl;
        //} else if (choice == "Q" || choice == "q")
        //{
        //    return 0;
        //} else
        //{
        //    std::cout << "Invalid choice" << std::endl;
        //};
        // Switch :: Replacement for an if-else-if where each if condition is Expr == Value
        // switch-statement ::= switch (E) { case-statement* [ default-statement ] }
        // case-statement ::= case E : S 
        // default-statement ::= default : S
        // break-statement ::= break ;
        // 
        // Switch expression must be either char or an integral expression
        // case labels must be:
        //   - Compile time constants (e.g. literal, simple expression)
        //   - Unique within switch
        // Case statements fall through to next case unless break statement used
        // Default statement executes if no cases match expression
        switch (choice)
        {
            case 'A': //std::cout << "Add not implemented" << std::endl; break;
            case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

            case 'V':
            case 'v': std::cout << "View not implemented" << std::endl; done = true; break;

            case 'D':
            case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

            case 'E':
            case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

            case 'Q':
            case 'q': return 0;

            default: std::cout << "Invalid choice" << std::endl; break;
        }
    };

    //Movie details
    std::string title;          //Required
    std::string description;    //Optional
    int runLength;              //Required, 0
    int releaseYear;            //Optional, but between 1900-2100
    double userRating;          //Optional, 1.0-10.0
    bool isClassic;             //Required, false

    //Get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    //Title is required
    bool isEmpty = title == "";
    if (isEmpty)
        std::cout << "Title is required" << std::endl;
    /*
    std::cout << "Enter the run length (in minutes): ";
    runLength = -1;
    while(runLength < 0)
    {
    std::cin >> runLength;
    if (runLength < 0)
        std::cout << "ERROR: Run length must be at least 0" << std::endl;
   
    }*/
    std::cin >> runLength;
    while (runLength < 0)
    {
        std::cout << "ERROR: Run length must be at least 0" << std::endl;
        std::cin >> runLength;
    }

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
    /*if (releaseYear < 1900)
    {
        std::cout << "Release year must be at least 1900" << std::endl;
        releaseYear = 1900;
    } else if (releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        releaseYear = 1900;
    }*/

    // Logical AND &&   Eb && Eb => bool
    // Logical OR ||    Eb || Eb => bool
    // Logical NOT !    !Eb => bool
    if (releaseYear < 1900 || releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        releaseYear = 1900;
    }

    std::cout << "Enter the optional description: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    // Validate userRating
    std::cout << "Enter the optional user rating (1.0-10.0): ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    }
    /*if (userRating < 1.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    } else if (userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    }*/

    std::cout << "Is this a classic (Y/N)? ";
    std::string input;
    std::cin >> input;

    // if (Eb) S [ else S ] ;
    // Else associates with nearest preceding if
    // Nested if
    //   if (E1) 
    //     if (E2) 
    //       if (E3)
    //          S (E1, E2 and E3 must be true)
    // if-else-if
    //   if (E1)
    //     S
    //   else if (E2)
    //     S  (E1 is false and E2 is true)
    // 

    /*if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    else
        std::cout << "You must enter either Y or N";*/
    isClassic = false;
    if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    else
        if (_strcmpi(input.c_str(), "N") == 0)
            isClassic = false;
        else
            std::cout << "You must enter either Y or N";

    // View movie
    //    Title (Year)
    //    Run Length # min
    //    User Rating = ##
    //    Is Classic? 
    //    [Description]
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << title << " (" << releaseYear << ")" << std::endl;
    std::cout << "Run Length " << runLength << " mins" << std::endl;
    std::cout << "User Rating = " << userRating << std::endl;
    //std::cout << "Is Classic? " << isClassic << std::endl;
    /*if (isClassic)
        std::cout << "Is Classic? Yes" << std::endl;
    else
        std::cout << "Is Classic? No" << std::endl;*/
    /*std::string classicIndicator;
    if (isClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";*/
    //Conditional_expression ::= Eb ? Et : Ef
    //std::string classicIndicator = isClassic ? "Yes" : "No";
    std::cout << "Is Classic? " << (isClassic ? "Yes" : "No") << std::endl;
    if (description != "")
        std::cout << description << std::endl;
    std::cout << std::endl;
}

void relationalDemo()
{
    std::cout << "Enter two values: ";

    int left, right;
    std::cin >> left >> right;

    // Relational operators ::= > >= < <= == !=
    //   Warning 1 - Equality and equals are similar and work in the same situations
    //   Warning 2 - Be very, very careful of floating point comparison for equality
    //                 Consider using >= or <= instead unless comparing to an integer
    //   Warning 3 - Strings compare by character values not by locale
    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;

    //areEqual = 10 == left;
    //areEqual = 10 = left;

    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">= " << (left >= right) << std::endl;
    std::cout << "<= " << (left <= right) << std::endl;
    std::cout << "== " << (left == right) << std::endl;
    std::cout << "!= " << (left != right) << std::endl;

    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 * 3.0) / 3.0;
    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    // Comparison works but is case sensitive
    std::string name1 = "Bob";
    std::string name2 = "bob";
    std::cout << (name1 == name2) << std::endl;

    // To compare strings case insensitive use the strcmpi
    //  > 0 ::= left > right
    //  < 0 ::= left < right
    //  == 0 ::= left == right
    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;
}

            /* Relational operators :: = > >= < <= == !=
               Warning 1 - Equality and equals are similar and work in the same situations
               Warning 2 - Be very, very careful of floating point comparison for equality
                             Consider using >= or <= instead unless comparing to an integer
               Warning 3 - Strings compare by character values not by locale
            std::cout << "areEqual = " << areEqual << std::endl;
            areEqual = left == right;
            std::cout << "areEqual = " << areEqual << std::endl;

            areEqual = 10 == left;
            areEqual = 10 = left;
            std::cout << "> " << (left > right) << std::endl;
            std::cout << "< " << (left < right) << std::endl;
            std::cout << ">= " << (left >= right) << std::endl;
            std::cout << "<= " << (left <= right) << std::endl;
            std::cout << "== " << (left == right) << std::endl;
            std::cout << "!= " << (left != right) << std::endl;

            float someValue = (10 / 3.0) * 3.0;
            float someOtherValue = (10 * 3.0) / 3.0;
            areEqual = someValue == someOtherValue;
            std::cout << areEqual << std::endl;

             Comparison works but is case sensitive
            std::string name1 = "Bob";
            std::string name2 = "bob";
            std::cout << (name1 == name2) << std::endl;

             To compare strings case insensitive use the strcmpi
              > 0 ::= left > right
              < 0 ::= left < right
              == 0 ::= left == right
            areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;
         
         NEW OPERATOR: conditional expression Eb (boolean expression ? Et : Ef (two other operators)
            taking an if statement and coverting it into an expression. if boolean expression is true the value of your second operand is true, if false its your third.
            conditionally chooses. used for when you need a conditionally expression. 
            conditional_expression ::= Eb ? Et : Ef
            ex: std::string classicIndicator = (isClassic ? "Yes" : "No");
            used in a cout or any place you need an expression. when using cout complier will get confused if you dont use parenthesis. 
         
         ***SWITCH STATEMENT: SWITCH(EXPRESSION)
           {
           0- MORE CASE STATEMENTS, CASE STATEMENT BEGINS WITH KEYWORD CASE -->EXPRESSION(case label)--> : SINGLE STATEMENT;
           DESIGNED TO REPLACE IF ELSE IF STATEMENTS 
           executes the statements that corelates with the value of expression
           RULES: 
           CASE LABELS MUST BE COMPLIE TIME CONSTANTS( VALUE IS KNOWN BY COMPLIER AT TIME OF COMPULATION) LIMITED TO SIMPLE EXPRESSIONS( CONST INTIGERS, SIMPLE MATH FUNCTIONS)  
         (put at the end after all choices) 
         default statement ex: default: std::cout << "ivalid choice" <<endl;
         BE WEARY OF FALLTHROUGH IN CASE STATEMENTS ( FALL THROUGH TO THE NEXT CASE UNITL DEFAULT)
         ** BREAK SOLVES THIS: BREAK GETS YOU OUT OF YOUR CASE
         Ex: switch( letterGrade) 
           {case 'A' : cout << "passing" <<endl;break;
           case 'B' : cout << "also passing"<<,endl;break;
           case 'C' : cout << "barely passing"<<endl;break;
          */
    /*
    * BEGINNING OF CH5
    LOOPS:executes block of code again and again until some criteria is met. **careful for infinite loops**
    WHILE LOOP: while(E boolean)
    do something 
    
    operators:
    
    prefix icrement, decrement
    postfix increment, decrement
    :add 1 or subtract 1 from variable
    prefix increment is ++ variable, decrement is --variable(left side of variable)
    postfix is variable ++/-- (right side of variable)
    UPDATES VARIABLE VALUE THEN STORES IT AGAIN IN VARIABLE, EVERYTIME IT IS EVALUATED
    
    differences: prefix: returnes updated value
                postfix: gives you unmodified value of variable. 
    only works with integral values
    */

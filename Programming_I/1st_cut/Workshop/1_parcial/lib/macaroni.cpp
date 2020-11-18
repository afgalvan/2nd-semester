#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>
#define clean "cls"
#define bold "" 
#define green "color A"
#define red "color C"
#define default "color 7"
#define stop getch()


//TODO Clear the console's content
void clearConsole()
{
    /*This function take the pre-processor
    directives' return to clear the console
    depending of the O.S*/
    system(clean);
}


void errorMsgPersonalized(std::string message)
{
    
    system(red); // Red fore color for give the error aspect
    std::cout << message;
    stop; // A pause until the user press key
    system(default); // Set back the default color
    
}


// TODO errorMsg print an error in a structured format
void errorMsg(int errorType)
{
    /*This function print the common error types
    in red fore color with the same format and
    with a error code.
      *Instance: errorMsg(2) = Error 102. Only input positive numbers.
    */

    //List of errors
    std::string errorList [] = {"Error List Working.", //0
    "Error 101. Solo se permiten numeros.", //1
    "Error 102. Solo se permiten numeros positivos.", //2
    "Error 103. Opción fuera de rango.", //3
    "Error 104. Nombre muy corto.", //4
    "Error 105. Solo ingrese numeros negativos.", //5
    "Error 106. Sólo se permiten letras.", //6
    "Error 107. Debes ingresar algo.", //7
    "Error 108. El limite superior debe ser mayor.", //8
    "Macaroni Syntax error. In function's paramether."}; //9

    // The first error is to check if the function is working
    if (errorType == 0)
    {
        system(green);
        std::cout << errorList[0] << std::endl;
    }
    else
    {
        system(red); // Red fore color for give the error aspect
        std::cout << errorList[errorType];
        stop; // A pause until the user press key
    }
    system(default); // Set back the default color
    
}

void errorIdentifier(std::string errorID)
{
    std::cout << "\n\nEn \"" << errorID << "\".\n";
}


//TODO Print centered titles
void printTitle(std::string title, int centered, bool inCaps)
{
    /*This function receive three arguments, the first
    is the title for showing it, the second is how much
    centered is desired, and the third one is the upper
    case.
      *Instance: printTitle("macarena", 3, true)
                MACARENA
    */
    if (inCaps)
    {
        for (int i = 0; i < title.length(); i++)
            title[i] = toupper(title[i]);
    }
    
    for (int i = 0; i < centered; i++)
        std::cout << "\t";
    system(bold); std::cout << title << "\n\n";
    system(default);
}


// TODO Detect if an input is an int number or not
int isInteger(std::string evaluate)
{
    /* Receive a string and evaluates if it is a number or not
    *isInteger(n); # 1
                   # 0
    */
    int i, value;

    for(i = 0; i < evaluate.length(); i++)
    {
        value = evaluate[i] - '0';

        if(value < 0 || value > 9)
        {
            // The first character is '-'
            if(i == 0 && value == -3) continue;
            return 0;
        }
    }
   return 1;
}


//TODO Detect if an input is a float number or not
int isFloat(std::string evaluate)
{
    /* Receive a string and evaluates if it is a number or not
    *isFloat(n); # 1
                 # 0
    */
    int i, value;
    int hasDot = 0;

    for (i = 0; i < evaluate.length(); i++)
    {
        value = evaluate[i] - '0';

        if (value < 0 || value > 9)
        {
            // The first character is '-'
            if (i == 0 && value == -3)
                continue;

            //Check it only has one dpt
            if (value == -2 && !hasDot)
            {
                hasDot = 1;
                continue;
            }

            return 0;
        }
    }
    return 1;
}

//TODO Remove all spaces in a chars array
char *removeSpaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

/* TODO Repeat a whole program bringing a simply
    menu for the users*/
void repeatProgram(int main_function())
{
    /*Display a menu where the user can choose between two
    options:
    1. repeat the program.
    2. exit the program.
    
    And only validate the input of numbers between those ranges.
    Structure:

    int main()
    {
        # your code

        repeatProgram(main);
        return 0;
    }
    
    */
    std::string choice;
    int menuDisplayed = 0;
    bool repeat = true;
    int choiceInt;

    while (repeat)
    {
        // Check if is the first time that the menu is displayed
        if (menuDisplayed >= 1) clearConsole(); // If so clear the console
        else stop; // Make the regular enter to continue.
        std::cout << "------------------------------------------";
        std::cout << "\n\t¿Desea repetir el programa?\n";
        std::cout << "\tSi......................[1]\n";
        std::cout << "\tNo......................[2]\n";
        std::cout << "> ";std::cin >> choice;

        if (!isInteger(choice))
        {
            // Print an error from a list of errors
            errorMsg(1);
            menuDisplayed ++; // Count the display
            continue;
        }

        // Convert to integer the choice to stablish ranges
        choiceInt = std::stoi(choice);

        if (choiceInt > 2 or choiceInt < 1)
        {
            errorMsg(3);
            menuDisplayed ++;
            continue;
        }
        repeat = false;
    }

    if (choiceInt == 1) main_function();
}


//TODO Validate a name has no numbers and isn't empty
bool inputName(char *name)
{
    /*Get one name as an argument and validate if is there
    numbers in the string, if so, send an error message
    for input a number in a alphabetic string
      * Instance: inputName("4ndres");
        |
        └─> This will print an error and it'll keep asking.
    */
    int i;
    char *blankName = name;
    std::string nameLen;

    removeSpaces(blankName);
    nameLen = blankName;
    if (nameLen.empty())
    {
        errorIdentifier(name);
        errorMsg(7); // Error. You should input something
        return true;
    }

    nameLen = name;
    if (nameLen.length() < 3)
    {
        errorIdentifier(name);
        errorMsg(4);
        return true;
    }

    for (i = 0; i < nameLen.length(); i++)
    {
        if (std::isdigit(name[i]))
        {
            errorIdentifier(name);
            errorMsg(6); // Error. Only input alphabetic
            return true;
        }
    }

    return false;
}


//TODO Validate only numbers in an input.
bool inputNumbers(char numbersRange, std::string evaluate)
{
    /*This function takes two arguments, the first one is
    the numbers' range:
    'a' = All numbers   'p' = Only positive   'n' = Only negative

    The second one is the number to be evaluated in a string format.
    Note: The number must be receive in a string format and be
    converted next.
      *Instance: inputNumbers('p', number);
       |
       └─> Will only allow positive numbers and it'll print an error
           in case a negative value is typed.
    */
    bool isNumber = false;

    // First check if it's a number
    if (isInteger(evaluate) || isFloat(evaluate))
        isNumber = true;

    if (!isNumber)
    {
        errorIdentifier(evaluate); // Show where the error is
        errorMsg(1);// Error. Only input numbers
        return true;
    }
    
    int number = std::stoi(evaluate); // Pass the string to an integer var for be enraged
    numbersRange = tolower(numbersRange); //Convert in lowercase to be compared

    if (numbersRange == 'a')
        return false;
    else if (numbersRange == 'p')
    {
        if (number <= -1)
        {
            errorIdentifier(evaluate);
            errorMsg(2); // Only positive values error msg
            return true;
        }
        return false;
    }
    else if (numbersRange == 'n')
    {
        if (number >= 1)
        {
            errorIdentifier(evaluate);
            errorMsg(5); // Only negative values error msg
            return true;
        }
        return false;
    }

    errorMsg(9); // Macaroni syntax error
    return true;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
/* 
The scanf function requires pointers to the variables where the input should be stored. When you pass a variable to scanf using the & operator (like &age), you're actually passing the address of the variable, not the variable itself. This allows scanf to directly modify the value at that address.
For example, in scanf("%d", &age);, &age is the address of the age variable. scanf reads the input from the user and directly stores it at this address. 
*/
    int age;
    double gpa;
    char grade;
    char name[20]; // array of characters // 20 is the size of the array // name is the name of the array // char is the data type of the array // char name[20] is the declaration of the array // char name[] is the declaration of the array // char name is the declaration of the array


    /* There is a new line character at the end of each input. if we dont consume it, the next input will be read as part of the previous input. */
    printf("Please enter your age: ");
    scanf("%d", &age); // & is a pointer // take input for an integer
    getchar(); // Consume the leftover newline character

    printf("please enter your gpa: ");
    scanf("%lf", &gpa); // take input for a double
    getchar(); // Consume the leftover newline character

   

    printf("Please enter your grade: "); // %c is the format specifier for a character
    scanf("%c", &grade);         // take input for a character
    getchar(); // Consume the leftover newline character
    
    printf("Please enter your name: ");

    fgets(name, 20, stdin); 
    // fgets is used to read a string from the user. It takes the string to be read, the maximum number of characters to read, and a pointer to the file stream from which to read the string. (stdin is the standard input stream, which is the file stream from

    // scanf("%19s", name); 
    // Taking input for a string. Limiting to 19 to save space for null terminator, %s is the format specifier for a string
    

    printf("Your age is: %d\n", age);
    printf("Your gpa is: %lf\n", gpa);
    printf("Your grade is: %c\n", grade);
    printf("Your name is: %s\n", name);

    return 0;
}
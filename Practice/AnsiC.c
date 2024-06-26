#include <stdio.h>

void printCelsiusToFahrenheitTable() {
    // 1-3 & 1-4
    #define LOWER 0 /*lower limit of the table*/
    #define UPPER 300 /*upper limit*/
    #define STEP 20 /*step size*/

    float celsius, fahr;
    fahr = LOWER;

    printf("Fahrenheit-Celsius table\n");
    printf("-|  F  |   C   |-\n");

    while(fahr <= UPPER){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.0f | %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
/** Output
 Fahrenheit-Celsius table
-|  F  |   C   |-
     0 |  -17.8
    20 |   -6.7
    40 |    4.4
    60 |   15.6
    80 |   26.7
   100 |   37.8
   120 |   48.9
   140 |   60.0
   160 |   71.1
   180 |   82.2
   200 |   93.3
   220 |  104.4
   240 |  115.6
   260 |  126.7
   280 |  137.8
   300 |  148.9
*/
}

void takeCharInput() {
    int c;
    printf("Please enter a char:\n");
    while((c = getchar()) != EOF){
        if (c != '\n'){ // without this, the newline char is read and the output is not correct must handle \n chars
            printf("Char is: ");
            putchar(c);
            printf("\n");
            printf("Please enter another char:\n");
        }
    }
/** Output
Please enter a char:
q
Char is: q
Please enter another char:
w
Char is: w
Please enter another char:
e
Char is: e
Please enter another char:
r
Char is: r
Please enter another char:
t
Char is: t
Please enter another char:
y
Char is: y
Please enter another char:
*/
}

void checkGetChar() {
    printf("Verifying expression:\n");
    // printf("getchar() != EOF is: %d", getchar() != EOF);
    // Verifying expression:
    // g
    // getchar() != EOF is: 1%   // the % is here because you didnt use \n after %d - %d is for integers
    printf("getchar() != EOF is: %d\n", getchar() == EOF);
    // Verifying expression:
    // g
    // getchar() != EOF is: 0
}

void emptyFor(){
    double nc;
    for(nc = 0; getchar() != EOF; ++nc) // increments the counter for every charecter input, crtl+D will send the EOF char to termiante
        ;
    printf("%.5f\n", nc);
/** output
 * f
g
4.05
3.14
14
*/
}

void charConstants(){
    printf("Char constant A in ascII accessed by single quotes - 'A'\n");
    char a = 'A';
    printf("%d", 'A');
    printf("\n");
    printf("A");
    printf("\n");
}

void countBlanks_Tabs_NewLines(){
    int i;
    int blanks = 0;
    int tabs = 0;
    int new_lines = 0;
    printf("Please enter a char\n");
    while((i = getchar()) != EOF ){ // after every char inut , pressing enter will send a \n charecter
        if(i == '\t'){
            ++tabs;
        }else if(i == '\n'){
            ++new_lines;
        }else if(i == ' '){
            ++blanks;
        }else{
            printf("Please enter another char\n");
        }
    }
    printf("num blanks: %d\n", blanks);
    printf("num tabs: %d\n", tabs);
    printf("num new lines: %d\n", new_lines);
    
    /* output: 
Enter a char
r
Enter another char

d
Enter another char
 
g 
Enter another char
num blanks: 2
num tabs: 1
num new lines: 5   
*/
}

void copy_input_to_output(){
    char myStr[] = "q       w  e     r  t   y\n";
    
    int length = sizeof(myStr) - 1; // there is not .length property in C
    char cleanStr[length + 1]; // we need to copy into a new string

    int j = 0;
    int spaces = 0;

    for(int i = 0; i < length; i++){
        if(myStr[i] == '\t'){
            cleanStr[j] = ' ';
            j++;
        }
        else if(myStr[i] == ' '){
            if(spaces == 0){ // keep a count of spaces
                cleanStr[j] = ' ';
                j++;
            }
            spaces++;
        }
        else {
            cleanStr[j] = myStr[i];
            j++;
            spaces = 0;
        }
    }
    cleanStr[j] = '\0'; // Null-terminate the cleaned string
    printf("The cleaned up string is: %s\n", cleanStr);
/* Output
The cleaned up string is: q w e r t y
*/
}

void replace_special_chars(){
    char str[100];
    int length = sizeof(str) - 1;
    int i = 0;
    char c;

    printf("Please input a string with special characters\n");
    // this reads in the whole string then iterates over each char and puts it in the string
    while(i <= length && (c = getchar()) != '\n' && c != EOF){ 
        str[i++] = c;
    }

    str[i] = '\0';

    printf("The input string is: %s\n", str);

    /** output:
     Please input a string with special characters
    I like to write in C.
    The input string is: I like to write in C.
     */
}

int main() {

    printf("Hello, World\n");
    printf("Chapter 1 exercises\n");
    // printCelsiusToFahrenheitTable();
    // takeCharInput();
    // checkGetChar();
    // emptyFor();
    // charConstants();
    // countBlanks_Tabs_NewLines();
    // copy_input_to_output();
    replace_special_chars();


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //this is needed for pow and all math functions
#include <string.h> // this is needed for strpcy

void sayHi( char name[] ){
    printf("Hello %s\n", name);
}

double cube(double num){
    double result = pow(num, 3);
    return result;
}

char gradeDetermine (grade){
    switch (grade){
        case 'A':
            printf ("Excellent\n");
            break;
        case 'B':
            printf ("Good\n");
            break;
        case 'C':
            printf ("Average\n");
            break;
        case 'D':
            printf ("Bad\n");
            break;
        case 'F':
            printf ("Fail\n");
            break;
        default:
            printf( "Invalid Grade\n");
            break;
    }
};

struct Student{ // this is like a class in python
    char name[50];
    char major[50];
    int age;
    double gpa;
};

void poiterVar(){
    
	int age =30;
    printf( "%p ", &age); // i.e. you have to use the pointer
	int * pAge= &age; //convention is to use pVar to name pointers 
	//you have to use * to create a pointer variable 
	double gpa= 3.4;
	double * pGpa= &gpa;
    char grade= 'A';
    char * pGrade= &grade;
}

void dereferencePointer(){
    int age = 30;
    int * pAge = &age;
    printf("%d\n", *pAge); 
    // &* undoes it and you can keep doing &*&*&*...
}

void readFile(){
    FILE * fpointer = fopen("employees.txt", "w"); //r is read, w is write, a is append
    //fpointer is a pointer to a file
    //fopen returns a pointer to a file
    //fopen("employees.txt", "r") is a pointer to a
    fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting");
    fclose(fpointer);
}

void guess_the_number(void); //this is a function prototype

int main(){
    printf("Top\n");
    sayHi("Mike");
    printf("Answer: %f\n", cube(3.0));
    printf("what is your grade?\n");
    char grade;
    scanf("%c", &grade);
    gradeDetermine(grade);
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");// when we use a string we have to use strcpy
    strcpy(student1.major, "Business");
    printf("%s is %d years old and has a gpa of %f\n", student1.name, student1.age, student1.gpa);
    printf("Bottom\n");
    int i=1;
    while (i<=5){
        printf("%d\n", i);
        i++;
    }
    int j=1;
    do{//this is a do while loop, it will execute at least once
        printf("%d\n", j);
        j++;
    }while(j<=5);
    guess_the_number();
    for (int i=1; i<=6; i++){ //for loop (initialization; condition; increment) you can enter i+= i++ or i=i+1
        printf("%d\n", i);
    }
    int array[3][3]={ //2d array
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    return 0;
}

void guess_the_number(){ //while loop, this is also the actual function
    int guess=0;
    int secretNumber = 5;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;
    while (guess != secretNumber && outOfGuesses == 0){
        if (guessCount < guessLimit){
            printf("Enter guess: ");
            scanf("%d", &guess);
            guessCount++;
        }else{
            outOfGuesses = 1;
        }
    }
    if (outOfGuesses == 1){
        printf("Out of guesses\n");
    }else{
        printf("You win!\n");
    }
}

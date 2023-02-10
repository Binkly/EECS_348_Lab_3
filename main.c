#include <stdio.h>
#include <string.h>


char problem_1() {
    FILE* ptr;
    char ch;
    char default_data[12];
    char temp_data[12];
    int month = 0;

    // Opening file in reading mode
    ptr = fopen("test.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    while (ch != EOF){
        ch = fgetc(ptr);
        strcat(temp_data, ch);
        if (ch == "\n") {
            default_data[month] = temp_data;
            month += 1;
            memset(temp_data, '\0', 12);
        }
    }

    //Format and calculate arrays here

    //Print formatted arrays

    fclose(ptr);
}


int main() {
    int terminate = 0;
    int selection;
    while (!terminate) {
        printf("Problem 1 (1)\n");
        printf("Problem 2 (2)\n");
        printf("Terminate Program (3)\n");
        printf("Select Problem: \n");
        scanf("%d", &selection);

        if (selection == 1) {
            problem_1();
            break;
        }
        else if (selection == 2) {
            printf("Problem 2");
            break;
        }
        else if (selection == 3) {
            printf("Terminating program...");
            terminate = 1;
            break;
        }
        else {
            printf("Invalid Selection.");
            break;
        }
    }
    return 0;
}

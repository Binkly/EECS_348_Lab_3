/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: k801a197
 */


#include <stdio.h>
#include <stdlib.h>


struct str
{
    float value;
    int index;
};

int cmp(const void *a, const void *b)
{
    struct str *a1 = (struct str *)a;
    struct str *a2 = (struct str *)b;
    if ((*a1).value > (*a2).value)
        return -1;
    else if ((*a1).value < (*a2).value)
        return 1;
    else
        return 0;
}


int main() {
	FILE *myfile = fopen("test.txt", "r");
		    if (myfile == NULL) {
		        printf("Cannot open file.\n");
		        return 1;
		    }
		    else {
		        //Check for number of line
		        char ch;
		        int count = 0;
		        char *month_names[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
		        do
		        {
		        ch = fgetc(myfile);
		        if (ch == '\n') count++;
		        } while (ch != EOF);
		        rewind(myfile);
		        float month_data[12];
		        int i;
		        printf("Monthly Sales Report for This Year:\n");
		        printf("Month \t Sales\n");
		        for (i = 0; i < 12; i++) {
		            fscanf(myfile, "%f\n", &month_data[i]);
		            printf("%s\t$%f\n", month_names[i], month_data[i]);

		        }
		        printf("\nSales Summary:\n");

		        float minimum, maximum, average;
		        int c;
		        minimum = month_data[0];
		        maximum = month_data[0];

		            for ( c = 0 ; c < 12 ; c++ ) {
		                if (month_data[c] < minimum ) {
		                   minimum = month_data[c];
		                }
		            }

		            for ( c = 0 ; c < 12 ; c++ ) {
		            	if ( month_data[c] > maximum ) {
		            	maximum = month_data[c];
		            	}
		            }
		            for (c = 0 ; c < 12 ; c++) {
		            	average += month_data[c];
		            }
		            average = average / 12;
		       int min_index;
		       int max_index;

		       for (int i = 0 ; i < 12 ; i++) {
		    	   if (month_data[i] == minimum) {
		    		   min_index = i;
		    		   break;
		    	   }
		       }

		       for (int i = 0 ; i < 12 ; i++) {
		    	   if (month_data[i] == maximum) {
		    		   max_index = i;
		       		   break;
		    	   }
		       }

		       printf("Minimum sales: $%f (%s)\n", minimum, month_names[min_index]);
		       printf("Maximum sales: $%f (%s)\n", maximum, month_names[max_index]);
		       printf("Average sales: $%f\n", average);

		       printf("\nSix-Month Moving Average Report:\n");
		       float average_1, average_2, average_3, average_4, average_5, average_6, average_7;

		       for (c = 0 ; c < 6 ; c++) {
		    	   average_1 += month_data[c];
		       }
		       average_1 = average_1 / 6;

		       for (c = 1 ; c < 7 ; c++) {
		    	   average_2 += month_data[c];
		       }
		       average_2 = average_2 / 6;

		       for (c = 2 ; c < 8 ; c++) {
		    	   average_3 += month_data[c];
		       }
		       average_3 = average_3 / 6;

		       for (c = 3 ; c < 9 ; c++) {
		    	   average_4 += month_data[c];
		       }
		       average_4 = average_4 / 6;

		       for (c = 4 ; c < 10 ; c++) {
		    	   average_5 += month_data[c];
		       }
		       average_5 = average_5 / 6;

		       for (c = 5 ; c < 11 ; c++) {
		    	   average_6 += month_data[c];
		       }
		       average_6 = average_6 / 6;

		       for (c = 6 ; c < 12 ; c++) {
		    	   average_7 += month_data[c];
		       }
		       average_7 = average_7 / 6;

		       printf("January - June\t $%f\n", average_1);
		       printf("February - July\t $%f\n", average_2);
		       printf("March - August\t $%f\n", average_3);
		       printf("April - September\t $%f\n", average_4);
		       printf("May - October\t $%f\n", average_5);
		       printf("June - November\t $%f\n", average_6);
		       printf("July - December\t $%f\n", average_7);

		       printf("\nSales Report (Highest to Lowest):\n");
		       printf("Month\tSales\n");

		       struct str objects[12];
		       for (int i = 0; i < 12; i++)
		           {
		    	   objects[i].value = month_data[i];
		           objects[i].index = i;
		           }
		       qsort(objects, 12, sizeof(objects[0]), cmp);
		       for (int i = 0; i < 12; i++)
		    	   printf("%s\t%f\n", month_names[objects[i].index], month_data[objects[i].index]);
		    }
	return 0;
}

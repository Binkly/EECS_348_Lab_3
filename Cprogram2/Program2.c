/*
 * Program2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: k801a197
 */


#include <stdio.h>


int count(int remaining_score, int score_values[], int checked_values[])
{
	if (remaining_score == 0) { //Checks if the passed score is 0, meaning a solution has been found
	    	printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", score_values[0], score_values[1], score_values[2], score_values[3], score_values[4]); //Prints formatted score combination
	        return 1; //Exits function call
		}

	if (((remaining_score - 8) >= 0) & (checked_values[0] == 0)) { //Checks if a two point conversion is possible and has not already been fully attempted
        score_values[0]++; //Increments count of two point conversions by 1
		if (count(remaining_score - 8, score_values, checked_values) == 0) { //Recurses with reduced score and updated combinations count
                for (int i = 0; i < 5; i++) { //Loops over each index in the checked_values array (array that keeps track of evaluated combinations)
                    checked_values[i]--; //Decrements value of each combination index by 1 so that other combinations can be evaluated
                }
            }
            score_values[0]--; //Decrements two point conversion index by 1 after exiting recursive
	}

    checked_values[0]++; //Increments two point conversion index by 1 to show that all of this score type has been found for this output

	if (((remaining_score - 7) >= 0) & (checked_values[1] == 0)) { //Checks if an extra point is possible and has not already been fully attempted
	    score_values[1]++; //Increments count of extra points by 1
		if (count(remaining_score - 7, score_values, checked_values) == 0) { //Recurses with reduced score and updated combinations count
                for (int i = 0; i < 5; i++) { //Loops over each index in the checked_values array (array that keeps track of evaluated combinations)
                    checked_values[i]--; //Decrements value of each combination index by 1 so that other combinations can be evaluated
                }
            }
            score_values[1]--; //Decrements extra point index by 1 after exiting recursive
    }

    checked_values[1]++; //Increments extra point index by 1 to show that all of this score type has been found for this output

	if (((remaining_score - 6) >= 0) & (checked_values[2] == 0)) { //Checks if a touch down is possible and has not already been fully attempted
	    score_values[2]++; //Increments count of touch downs by 1
		if (count(remaining_score - 6, score_values, checked_values) == 0) { //Recurses with reduced score and updated combinations count
                for (int i = 0; i < 5; i++) { //Loops over each index in the checked_values array (array that keeps track of evaluated combinations)
                    checked_values[i]--; //Decrements value of each combination index by 1 so that other combinations can be evaluated
                }
            }
        score_values[2]--; //Decrements touch down index by 1 after exiting recursive
    }

    checked_values[2]++; //Increments touch down index by 1 to show that all of this score type has been found for this output

	if (((remaining_score - 3) >= 0) & (checked_values[3] == 0)) { //Checks if a field goal is possible and has not already been fully attempted
	    score_values[3]++; //Increments count of field goals by 1
		if (count(remaining_score - 3, score_values, checked_values) == 0) { //Recurses with reduced score and updated combinations count
                for (int i = 0; i < 5; i++) { //Loops over each index in the checked_values array (array that keeps track of evaluated combinations)
                    checked_values[i]--; //Decrements value of each combination index by 1 so that other combinations can be evaluated
                }
            }
        score_values[3]--; //Decrements field goal index by 1 after exiting recursive
    }

    checked_values[3]++; //Increments field goal index by 1 to show that all of this score type has been found for this output

	if (((remaining_score - 2) >= 0) & (checked_values[4] == 0)) { //Checks if a safety is possible and has not already been fully attempted
	    score_values[4]++; //Increments count of safeties by 1
		if (count(remaining_score - 2, score_values, checked_values) == 0) { //Recurses with reduced score and updated combinations count
                for (int i = 0; i < 5; i++) { //Loops over each index in the checked_values array (array that keeps track of evaluated combinations)
                    checked_values[i]--; //Decrements value of each combination index by 1 so that other combinations can be evaluated
                }
            }
        score_values[4]--; //Decrements field goal index by 1 after exiting recursive
    }

    checked_values[4]++; //Increments safety index by 1 to show that all of this score type has been found for this output

    return 0; //Returns 0 if the score for this call is not reduced to 0

}



int main() {

    int score; //Score value inputed by user
    printf("\nEnter Score (or integer <= 1 to exit): \n"); //Prompts user for score input
    scanf("%d", &score); //Stores user input in score integer

    while (score > 1) { //Loops until a value <= 1 is entered (invalid score).
        int default_scores[5] = {0, 0, 0, 0, 0}; //Array storing amounts of each scoring type for each combination
        int checked_scores[5] = {0, 0, 0, 0, 0}; //Array acting as a check to make sure that all of one score type has been found before moving on
        printf("\nScoring combinations for %d points\n", score); //Output formatting
        count(score, default_scores, checked_scores); //Calls recursive function "count" with inputed score and assisting arrays

        printf("\nEnter Score (or integer <= 1 to exit): \n"); //Prompts user for score input
        scanf("%d", &score); //Stores user input in score integer
    }

    printf("\nExiting..."); //Exit message

    return 0;
}

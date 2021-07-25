#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Keeping track of scores
int computerScore;
int playerScore;
int counter;

void startGame(void);

//Calculate the results
void results(char* player, int computer) {
    char* computerChoice = malloc(sizeof(10));
    switch(computer) {
        case 0:
            computerChoice = "rock\n";
            break;
        case 1:
            computerChoice = "paper\n";
            break;
        case 2:
            computerChoice = "scissors\n";
            break;
    }

    //Comparing the player's choice against the computer's
    if(strcmp(player, "rock\n") == 0){
        if(strcmp(computerChoice, "scissors\n") == 0){
            playerScore++;
        }
        if(strcmp(computerChoice, "paper\n") == 0){
            computerScore++;
        }
    
    } else if(strcmp(player, "paper\n") == 0){
        if(strcmp(computerChoice, "rock\n") == 0){
            playerScore++;
        }
        if(strcmp(computerChoice, "scissors\n") == 0){
            computerScore++;
        }
    } else {
        if(strcmp(computerChoice, "rock\n") == 0){
            computerChoice++;
        }
        if(strcmp(computerChoice, "paper\n") == 0){
            playerScore++;
        }
    }
    
    printf("You chose: %sComputer chose: %sYour score: %d  Computer score: %d\n\n", player, computerChoice, playerScore, computerScore);
    //Best out of 3
    if(counter < 3){
        startGame();
    } else {
        if (playerScore > computerScore) {
            printf("You won!");
        } else if(playerScore < computerScore){
            printf("You lost!");
        }
        else{
            printf("Its a tie!");
        }
    }
}

//Making sure the input is valid
void inputVerification(char* player, int computer) {

    if (strcmp("rock\n", player) == 0 || strcmp("paper\n", player) == 0 || strcmp("scissors\n", player) == 0) {

            counter++;
            results(player, computer);
    }

    else {
        printf("Invalid input. \n");
        startGame();
    }
}

//Starts game, takes in user's choice and generates random number for computer
void startGame(){
    char* player = malloc(sizeof(10));
    printf("Choose rock, paper, or scissors: \n");
    fgets(player, 10, stdin);
    int computer = (rand() % 3);
    inputVerification(player, computer);
    free(player);
    }

int main(){
    srand( (unsigned int) time(NULL) );
    printf("********************************\n");
    printf("*****  Best Out of Three  ******\n");
    printf("********************************\n\n");
    startGame();
    printf("\n\n\n");
   return 0;
}



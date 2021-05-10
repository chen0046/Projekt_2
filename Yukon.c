#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cardDeck();
typedef enum { F, T } boolean; // or we could use stdbool.h file


struct card{
    char value;
    char suit;
    int data;
struct card* next;
struct card* prev;

};

struct node{
    //struct node* next;
   // struct node* prev;
    struct card* card;
};

struct node nodearray[7];
struct card cardarray[52];

int topcard =0;
char inputCommandValue[100];

//Below function was previously called insertAfter
    void insertCardsToColumns(int cardonc, int arrayndex) {
        nodearray[arrayndex].card = &cardarray[topcard];
        ++topcard;
        if (cardonc == 0) {
            return;
        }
        struct card *current;
        struct card *next;
        struct card *prev;
        current = nodearray[arrayndex].card;
        for (int i = 1; i < cardonc; ++i) {
            if (i == cardonc - 1) {
                ++topcard;
                current->prev = prev;
                return;
            }

            if (i != 0) {
                current->prev = &cardarray[topcard - 1];
            }
            current->next = &cardarray[topcard];
            next = current->next;
            prev = current;
            current = next;
            ++topcard;
        }
        current->prev = prev;
    }


void cardDeck() {
    //opret kort med values og suits
    int c = 0;
    char suits[4] = {'C', 'H', 'D', 'S'};
    for (int j = 0; j < 4; ++j) {
    for (int i = 1; i < 14; ++i) {
        struct card tempc;
        tempc.value = i;
        cardarray[c].value = i;
        cardarray[c].suit = suits[j];
        ++c;
        }
    }
}


void loadDefaultDeck() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK. Default deck loaded.");
    printf("\n INPUT >:");
}

void showDeck() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void splitDeck() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void shuffleRandom() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void saveDeck() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void startGame() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void quitCurrentGame() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK.");
    printf("\n INPUT >:");
}

void quitGame() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: OK. Quitting program. ");
    printf( "\n INPUT >:");
    exit(1);
}

void helpMessage() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: Please use one of the following inputs: 'LD', 'SW', 'SI', 'SR', 'SD', 'P', 'Q' or 'QQ'");
    printf( "\n INPUT >:");
}

void invalidInput() { 
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: Input not recognized. Type 'HELP' for a help message");
    printf( "\n INPUT >:");
}
void playerInput() {

    char tempCommandValue;

//MANGLER SPILLOGIK 
// HVIS NU DET ER NOGLE AF DE TING HVOR DER KAN INDTASTES FILNAVN ETC: 
//BESKEDERNE SKAL ERSTATTE TIDLIGERE BESKEDER OG IKKE VÆRE EN NY LINJE! 
    do { 
        tempCommandValue = scanf("%s[0-9a-zA-Z ]", inputCommandValue); //"%s"
        
        if (strcmp(inputCommandValue, "LD") == 0) {
            loadDefaultDeck(); 
            //Load default deck function  
        } else if(strcmp(inputCommandValue, "SW") == 0) {
            showDeck(); 
            //Show deck function 
        } else if(strcmp(inputCommandValue, "SI") == 0) {
            splitDeck(); 
            // Split shuffle function 
        } else if (strcmp(inputCommandValue, "SR") == 0) {
            shuffleRandom();
            // Shuffle random function
        } else if (strcmp(inputCommandValue, "SD") == 0) {
            saveDeck(); 
            // Save current deck function 
        } else if (strcmp(inputCommandValue, "P") == 0) {
            startGame(); 
            // Start game function 
        } else if (strcmp(inputCommandValue, "Q") == 0) {
            quitCurrentGame(); 
            // Quit current game function
        } else if (strcmp(inputCommandValue, "QQ") == 0) {
            quitGame(); 
            // Quit program
        } else if (strcmp(inputCommandValue, "HELP") == 0) {
            helpMessage(); 
            // Help function 
        } else { //If incorrect input is taken 
            invalidInput(); 
        }

    } while (strcmp(inputCommandValue, "QQ") != 0); //If QQ is taken then quit. This while statement is a formality for the loop. It will never run. 
}


void loadDeck() {
    char tempArray[52];
    FILE *fp;

    fp = fopen("CardDeck.txt", "r"); // Open the file with 'read' option.

    if (fp == NULL){ 
        printf("Error! The file is not found or could not be opened \n");
        exit(-1);
    }     
        for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (fgets(tempArray, 52, fp) != NULL){
            }            
        }
    fclose(fp);
    }
}   


int main() {

    playerInput();
    cardDeck();
    loadDeck(); // from file

    insertCardsToColumns( 9,0);
    insertCardsToColumns( 9,1);
    insertCardsToColumns( 9,2);
    insertCardsToColumns( 8,3);
    insertCardsToColumns( 8,4);
    insertCardsToColumns( 8,5);
    insertCardsToColumns( 8,6);

    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\t\t\t\n\n");
    //printf("hell");

    return 0;

   }

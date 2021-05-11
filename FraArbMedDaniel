#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Data type for the card */
struct card{
    char value;
    char suit;
    int data;
    int cardRevealed; 
struct card* next;
struct card* prev;
};

/* Data type for the piles */ 
struct Pile{
    struct Pile* next;
    struct Pile* prev;
    struct card* tail;
    struct card* head;
};


/***************************************** Function prototyping *****************************************/
/* Node operation functions */
void addPile(); /*Push / Add pile */ 
int removePile(); /* Pop / Remove pile */
void addCard(struct Pile *location); /*Tilføj et kort. Det skal altid tilføjes til den første bunke af alle bunkerne.  */
int removeCard(struct Pile *from); /* Fjerner et kort. Returnerer int ifm om der er flere kort i bunken*/
void moveCard(struct Pile *from, struct Pile *to); /* Ryk et kort fra en bunke til en anden. */
int moveCards(struct Pile *from, struct Pile *to, int index); /* Rykker flere kort af gangen. Man kan rykke konkrete kort fra en bunke (v int index)*/

/* Game logical functions */
void shuffleRandom(); /* Random shuffle function. */
void splitDeck();
void clearGame(); /* Reset game */
void startGame(); /* Start game */
void basicLD();
void initializeDeck();
void dealCards(); 
void saveDeck();
void quitCurrentGame();
void quitGame();
void helpMessage();
void invalidInput();
void playerInput();

/* Printing operations */
void printDeck(); /* Load deck */ 
void printConsole();


void loadDefaultDeck();
void showDeck();





/***************************************** Global variables *****************************************/

struct Pile *start; // head
struct Pile *end;  // tail

char inputCommandValue[100];
char message[100];

int main() {

    playerInput();
    /*initializeDeck();
    basicLD();
    printDeck();*/
    return 0;

   }


/***************************************** Node operations *****************************************/
void addPile() { /*Push / Add pile */ 
    if(start != NULL){ //Der findes noder i forvejen
        struct Pile* temp1 = malloc(sizeof(struct Pile));
        temp1->next = NULL; 
        temp1->prev = end; 
        end->next = temp1;
        end = temp1;
        end->head = NULL;
        end->tail = NULL; 
    } else { //list is empty
        end = malloc(sizeof(struct Pile));	// setting up space in the memory for the 1st Pile/node.
        end->prev = NULL;
        end->next = NULL;
        start = end;
        end->head = NULL;
        end->tail = NULL; 
    } 
}

/* Fjerner last pile in doubly linked list */
int removePile(){
    if(start != NULL){
        struct Pile* temp1;
        if(end->prev != NULL){ //multiple piles remains
            temp1 = end;
            end = end->prev;
            free(temp1);
            end->next = NULL;
            return 1;
        } else { // Only 1 Pile/node remains
            free(end);
            end = NULL;
            start = NULL;
            return 0;
        }
    } 
    return 0;
}

void addCard(struct Pile *location) { /*Tilføj et kort. Det skal altid tilføjes til den første bunke af alle bunkerne.  */ 
    struct card* temp1 = malloc(sizeof(struct card));
    if (location->tail != NULL) { //Der findes kort i bunken i forvejen 
        temp1->prev = location->tail;
        location->tail->next = temp1;
        location->tail = temp1;
    } else { // Der findes ingen kort i bunken
        location->head = temp1;
        location->tail = temp1;
    }
    temp1->cardRevealed = 0;
}
 
int removeCard(struct Pile *from) { /* Fjerner et kort. Returnerer int ifm om der er flere kort i bunken*/
        if(from->head == NULL){ // Ingen kort findes
            return 0; }
        struct card* temp1;
        if (from->tail->prev == NULL) { //Only one card
            temp1 = from->tail;
            free(temp1);
            from->head = NULL;
            from->tail = NULL; 
            return 0;
        }
        //Flere kort mangler / flere kort i bunken
        temp1 = from->tail;
        from->tail = from->tail->prev;
        free(temp1);
        from->tail->next = NULL; 
        return 1;
}

void moveCard(struct Pile *from, struct Pile *to) { /* Ryk et kort fra en bunke til en anden. */
    if (from->head = NULL) { //Ingen kort
        return; 
    } 
    struct card* tempCard; 
    tempCard = from->tail;
    if (from->tail->prev == NULL) { //Kun et enkelt kort
        from->tail = NULL; 
        from->head = NULL; 
    } else { // Der er flere end eet kort tilbage
        from->tail->prev->next = NULL; 
        from->tail = from->tail->prev;
        tempCard->prev = NULL; 
    } 
    
    if (to->tail = NULL) { // Hvis "til bunken" er tom, peger pointers i til bunken til den nye node (head/tail)
        to->head = tempCard; 
        to->tail = tempCard;
    } else { // Hvis bunken IKKE er tom
        to->tail->next = tempCard;
        tempCard->prev = to->tail;
        to->tail = tempCard; //to->tail->next
    }
}

int moveCards(struct Pile *from, struct Pile *to, int index) { /* Rykker flere kort af gangen. Man kan rykke konkrete kort fra en bunke (v int index)*/
    struct card* tempCard; 
    int count = 0; 

    if (from->head = NULL) { //Ingen kort
        return 0; //Antager det skal være 0...
    } 

    tempCard = from->head;

    for (int i = 0; i < index; ++i) {
        if (tempCard == NULL) { //hvis man går for langt ift hvor mange kort der er 
            break;
        }
        tempCard = tempCard->next;
    }

    if (tempCard == NULL) { // Kortet vi ledte efter fandtes
        return 0; // Antager det skal være 0...
    }

    if (tempCard->prev == NULL) { // Vi tømmer bunken
        from->head = NULL;
        from->tail = NULL; 
    } else { // Der er flere kort tilbage i bunken
        from->tail = tempCard->prev;
        from->tail->next = NULL; 
        tempCard->prev = NULL; 
        
    }
    // Skal nu indsættes i nye bunke
    if (to->head == NULL) { // Hvis til bunken er tom
        to->head = tempCard; //1. element peger på 1. element 

    } else {
        to->tail->next = tempCard; 
        tempCard->prev = to->tail;

    }

    while (tempCard->next != NULL) {
        tempCard = tempCard->next;
    }

    to->tail = tempCard;

} 




void printConsole() {
    printf("\n LAST Command: %s", inputCommandValue);
    printf("\n Message: %s", message);
    printf("\n INPUT >:");
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

    char tempCommandValue[100];

// Denne funktion validerer brugerinput ifm. spillogik, og derefter vælger den tilhørende spillogik

    do { 
        //tempCommandValue = scanf("%s[0-9a-zA-Z ]", inputCommandValue); //"%s"
            fgets(tempCommandValue, 100, stdin);
            if ( tempCommandValue[strlen(tempCommandValue)-1] == '\n') {
                tempCommandValue[strlen(tempCommandValue)-1] = '\0';
            } 

        if (strcmp(tempCommandValue, "LD") == 0) {
            loadDefaultDeck();
            initializeDeck();
            basicLD(); 
            //Load default deck function  
        } else if(strcmp(tempCommandValue, "SW") == 0) {
            showDeck(); 
            //Show deck function 
        } else if(strcmp(tempCommandValue, "SI") == 0) {
            splitDeck(); 
            // Split shuffle function 
        } else if (strcmp(tempCommandValue, "SR") == 0) {
            shuffleRandom();
            // Shuffle random function
        } else if (strcmp(tempCommandValue, "SD") == 0) {
            saveDeck(); 
            // Save current deck function 
        } else if (strcmp(tempCommandValue, "P") == 0) {
            startGame(); 
            // Start game function 
        } else if (strcmp(tempCommandValue, "Q") == 0) {
            quitCurrentGame(); 
            // Quit current game function
        } else if (strcmp(tempCommandValue, "QQ") == 0) {
            quitGame(); 
            // Quit program
        } else if (strcmp(tempCommandValue, "HELP") == 0) {
            helpMessage(); 
            // Help function 
        } else if (tempCommandValue[0] == 'L' && tempCommandValue[1] == 'D'  // "LD <filename>"  
                && tempCommandValue[2] == ' ' && strlen(tempCommandValue)>5) { 
                    // placeholder
                    loadDefaultDeck();
                    initializeDeck();
                    basicLD(); 
        } else { //If incorrect input is taken 
            invalidInput(); 
        }
    
        //Insert printing functions (print funktionen skal være her og ikke i de andre, da det skal være spillogik!!)
        //printDeck();
        printConsole();
    } while (strcmp(inputCommandValue, "QQ") != 0); //If QQ is taken then quit. This while statement is a formality for the loop. It will never run. 
}


void basicLD() {
    char tempArray[20];

    FILE *fp;
    fp = fopen ("CardDeck.txt", "r");		// Open the file with 'read' option.	''
    if(fp==NULL){ exit(-1);}
    while(!feof(fp)){

       fgets(tempArray, 20, fp);
       if (strlen(tempArray)>4) { 
            //Placeholder remove all nodes
       }
       if(tempArray[strlen(tempArray)-1]== '\n'){
            tempArray[strlen(tempArray)-1] = 0;
        }
        addCard(end);
        end->tail->suit = tempArray[1];
        end->tail->value = tempArray[0];
    }
    fclose(fp);
}   

// Initialize all piles
void initializeDeck() {
    for (int i=0 ; i < 12 ; i++) {
        addPile();
    }
}

// Sletter alle piles og kort i gamet
void clearGame() { 
    while (end != NULL) {
        while (end->tail != NULL) {
            removeCard(end);
        } 
        removePile();
    }
}

void printDeck() {
    struct Pile *tempPile = NULL, *tempFoundation = NULL; 
    struct card *tempCard = NULL; 
    int row = 0, column = 0, lastElementCount = 0, count = 0; 
    tempFoundation = start->next->next->next->next->next->next->next; //for 8 (7+1) columns
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    while (1) { //infinite loop
        tempPile = start; 
        for (int i= 0 ; i < column ; i++) {
            tempPile = tempPile->next;

        } 
        if (tempPile->head != NULL) {//navigere til hvilket kort vi er nået til
            tempCard = tempPile->head;
            count = 0; 
            while (count < row) { // vil gerne hoppe fremad til næste node
                tempCard = tempCard->next;
                count++;
                if (tempCard->next == NULL) {
                    lastElementCount++;
                }
            }
        
        } else {
            tempCard = NULL; 
            lastElementCount++;
        } 
        //PRINTING TIME!
        if (tempCard == NULL) {
            //Nothing
        } else {
            if (tempCard->cardRevealed = 0) { // det må ikke vises hvad der er i, print []
                printf("[]");

            } else {
                printf("%c%c", tempCard->value, tempCard->suit);         
            }
        }
        printf("\t");  // hop til næste element

        column++;
        if (column == 7) {
            if (row == 0 || row == 2 || row == 4 || row == 6) {
                if(tempFoundation->tail == NULL) {
                    printf("[]");                
                } else {
                    printf("%c%c", tempFoundation->tail->value, tempFoundation->tail->suit);    
                }
                printf("\tF%d", row/2+1); 
                if (tempFoundation->next != NULL){
                    tempFoundation = tempFoundation->next;
                }

            }
            row++;
            printf("\n");
            if (row > 5 && lastElementCount == 7) { // vi vil gerne breake / ud af infinite loop
                break;
            }

        }

        column = column % 7;
    } // End infinite loop
}


void dealCards() {
    struct Pile *tempPile = NULL; 
    int count = 0; 
    tempPile = start;

    while (end->tail != NULL) { // 12th hidden list accessed
        moveCard(end, tempPile);
        count++;
        if (count == 7) {
            tempPile = start;
        } else {
            tempPile = tempPile->next;
        }
        count = count % 7; //makes it dynamic
    }
    
}


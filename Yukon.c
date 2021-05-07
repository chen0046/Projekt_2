#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*Datatype for kort*/
struct Card { 
  char *card; /*card[3]; //Array med 3 pladser til kulør, kortværdi og nullpointer.*/
  int revealed; 
  struct Node* next; // Pointer to next node in DLL 
  struct Node* prev; // Pointer to previous node in DLL 
}; 

/*Datatype for bunke*/
struct Pile { 
  char *description; 
  int index; 
  struct Pile* next; // Pointer to next Pile 
  struct Pile* prev; // Pointer to previous Pile 
  struct Card* head; // Pointer to next node in DLL 
  struct Card* tail; // Pointer to previous node in DLL 
}; 


/**  * All node operations. Skal fungere for hele spillet */ 
void addPile(); /*Push / Add pile */ 
void removePile(); /* Pop / Remove pile */
void addCard(); /*Tilføj et kort. Det skal altid tilføjes til den første bunke af alle bunkerne.  */
int removeCard(struct Pile *from); /* Fjerner et kort. Returnerer int ifm om der er flere kort i bunken*/
void moveCard(struct Pile *from, struct Pile *to); /* Ryk et kort fra en bunke til en anden. */
int moveCards(struct Pile *from, struct Pile *to, int index); /* Rykker flere kort af gangen. Man kan rykke konkrete kort fra en bunke (v int index)*/

/* Logik */
void shuffle(); /* Shuffle function. */
void clearDeck(); /* Reset game */
void generateGame(); /* Start game */

void printDeck(); /* Load deck */ 

struct Pile *start; //head?
struct Pile *end;  //tail? 

int main(void){
    //addPile();
    //removePile();
    //addCard();
}

/* Adds empty pile */
/* See A017 DLL - Push function for inspiration - tail = start, head = end  */
void addPile(){ 
    if(start != NULL){
        struct Pile* temp1 = malloc(sizeof(struct Pile));
        temp1->next = NULL; 
        temp1->prev = start; 
        start->next = temp1;
        start = temp1;
    } else { //list is empty
        end = malloc(sizeof(struct Pile));	// setting up space in the memory for the 1st Pile/node.
        end->prev = NULL;
        end->next = NULL;
        start = end;
        //printf("Node specific addr: %p\n", end);
    }

} 

/* Removes pile. Shall only be used when game is not being played, therefore cards are not removed */
/* See A017 DLL - Pop function for inspiration - tail = start, head = end */
void removePile(){
    if(start != NULL){
        struct Pile* temp1;
        if(start->prev != NULL){
            temp1 = start;
            start = start->prev;
            free(temp1);
            start->next = NULL;
        } else { // Only 1 Pile/node remains
            free(start);
            end = NULL;
            start = NULL;
        }
    } else { printf("List is empty.\n"); }
}

/* Adds one card to the pile */
/* See A017 DLL - Pop function for inspiration - tail = start, head = end */

// SKAL ÆNDRES MED REFERENCER TIL CARD HEAD/TAIL 
void addCard(){
    if(end != NULL){
        struct Pile* temp1 = malloc(sizeof(struct Pile));
        temp1->next = NULL; 
        temp1->prev = start; 
        start->next = temp1;
        start = temp1;
    } else { //list is empty or no Piles found
        end = malloc(sizeof(struct Pile));	// setting up space in the memory for the 1st node.
        end->prev = NULL;
        end->next = NULL;
        start = end;
        //printf("Node specific addr: %p\n", end);
    }

} 

/* Removes one card from the pile */
/* See A017 DLL - Pop function for inspiration - tail = start, head = end */
int removeCard(struct Pile *from){
    if(start != NULL){
        struct Pile* temp1;
        if(start->prev != NULL){
            temp1 = start;
            start = start->prev;
            free(temp1);
            start->next = NULL;
            return //;
        } else { // Only 1 node remains
            free(start);
            end = NULL;
            start = NULL;
            return //;
        }
    } else { return //;");}
}

/*
void push(int value){
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        temp1->prev = tail; 
        temp1->data = value;
        tail->next = temp1;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));	// setting up space in the memory for the 1st node.
        head->prev = NULL;
        head->next = NULL;
        head->data = value;
        tail = head;
        printf("Node specific addr: %p\n", head);
    }

} 
*/

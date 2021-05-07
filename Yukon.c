#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Card { 
  char card[3]; //Array med 3 pladser til kulør, kortværdi og nullpointer.
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

void printDeck(); 

struct Pile *start;
struct Pile *end; 

int main(void){
    //Nothing
}

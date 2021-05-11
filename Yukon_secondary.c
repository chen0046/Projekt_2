#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct card* CardDeck();
struct card* MixCards(struct card* deck);
void Print(struct card* deck);

typedef struct card {
char suit;
int value;
struct card *next;
struct card *prev;
} card;


int main() {
struct card *deck;

srand(time(NULL)); // initialisere random funktion vha time libary

deck = CardDeck(); 

printf("Print 52 kort\n");
Print(deck);

deck = MixCards(deck); // blande kort og print den nye deck
printf("\nBlandede kort\n");
Print(deck);
return 0;
}


struct card* CardDeck() {
struct card* deck = NULL,*current = NULL, *node;   //laver en lokalt struct og pointers
int i,j;

for(j = 1; j <= 13; j++) { //for loop 1 til 13 laves til kort værdierne
for(i = 0; i < 4; i++) { //for loop 1 til 4 der kører til suits
    node = (struct card *)malloc(sizeof(struct card));  //allokere plads til struct card
if(i == 0)  //if loop der sætter for loop 1 til 4 der definere suits
    node->suit = 'S';      
else if(i == 1)
    node->suit = 'D';
else if(i == 2)
    node->suit = 'H';
else
    node->suit = 'C';
    node->value = j;
    node->next = NULL;
if(current == NULL) {    
    deck = node;                        
} else {
    current->next = node;
}
    current = node;
}
}
return deck;
}


struct card* MixCards(struct card* deck) {
struct card* tempCard;
int n, i, j, b;
struct card** tempA;

for(n = 0, tempCard = deck; tempCard != NULL; n++, tempCard = tempCard->next);
    tempA = (struct card**)malloc (n * sizeof(struct card*));
for(i = 0, tempCard = deck; tempCard != NULL; i++, tempCard = tempCard->next) { 
    tempA[i] = tempCard;
}
for(i = 0; i < 1000; i++) { // Loop 1000 gange
for(j = 0; j < 52; j++) { // for hver kort
    b = rand() % 52; // swap 52 kort 
    tempCard = tempA[j];
    tempA[j] = tempA[b];
    tempA[b] = tempCard;
}
}


for(i = 0; i < n - 1; i++) {
tempA[i]->next = tempA[i+1];
}
tempA[i]->next = NULL; 
tempCard = tempA[0]; 
return tempCard;
}

void giveSuit(char suit) {
switch(suit) {
case 'S':
    printf("S"); 
    return;
case 'D':
    printf("D");
    return;
case 'H':
    printf("H");
    return;
case 'C':
    printf("C");
    return;
}
};
// her printes kortene i linked list
void Print(struct card* deck) {
char text[20];
int i;
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
for(i = 0; deck != NULL; i++, deck = deck->next) {
if(i % 7 == 0) //fordel kort i 7 kolumner
    printf("\n");
if(deck->value == 1)
    printf("A");
else if(deck->value == 11)
    printf("J");
else if(deck->value == 12)
    printf("Q");
else if(deck->value == 13)
    printf("K");
else
    printf("%d", deck->value);
    giveSuit(deck->suit);
    printf("\t");
}
    printf("\n");
    printf("last command:\n %s", text);
    printf("message:OK\n");
    printf("input:");
    scanf("%s",text);
}



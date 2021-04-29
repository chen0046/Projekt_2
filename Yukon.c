#include <stdio.h>


int main(){
char value[14][6]={"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
  char suit[4][9]= {"Hearts", "Diamonds", "Clubs", "Spades"};
   
  int i=0;
  int j=0;
   
  for (i=0; i<13; i++){
      for (j=0; j<4; j++){
           printf("The %s of %s\n\n", value[i], suit[j]);
      }
  }
  system("pause");
}''
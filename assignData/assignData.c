#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _state{
       char name [ 31 ]  ;  // to store 30 chars of state name
       char capital [ 31 ] ; // to store 30 char of capital
 }  State_T ;

State_T StateList[6] = {0}; // array of structures , one cell to store state and capital
State_T *ListPtr = StateList;//initializing pointer to point to StateList

void printStateNameAndCapitalsUsingPointer (  State_T *ptr, int len  ){

	int i;
	printf("\n\nAs a Pointer: ");
	for(i = 0; i < len; i++){

		printf("\n%s", (ptr+i)->name);
		printf(" : %s", (ptr+i)->capital);
	}

	// Task 4:  Fill in the code
	// use the ptr to print
	// This function will print the state in 30 character space, and capital in 30 character space.

}

void printStateNameAndCapitalsUsingArrayIndex (  State_T  data[ ] , int len  ){

	int i;
	printf("\n\nAs an Array: ");
	for(i = 0; i < len; i++){
	
		printf("\n%s", StateList[i].name);
		printf(" : %s", StateList[i].capital);
	}
	// Task 5
	// print the structure using data array
	//This function will print the state in 30 character space, and capital in 30 character space.
}

int assignData()
{
 	int  i, j, k;
 	FILE *fp;
	char ch;
	char temp[30];
	char ctemp[30];
	bool repeat = false; 
 	fp = fopen("stateCap.input","r");
 	if (fp == NULL)
 	{
		printf("Unable to open the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of the file are:\n", fp);
	i = 0 ;
	
	while(1){
		repeat = false;
		j = 0;
 	
		ch = fgetc(fp);//get first character of the file
		if(ch == EOF)
			break;
		while(ch != ' '){
			temp[j++] = ch;
	//		printf("%c", temp[j-1]);
			ch = fgetc(fp);
			if(ch == EOF)
				break;

		}
		temp[j] = '\0';

		if(strcmp(temp, "New") == 0){
			repeat = true;
		//	printf("\nr");
		}
		else if(strcmp(temp, "North") == 0){
			repeat = true;
		//	printf("\nr");
		}
		else if(strcmp(temp, "Rhode") == 0){
			repeat = true;
		}
		else if(strcmp(temp, "South") == 0){
			repeat = true;
		}
		else if(strcmp(temp, "West") == 0){
		repeat = true;
		}
		else{
			repeat = false;
		//	printf("\nD");
		}
	
		if (repeat == true){
		//	printf("repeat");
			temp[j++] = ch;
			ch = fgetc(fp);
			if(ch == EOF)
				break;
			while(ch != ' '){
				temp[j++] = ch;
			//	printf("%c", temp[j-1]);
				ch = fgetc(fp);
				if(ch == EOF)
					break;
			}
			temp[j] = '\0';
		}	

		strcpy(StateList[i].name,temp);
	//	printf("\n%s", StateList[i].name);

		k = 0;
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		while(ch != '\n'){

		ctemp[k++] = ch;
		//printf("%c", ctemp[k-1]);
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		}
		ctemp[k] = '\0';

		strcpy(StateList[i++].capital, ctemp);
	//	printf(": %s", StateList[i-1].capital);
	}
  //while ( 1 )
  //{
    //char ch;
    //ch = fgetc (fp);
	/*
    if ( ch == '+' || ch == '*' || ch == '-' || ch == '/' )
      {
         printf ( "i=%c ", ch );
         quizData[i++] = ch; // not casting, but I should actually
         fscanf ( fp, "%d", &quizData [i++]);
         printf ( "%d ", quizData [i-1] );
         fscanf ( fp, "%d", &quizData [i++]);
         printf ( "%d \n ", quizData [i-1] );
      }
	*/

   // ch = fgetc (fp);
   // if ( ch == EOF )
  //     break;
 // }

  fclose(fp);
}

int main(){
	assignData();
	printStateNameAndCapitalsUsingPointer(ListPtr, 6);
	printStateNameAndCapitalsUsingArrayIndex(StateList, 6);
	
}

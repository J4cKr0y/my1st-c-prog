#include <stdio.h>
#include "logic.h"

void collectName(){
	char name[50];
	printf("Entrez votre nom:");
	scanf("%49s",name);
	collectFirstName(name);}

void collectFirstName(char* name){
	char firstname[50];
	printf("Entrez votre prénom:");
	scanf("%49s", firstname);
	storeInfo(name, firstname);}

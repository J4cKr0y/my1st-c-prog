#include <stdio.h>
#include <string.h>
#include "logic.h"
#include "validation.h"
void storeInfo(char* name, char* firstname){
	mergeWelcomeMessage(name, firstname);}

void mergeWelcomeMessage(char* name, char* firstname){
	char message[120];
	sprintf(message, "Bonjour %s %s, bienvenue !", firstname, name);
	validateMessage(message);}

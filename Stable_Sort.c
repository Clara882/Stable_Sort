#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
#include<unistd.h>

int option;
void help(void){
	printf("Version: 1.0 \n");
	printf("Autor: Clara Stute\n");
	printf("Mit diesem Programm, können bis zu 50 ganze Zahlen der größe nach aufsteigend sortiert werden.\n");
	printf("Die Anzahl der Element (bis 50) und ihre Werte können beim start des Programms ausgewählt werden.\n");
	printf("Die sortierten Werte werden in die Konsole ausgegeben.\n");
}
int main(int argc, char *argv[]){
	while ((option = getopt(argc, argv, "h")) != -1) {
		switch (option) {
			case 'h' :
				help();
				break;
		}
	}

	int array[50];	// Maximal 50 Werte
	int anzahl;	// Anzahl der zu sortierenden Werte
	int x; 
	int y; 
	int zwischenwert;	// temporäre Wert zum zwischenspeichern eines Elements


	printf("Bitte geben sie die Anzahl der zu sortierenden Elemente ein:");
	scanf("%d",&anzahl);
	printf("Bitte geben sie die Werte der Elemente ein:");
	for(x=0;x<anzahl;x++)
		scanf("%d",&array[x]);
	for(x=0;x<anzahl-1;x++){
		for(y=0;y<anzahl-x-1;y++){
			if(array[y]>array[y+1]){
				zwischenwert=array[y];
				array[y]=array[y+1];
				array[y+1]=zwischenwert;
			}
		}
	}
	printf("Array nach Bubble Sort:");
	for(x=0;x<anzahl;x++){
		printf("%d",array[x]);
	}
	return 0;
}

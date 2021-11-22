#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 32769

/*
Pedro Henrique Cometti Lelis
156.341
tarefa 3 aed - marcio
*/

//===================== TAD ROW =====================//
//Itens struct
typedef struct{
    int strCombat;
    int index;
    int strInitial;
} TProfile;

//Row struct
typedef struct{
    TProfile fighter[MAX];
    int front, back;
} TRow;

//Inicializing a row, setting the 'front' and 'back' pointer to 0
void TRow_start(TRow *row){
	row->front = 0;
    row->back = 0;
}

//Verifying if the row is empty. Return the test: if empty is true, so '(row->front == row->back)' is true
int TRow_isEmpty(TRow *row){
	return (row->front == row->back);
}

//Row length
int TRow_length(TRow *row){
    //        if this                  so return this,             else, so return this         
	return ( (row->back >= row->front) ? (row->back - row->front) : (MAX + row->back - row->front) );
}

//Puting data on the row (from the back)
int TRow_put(TRow *row, TProfile x){
	//If back+1 equal to front, means the next will be the data on the front, meaning no extra space to put more. Row full
	if (row->front == (row->back + 1) % MAX){
        printf("Row Full");
		return 0;
	}

	row->fighter[row->back] = x;
	row->back = (row->back + 1) % MAX;
	return 1;
}

//Taking data from the row (from the front)
int TRow_pop(TRow *row, TProfile *pX){
	//If empty row. Theres nothing to pop
	if (TRow_isEmpty(row)){
		printf("Empty row. Nothing to pop");
		return 0;
	}
	
	*pX = row->fighter[row->front];
    row->front = (row->front + 1) % MAX;
	return 1;
}

//===================== MAIN FUNCTION =====================//
int main(){
	int n, k, i, str, strFinal;

	TRow* row;
    row = (TRow *) malloc (sizeof(TRow)); //IMPORTANT

	//printf("Digit the value of 'n' (for 2^n fighters) and 'k' (for strength recover after fight): ");
	scanf("%i", &n);
	scanf("%i", &k);
    
    TRow_start(row); 

    //Registering the fighters in a temporary profile array and putting data into the row
    TProfile profile;
    for (i=0; i<(pow(2, n)); i++){
        scanf("%i", &str);

        //Puting in temporary struct 'profile'
        profile.index = i;
        profile.strCombat = str;
        profile.strInitial = str;

        //Puting the 'profile' in the row
        TRow_put(row, profile);
    }
    
    //While dont have a winner, put waves of 1x1 fight
    TProfile aux1, aux2;
    for (i=0; i<((pow(2, n)) - 1); i++){
        //Picking data (profile struct with 3 ints) of 2 fighters
        TRow_pop(row, &aux1);
        TRow_pop(row, &aux2);
        
        //Pick 2 from from to fight 1x1 and put back only the winner on the row
        if (aux1.strCombat >= aux2.strCombat){ //Fighter1 wins
            strFinal = aux1.strCombat - aux2.strCombat + k;
            if (strFinal > aux1.strInitial){
                strFinal = aux1.strInitial;
            }
            aux1.strCombat = strFinal;
            TRow_put(row, aux1);

        } else{ //Fighter2 wins
            strFinal = aux2.strCombat - aux1.strCombat + k;
            if (strFinal > aux2.strInitial){
                strFinal = aux2.strInitial;
            }
            aux2.strCombat = strFinal;
            TRow_put(row, aux2);
        }
    }

    //Showing the winner
    TRow_pop(row, &aux1);
    printf("%i", aux1.index+1);

	//Freeing space on row
	free(row);

	return 0;
}

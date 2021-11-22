#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Pedro Henrique Cometti Lelis
156.341
tarefa 3 aed - marcio
*/

//===================== TAD ROW =====================//
//Fighter profile struct
typedef struct{
    int strCombat;
    int index;
    int strInitial;
} TProfile;

typedef struct SCell *TPointer;

//Cell struct (with fighter profile + pointer to next)
typedef struct SCell{
    TProfile fighter;
    TPointer next;
} TCell;

//Row struct
typedef struct{
    TPointer front, back;
    int length;
} TRow;

//Inicializing a row, setting the 'front' and 'back' pointer to NULL 
void TRow_start(TRow *row){
	row->front = NULL;
    row->back = NULL;
    row->length = 0;
}

//Verifying if the row is empty. Return the test: if empty is true, so '(row->front == NULL)' is true
int TRow_isEmpty(TRow *row){
	return (row->front == NULL);
}

//Row length
int TRow_length(TRow *row){  
	return (row->length);
}

//Puting data on the row (from the back)
int TRow_put(TRow *row, TProfile x){
	TPointer pNew;

    pNew = (TPointer) malloc (sizeof(TCell));
    pNew->fighter = x;
    pNew->next = NULL;

    if(TRow_length(row) == 0){
        row->front = pNew;

    } else{
        row->back->next = pNew;
    }

    row->back = pNew;
    row->length++;

    return 1;
}

//Taking data from the row (from the front)
int TRow_pop(TRow *row, TProfile *pX){
	if (TRow_isEmpty(row)){
		printf("Empty row. Nothing to pop\n");
		return 0;
	}

    TPointer pAux;

    pAux = row->front;
    row->front = pAux->next;
    *pX = pAux->fighter;
    
    free(pAux);
    row->length--;

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

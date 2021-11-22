#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Pedro Henrique Cometti Lelis
156.341
tarefa 4 aed tad list hot potato - marcio
*/

//===================== TAD LIST =====================//
//Item struct
typedef struct{
    char name[20];
    //others
} TItem;

typedef struct SCell *TPointer;

//Cell struct (with fighter profile + pointer to next)
typedef struct SCell{
    TItem item;
    TPointer next;
} TCell;

//Row struct
typedef struct{
    TPointer first, last;
    int length;
} TList;

//Inicializing a list, setting the 'first' and 'last' pointer to 0
void TList_start(TList *list){
	list->first = NULL;
    list->last = NULL;
    list->length = 0;
}

//Verifying if the list is empty. Return the test: if empty is true, so '(list->first == NULL)' is true
int TList_isEmpty(TList *list){
	return (list->first == NULL);
}

//Row length
int TList_length(TList *list){
	return (list->length);
}

//Returns a pointer to p-th item of list
TPointer TList_return(TList *list, int p){
    TPointer pPointer;
    int index = 0;

    pPointer = list->first;
    while ((pPointer != NULL) && (index != p)){
        pPointer = pPointer->next;
        index++;
    }

    return pPointer;
}

//Puting in 1st index of list
int TList_putFirst(TList *list, TItem x){
    TPointer pNew;

    pNew = (TPointer) malloc (sizeof(TCell));
    pNew->item = x;
    pNew->next = list->first;

    if (TList_isEmpty(list)){
        list->last = pNew;
    }

    list->first = pNew;
    list->length++;

    return 1;
}

//Puting in last index of list
int TList_putLast(TList *list, TItem x){
    TPointer pNew;

    pNew = (TPointer) malloc (sizeof(TCell));
    pNew->item = x;
    pNew->next = NULL;

    if (TList_isEmpty(list)){
        list->first = pNew;
    } else{
        list->last->next = pNew;
    }

    list->last = pNew;
    list->length++;

    return 1;
}

//Puting in p-th pointer index of list
int TList_put(TList *list, TPointer index, TItem x){
	TPointer pLast, pNew;

    if (index == list->first){
        return TList_putFirst(list, x);
    } else if (index == NULL){
        return TList_putLast(list, x);
    } else{
        pLast = list->first;

        while ((pLast != list->last) && (pLast->next != index)){
            pLast = pLast->next;
        }

        if (pLast == list->last){
            return 0;
        }

        pNew = (TPointer) malloc (sizeof(TCell));
        pNew->item = x;
        pNew->next = pLast->next;
        pLast->next = pNew;
        list->length++;

        return 1;
    }
}

//Puting in p-th index of list
int TList_put2(TList *list, int index, TItem x){
	TPointer pLast, pNew;
    int i;


    if (index == 1){
        return TList_putFirst(list, x);
    } else if (index == TList_length(list)){
        return TList_putLast(list, x);
    } else if ((index < 0) || (index > TList_length(list))){
        return 0;
    } else{
        i = 2;
        pLast = list->first;

        while (i != index){
            pLast = pLast->next;
            i++;
        }

        if (pLast == list->last){
            return 0;
        }

        pNew = (TPointer) malloc (sizeof(TCell));
        pNew->item = x;
        pNew->next = pLast->next;
        pLast->next = pNew;
        list->length++;
        return 1;
    }
}

//Taking data from first index of list
int TList_popFirst(TList *list, TItem *pX){
	//If empty list. Theres nothing to pop
	if (TList_isEmpty(list)){
        printf("List full");
		return 0;
	}

    TPointer pAux;

	pAux = list->first;
    list->first = pAux->next;
    *pX = pAux->item;
    free(pAux);
    list->length--;

	return 1;
}

//Taking data from last index of list
int TList_popLast(TList *list, TItem *pX){
	//If empty list. Theres nothing to pop
	if (TList_isEmpty(list)){
        printf("List full");
		return 0;
	}

    TPointer pLast, pAux;

	pLast = list->first;
    if (pLast == list->last){
        return TList_popFirst(list, pX);
    } else {
        while (pLast->next != list->last){
            pLast = pLast->next;
        }

        pAux = list->last;
        pLast->next = NULL;
        list->last = pLast;
        *pX = pAux->item;
        free(pAux);
        list->length--;

        return 1;
    }
}

//Taking data from p-th pointer index of list
int TList_pop(TList *list, TPointer index, TItem *pX){
	//If empty list. Theres nothing to pop
	if (TList_isEmpty(list)){
        printf("List full");
		return 0;
	}

    TPointer pLast, pAux;

    if (index == list->first){
        return TList_popFirst(list, pX);
    } else if (index == list->last){
        return TList_popLast(list, pX);
    } else {
        pLast = list->first;
        while ((pLast != list->last) && (pLast->next != index)){
            pLast = pLast->next;
        }
        if (pLast == list->last){
            return 0;
        }

        pAux = pLast->next;
        pLast->next = pAux->next;
        *pX = pAux->item;
        free(pAux);
        list->length--;

        return 1;
    }
}


//===================== MAIN FUNCTION =====================//
int main(){
	int N, K, i;
    char name[20];
	TList* list;
    
    list = (TList *) malloc (sizeof(TList)); //IMPORTANT
    TList_start(list);

    scanf("%i %i", &N, &K);

    //Picking the kid's name, putting in a struct and put the struct in the list
    TItem kid;
    for (i=0; i<N; i++){
        scanf("%s", name);

        strcpy(kid.name, name);
        TList_put(list, TList_return(list, i), kid);
    }

    //While remains more than 1 child, the game continues
    i = K;
    while (TList_length(list) > 1){
        //Killing the unlucky child
        TList_pop(list, TList_return(list, i), &kid);
        //Print killed child
        printf("%s\n", kid.name);
        //Recalc of where potatos go. Cant be more than list length 
        i = (i + K) % TList_length(list);
    }

    //Poping the remaining alive/winner child to print
    TList_pop(list, TList_return(list, 0), &kid);
    printf("%s", kid.name);
    
	//Freeing space on list
	free(list);
    
	return 0;
}

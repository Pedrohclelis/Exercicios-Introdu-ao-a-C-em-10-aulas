#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 1000
#define START 0

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

//Row struct
typedef struct{
    TItem item[MAX];
    int first, last;
} TList;

//Inicializing a list, setting the 'first' and 'last' pointer to 0
void TList_start(TList *list){
	list->first = 0;
    list->last = 0;
}

//Verifying if the list is empty. Return the test: if empty is true, so '(list->first == list->last)' is true
int TList_isEmpty(TList *list){
	return (list->first == list->last);
}

//Row length
int TList_length(TList *list){
	return (list->last - list->first);
}

//Puting data on the list 
int TList_put(TList *list, int index, TItem x){
	//List full
	if ((list->last == MAX) || (index < list->first) || (index > list->last)){
        printf("List full");
		return 0;
	}

    int aux;
    for (aux = list->last - 1; aux >= index; aux--){
        //Shifting all the elements +1 position to down. From the last one to first one
        list->item[aux+1] = list->item[aux];
    }

    list->item[index] = x;
    list->last++;
	return 1;
}

//Taking data from the list 
int TList_pop(TList *list, int index, TItem *pX){
	//If empty list. Theres nothing to pop
	if ((TList_isEmpty(list)) || (index < list->first) || (index >= list->last)){
        printf("List full");
		return 0;
	}

	*pX = list->item[index];

    int aux;
    for (aux = index + 1; aux < list->last; aux++){
        //Shifting all the elements +1 position to up. From the first one to last one
        list->item[aux-1] = list->item[aux];
    }

    list->last--;
	return 1;
}

//List lists (EXTRA)
void TList_list(TList *list){
    int i;
    for (i=0; i<11; i++){
        printf("> List.item[%i].name = %s\n", i, list->item[i].name);
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
        TList_put(list, i, kid);
    }

    //While remains more than 1 child, the game continues
    i = K;
    while (TList_length(list) > 1){
        //Killing the unlucky child
        TList_pop(list, i, &kid);
        //Print killed child
        printf("%s\n", kid.name);
        //Recalc of where potatos go. Cant be more than list length 
        i = (i + K) % TList_length(list); 
    }

    //Poping the remaining alive/winner child to print
    TList_pop(list, 0, &kid);
    printf("%s", kid.name);

	//Freeing space on list
	free(list);

	return 0;
}

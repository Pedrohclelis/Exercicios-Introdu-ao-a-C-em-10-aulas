#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_PILHA 100
 
/*
Pedro Henrique Cometti Lelis
156.341
tarefa 2 aed - marcio
*/
 
 
//Estrutura da pilha
typedef struct{
    float item[MAX_PILHA];
    int topo;
} TPilha;
 
 
//Criando uma pilha, setando o apontador do 'topo' para 0
TPilha* inicia(){
    TPilha* pi = (TPilha *) malloc (sizeof(TPilha));
    pi->topo = 0;
    return pi;
}
 
//Verificando se a pilha é vazia. Retorna o teste, se for verdadeiro é falso, ou seja, a pilha é verdadeira
int TPilha_ehvazia(TPilha *pi){
    return (pi->topo == 0);
}
 
//Empilhando dados na pilha
int TPilha_empilha(TPilha *pi, float x){
    //Apontador 'topo' apontando pro ultimo espaço da pilha = pilha cheia
    if (pi->topo == MAX_PILHA){
        return 0;
    }
    
    pi->item[pi->topo] = x;
    pi->topo++;
    return 1;
}
 
//Desempilhando dados na Pilha
int TPilha_desempilha(TPilha *pi, float *px){
    //Se a pilha ta vazia, nao tem oque desempilhar
    if (TPilha_ehvazia(pi)){
        printf("pilha vazia");
        return 0;
    }
    
    pi->topo--;
    *px = pi->item[pi->topo];
    return 1;
}
 
//Tamanho da pilha
int TPilha_tamanho(TPilha *pi){
    return (pi->topo);
}
 
//Listar elementos da pilha
void consultaPilha(TPilha *pi){
    int i;
 
    for (i = pi->topo-1; i >= 0; i--){
        printf("Item[%i]: %f \n", i, pi->item[i]);
    }
}
 
 
int main(){
 
    char exp[100];
    int i, j, jaLido;
    float auxVar, aux1, aux2, var[52][2];
    TPilha *pilha;
    
    scanf("%s", exp);
    int tamExp = strlen(exp);
    
    //Assimilando as variaveis letras da expressão
    for (i=0; i<tamExp; i++){
        
        //Verificaçao na lista de codigos de 'var' para cada caracter de exp[i]
        jaLido = 0;
        for (j=0; j<52; j++){
            //Se o codigo do numero de 'exp[i]' já estiver na lista de codigos de var (var[j][0]), pula pro proximo caracter da expressão
            if(exp[i] == var[j][0]){
                jaLido = 1;
            }
        }
        
        //Se o caracter exp[i] ja teve seu codigo lido por 'var', então passa pro proximo carcater
        if (jaLido == 1){
            continue;
        }
                
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z')){
            var[i][0] = exp[i]; //Seta o slot de codigo de 'var' para o codigo da letra de 'exp[i]'
            scanf("%f", &var[i][1]);
        }
    }
    
    //Inicia a pilha
    pilha = inicia();
    
    //Ler cada caracter da expressão
    for (i=0; i<tamExp; i++){
        switch (exp[i]){
            case '+':
                TPilha_desempilha(pilha, &aux1); //Ultimo numero
                TPilha_desempilha(pilha, &aux2); //Penultimo numero
                auxVar = aux2 + aux1;
                
                TPilha_empilha(pilha, auxVar);
                break;
            case '-':
                TPilha_desempilha(pilha, &aux1); //Ultimo numero
                TPilha_desempilha(pilha, &aux2); //Penultimo numero
                auxVar = aux2 - aux1;
                
                TPilha_empilha(pilha, auxVar);
                break;
            case '*':
                TPilha_desempilha(pilha, &aux1); //Ultimo numero
                TPilha_desempilha(pilha, &aux2); //Penultimo numero
                auxVar = aux2 * aux1;
                
                TPilha_empilha(pilha, auxVar);
                break;
            case '/':
                TPilha_desempilha(pilha, &aux1); //Ultimo numero
                TPilha_desempilha(pilha, &aux2); //Penultimo numero
                auxVar = aux2 / aux1;
                
                TPilha_empilha(pilha, auxVar);
                break;    
            //Se for uma letra
            default:
                //Varrer a lista de variaveis
                for (j=0; j<52; j++){
                    //Se o codigo do numero de 'exp[i]' estiver na lista de codigos de var (var[j][0]), pega seu valor em numero correspondente (var[j][1])
                    if(exp[i] == var[j][0]){
                        auxVar = var[j][1];
                    }
                }
                
                TPilha_empilha(pilha, auxVar);
                
                break;
        }
    }
    TPilha_desempilha(pilha, &aux1);
    printf("%f", aux1);
    
    
    //Liberando espaço na pilha
    free(pilha);
    
    return 0;
}
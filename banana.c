/*
	Nome: Caio Bonani Carvalho
	RA: 156.313
	Turma: IB
	
    Algoritmos e Estruturas de Dados I 

	Exercício 1
*/

//Bibliotecas usadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definindo a struct com os dados dos carros.
typedef struct Carro{
    char Marca[15];
    char Modelo[25];
    int Ano_de_fabricacao;
    char Placa_do_carro[6];
    int Quilometragem;
    int Numeros_de_portas;
    char Ar_condicionado[1];
}Carro;

//Função para criar um novo cadastro.
void novo_cadastro(Carro *carro){

  FILE *arquivo;

  arquivo = fopen("carros.txt", "a");

  if (arquivo == NULL){
    printf("Não foi possível achar o arquivo");
    return;
  }

  system("clear||cls");

  printf("----------------------------------------------------------");
  printf("\nCadastrar Veiculo!");

  printf("\n\nQual a marca do carro: \n");
  scanf("%s", carro->Marca);
  getchar();
  fprintf(arquivo, "%s\n", carro->Marca);

  printf("Qual o modelo do carro: \n");
  scanf("%s", carro->Modelo);
  getchar();
  fprintf(arquivo, "%s\n", carro->Modelo);

  printf("Qual o ano de fabricacao do carro: \n");
  scanf("%d", &carro->Ano_de_fabricacao);
  getchar();
  fprintf(arquivo, "%d\n", carro->Ano_de_fabricacao);

  printf("Qual a placa do carro: \n");
  scanf("%s", carro->Placa_do_carro);
  getchar();
  fprintf(arquivo, "%s\n", carro->Placa_do_carro);

  printf("Qual a quilometragem do carro: \n");
  scanf("%d", &carro->Quilometragem);
  fprintf(arquivo, "%d\n", carro->Quilometragem);

  printf("Qual o numero de portas do carro: \n");
  scanf("%d", &carro->Numeros_de_portas);
  fprintf(arquivo, "%d\n", carro->Numeros_de_portas);

  printf("O carro tem Ar condicionado(s/n): \n");
  scanf("%s", carro->Ar_condicionado);
  getchar();
  fprintf(arquivo, "%s\n", carro->Ar_condicionado);

  system("clear||cls");
  printf("\nCarro cadastrado com sucesso!\n");

  fclose(arquivo);
}

//Função para alterar os dados.
void alt_dados(Carro* carros){

    int i=0, num, linha=1, saida_cad=0, placa_encontrada=1, placa_existe, opcao_alt_cadast=0;
    char aux[15], placa[6], caracter;
    FILE *arquivo;

    arquivo = fopen("carros.txt", "r");

    if (arquivo == NULL){
        printf("Não foi possível achar o arquivo");
        return;
    }

    while(fscanf(arquivo, "%s", aux) != EOF){
        strcpy(carros[i].Marca, aux);
        fscanf(arquivo, "%s", carros[i].Modelo);
        fscanf(arquivo, "%d", &carros[i].Ano_de_fabricacao);
        fscanf(arquivo, "%s", carros[i].Placa_do_carro);
        fscanf(arquivo, "%d", &carros[i].Quilometragem);
        fscanf(arquivo, "%d", &carros[i].Numeros_de_portas);
        fscanf(arquivo, "%s", carros[i].Ar_condicionado);
        i++;
    }

    rewind(arquivo);
    caracter = getc(arquivo);

    while(caracter!=EOF){
        if(caracter=='\n'){
            linha++;
        }
        caracter = getc(arquivo);
    }

    linha = linha - 1;
    linha = linha/7;

    system("clear||cls");

    printf("----------------------------------------------------------");
    printf("\nAlterar Dados!");

    
    printf("\n\nDigite a placa do carro que voce deseja visualizar os dados: ");
    scanf("%s", placa);

    for(i=0; i<10; i++){
        if(strcmp(carros[i].Placa_do_carro, placa)==0){
            num = i;
            placa_existe=1;
        }else{
            placa_encontrada=0;
        }
    }   

    if(placa_existe==1){
        placa_encontrada=1;
    }

    if(placa_encontrada==0){
        system("clear||cls");
        printf("Placa nao encontrada.\n");
        return;
    }
    

    system("clear||cls");

    do{ 
        
        printf("\nMarca: %s", carros[num].Marca);
        printf("\nModelo: %s", carros[num].Modelo);
        printf("\nAno de Fabricacao: %d", carros[num].Ano_de_fabricacao);
        printf("\nPlaca: %s", placa);
        printf("\nQuilometragem: %d", carros[num].Quilometragem);
        printf("\nNumero de portas: %d", carros[num].Numeros_de_portas);
        printf("\nAr condicionado: %s", carros[num].Ar_condicionado);

        printf("\n\n1) Alterar Marca");
        printf("\n2) Alterar Modelo");
        printf("\n3) Alterar Ano de Fabricacao");
        printf("\n4) Alterar Quilometragem");
        printf("\n5) Alterar Numero de portas");
        printf("\n6) Alterar Ar condicionado");
        printf("\n7) Fim da alteracao");

        printf("\n\nO que voce deseja alterar: ");
        scanf("%d", &opcao_alt_cadast);

        switch(opcao_alt_cadast){
            case 1:
                printf("\nQual a marca do Carro: ");
                scanf("%s", carros[num].Marca);
                getchar();
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 2:
                printf("\nQual o modelo do Carro:");
                scanf("%s", carros[num].Modelo);
                getchar();
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 3:
                printf("\nQual o ano de fabricacao do Carro: ");
                scanf("%d", &carros[num].Ano_de_fabricacao);
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 4:
                printf("\nQual a quilometragem do Carro: ");
                scanf("%d", &carros[num].Quilometragem);
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 5:
                printf("\nQual o numero de portas do Carro: ");
                scanf("%d", &carros[num].Numeros_de_portas);
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 6:
                printf("\nO carro tem Ar condicionado: ");
                scanf("%s", carros[num].Ar_condicionado);
                getchar();
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
            break;

            case 7:
                system("clear||cls");
                printf("Dados alterados com sucesso!\n");
                saida_cad = 1;
            break;

            default:
                system("clear||cls");
                printf("Opcao invalida, tente novamente.\n");
        }            

    }while(saida_cad!=1);

    fclose(arquivo);

    arquivo = fopen("carros.txt", "w");
    if (arquivo == NULL){
        printf("Não foi possível achar o arquivo");
        return;
    }


    for(i=0; i<linha; i++){
        fprintf(arquivo, "%s\n", carros[i].Marca);
        fprintf(arquivo, "%s\n", carros[i].Modelo);
        fprintf(arquivo, "%d\n", carros[i].Ano_de_fabricacao);
        fprintf(arquivo, "%s\n", carros[i].Placa_do_carro);
        fprintf(arquivo, "%d\n", carros[i].Quilometragem);
        fprintf(arquivo, "%d\n", carros[i].Numeros_de_portas);
        fprintf(arquivo, "%s\n", carros[i].Ar_condicionado);
    }

    fclose(arquivo);

}

//Função para exibir os dados.
void mostrar_dados(Carro* carros){

    int i=0, num, placa_existe, placa_encontrada;
    char aux[15], placa[6];
    FILE *arquivo;

    arquivo = fopen("carros.txt", "r");

    if (arquivo == NULL){
        printf("Não foi possível achar o arquivo");
        return;
    }

    while(fscanf(arquivo, "%s", aux) != EOF){
        strcpy(carros[i].Marca, aux);
        fscanf(arquivo, "%s", carros[i].Modelo);
        fscanf(arquivo, "%d", &carros[i].Ano_de_fabricacao);
        fscanf(arquivo, "%s", carros[i].Placa_do_carro);
        fscanf(arquivo, "%d", &carros[i].Quilometragem);
        fscanf(arquivo, "%d", &carros[i].Numeros_de_portas);
        fscanf(arquivo, "%s", carros[i].Ar_condicionado);
        i++;
    } 

    system("clear||cls");

    

    printf("----------------------------------------------------------");
    printf("\nExibir dados!");

        
    printf("\n\nDigite a placa do carro que voce deseja visualizar os dados: ");
    scanf("%s", placa);

    for(i=0; i<10; i++){
        if(strcmp(carros[i].Placa_do_carro, placa)==0){
            num = i;
            placa_existe=1;
        }else{
            placa_encontrada=0;
        } 
    }   

        if(placa_existe==1){
            placa_encontrada=1;
        }

        if(placa_encontrada==0){ 
            system("clear||cls");
            printf("Placa nao encontrada\n");
            return;
        }

    system("clear||cls");

    printf("\nDados do carro placa: %s\n\n", placa);
    printf("Marca: %s\n", carros[num].Marca);
    printf("Modelo: %s\n", carros[num].Modelo);
    printf("Ano de Fabricacao: %d\n", carros[num].Ano_de_fabricacao);
    printf("Placa: %s\n", carros[num].Placa_do_carro);
    printf("Quilometragem: %d\n", carros[num].Quilometragem);
    printf("Numero de Portas: %d\n", carros[num].Numeros_de_portas);
    printf("Ar Condicionado: %s\n", carros[num].Ar_condicionado);

    printf("\nDigite enter para continuar...\n");
    system("pause");
    system("clear||cls");
    
}

//Função para apagar o registro.
void excluir_reg(Carro* carros){
    int i=0, num, linha=1, saida_cad=0, placa_encontrada=1, placa_existe, opcao_alt_cadast=0;
    char aux[15], placa[6], caracter;

    FILE *arquivo;
    arquivo = fopen("carros.txt", "r");

    if (arquivo == NULL){
        printf("Não foi possível achar o arquivo");
        return;
    }

    while(fscanf(arquivo, "%s", aux) != EOF){
        strcpy(carros[i].Marca, aux);
        fscanf(arquivo, "%s", carros[i].Modelo);
        fscanf(arquivo, "%d", &carros[i].Ano_de_fabricacao);
        fscanf(arquivo, "%s", carros[i].Placa_do_carro);
        fscanf(arquivo, "%d", &carros[i].Quilometragem);
        fscanf(arquivo, "%d", &carros[i].Numeros_de_portas);
        fscanf(arquivo, "%s", carros[i].Ar_condicionado);
        i++;
    }

    rewind(arquivo);
    caracter = getc(arquivo);

    while(caracter!=EOF){
        if(caracter=='\n'){
            linha++;
        }
        caracter = getc(arquivo);
    }

    linha = linha - 1;
    linha = linha/7;

    system("clear||cls");

    printf("----------------------------------------------------------");
    printf("\nExcluir Dados!");

    do{
        printf("\n\nDigite a placa do carro que voce deseja excluir os dados: ");
        scanf("%s", placa);

        for(i=0; i<10; i++){
            if(strcmp(carros[i].Placa_do_carro, placa)==0){
                num = i;
                placa_existe=1;
            }else{
                placa_encontrada=0;
            }
        }   

        if(placa_existe==1){
            placa_encontrada=1;
        }

        if(placa_encontrada==0){
            system("clear||cls");
            printf("Placa nao encontrada.\n");
            return;
        }

    }while(placa_existe!=1);

    system("clear||cls");

    printf("Apagando os dados do seguinte carro:\n");
    printf("\nMarca: %s", carros[num].Marca);
    printf("\nModelo: %s", carros[num].Modelo);
    printf("\nAno de Fabricacao: %d", carros[num].Ano_de_fabricacao);
    printf("\nPlaca: %s", placa);
    printf("\nQuilometragem: %d", carros[num].Quilometragem);
    printf("\nNumero de portas: %d", carros[num].Numeros_de_portas);
    printf("\nAr condicionado: %s", carros[num].Ar_condicionado);

    
    for(i=num; i<linha; i++){
        strcpy(carros[i].Marca, carros[i+1].Marca);
        strcpy(carros[i].Modelo, carros[i+1].Modelo);
        carros[i].Ano_de_fabricacao = carros[i+1].Ano_de_fabricacao;
        strcpy(carros[i].Placa_do_carro, carros[i+1].Placa_do_carro);
        carros[i].Quilometragem = carros[i+1].Quilometragem;
        carros[i].Numeros_de_portas = carros[i+1].Numeros_de_portas;
        strcpy(carros[i].Ar_condicionado, carros[i+1].Ar_condicionado);
    }

    fclose(arquivo);

    arquivo = fopen("carros.txt", "w");

    if (arquivo == NULL){
        printf("Não foi possível achar o arquivo");
        return;
    }
    
    for(i=0; i<linha-1; i++){
        fprintf(arquivo, "%s\n", carros[i].Marca);
        fprintf(arquivo, "%s\n", carros[i].Modelo);
        fprintf(arquivo, "%d\n", carros[i].Ano_de_fabricacao);
        fprintf(arquivo, "%s\n", carros[i].Placa_do_carro);
        fprintf(arquivo, "%d\n", carros[i].Quilometragem);
        fprintf(arquivo, "%d\n", carros[i].Numeros_de_portas);
        fprintf(arquivo, "%s\n", carros[i].Ar_condicionado);
    }

    printf("\n\nDados apagados com sucesso!\n\nPressione enter para continuar\n\n.");
    system("pause");
    system("clear||cls");

    fclose(arquivo);

}   

//Função main.
int main(){
    int saida=0, opcao;

    Carro* carros = (Carro*)malloc(1000*sizeof(Carro));

    do{
        printf("\n\n----------------------------------------------------------");
        printf("\n1) Inserir novo cadastro de veiculo");
        printf("\n2) Alterar cadastro");
        printf("\n3) Mostrar os dados de um veiculo");
        printf("\n4) Apagar registro");
        printf("\n5) Sair");

        printf("\n\nO que deseja fazer: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                novo_cadastro(carros);
        break;

            case 2:
                alt_dados(carros);
            break;

            case 3:
                mostrar_dados(carros);
            break;

            case 4:
                excluir_reg(carros);
            break;

            case 5:
                system("clear||cls");
                printf("Programa finalizado com sucesso!");
                saida = 1;
            break;

            default:
                system("clear||cls");
                printf("Erro!\n");
        }
    } while (saida != 1);

    free(carros);
    return 0;
}

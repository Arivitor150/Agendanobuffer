#include <stdio.h>
#include <stdlib.h>

typedef struct Agenda{
    int cfone;
    char nome[10];
}tipoagenda;

void menu();
void attVar(void *pBuffer, void **op, void **count, void **lp);
void adcTo(void *pBuffer, int *count);
void printAll(void *pBuffer, void *count, void *lp);

int main()
{
    void *pBuffer;  // Inicio da agenda
    void *op;       // Opção do menu
    void *count;    // Número de contatos
    void *lp;       // contato a ser exibido(varia até ser igual ao número de contatos)
    tipoagenda * completa;

    pBuffer = (void*)malloc((sizeof(int)*3));
    *(int *)pBuffer = 0; // Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0; // Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 0; // Variavel Contadora


    attVar(pBuffer,&op,&count,&lp);
    adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    printAll(pBuffer,count,lp);



    /* teste com apenas 1 contato
    attVar(pBuffer, &op, &count, &lp);
    adcTo(pBuffer, count);
    attVar(pBuffer, &op, &count, &lp);
    completa = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(tipoagenda));
    printf("Phone : %d\n", completa->cfone);
    printf("Nome  : %s \n", completa->nome);
    */

    /*AddTo(pBuffer, *(int *)op);
    refreshVar(pBuffer, &op, &count, &lp);
    completa = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(tipoagenda));
    printf("Phone : %d\n", completa->fone);
    printf("Nome  : %s \n", completa->nome); */


    free(pBuffer);
    return 0;
}
//-------------------------------------------------------------/
//--------------------------FUNÇÕES----------------------------/
//-------------------------------------------------------------/

void attVar(void *pBuffer, void **op, void **count, void **lp){
    *op = pBuffer;
    *lp = pBuffer+sizeof(int);
    *count = pBuffer + (2*sizeof(int));

}

void adcTo(void *pBuffer, int *count){

        *count = *count + 1;

        pBuffer = realloc(pBuffer, (3 * sizeof(int)) + ( (*count) * sizeof(tipoagenda)));
        tipoagenda * test;

        test = pBuffer + (3 * sizeof(int)) + ( (*(int *)(pBuffer + (2*sizeof(int)))) * sizeof(tipoagenda));

        printf("Digite o Numero\n");
        scanf("%d",&test->cfone);
        getchar(); //pega o enter, para ele n ser pego pela proxima leitura
        printf("Digite o Nome\n");
        //__fpurge(stdin); no achou a função, para limpar o buffer do teclado
        fgets (test->nome , (sizeof(char)*10) , stdin);

}

void printAll(void *pBuffer, void *count, void *lp){
    printf("Buffer: %p\n", pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(tipoagenda)));

    if(*(int *)count > 0){
        tipoagenda * completa;
        for(*(int *)lp = 0; (*(int *)lp) < (*(int *)count); (*(int *)lp)++){

                completa = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda)); 
            //  completa = inicio da area de memoria + vars de controle + contato a ser exibido;
                printf("\n");
                printf("Phone:%d\n", completa->cfone);
                printf("Name:%s\n", completa->nome);
                printf("\n");
        }
}
}

void menu(){
        /*pBuffer = realloc(pBuffer, (sizeof(pBuffer) + sizeof(tipoagenda)));
        tipoagenda * test;
        test = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);
        test->cphone = 999;
        test->name[0] = 't';
        printf("R2:%d\n", sizeof(pBuffer));
        printf("Ce : %d\n", &test->cphone);
        printf("No : %d\n", &test->name[0]);
        // *(int *)pBuffer = 7;
        // *(int *)(pBuffer + sizeof(int)) = 9;
        // *op = 10;
        // *lp = 5;
        //printf("RefV : %d\n", *(int *)pBuffer);
        */


 //   tipoagenda * test;
  //  test = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);
   // printf("Ce : %d\n", test->cphone);
   // printf("No : %d\n", test->name[0]);
    //printf("M: %d\n", pBuffer);

        //printf("Main : \n");
   // printf("OP : %i\n", op);
   // printf("LP : %i\n", *(int *)lp);
    //printf("CO : %i\n", *(int *)counT);

}
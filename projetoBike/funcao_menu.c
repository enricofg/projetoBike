#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"


int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente, int bicicletasOcupadas, float distTotPecorrida, int quantAvariadas)
{
    int opcao;
    int bicicletasDisponiveis = MAXBICICLETA - bicicletasOcupadas;

    printf("\n\n--------__@                     @~_ --------");
    printf("\n----- _-\\<,_                   _,>/-_ ------");
    printf("\n---- (*)/ (*)                 (*) \\(*) -----");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  //  printf("\n--------------------------------------------");
    printf("\n___________Welcome to CampusBike____________\n\n");

    printf("\nNumero de bicicletas registradas:%d",contBicicletas);
    printf("\nNumero de utentes registrados:%d",contUtente);
    printf("\nNumero total de emprestimos:%d",contEmprestimo);
    printf("\nQuantidade de pedidos na lista de espera:%d",contEspera);
    printf("\nDistancia total percorrida:%.2f",distTotPecorrida);
    printf("\nQuantidade de bicicletas avariadas:%d",quantAvariadas);
    printf("\nNumero de bicicletas disponiveis:%d",bicicletasDisponiveis);

    printf("\n\n1->Bicicletas\n");
    printf("2->Utente\n");
    printf("3->Espera\n");
    printf("4->Emprestimo\n");
    printf("5->Listar utentes por ordem decrescente de emprestimos\n");
    printf("6->Estatisticas\n");
    printf("7->Listar os dados da ultima bicicleta utilizada por um utente\n");
    printf("8->Salvar e fechar o programa\n");
    opcao = lerInteiro("\nEscolha uma opcao:",1,8);
    return opcao;
}

char menuBicicleta(int contBicicletas)
{
    char opcao;
    do
    {
        printf("\nNumero de bicicletas registradas:%d", contBicicletas);
        printf("\n\t(I)nserir\n");
        printf("\t(C)onsultar\n");
        printf("\t(R)egistrar avaria/devolucao\n");
        printf("\t(L)istar\n");
        printf("\t(V)oltar\n");
        printf("Escolha uma opcao: ");

        scanf(" %c",&opcao);
        limpaBufferStdin();
        opcao=toupper(opcao);

        if(opcao!='I' && opcao!='C' && opcao!='R' && opcao!='L' && opcao!='V')
        {
            printf("\nOpcao invalida\n");
        }
    }
    while(opcao!='I' && opcao!='C' && opcao!='R' && opcao!='L' && opcao!='V');
    return opcao;
}

char menuUtente(int contUtente)
{
    char opcao;
    do
    {
        printf("\nNumero de utentes registrados:%d", contUtente);
        printf("\n\t(I)nserir\n");
        printf("\t(A)lterar\n");
        printf("\t(C)onsultar\n");
        printf("\t(L)istar\n");
        printf("\t(V)oltar\n");
        printf("Escolha uma opcao: ");

        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);

        if(opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V')
        {
            printf("\nOpcao invalida\n");
        }
    }
    while(opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V');

    return opcao;
}

char menuEmprestimo(int bicicletasOcupadas)
{
    int bicicletasDisponiveis = MAXBICICLETA - bicicletasOcupadas;
    char opcao;

    do
    {
        printf("\nNumero de bicicletas disponiveis:%d", bicicletasDisponiveis);
        printf("\n\t(R)egistar\n");
        printf("\t(D)evolucao\n");
        printf("\t(C)onsultar\n");
        printf("\t(L)istar\n");
        printf("\t(V)oltar\n");
        printf("Escolha uma opcao: ");

        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);

        if(opcao!='R' && opcao!='C' && opcao!='D' && opcao!='L' && opcao!='V')
        {
            printf("\nOpcao invalida\n");
        }
    }
    while(opcao!='R' && opcao!='C' && opcao!='D' && opcao!='L' && opcao!='V');

    return opcao;
}

int menuCampus()
{
    int opcao;

    printf("\n1->Residencias");
    printf("\n2->Campus 1");
    printf("\n3->Campus 2");
    printf("\n4->Campus 5");
    opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

    return opcao;
}

int subMenuTipoUtente()
{
    int opcao;

    printf("\n\nInsira o tipo do utente:");
    printf("\n1->Estudante");
    printf("\n2->Docente");
    printf("\n3->Tecnico Administrativo");
    printf("\n4->Convidado");
    opcao = lerInteiro("\nEscolhe uma opcao: ",1,4);

    return opcao;
}

int subMenuAvariaReparacao(){
        int opcao;
        printf("\nEscolha a opcao pretendida");
        printf("\n1->Avaria");
        printf("\n2->Reparacao");
        printf("\n3->Voltar");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,3);
        return opcao;
}

char menuEspera(int numeroDeEsperas)
{
    char opcao;

    do
    {
        printf("\nNumero de utentes em espera:%d", numeroDeEsperas);
        printf("\n\t(A)lterar campus de destino\n");
        printf("\t(E)liminar da lista\n");
        printf("\t(C)onsultar\n");
        printf("\t(L)istar\n");
        printf("\t(V)oltar\n");
        printf("Escolha uma opcao: ");

        scanf(" %c", &opcao);
        limpaBufferStdin();
        opcao = toupper(opcao);

        if(opcao!='A' && opcao!='C' && opcao!='E' && opcao!='L' && opcao!='V')
        {
            printf("\nOpcao invalida\n");
        }
    }
    while(opcao!='A' && opcao!='C' && opcao!='E' && opcao!='L' && opcao!='V');
    return opcao;
}

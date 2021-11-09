#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void inserirUtente(tipoUtente Utente[],int *contUtente){
    int pos = -1;
    int codigo;
    int opcao;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(Utente,codigo,*contUtente);

    if(pos != -1){
        printf("\nJa existe um utente com esse codigo");
    }else{
        Utente[*contUtente].numero = codigo;
        lerString("\nNome do utente:",Utente[*contUtente].nome,MAXSTRING);
        Utente[*contUtente].distanciaPercorrida = 0;
        Utente[*contUtente].quantidadeEmprestimos = 0;
        Utente[*contUtente].telemovel = lerInteiro("\nTelemovel do utente:",MINTELEMOVEL,MAXTELEMOVEL);

        ///estudante docente tecnico administrativo convidado
        opcao = subMenuTipoUtente();

        switch(opcao){
            case 1:
                strcpy(Utente[*contUtente].tipo,"estudante");
            break;
            case 2:
                strcpy(Utente[*contUtente].tipo,"docente");
            break;
            case 3:
                strcpy(Utente[*contUtente].tipo,"tecnico administrativo");
            break;
            case 4:
                strcpy(Utente[*contUtente].tipo,"convidado");
            break;

        }

        (*contUtente)++;
        printf("\nUtente criado com sucesso");

    }
}

int procurarUtente(tipoUtente Utente[],int codigo,int contUtente){
    int pos = -1;
    int i;

    for(i=0;i<contUtente;i++){
        if(Utente[i].numero == codigo){
            pos = i;
            break;
        }
    }
    //se ele encontrar,devolve a posicao que encontrou
    return pos;
}

void alterarUtente(tipoUtente Utente[],int contUtente){
    int pos = -1;
    int codigo;
    int opcao;

    codigo = lerInteiro("\nIntroduza o numero de utente que pretende alterar:",0,MAXNUMEROUTENTE);
     pos = procurarUtente(Utente,codigo,contUtente);

    if(pos != -1){
        lerString("\nNome do utente:",Utente[pos].nome,MAXSTRING);
        Utente[pos].telemovel = lerInteiro("\nTelemovel do utente:",MINTELEMOVEL,MAXTELEMOVEL);

        opcao = subMenuTipoUtente();

        switch(opcao){
            case 1:
                strcpy(Utente[pos].tipo,"estudante");
            break;
            case 2:
                strcpy(Utente[pos].tipo,"docente");
            break;
            case 3:
                strcpy(Utente[pos].tipo,"tecnico administrativo");
            break;
            case 4:
                strcpy(Utente[pos].tipo,"convidado");
            break;

        }

        printf("\nUtente alterado com sucesso");
    }else{
         printf("\nNao existe nenhum utente com o numero de utente inserido");
    }

}

void consultarUtente(tipoUtente Utente[],int contUtente){
    int codigo;
    int pos = -1;

    codigo = lerInteiro("\nInsira o numero do utente que pretende consultar:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(Utente,codigo,contUtente);

    if(pos != -1){
        printf("\nUtente encontrado");
        printf("\n\nNome Utente:%s",Utente[pos].nome);
        printf("\nNumero Utente:%d",Utente[pos].numero);
        printf("\nTelemovel Utente:%d",Utente[pos].telemovel);
        printf("\nTipo de Utente:%s",Utente[pos].tipo);
        printf("\nDistancia percorrida pelo Utente:%.2f",Utente[pos].distanciaPercorrida);
        printf("\nQuantidade de emprestimo efectuadas pelo Utente:%d",Utente[pos].quantidadeEmprestimos);
    }else{
        printf("\nNao existe nenhum utente com o numero inserido");
     }
}

void listarUtente(tipoUtente Utente[],int contUtente){
    int i;

    for(i=0;i<contUtente;i++){
        printf("\n\nNome Utente:%s",Utente[i].nome);
        printf("\nNumero Utente:%d",Utente[i].numero);
        printf("\nTelemovel Utente:%d",Utente[i].telemovel);
        printf("\nTipo de Utente:%s",Utente[i].tipo);
        printf("\nDistancia percorrida pelo Utente:%.2f",Utente[i].distanciaPercorrida);
        printf("\nQuantidade de emprestimo efectuadas pelo Utente:%d",Utente[i].quantidadeEmprestimos);
    }

}

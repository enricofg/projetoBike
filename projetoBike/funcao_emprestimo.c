#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas, int *verPossibEmprestimo)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    aux = emprestimos;  ///add
    int emprestimoRealizado=0,naoDisponivel=0;

    codigo = lerInteiro("\nIntroduza o numero de utente:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtente);


    if(pos == -1)
    {
        printf("\nNao existe nenhum utente com este numero!");
    }
    else
    {

        for(i=0; i<*contEmprestimo; i++)    //verificar se ja possui emprestimo
        {
            //  printf("teste2:%d",emprestimos[i].codigoUtente);
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente)
            {
                emprestimoRealizado=1;
                //break;
            }
        }

        if(emprestimoRealizado==1)
        {
            printf("\n\nO utente ja possui um emprestimo realizado.");
        }
        else
        {
            printf("\nInsira o campus de origem que deseja:");
            opcao = menuCampus();

            switch(opcao)
            {
            case 1:
                strcpy(campus,"residencias");
                break;
            case 2:
                strcpy(campus,"campus 1");
                break;
            case 3:
                strcpy(campus,"campus 2");
                break;
            case 4:
                strcpy(campus,"campus 5");
                break;
            }

            for(i=0; i<contBicicleta; i++)
            {

                if(strcmp(bicicleta[i].campus,campus)==0)
                {

                    if(strcmp(bicicleta[i].estado,"disponivel")==0)  //ve se tem alguma bicicleta disponivel naquele campus
                    {

                        aux = realloc(aux,(*contEmprestimo+1)*sizeof(tipoEmprestimo));

                        if(aux == NULL)
                        {
                            printf("\nImpossivel alocar memoria.");
                        }
                        else
                        {
                            aux[*contEmprestimo].numeroRegisto = *idEmprestimo;
                            aux[*contEmprestimo].codigoUtente = codigo;
                            strcpy(aux[*contEmprestimo].designacaoBicicleta,bicicleta[i].designacao);
                            aux[*contEmprestimo].dataEmprestimo = lerData();
                            strcpy(aux[*contEmprestimo].campusOrigem,campus);


                            printf("\nInsira o campus de destino que deseja:");
                            opcao = menuCampus();   ///menu


                            switch(opcao)
                            {
                            case 1:
                                strcpy(campus,"residencias");
                                break;
                            case 2:
                                strcpy(campus,"campus 1");
                                break;
                            case 3:
                                strcpy(campus,"campus 2");
                                break;
                            case 4:
                                strcpy(campus,"campus 5");
                                break;
                            }
                        }
                        if(strcmp(aux[*contEmprestimo].campusOrigem,campus)==0)
                        {
                            printf("Mesmo campus de origem e destino, tente novamente inserindo locais diferentes para a bicicleta");
                        }
                        else
                        {
                            strcpy(aux[*contEmprestimo].campusDestino,campus);
                            //aux[*contEmprestimo].numeroRegisto = *idEmprestimo;
                            bicicleta[i].quantidadeEmprestimos++;
                            strcpy(bicicleta[i].estado,"emprestada");
                            utentes[pos].quantidadeEmprestimos++;
                            (*contEmprestimo)++;
                            (*idEmprestimo)++;
                            (*bicicletasOcupadas)++;
                            (*verPossibEmprestimo)=1;//foi possivel fazer o emprestimo
                            naoDisponivel = 0;
                            printf("\nEmprestimo realizado com sucesso");

                            break;
                        }
                        //tipoData dataDevolucao;
                        //int distanciaPercorrida;
                    }
                    else
                    {
                        naoDisponivel=1;
                        (*verPossibEmprestimo)=0;
                    }
                }
                else
                {
                    naoDisponivel=1;
                }
            }

            if(naoDisponivel==1)
            {
                printf("\nNao ha bicicletas disponiveis no campus selecionado.");
                (*verPossibEmprestimo)=0;
            }
        }
    }
    return aux;//para atualizar a memoria dinamica
}

void consultarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j = 1;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer consultar os emprestimo:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0; i<contEmprestimo; i++)
        {
            if(emprestimos[i].codigoUtente == utentes[pos].numero)
            {
                printf("\nEmprestimo %d",j);
                printf("\n\nID do emprestimo:%d",emprestimos[i].numeroRegisto);
                printf("\nCodigo de utente:%d\t\tNome Utente:%s",emprestimos[i].codigoUtente,utentes[pos].nome);
                printf("\nID da bicicleta:%s",emprestimos[i].designacaoBicicleta);
                printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
                printf("\nCampus destino:%s",emprestimos[i].campusDestino);
                printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
                       emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
                printf("\nData de devolucao:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
                       emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
                printf("\nDistancia percorrida:%.2f",emprestimos[i].distanciaPercorrida);
                j++;

            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");
    }
}

void listarEmprestimos(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int i, j = 1;

    for(i=0; i<contEmprestimo; i++)
    {
        printf("\n\nEmprestimo %d",j);
        printf("\nID do emprestimo:%d",emprestimos[i].numeroRegisto);
        printf("\nCodigo de utente:%d",emprestimos[i].codigoUtente);
        printf("\nID da bicicleta:%s",emprestimos[i].designacaoBicicleta);
        printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
        printf("\nCampus destino:%s",emprestimos[i].campusDestino);
        printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
               emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
        printf("\nData de devolucao:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
               emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
        printf("\nDistancia percorrida:%.2f",emprestimos[i].distanciaPercorrida);
        j++;

    }
}

void devolverBicicleta(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas,int *sucessoDevolucao)
{
    int numeroUtente;
    int pos = -1;
    int i;
    int j;
    char designacao[MAXSTRING];
    int opcao;
    int dia,mes,ano;
    float distancia = 0;
    int possuiBicicleta=0;
    tipoData verificar;
    int dataValida= 0;
    (*sucessoDevolucao) =0;

    numeroUtente = lerInteiro("\nInsira o numero de utente que quer devolver uma bicicleta:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,numeroUtente,contUtentes);

    if(pos != -1)
    {
        for(i=0 ; i<contEmprestimo; i++)
        {
            if(emprestimos[i].dataDevolucao.dia == 0 && utentes[pos].numero == emprestimos[i].codigoUtente)
            {
                for(j=0; j<contBicicleta; ++j)
                {
                    if(strcmp(bicicleta[j].designacao,emprestimos[i].designacaoBicicleta)==0 && strcmp(bicicleta[j].estado,"emprestada")==0)
                    {
                        verificar= lerData();
                        dataValida = verificarData(verificar,emprestimos[i].dataEmprestimo);

                        if(dataValida==-1)
                        {
                            ///data invalida
                            printf("\nA data de devolucao tem de ser superior a data de emprestimo. ");
                        }
                        else
                        {
                            strcpy(bicicleta[j].estado,"disponivel");
                            strcpy(bicicleta[j].campus, emprestimos[i].campusDestino);
                            emprestimos[i].dataDevolucao=verificar;

                            if(strcmp(emprestimos[i].campusOrigem,"residencias")==0 && strcmp(emprestimos[i].campusOrigem,"campus 1")==0)
                            {
                                distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_R_C1,MAXDISTANCIA);
                            }
                            else
                            {
                                if(strcmp(emprestimos[i].campusOrigem,"residencias")==0 && strcmp(emprestimos[i].campusOrigem,"campus 2")==0)
                                {
                                    distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_R_C2,MAXDISTANCIA);
                                }
                                else
                                {
                                    if(strcmp(emprestimos[i].campusOrigem,"residencias")==0 && strcmp(emprestimos[i].campusOrigem,"campus 5")==0)
                                    {
                                        distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_R_C5,MAXDISTANCIA);
                                    }
                                    else
                                    {
                                        if(strcmp(emprestimos[i].campusOrigem,"campus 1")==0 && strcmp(emprestimos[i].campusOrigem,"campus 2")==0)
                                        {
                                            distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_C1_C2,MAXDISTANCIA);
                                        }
                                        else
                                        {
                                            if(strcmp(emprestimos[i].campusOrigem,"campus 1")==0 && strcmp(emprestimos[i].campusOrigem,"campus 5")==0)
                                            {
                                                distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_C1_C5,MAXDISTANCIA);
                                            }
                                            else
                                            {
                                                distancia= lerFloat("\nIntroduza a distancia percorrida:",DIST_C2_C5,MAXDISTANCIA);
                                            }
                                        }
                                    }
                                }
                            }
                            bicicleta[j].distanciaTotal= bicicleta[j].distanciaTotal + distancia;
                            emprestimos[i].distanciaPercorrida = distancia;
                            utentes[pos].distanciaPercorrida = utentes[pos].distanciaPercorrida + distancia;//atualizar a distancia pecorrida do utilizador
                            (*bicicletasOcupadas)--;
                            (*sucessoDevolucao) =1;

                            printf("\nDevolucao concluida com sucesso.");
                        }
                    }
                    else
                    {
                        possuiBicicleta=1;
                    }
                }

            }
            else
            {
                printf("Este utente nao possui uma bicicleta para ser devolvida.");
            }
        }
    }
    else
    {
        printf("\nNao existe nenhum utente com o numero escolhido");

    }
}

int quantidadeEmprestimos(tipoEmprestimo emprestimos[], int *contEmprestimo)
{
    int quantidade=0, i=0;

    for(i=0; i<*contEmprestimo; i++)
    {
        quantidade++;
    }

    return quantidade;
}

int verificarData(tipoData verificar,tipoData dataEmprestimo)
{
    int dataValida=0;

    if(dataEmprestimo.ano < verificar.ano)
    {
        dataValida=1;
    }
    else
    {
        if(dataEmprestimo.ano > verificar.ano)
        {
            dataValida=-1;
        }
        else
        {
            ///anos iguais
            if(dataEmprestimo.mes < verificar.mes)
            {
                dataValida=1;
            }
            else
            {
                if(dataEmprestimo.mes > verificar.mes)
                {
                    dataValida=-1;
                }
                else
                {
                    ///meses iguais
                    if(dataEmprestimo.dia < verificar.dia)
                    {
                        dataValida = 1;
                    }
                    else
                    {
                        if(dataEmprestimo.dia > verificar.dia)
                        {
                            dataValida = -1;
                        }
                        else
                        {
                            ///dias iguais

                            if(dataEmprestimo.hora < verificar.hora)
                            {
                                dataValida=1;
                            }
                            else
                            {
                                if(dataEmprestimo.hora > verificar.hora)
                                {
                                    dataValida=-1;
                                }
                                else
                                {
                                    ///horas iguais

                                    if(dataEmprestimo.minuto < verificar.minuto)
                                    {
                                        dataValida=1;
                                    }
                                    else
                                    {
                                        if(dataEmprestimo.minuto > verificar.minuto)
                                        {
                                            dataValida=-1;
                                        }
                                        else
                                        {
                                            ///minutos iguais
                                            dataValida=-1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
    return dataValida;
}

tipoEmprestimo *atribuirBike(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],tipoEspera espera[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas,int posEspera)
{
    int pos = -1;
    int i;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    aux = emprestimos;  ///add
    int emprestimoRealizado=0,naoDisponivel=0;

    for(i=0; i<contUtente; i++)
    {
        if(utentes[i].numero == espera[posEspera].codigoUtente)
        {
            //printf("\nteste:%d",i);
            pos = i;
        }
    }

    //printf("\nasdasd:%d",esperaAux.codigoUtente);

    aux = realloc(aux,(*contEmprestimo+1)*sizeof(tipoEmprestimo));

    if(aux == NULL)
    {
        printf("\nImpossivel alocar memoria.");
    }
    else
    {
        aux[*contEmprestimo].codigoUtente = espera[posEspera].codigoUtente;
        printf("\nData de realizacao do emprestimo:");
        aux[*contEmprestimo].dataEmprestimo = lerData();
        strcpy(aux[*contEmprestimo].campusOrigem,espera[posEspera].campusOrigem);
        strcpy(aux[*contEmprestimo].campusDestino,espera[posEspera].campusDestino);
        aux[*contEmprestimo].numeroRegisto = *idEmprestimo;

        for(i=0; i<contBicicleta; i++)
        {
            if(strcmp(bicicleta[i].campus,espera[posEspera].campusOrigem)==0)
            {
                if(strcmp(bicicleta[i].estado,"disponivel")==0)  //ve se tem alguma bicicleta disponivel naquele campus
                {
                    strcpy(aux[*contEmprestimo].designacaoBicicleta,bicicleta[i].designacao);
                    bicicleta[i].quantidadeEmprestimos++;
                    strcpy(bicicleta[i].estado,"emprestada");
                    utentes[pos].quantidadeEmprestimos++;
                    (*contEmprestimo)++;
                    (*idEmprestimo)++;
                    (*bicicletasOcupadas)++;
                }
            }
        }
    }

    return aux;//para atualizar a memoria dinamica
}

int atribuirBicicletaConsoanteCriterio(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEspera espera[],int contBicicletas,int contUtente,int contEspera)
{
    int opcao;
    int i;
    int j;
    int pos;
    char tipo[MAXSTRING];
    int distanciaAux=0;

///ordem de entrada do pedido, por tipo de utente ou por distância a percorrer (entre os campi).
    printf("\n1->Ordem de entrada do pedido");
    printf("\n2->Tipo Utente");
    printf("\n3->Distancia a percorrer");
    opcao = lerInteiro("\nEscolha o criterio de atribuicao:",1,3);

    switch(opcao)
    {
    case 1:
        ///ordem de entrada do pedido
        for(i=0; i<contEspera; i++)
        {
            for(j=i+1; j<contEspera; j++)
            {
                if(espera[i].dataRegistro.ano < espera[j].dataRegistro.ano)
                {
                    pos=j;
                }
                else
                {
                    if(espera[i].dataRegistro.ano > espera[j].dataRegistro.ano)
                    {
                        pos=i;
                    }
                    else
                    {
                        ///anos iguais
                        if(espera[i].dataRegistro.mes < espera[j].dataRegistro.mes)
                        {
                            pos=j;
                        }
                        else
                        {
                            if(espera[i].dataRegistro.mes > espera[j].dataRegistro.mes)
                            {
                                pos=i;
                            }
                            else
                            {
                                ///meses iguais
                                if(espera[i].dataRegistro.dia < espera[j].dataRegistro.dia)
                                {
                                    pos = j;
                                }
                                else
                                {
                                    if(espera[i].dataRegistro.dia > espera[j].dataRegistro.dia)
                                    {
                                        pos = i;
                                    }
                                    else
                                    {
                                        ///dias iguais

                                        if(espera[i].dataRegistro.hora < espera[j].dataRegistro.hora)
                                        {
                                            pos=j;
                                        }
                                        else
                                        {
                                            if(espera[i].dataRegistro.hora > espera[j].dataRegistro.hora)
                                            {
                                                pos=i;
                                            }
                                            else
                                            {
                                                ///horas iguais

                                                if(espera[i].dataRegistro.minuto < espera[j].dataRegistro.minuto)
                                                {
                                                    pos=j;
                                                }
                                                else
                                                {
                                                    if(espera[i].dataRegistro.minuto > espera[j].dataRegistro.minuto)
                                                    {
                                                        pos=i;
                                                    }
                                                    else
                                                    {
                                                        ///minutos iguais tanto faz porque as datas sao iguais
                                                        pos=i;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
        break;
    case 2:
        ///por tipo de utente
        opcao = subMenuTipoUtente();

        switch(opcao)
        {
        case 1:
            strcpy(tipo,"estudante");
            break;
        case 2:
            strcpy(tipo,"docente");
            break;
        case 3:
            strcpy(tipo,"tecnico administrativo");
            break;
        case 4:
            strcpy(tipo,"convidado");
            break;

        }
        for(i=0; i<contEspera; i++)
        {
            for(j=0; j<contUtente; j++)
            {
                if(utente[j].numero == espera[i].codigoUtente)
                {
                    if(strcmp(utente[j].tipo,tipo)==0)
                    {
                        pos = i;
                    }
                }
            }
        }
        break;
    case 3:
        ///por distância a percorrer
        ///residencias, campus 1, campus 2, campus 5

        /**for(i=0; i<contEspera-1; i++)
        {
            j=i+1;
            if(strcmp(espera[i].campusOrigem,"residencias")==0 && strcmp(espera[i].campusDestino,"campus 1")==0)
            {
                distanciaAux = DIST_R_C1;
            }

            if(strcmp(espera[i].campusOrigem,"residencias")==0 && strcmp(espera[i].campusDestino,"campus 2")==0)
            {
                distanciaAux = DIST_R_C2;
            }
            if(strcmp(espera[i].campusOrigem,"residencias")==0 && strcmp(espera[i].campusDestino,"campus 5")==0)
            {
                distanciaAux = DIST_R_C5;
            }
            if(strcmp(espera[i].campusOrigem,"campus 1")==0 && strcmp(espera[i].campusDestino,"campus 2")==0)
            {
                distanciaAux = DIST_C1_C2;
            }
            if(strcmp(espera[i].campusOrigem,"campus 1")==0 && strcmp(espera[i].campusDestino,"campus 5")==0)
            {
                distanciaAux = DIST_C1_C5;
            }
            if(strcmp(espera[i].campusOrigem,"campus 2")==0 && strcmp(espera[i].campusDestino,"campus 5")==0)
            {
                distanciaAux = DIST_C2_C5;
            }

        }

        printf("\n1->Maior distancia");
        printf("\n2->Menor distancia");
        opcao = lerInteiro("\nEscolha a opcao pretendida:",1,2);

        switch(opcao)
        {
        case 1:
            for(i=0; i<contEspera-1; i++)
            {
                for(j=i+1; i<contEspera; i++)
                {

                }
            }
            break;
        case 2:
            break;
        }**/

        break;
    }

    return pos;
}

tipoEmprestimo *atribuirBicicleta(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEmprestimo emprestimo[],tipoEspera esperaAux,int contBicicletas,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas,int posBicicleta)
{
    int pos = -1;
    int opcao;
    char campus[MAXSTRING];
    int codigo;
    tipoEmprestimo *aux;
    aux = emprestimo;  ///add
    int emprestimoRealizado=0,naoDisponivel=0;
    int i;

    for(i=0; i<contUtente; i++)
    {
        if(utente[i].numero == esperaAux.codigoUtente)
        {
            pos = i;
        }
    }

    aux = realloc(aux,(*contEmprestimo+1)*sizeof(tipoEmprestimo));

    if(aux == NULL)
    {
        printf("\nImpossivel alocar memoria.");
    }
    else
    {
        aux[*contEmprestimo].codigoUtente = esperaAux.codigoUtente;
        aux[*contEmprestimo].dataEmprestimo = lerData();
        strcpy(aux[*contEmprestimo].campusOrigem,esperaAux.campusOrigem);
        strcpy(aux[*contEmprestimo].campusDestino,esperaAux.campusDestino);
        aux[*contEmprestimo].numeroRegisto = *idEmprestimo;


        strcpy(aux[*contEmprestimo].designacaoBicicleta,bicicleta[posBicicleta].designacao);
        bicicleta[posBicicleta].quantidadeEmprestimos++;
        strcpy(bicicleta[posBicicleta].estado,"emprestada");
        utente[pos].quantidadeEmprestimos++;
        (*contEmprestimo)++;
        (*idEmprestimo)++;
        (*bicicletasOcupadas)++;



    }

    return aux;//para atualizar a memoria dinamica
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void inserirBicicleta(tipoBicicleta bicicletas[],int *contBicicletas)
{
    char designacao[MAXSTRING];
    int pos = -1;
    int opcao;

    printf("\n\nInserir Bicicleta   \n");
    lerString("\nInserir ID da bicicleta:",designacao,MAXSTRING);

    pos = procurarBicicleta(bicicletas,designacao,*contBicicletas);

    if(pos != -1)
    {
        printf("\n\nJa existe uma bicicleta com este ID");
    }
    else
    {
        ///copia string origem para o vetor destino (incluindo \0)
        strcpy(bicicletas[*contBicicletas].designacao,designacao); //salva a designacao da bicicleta no vetor
        strcpy(bicicletas[*contBicicletas].estado,"disponivel");    //"automaticamente" passa a estar disponivel

        opcao = menuCampus();        ///menu

        switch(opcao)
        {
        case 1:
            strcpy(bicicletas[*contBicicletas].campus,"residencias");
            break;
        case 2:
            strcpy(bicicletas[*contBicicletas].campus,"campus 1");
            break;
        case 3:
            strcpy(bicicletas[*contBicicletas].campus,"campus 2");
            break;
        case 4:
            strcpy(bicicletas[*contBicicletas].campus,"campus 5");
            break;
        }

        lerString("\n\nInsira o modelo da bicicleta:",bicicletas[*contBicicletas].modelo,MAXSTRING);
        bicicletas[*contBicicletas].quantidadeAvarias = 0;
        bicicletas[*contBicicletas].quantidadeEmprestimos = 0;
        bicicletas[*contBicicletas].distanciaTotal = 0;
        (*contBicicletas)++;
        printf("\nBicicleta criada com sucesso");

    }
}

void consultarBicicleta(tipoBicicleta bicicletas[],int contBicicleta)
{
    char designacao[MAXSTRING];
    int pos = -1;

    lerString("\nInserir ID da bicicleta:",designacao,MAXSTRING);

    pos = procurarBicicleta(bicicletas,designacao,contBicicleta);

    if(pos != -1)
    {
        printf("\n\nBicicleta Encontrada");
        printf("\nID:%s",bicicletas[pos].designacao);
        printf("\nCampus:%s",bicicletas[pos].campus);
        printf("\nModelo:%s",bicicletas[pos].modelo);
        printf("\nEstado:%s",bicicletas[pos].estado);
        printf("\nQuantidade Avarias:%d",bicicletas[pos].quantidadeAvarias);
        printf("\nQuantidade Emprestimo:%d",bicicletas[pos].quantidadeEmprestimos);
        printf("\nDistancia percorrida:%.2f\n\n",bicicletas[pos].distanciaTotal);
    }
    else
    {
        printf("\n\nNao existe nenhuma bicicleta com essa designacao\n");
    }

}

void listarBicicletas(tipoBicicleta bicicletas[],int contBicicleta)
{
    int i,j = 1;

    for(i = 0; i<contBicicleta; i++)
    {
        printf("\n\nBicicleta:%d",j);
        printf("\nID:%s",bicicletas[i].designacao);
        printf("\nCampus:%s",bicicletas[i].campus);
        printf("\nModelo:%s",bicicletas[i].modelo);
        printf("\nEstado:%s",bicicletas[i].estado);
        printf("\nQuantidade Avarias:%d",bicicletas[i].quantidadeAvarias);
        printf("\nQuantidade Emprestimo:%d",bicicletas[i].quantidadeEmprestimos);
        printf("\nDistancia percorrida:%.2f",bicicletas[i].distanciaTotal);
        j++;
    }
}

int procurarBicicleta(tipoBicicleta bicicletas[],char designacao[],int contBicicleta)
{
    int pos = -1;
    int i;

    for(i=0; i<contBicicleta; i++)
    {
        ///compara alfabeticamente strings destino e origem, devolve 0 se iguais
        if(strcmp(bicicletas[i].designacao,designacao)==0) //se forem iguais devolve 0, ja existe
        {
            pos = i;
        }
    }
    return pos;
}


int bicicletasDisponiveis(tipoBicicleta bicicletas[], int *contBicicleta)
{
    int ocupadas=0, i=0;

    for(i=0; i<*contBicicleta; i++)
    {
        ///compara alfabeticamente strings destino e origem, devolve 0 se iguais
        if(strcmp(bicicletas[i].estado,"disponivel")!=0) //se forem iguais devolve 0, ja existe
        {
            ocupadas++;
        }
    }
    return ocupadas;
}

void registarAvariaReparacao(tipoBicicleta bicicletas[], int contBicicleta,int *bicicletasOcupadas)
{
    char designacao[MAXSTRING];
    int pos = -1;
    int opcao;
    FILE *file;
    char causaAvaria[MAX];
    tipoData data;

    lerString("\nInserir ID da bicicleta:",designacao,MAXSTRING);

    pos = procurarBicicleta(bicicletas,designacao,contBicicleta);

    if(pos != -1)
    {
      /*  printf("\nEscolha a opcao pretendida");
        printf("\n1->Avaria");
        printf("\n2->Reparacao");
        printf("\n3->Voltar");
        opcao = lerInteiro("\nEscolhe uma opcao: ",1,3);
*/
        opcao = subMenuAvariaReparacao();

        ///disponivel emprestada avariada
        switch(opcao)
        {
        case 1:
            ///avaria
            if(strcmp(bicicletas[pos].estado,"disponivel")== 0)
            {
                strcpy(bicicletas[pos].estado,"avariada");
                bicicletas[pos].quantidadeAvarias++;
                lerString("\nIntroduza a causa da avaria da bicicleta:",causaAvaria,MAX);

                data = lerData();
                //comparar data, data>data.emprestimo e data<data.devolucao

                ///TODO escrever para ficheiro texto um log
                file = fopen("bicicletas.txt","a");

                if (file == NULL)
                {
                    printf ("Erro abrir ficheiro");
                }
                else
                {
                    ///designação da bicicleta, distância total percorrida, data e hora da avaria, e descrição da avaria.
                    fprintf(file,"Designacao bicicleta: %s\n",bicicletas[pos].designacao);
                    fprintf(file,"Distancia total percorrida: %.2f\n",bicicletas[pos].distanciaTotal);
                    fprintf(file,"Data da avaria: %02d/%02d/%04d\t%02d:%02d\n",data.dia, data.mes, data.ano,data.hora,data.minuto);
                    fprintf(file,"Causa da avaria: %s\n",causaAvaria);
                    fprintf(file,"-----------------------------------------------------\n");
                    fclose(file);
                }
                (*bicicletasOcupadas)++;

            }
            else
            {
                printf("\nA bicicleta com a designacao introduzida encontra-se avariada ou emprestada");
            }
            break;
        case 2:
            ///reparacao
            if(strcmp(bicicletas[pos].estado,"avariada")!= 0)
            {
                printf("\nA bicicleta nao se encontra avariada para realizar uma reparacao");
            }
            else
            {
                strcpy(bicicletas[pos].estado,"disponivel");
                (*bicicletasOcupadas)--;
                printf("\n\nA bicicleta foi reparada!");
            }
            break;
        }
    }
    else
    {
        printf("\nA bicicleta com a designacao introduzida nao existe");
    }
}

float atualizarDistanciaTotal(tipoBicicleta bicicleta[],int contBicicletas)
{
    int i;
    float distancia=0;

    for (i=0; i<contBicicletas; i++)
    {
        distancia = distancia + bicicleta[i].distanciaTotal;
    }
    return distancia;
}

int atualizarNumeroBicicletasAvariadas(tipoBicicleta bicicletas[],int contBicicletas){
    int i, numeroAvarias=0;

    for(i=0; i<contBicicletas; i++){
        if(strcmp(bicicletas[i].estado,"avariada")==0) //se forem iguais devolve 0, ja existe
        {
            numeroAvarias++;
        }
    }
    return numeroAvarias;
}

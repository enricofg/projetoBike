#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void listarUtentesPorNumeroDecrescenteDeEmprestimos(tipoUtente utentes[],tipoEmprestimo emprestimos[],int contUtentes,int contEmprestimo)
{
    int i, j, aux;
    tipoUtente auxiliar[MAXUTENTE];
    tipoUtente ut;
    ///para nao alterar diretamente o vetor utentes, fizemos a copia para o auxiliar
    for(i=0; i<contUtentes; ++i) //so para fazer a copia
    {
        strcpy(auxiliar[i].nome,utentes[i].nome);
        auxiliar[i].numero = utentes[i].numero;
        auxiliar[i].telemovel = utentes[i].telemovel;
        strcpy(auxiliar[i].tipo,utentes[i].tipo);
        auxiliar[i].distanciaPercorrida = utentes[i].distanciaPercorrida;
        auxiliar[i].quantidadeEmprestimos = utentes[i].quantidadeEmprestimos;
    }

    for(i=0; i < contUtentes-1; i++)           //troca direta
    {
        for (j= i+1; j < contUtentes; j++)
        {
            if(utentes[j].quantidadeEmprestimos > utentes[i].quantidadeEmprestimos)     //> para descrescente
            {
                strcpy(ut.nome,utentes[j].nome);
                ut.numero = utentes[j].numero;
                ut.telemovel = utentes[j].telemovel;
                strcpy(ut.tipo,utentes[j].tipo);
                ut.distanciaPercorrida = utentes[j].distanciaPercorrida;
                ut.quantidadeEmprestimos = utentes[j].quantidadeEmprestimos;

                strcpy(auxiliar[i].nome,ut.nome);
                auxiliar[i].numero = ut.numero;
                auxiliar[i].telemovel = ut.telemovel;
                strcpy(auxiliar[i].tipo,ut.tipo);
                auxiliar[i].distanciaPercorrida = ut.distanciaPercorrida;
                auxiliar[i].quantidadeEmprestimos = ut.quantidadeEmprestimos;

                strcpy(auxiliar[j].nome,utentes[i].nome);
                auxiliar[j].numero = utentes[i].numero;
                auxiliar[j].telemovel = utentes[i].telemovel;
                strcpy(auxiliar[j].tipo,utentes[i].tipo);
                auxiliar[j].distanciaPercorrida = utentes[i].distanciaPercorrida;
                auxiliar[j].quantidadeEmprestimos = utentes[i].quantidadeEmprestimos;
            }
        }
    }

    j=1;

    for(i=0; i<contUtentes; ++i)
    {
        printf("\n\nUtente %d",j);
        printf("\nNome Utente:%s",auxiliar[i].nome);
        printf("\nNumero Utente:%d",auxiliar[i].numero);
        printf("\nTelemovel Utente:%d",auxiliar[i].telemovel);
        printf("\nTipo de Utente:%s",auxiliar[i].tipo);
        printf("\nDistancia percorrida pelo Utente:%f",auxiliar[i].distanciaPercorrida);
        printf("\nQuantidade de emprestimo efectuadas pelo Utente:%d",auxiliar[i].quantidadeEmprestimos);
        j++;
    }
}

void listarDadosEmprestimoUtente(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo)
{
    int pos = -1;
    int codigo;
    int i;
    int opcao;
    int j = 1;
    int posUltimaBicicleta = -1;
    int aux=0;
    int naoExisteEmprestimoDoUtente=0;

    codigo = lerInteiro("\nInsira o numero de utente que saber os dados:",0,MAXNUMEROUTENTE);

    pos = procurarUtente(utentes,codigo,contUtentes);

    if(pos == -1)
    {
        printf("\nO utente nao existe");
    }
    else
    {
        for(i=0; i<contEmprestimo; ++i)
        {
            if(emprestimos[i].codigoUtente == utentes[pos].numero)
            {
                printf("\n\n\t\tEmprestimo do utente com a designacao selecionada");
                printf("\nEmprestimo %d",j);
                printf("\nNumero de registo:%d",emprestimos[i].numeroRegisto);
                printf("\nCodigo de utente:%d\t\tNome Utente:%s",emprestimos[i].codigoUtente,utentes[pos].nome);
                printf("\nDesignacao da bicicleta:%s",emprestimos[i].designacaoBicicleta);
                printf("\nCampus Origem:%s",emprestimos[i].campusOrigem);
                printf("\nCampus destino:%s",emprestimos[i].campusDestino);
                printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimos[i].dataEmprestimo.dia,emprestimos[i].dataEmprestimo.mes,emprestimos[i].dataEmprestimo.ano,
                       emprestimos[i].dataEmprestimo.hora,emprestimos[i].dataEmprestimo.minuto);
                printf("\nData de devolucao:%d-%d-%d\t\t%d:%d",emprestimos[i].dataDevolucao.dia,emprestimos[i].dataDevolucao.mes,emprestimos[i].dataDevolucao.ano,
                       emprestimos[i].dataDevolucao.hora,emprestimos[i].dataDevolucao.minuto);
                printf("\nDistancia percorrida:%.2f",emprestimos[i].distanciaPercorrida);
                j++;
            }
            else
            {

                naoExisteEmprestimoDoUtente = 1;
            }
        }

        for(i=0; i<contEmprestimo-1; i++)
        {
            if(emprestimos[i].codigoUtente==codigo)
            {
                aux++;
            }
        }

        if(aux == 1)
        {
            for(i=0; i<contEmprestimo-1; i++)
            {
                if(emprestimos[i].codigoUtente==codigo)
                {
                    aux++;
                    printf("\n\nDados da ultima bicicleta emprestado ao utilizador selecionado\n");
                    printf("\nDesignacao:%s",bicicletas[i].designacao);
                    printf("\nCampus:%s",bicicletas[i].campus);
                    printf("\nModelo:%s",bicicletas[i].modelo);
                    printf("\nEstado:%s",bicicletas[i].estado);
                    printf("\nQuantidade Avarias:%d",bicicletas[i].quantidadeAvarias);
                    printf("\nQuantidade Emprestimo:%d",bicicletas[i].quantidadeEmprestimos);
                    printf("\nDistancia percorrida:%.2f",bicicletas[i].distanciaTotal);
                }
            }
        }
        else
        {
            for(i=0; i<contEmprestimo-1; i++)
            {
                for(j=i+1; j<contEmprestimo; j++)
                {
                    if(emprestimos[i].codigoUtente==codigo && emprestimos[j].codigoUtente==codigo)
                    {
                        //verificar maior data
                        if(emprestimos[i].dataDevolucao.ano < emprestimos[j].dataDevolucao.ano)
                        {
                            posUltimaBicicleta=j;
                        }
                        else
                        {
                            if(emprestimos[i].dataDevolucao.ano > emprestimos[j].dataDevolucao.ano)
                            {
                                posUltimaBicicleta=i;
                            }
                            else
                            {
                                ///anos iguais
                                if(emprestimos[i].dataDevolucao.mes < emprestimos[j].dataDevolucao.mes)
                                {
                                    posUltimaBicicleta=j;
                                }
                                else
                                {
                                    if(emprestimos[i].dataDevolucao.mes > emprestimos[j].dataDevolucao.mes)
                                    {
                                        posUltimaBicicleta=i;
                                    }
                                    else
                                    {
                                        ///meses iguais
                                        if(emprestimos[i].dataDevolucao.dia < emprestimos[j].dataDevolucao.dia)
                                        {
                                            posUltimaBicicleta = j;
                                        }
                                        else
                                        {
                                            if(emprestimos[i].dataDevolucao.dia > emprestimos[j].dataDevolucao.dia)
                                            {
                                                posUltimaBicicleta = i;
                                            }
                                            else
                                            {
                                                ///dias iguais

                                                if(emprestimos[i].dataDevolucao.hora < emprestimos[j].dataDevolucao.hora)
                                                {
                                                    posUltimaBicicleta=j;
                                                }
                                                else
                                                {
                                                    if(emprestimos[i].dataDevolucao.hora > emprestimos[j].dataDevolucao.hora)
                                                    {
                                                        posUltimaBicicleta=i;
                                                    }
                                                    else
                                                    {
                                                        ///horas iguais

                                                        if(emprestimos[i].dataDevolucao.minuto < emprestimos[j].dataDevolucao.minuto)
                                                        {
                                                            posUltimaBicicleta=j;
                                                        }
                                                        else
                                                        {
                                                            if(emprestimos[i].dataDevolucao.minuto > emprestimos[j].dataDevolucao.minuto)
                                                            {
                                                                posUltimaBicicleta=i;
                                                            }
                                                            else
                                                            {
                                                                ///minutos iguais tanto faz porque as datas sao iguais
                                                                posUltimaBicicleta=i;
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
            }


            if(naoExisteEmprestimoDoUtente==0)
            {
                printf("\n\nDados da ultima bicicleta emprestado ao utilizador selecionado\n");
                printf("\nDesignacao:%s",bicicletas[posUltimaBicicleta].designacao);
                printf("\nCampus:%s",bicicletas[posUltimaBicicleta].campus);
                printf("\nModelo:%s",bicicletas[posUltimaBicicleta].modelo);
                printf("\nEstado:%s",bicicletas[posUltimaBicicleta].estado);
                printf("\nQuantidade Avarias:%d",bicicletas[posUltimaBicicleta].quantidadeAvarias);
                printf("\nQuantidade Emprestimo:%d",bicicletas[posUltimaBicicleta].quantidadeEmprestimos);
                printf("\nDistancia percorrida:%.2f",bicicletas[posUltimaBicicleta].distanciaTotal);
            }
            else
            {
                printf("\nO utente nao possui emprestimo");
            }
        }
    }
}

void estatisticas(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEmprestimo emprestimo[],tipoEspera espera[],int contBicicletas,int contUtente,int contEmprestimo,int contEspera)
{
    int i;
    float distanciaMediaPercorrida = 0;
    tipoData dataInicio;
    tipoData dataFim;
    int j;
    int totalEmprestimosAluno = 0;
    int totalEmprestimosDocente = 0;
    int totalEmprestimosTecnico = 0;
    int totalEmprestimosconvidado = 0;
    float percentagemUtente = 0;
    int quantEmprestResidencias = 0;
    int quantEmprestCampus1 = 0;
    int quantEmprestCampus2 = 0;
    int quantEmprestCampus5 = 0;
    int auxiliar[4];
    int aux;
    char campus[MAXSTRING];
    char designacao[MAXSTRING];
    int pos = -1;
    int quantidade = 0;
    int haEmprestimosEntreAsDatas = 0;
    int dataValida =  0;


    if(contBicicletas == 0)
    {
        printf("\nNao existem bicicletas");
    }
    else
    {
        for(i=0; i<contBicicletas; i++)
        {
            if(bicicleta[i].quantidadeEmprestimos == 0)
            {
                printf("\nA bicicleta '%s' nunca foi emprestada",bicicleta[i].designacao);
            }
            else
            {
                distanciaMediaPercorrida = bicicleta[i].distanciaTotal/bicicleta[i].quantidadeEmprestimos;
                printf("\nBicicleta '%s'\t\tDistancia media percorrida:%.2f",bicicleta[i].designacao,distanciaMediaPercorrida);
            }
        }
    }


    ///quantidade de emprestimo entre duas datas
    if(contEmprestimo == 0)
    {
        printf("\nNao existem emprestimos");
    }
    else
    {
        printf("\n\nSelecione um intervalo de datas que deseja saber estatisticas dos emprestimos realizados");
        printf("\nData inicio:");
        dataInicio = lerData();
        printf("\nData fim:");
        dataFim = lerData();

        dataValida = verificarData(dataFim,dataInicio);
        if(dataValida==-1)
        {
            ///data invalida
            printf("\nA data de devolucao tem de ser superior a data de emprestimo. ");
        }
        else
        {
            j=1;

            for(i=0; i<contEmprestimo; i++)
            {
                if(emprestimo[i].dataEmprestimo.ano<dataFim.ano &&emprestimo[i].dataEmprestimo.ano>dataInicio.ano)
                {
                    ///
                    mostrar(emprestimo,i);
                    haEmprestimosEntreAsDatas = 1;
                }
                else
                {
                    if(emprestimo[i].dataEmprestimo.ano==dataFim.ano &&emprestimo[i].dataEmprestimo.ano==dataInicio.ano)
                    {
                        if(emprestimo[i].dataEmprestimo.mes<dataFim.mes &&emprestimo[i].dataEmprestimo.mes>dataInicio.mes)
                        {

                            ///
                            mostrar(emprestimo,i);
                            haEmprestimosEntreAsDatas = 1;
                        }
                        else
                        {
                            if(emprestimo[i].dataEmprestimo.mes==dataFim.mes &&emprestimo[i].dataEmprestimo.mes==dataInicio.mes)
                            {
                                if(emprestimo[i].dataEmprestimo.dia<dataFim.dia &&emprestimo[i].dataEmprestimo.dia>dataInicio.dia)
                                {
                                    ///
                                    mostrar(emprestimo,i);
                                    haEmprestimosEntreAsDatas = 1;
                                }
                                else
                                {
                                    if(emprestimo[i].dataEmprestimo.dia==dataFim.dia &&emprestimo[i].dataEmprestimo.dia==dataInicio.dia)
                                    {
                                        if(emprestimo[i].dataEmprestimo.hora<dataFim.hora &&emprestimo[i].dataEmprestimo.hora>dataInicio.hora)
                                        {
                                            ///
                                            mostrar(emprestimo,i);
                                            haEmprestimosEntreAsDatas = 1;
                                        }
                                        else
                                        {
                                            if(emprestimo[i].dataEmprestimo.hora==dataFim.hora &&emprestimo[i].dataEmprestimo.hora==dataInicio.hora)
                                            {
                                                if(emprestimo[i].dataEmprestimo.minuto<dataFim.minuto &&emprestimo[i].dataEmprestimo.minuto>dataInicio.minuto)
                                                {
                                                    ///
                                                    mostrar(emprestimo,i);
                                                    haEmprestimosEntreAsDatas = 1;
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
            if(haEmprestimosEntreAsDatas == 0)
            {
                printf("\nNao ha emprestimos entre as datas selecionadas");
            }
        }
    }


    ///percentagem de empréstimos efetuados por cada tipo de utente
    ///estudante docente tecnico administrativo convidado

    if(contUtente == 0)
    {
        printf("\nNao existem utentes");
    }
    else
    {
        for(i=0; i<contUtente; i++)
        {
            if(strcmp(utente[i].tipo,"estudante")==0)
            {
                totalEmprestimosAluno = totalEmprestimosAluno + utente[i].quantidadeEmprestimos;
            }
            else
            {
                if(strcmp(utente[i].tipo,"docente")==0)
                {
                    totalEmprestimosDocente = totalEmprestimosDocente + utente[i].quantidadeEmprestimos;
                }
                else
                {
                    if(strcmp(utente[i].tipo,"tecnico administrativo")==0)
                    {
                        totalEmprestimosTecnico = totalEmprestimosTecnico + utente[i].quantidadeEmprestimos;
                    }
                    else
                    {
                        totalEmprestimosconvidado = totalEmprestimosconvidado + utente[i].quantidadeEmprestimos;
                    }
                }
            }
        }

        if(contEmprestimo == 0)
        {
            printf("\nNao existem emprestimos");
        }
        else
        {
            percentagemUtente = ((float)totalEmprestimosAluno/contEmprestimo)*100;
            printf("\n\nPercentagem de emprestimo por tipo de utente");
            printf("\nAlunos:%.2f%%",percentagemUtente);

            percentagemUtente = ((float)totalEmprestimosDocente/contEmprestimo)*100;
            printf("\nDocente:%.2f%%",percentagemUtente);

            percentagemUtente = ((float)totalEmprestimosTecnico/contEmprestimo)*100;
            printf("\nTecnico Administrativo:%.2f%%",percentagemUtente);

            percentagemUtente = ((float)totalEmprestimosconvidado/contEmprestimo)*100;
            printf("\nConvidado:%.2f%%",percentagemUtente);
        }
    }



    ///campus de origem com a maior quantidade de empréstimos
    ///residencias, campus 1, campus 2, campus 5
    if(contEmprestimo==0)
    {
        printf("\nNao existem emprestimos");
    }
    else
    {
        for(i=0; i<contEmprestimo; i++)
        {
            if(strcmp(emprestimo[i].campusOrigem,"residencias")==0)
            {
                quantEmprestResidencias++;
            }
            else
            {
                if(strcmp(emprestimo[i].campusOrigem,"campus 1")==0)
                {
                    quantEmprestCampus1++;
                }
                else
                {
                    if(strcmp(emprestimo[i].campusOrigem,"campus 2")==0)
                    {
                        quantEmprestCampus2++;
                    }
                    else
                    {
                        quantEmprestCampus5++;
                    }
                }
            }
        }
        j=0;

        auxiliar[0] = quantEmprestResidencias;
        auxiliar[1] = quantEmprestCampus1;
        auxiliar[2] = quantEmprestCampus2;
        auxiliar[3] = quantEmprestCampus5;

        for(i=0; i < 3; i++)           //troca direta
        {
            for (j= i+1; j < 4; j++)
            {
                if(auxiliar[j] > auxiliar[i])     //> para descrescente
                {
                    aux=auxiliar[j];
                    auxiliar[j]=auxiliar[i];
                    auxiliar[i]=aux;
                }
            }
        }

        if(auxiliar[0] == quantEmprestResidencias)
        {
            strcpy(campus,"residencias");
        }
        else
        {
            if(auxiliar[0] == quantEmprestCampus1)
            {
                strcpy(campus,"campus 1");
            }
            else
            {
                if(auxiliar[0] == quantEmprestCampus2)
                {
                    strcpy(campus,"campus 2");
                }
                else
                {
                    strcpy(campus,"campus 5");
                }
            }
        }

        printf("\nCampus com maior quantidade de emprestimo:%s\n",campus);
    }



    ///e a quantidade de utentes que utilizaram uma determinada bicicleta (indicada pelo utilizador).
    if(contBicicletas == 0)
    {
        printf("\nNao existem bicicletas");
    }
    else
    {
        lerString("\n\nIntroduza o ID da bicicleta que pretence saber:",designacao,MAXSTRING);

        pos = procurarBicicleta(bicicleta,designacao,contBicicletas);

        if(pos == -1)
        {
            printf("\nA bicicleta com a desginacao introduzida nao existe");
        }
        else
        {
            if(contEmprestimo==0)
            {
                printf("\nNao existem emprestimos");
            }
            else
            {
                if(contEmprestimo == 1)
                {
                    for(i=0; i<contEmprestimo; i++)
                    {
                        if(strcmp(emprestimo[i].designacaoBicicleta,designacao)==0)
                        {
                            //printf("teste");
                            quantidade++;
                        }
                    }
                }
                else
                {
                    for(i=0; i<contEmprestimo-1; i++)
                    {
                        for(j=i+1; i<contEmprestimo; i++)
                        {
                            if(emprestimo[i].codigoUtente != emprestimo[j].codigoUtente)
                            {
                                if(strcmp(emprestimo[i].designacaoBicicleta,designacao)==0)
                                {
                                    quantidade++;
                                }
                                if(strcmp(emprestimo[j].designacaoBicicleta,designacao)==0)
                                {
                                    quantidade++;
                                }
                            }
                        }
                    }
                }
                printf("\n\nQuantidade de utentes que usaram a bicicleta escolhida:%d",quantidade);
            }
        }
    }
}

void mostrar(tipoEmprestimo emprestimo[],int i)
{
    printf("\nID do emprestimo:%d",emprestimo[i].numeroRegisto);
    printf("\nCodigo de utente:%d",emprestimo[i].codigoUtente);
    printf("\nID da bicicleta:%s",emprestimo[i].designacaoBicicleta);
    printf("\nCampus Origem:%s",emprestimo[i].campusOrigem);
    printf("\nCampus destino:%s",emprestimo[i].campusDestino);
    printf("\nData de emprestimo:%02d-%02d-%04d\t\t%02d:%02d",emprestimo[i].dataEmprestimo.dia,emprestimo[i].dataEmprestimo.mes,emprestimo[i].dataEmprestimo.ano,
           emprestimo[i].dataEmprestimo.hora,emprestimo[i].dataEmprestimo.minuto);
    printf("\nData de devolucao:%02d-%02d-%04d\t\t%02d:%02d",emprestimo[i].dataDevolucao.dia,emprestimo[i].dataDevolucao.mes,emprestimo[i].dataDevolucao.ano,
           emprestimo[i].dataDevolucao.hora,emprestimo[i].dataDevolucao.minuto);
    printf("\nDistancia percorrida:%.2f\n",emprestimo[i].distanciaPercorrida);

}

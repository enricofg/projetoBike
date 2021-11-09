#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

int main()
{
    int opcao,contBicicletas=0,contEmprestimo=0,contEspera=0,contUtente=0,bicicletasOcupadas=0;
    int idEmprestimo = 1, quantEmprestimos=0, quantAvariadas=0;
    char opcaoBicicleta,opcUtente,opcEmprestimo, opcEspera;
    float distTotPecorrida=0.;
    int verPossibEmprestimo=0;
    int sucessoDevolucao=0, existe=0,posAtribuir=-1;//devolucao
    int pos = -1;
    int posBicicleta = -1;
  //  tipoEspera esperaAux;

    //  tipoData data;
    tipoBicicleta bicicleta[MAXBICICLETA];
    tipoUtente utente[MAXUTENTE];
    tipoEmprestimo *emprestimo;
    tipoEspera *espera;
    tipoEspera esperaAux;

    emprestimo=NULL;
    espera=NULL;

    lerFicheiroBinBicicleta(bicicleta,&contBicicletas);
    lerFicheiroBinUtente(utente,&contUtente);

    emprestimo = lerFicheiroBinEmprestimo(emprestimo,&contEmprestimo);//dinamico
    espera = lerFicheiroBinEspera(espera,&contEspera);

    if(quantEmprestimos!=0)
    {
        idEmprestimo=quantEmprestimos+1;
        //printf("idEmprestimo: %d", idEmprestimo);
    }
    //printf("\nOCUPADAS: %d",bicicletasOcupadas);

    do
    {
        bicicletasOcupadas = bicicletasDisponiveis(bicicleta,&contBicicletas);
        quantEmprestimos = quantidadeEmprestimos(emprestimo,&contEmprestimo);
        distTotPecorrida = atualizarDistanciaTotal(bicicleta,contBicicletas);
        quantAvariadas = atualizarNumeroBicicletasAvariadas(bicicleta,contBicicletas);

        opcao = menuPrincipal(contBicicletas, contEmprestimo, contEspera, contUtente, bicicletasOcupadas, distTotPecorrida,quantAvariadas);
        switch(opcao)
        {
        case 1:
            opcaoBicicleta = menuBicicleta(contBicicletas);
            switch(opcaoBicicleta)
            {
            case 'I':
                if(contBicicletas == MAXBICICLETA)
                {
                    printf("\nJa atingiu o numero maximo de bicicletas");
                }
                else
                {
                    inserirBicicleta(bicicleta,&contBicicletas);
                    pos = verificarListaDeEspera(bicicleta,utente,espera,contUtente,contEspera,contBicicletas,&posBicicleta);

                    if(pos != -1 && posBicicleta != -1){
                        espera = removerEspera(utente,espera,esperaAux,contUtente,&contEspera,pos);
                        emprestimo = atribuirBicicleta(bicicleta,utente,emprestimo,esperaAux,contBicicletas,contUtente,&contEmprestimo,&idEmprestimo,&bicicletasOcupadas,posBicicleta);
                    }
                }
                break;
            case 'C':
                consultarBicicleta(bicicleta,contBicicletas);
                break;
            case 'L':
                listarBicicletas(bicicleta,contBicicletas);
                break;
            case 'R':
                registarAvariaReparacao(bicicleta,contBicicletas,&bicicletasOcupadas);
                break;
            }
            break;
        case 2:
            opcUtente = menuUtente(contUtente);
            switch(opcUtente)
            {
            case 'I':
                if(contUtente == MAXUTENTE)
                {
                    printf("\nJa atingiu o numero maximo de utentes");
                }
                else
                {
                    inserirUtente(utente,&contUtente);
                }
                break;
            case 'C':
                consultarUtente(utente,contUtente);
                break;
            case 'L':
                listarUtente(utente,contUtente);
                break;
            case 'A':
                alterarUtente(utente,contUtente);
                break;
            }
            break;
        case 3:
            opcEspera = menuEspera(contEspera);
            switch(opcEspera)
            {
            case 'A'://alterar campus de destino
                alterarCampusDestinoEspera(espera,contEspera);
                break;
            case 'E':
                if(contEspera == 0)
                {
                    printf("\nAinda nao ha utentes para eliminar.");
                }
                else
                {
                    espera = eliminarEspera(utente,espera,contUtente,&contEspera);
                }
                break;
            case 'C':
                if(contEspera == 0)
                {
                    printf("\nAinda nao ha utentes na lista de espera.");
                }
                else
                {
                    consultarEspera(bicicleta,utente,espera,contBicicletas,contUtente,contEspera);
                }
                break;
            case 'L':
                if(contEspera == 0)
                {
                    printf("\nAinda nao ha utentes na lista de espera.");
                }
                else
                {
                    listarEspera(bicicleta,utente,espera,contBicicletas,contUtente,contEspera);
                }
                break;
            }
            break;
        case 4:
            opcEmprestimo = menuEmprestimo(bicicletasOcupadas);
            switch(opcEmprestimo)
            {
            case 'R':
                emprestimo = registarEmprestimo(bicicleta,utente,emprestimo,contBicicletas,contUtente,&contEmprestimo,&idEmprestimo,&bicicletasOcupadas,&verPossibEmprestimo);
                if(verPossibEmprestimo==0)
                {
                    printf("\nInfelizmente nao ha bicicletas disponiveis, voce sera colocado na lista de espera!");
                    espera = registrarEspera(espera,utente,&contEspera,contUtente);
                }
                break;
            case 'D':
                devolverBicicleta(bicicleta,utente,emprestimo,contBicicletas,contUtente,contEmprestimo,&bicicletasOcupadas,&sucessoDevolucao);

                if(sucessoDevolucao == 1){
                    pos = verificarExistenciaNaListaDeEspera(bicicleta,espera,contBicicletas,contEspera);

                    if(pos != -1){
                            emprestimo = atribuirBike(bicicleta,utente,emprestimo,espera,contBicicletas,contUtente,&contEmprestimo,&idEmprestimo,&bicicletasOcupadas,pos);
                            espera = removerListaEspera(espera,&contEspera,pos);
                        //printf("\nANA:%d",esperaAux.codigoUtente);
                        //emprestimo = atribuirBike(bicicleta,utente,emprestimo,esperaAux,contBicicletas,contUtente,&contEmprestimo,&idEmprestimo,&bicicletasOcupadas);
                    }
                }
                break;
            case 'C':
                if(contEmprestimo == 0)
                {
                    printf("\nAinda nao foram efetuados qualquer emprestimo");
                }
                else
                {
                    consultarEmprestimo(bicicleta,utente,emprestimo,contBicicletas,contUtente,contEmprestimo);
                }
                break;
            case 'L':
                if(contEmprestimo == 0)
                {
                    printf("\nAinda nao foram efetuados qualquer emprestimo");
                }
                else
                {
                    listarEmprestimos(bicicleta,utente,emprestimo,contBicicletas,contUtente,contEmprestimo);
                }
                break;
            }
            break;
        case 5:
            if(contEmprestimo == 0)
            {
                printf("\nAinda nao foram efetuados qualquer emprestimo");
            }
            else
            {
                listarUtentesPorNumeroDecrescenteDeEmprestimos(utente,emprestimo,contUtente,contEmprestimo);
            }
            break;
        case 6:
            estatisticas(bicicleta,utente,emprestimo,espera,contBicicletas,contUtente,contEmprestimo,contEspera);
            break;
        case 7:
            if(contEmprestimo == 0)
            {
                printf("\nAinda nao foram efetuados qualquer emprestimo");
            }
            else
            {
                listarDadosEmprestimoUtente(bicicleta,utente,emprestimo,contBicicletas,contUtente,contEmprestimo);
            }
            break;
        }
    }
    while(opcao!=8);

    escreverFicheiroBinBicicleta(bicicleta,contBicicletas);//salvar
    escreverFicheiroBinUtente(utente,contUtente);//salvar
    escreverFicheiroBinEmprestimo(emprestimo,contEmprestimo);
    escreverFicheiroBinEspera(espera,contEspera);

    free(emprestimo);
    free(espera);

    return 0;
}

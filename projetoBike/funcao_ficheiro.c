#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaracoes_funcoes.h"
#include "constantes.h"
#include "estruturas.h"

void lerFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int *contBicicletas)
{
    FILE *ficheiro;
    ficheiro=fopen("bicicletas.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("\nErro abrir ficheiro bicicleta");
    }
    else
    {
        fread(contBicicletas,sizeof(int),1,ficheiro);
        fread(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);
    }
}

void escreverFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int contBicicletas)
{
    if (contBicicletas==0)
    {
        printf("\n\nNao existem bicicletas em registro");
    }
    FILE *ficheiro;

    ficheiro=fopen("bicicletas.dat","wb");
    if(ficheiro==NULL)
    {
        printf("\nErro de abertura bicicleta");
    }
    else
    {
        fwrite(&contBicicletas,sizeof(int),1,ficheiro);
        fwrite(bicicleta,sizeof(tipoBicicleta),MAXBICICLETA,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro bicicletas exportado com sucesso");
    }
}

void lerFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int *contUtente)
{
    FILE *ficheiro;
    ficheiro=fopen("utentes.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("\nErro abrir ficheiro utente");
    }
    else
    {
        fread(contUtente,sizeof(int),1,ficheiro);
        fread(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);
    }
}

void escreverFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int contUtente)
{
    if (contUtente==0)
    {
        printf("\n\nNao existem utentes em registro");
    }
    FILE *ficheiro;

    ficheiro=fopen("utentes.dat","wb");
    if(ficheiro==NULL)
    {
        printf("\nErro de abertura utente");
    }
    else
    {
        fwrite(&contUtente,sizeof(int),1,ficheiro);
        fwrite(utente,sizeof(tipoUtente),MAXUTENTE,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro utentes exportado com sucesso");
    }
}

tipoEmprestimo *lerFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int *contEmprestimo)
{
    FILE *ficheiro;
    tipoEmprestimo *aux;
    aux = NULL;
    ficheiro=fopen("emprestimos.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("\nErro abrir ficheiro emprestimo");
    }
    else
    {
        fread(contEmprestimo,sizeof(int),1,ficheiro);

        aux = realloc(aux,(*contEmprestimo)*sizeof(tipoEmprestimo));

        if(aux ==NULL && *contEmprestimo != 0)
        {
            printf("\nErro ao alocar memoria");
            *contEmprestimo =0;
        }
        else
        {
            fread(aux,sizeof(tipoEmprestimo),*contEmprestimo,ficheiro);
        }

    }

    return aux;
}

void escreverFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int contEmprestimo)
{
    if (contEmprestimo==0)
    {
        printf("\n\nNao existem emprestimos em registro");
    }
    FILE *ficheiro;

    ficheiro=fopen("emprestimos.dat","wb");
    if(ficheiro==NULL)
    {
        printf("\nErro de abertura emprestimos");
    }
    else
    {
        fwrite(&contEmprestimo,sizeof(int),1,ficheiro);
        fwrite(emprestimo,sizeof(tipoEmprestimo),contEmprestimo,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro emprestimos exportado com sucesso");
    }
}

tipoEspera *lerFicheiroBinEspera(tipoEspera espera[], int *contEspera)
{
    FILE *ficheiro;
    tipoEspera *aux;
    aux = NULL;
    ficheiro=fopen("esperas.dat","rb");
    if (ficheiro == NULL)
    {
        printf ("\nErro abrir ficheiro espera");
    }
    else
    {
        fread(contEspera,sizeof(int),1,ficheiro);

        aux = realloc(aux,(*contEspera)*sizeof(tipoEspera));

        if(aux ==NULL && *contEspera != 0)
        {
            printf("\nErro ao alocar memoria");
            *contEspera = 0;
        }
        else
        {
            fread(aux,sizeof(tipoEspera),*contEspera,ficheiro);
        }

    }

    return aux;
}

void escreverFicheiroBinEspera(tipoEspera espera[], int contEspera)
{
    if (contEspera==0)
    {
        printf("\n\nNao existem esperas em registro");
    }
    FILE *ficheiro;

    ficheiro=fopen("esperas.dat","wb");
    if(ficheiro==NULL)
    {
        printf("\nErro de abertura esperas");
    }
    else
    {
        fwrite(&contEspera,sizeof(int),1,ficheiro);
        fwrite(espera,sizeof(tipoEspera),contEspera,ficheiro);

        fclose(ficheiro);
        printf("\nFicheiro espera exportado com sucesso");
    }
}

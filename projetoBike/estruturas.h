#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct
{
    char modelo[MAX_STRING]; //el�trica
    char nome[MAX_STRING]; //O usu�rio dar um nome a bike
    int id;     //�nico e gerado autom�tico
    int status; //1-dispon�vel, 2-emprestada, 3-avariada
    int campus; //1-campus1, 2-campus2, 5-campus5, 3-residencia
} tipoBike;

typedef struct
{
    int id;    //�nico e gerado autom�tico
    char nome;
    int telemovel;
    int tipo;   //1-estudante, 2-docente, 3-t�cnico administrativo ou 4-convidado
} tipoUser;

typedef struct
{
    int campos;
} tipoEmprestimo;

#endif // ESTRUTURAS_H_INCLUDED

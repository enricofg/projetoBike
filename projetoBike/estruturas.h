#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct
{
    char modelo[MAX_STRING]; //elétrica
    char nome[MAX_STRING]; //O usuário dar um nome a bike
    int id;     //único e gerado automático
    int status; //1-disponível, 2-emprestada, 3-avariada
    int campus; //1-campus1, 2-campus2, 5-campus5, 3-residencia
} tipoBike;

typedef struct
{
    int id;    //único e gerado automático
    char nome;
    int telemovel;
    int tipo;   //1-estudante, 2-docente, 3-técnico administrativo ou 4-convidado
} tipoUser;

typedef struct
{
    int campos;
} tipoEmprestimo;

#endif // ESTRUTURAS_H_INCLUDED

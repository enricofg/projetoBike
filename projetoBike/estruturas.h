#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"
#include "declaracoes_funcoes.h"

typedef struct{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
}tipoData;

typedef struct{
    char designacao[MAXSTRING];///ID inserido pelo usuario
    char modelo[MAXSTRING];
    char estado[MAXESTADO];  ///disponivel, emprestada, avariada
    char campus[MAXSTRING];  ///residencias, campus 1, campus 2, campus 5
    int quantidadeEmprestimos;
    int quantidadeAvarias;
    float distanciaTotal;
}tipoBicicleta;

typedef struct{
    int numero;
    char nome[MAXSTRING];
    int telemovel;
    char tipo[MAXSTRING]; ///estudante docente tecnico administrativo convidado
    int quantidadeEmprestimos;
    float distanciaPercorrida;
}tipoUtente;

typedef struct{
    int numeroRegisto;
    int codigoUtente;
    char designacaoBicicleta[MAXSTRING];
    tipoData dataEmprestimo;
    char campusOrigem[MAXSTRING];
    char campusDestino[MAXSTRING];
    tipoData dataDevolucao;
    float distanciaPercorrida;
}tipoEmprestimo;

typedef struct{
    int codigoUtente;
    tipoData dataRegistro; //tipoData dataEmprestimo;
    char campusOrigem[MAXSTRING];
    char campusDestino[MAXSTRING];
}tipoEspera;

#endif // ESTRUTURAS_H_INCLUDED

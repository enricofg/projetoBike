#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"

int lerInteiro(char mensagem[MAXSTRING], int minimo, int maximo);
float lerFloat(char mensagem[MAXSTRING], float minimo, float maximo);
void lerString(char mensagem[MAXSTRING], char vetorCaracteres[MAXSTRING], int maximoCaracteres);
void limpaBufferStdin(void);

int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente);
char menuBicicleta(int contBicicletas);

void inserirBicicleta(tipoBicicleta bicicletas[],int *contBicicletas);
void consultarBicicleta(tipoBicicleta bicicletas[],int contBicicletas);
void listarBicicletas(tipoBicicleta bicicletas[],int contBicicletas);
int procurarBicicleta(tipoBicicleta bicicletas[],char designacao[],int contBicicletas);

#endif // FUNCOES_AUXILIARES_H_INCLUDED

#ifndef DECLARACOES_FUNCOES_H_INCLUDED
#define DECLARACOES_FUNCOES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"

//auxiliares
int lerInteiro(char mensagem[MAXSTRING], int minimo, int maximo);
float lerFloat(char mensagem[MAXSTRING], float minimo, float maximo);
void lerString(char mensagem[MAXSTRING], char vetorCaracteres[MAXSTRING], int maximoCaracteres);
void limpaBufferStdin(void);
tipoData lerData(void);

//menus
int menuPrincipal(int contBicicletas, int contEmprestimo, int contEspera, int contUtente, int bicicletasOcupadas, float distTotPecorrida,  int quantAvariadas);
char menuBicicleta(int contBicicletas);
char menuUtente(int contUtente);
char menuEmprestimo(int bicicletasOcupadas);
int menuCampus();
int subMenuTipoUtente();
char menuEspera(int numeroDeEsperas);
int subMenuAvariaReparacao();

//bicicletas
void inserirBicicleta(tipoBicicleta bicicletas[],int *contBicicletas);
void consultarBicicleta(tipoBicicleta bicicletas[],int contBicicletas);
void listarBicicletas(tipoBicicleta bicicletas[],int contBicicletas);
int procurarBicicleta(tipoBicicleta bicicletas[],char designacao[],int contBicicletas);
int bicicletasDisponiveis(tipoBicicleta bicicletas[], int *contBicicletas);
void registarAvariaReparacao(tipoBicicleta bicicletas[], int contBicicleta,int *bicicletasOcupadas);
float atualizarDistanciaTotal(tipoBicicleta bicicleta[],int contBicicletas);
int atualizarNumeroBicicletasAvariadas(tipoBicicleta bicicleta[],int contBicicletas);

//emprestimos
tipoEmprestimo *registarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas, int *verPossibEmprestimo);
void listarEmprestimos(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo);
void consultarEmprestimo(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo);
void devolverBicicleta(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo,int *bicicletasOcupadas,int *sucessoDevolucao);
int quantidadeEmprestimos(tipoEmprestimo emprestimos[], int *contEmprestimo);
int verificarData(tipoData verificar,tipoData dataEmprestimo);
//tipoEmprestimo *atribuirBike(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],tipoEspera esperaAux,int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas);
int atribuirBicicletaConsoanteCriterio(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEspera espera[],int contBicicletas,int contUtente,int contEspera);
tipoEmprestimo *atribuirBicicleta(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEmprestimo emprestimo[],tipoEspera esperaAux,int contBicicletas,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas,int posBicicleta);
tipoEmprestimo *atribuirBike(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEmprestimo emprestimos[],tipoEspera espera[],int contBicicleta,int contUtente,int *contEmprestimo,int *idEmprestimo,int *bicicletasOcupadas,int posEspera);

//ficheiro
void lerFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int *contBicicletas);
void escreverFicheiroBinBicicleta(tipoBicicleta bicicleta[MAXBICICLETA], int contBicicletas);
void lerFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int *contUtente);
void escreverFicheiroBinUtente(tipoUtente utente[MAXUTENTE], int contUtente);
tipoEmprestimo *lerFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int *contEmprestimo);
void escreverFicheiroBinEmprestimo(tipoEmprestimo emprestimo[], int contEmprestimo);
tipoEspera *lerFicheiroBinEspera(tipoEspera espera[], int *contEspera);
void escreverFicheiroBinEspera(tipoEspera espera[], int contEspera);

//utentes
void inserirUtente(tipoUtente Utente[],int *contUtente);
int procurarUtente(tipoUtente Utente[],int codigo,int contUtente);
void alterarUtente(tipoUtente Utente[],int contUtente);
void consultarUtente(tipoUtente Utente[],int contUtente);
void listarUtente(tipoUtente Utente[],int contUtente);

//espera
tipoEspera *registrarEspera(tipoEspera espera[],tipoUtente utente[],int *contEspera,int contUtente);
void consultarEspera(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEspera espera[],int contBicicleta,int contUtentes,int contEspera);
void listarEspera(tipoBicicleta bicicleta[],tipoUtente utentes[],tipoEspera espera[],int contBicicleta,int contUtentes,int contEspera);
void alterarCampusDestinoEspera(tipoEspera espera[],  int contEspera);
tipoEspera *eliminarEspera(tipoUtente utentes[],tipoEspera espera[],int contUtentes,int *contEspera);
int verificarListaDeEspera(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEspera espera[],int contUtente,int contEspera,int contBicicletas,int *posBicicleta);
tipoEspera *removerEspera(tipoUtente utente[],tipoEspera espera[],tipoEspera esperaAux,int contUtente,int *contEspera,int posEspera);
tipoEspera *removerListaEspera(tipoEspera espera[],int *contEspera,int pos);

//estatistica
void listarUtentesPorNumeroDecrescenteDeEmprestimos(tipoUtente utentes[],tipoEmprestimo emprestimos[],int contUtentes,int contEmprestimo);
void listarDadosEmprestimoUtente(tipoBicicleta bicicletas[],tipoUtente utentes[],tipoEmprestimo emprestimos[],int contBicicleta,int contUtentes,int contEmprestimo);
void estatisticas(tipoBicicleta bicicleta[],tipoUtente utente[],tipoEmprestimo emprestimo[],tipoEspera espera[],int contBicicletas,int contUtente,int contEmprestimo,int contEspera);

#endif // DECLARACOES_FUNCOES_H_INCLUDED

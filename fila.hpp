#ifndef FILA_H
#define FILA_H
#include <iostream>
#include <ctime>
#define MAXTAM 5
using namespace std;
// Criando a struct dos médicos
typedef struct
{
    string nome;
    string especialidade;
    string CRM;
    bool disponivel = true;
} Medico;
// Criando a struct dos pacientes
typedef struct
{
    string nome;
    string endereco;
    int idade;
    string sexo;
    char triagem[18];
    int prioridade;
    bool atendido = false;
    time_t horaChegada;
    time_t horaSaida;
    double tempo;
} Paciente;

//structs básicas retiradas da TAD
typedef struct TElemento *Apontador;


typedef struct TElemento
{
    Medico medico;
    Paciente paciente;
    Apontador prox;
} TElemento;


typedef struct TFila
{
    Apontador inicio, fim;
    int tamanho;
} TFila;
//declarando as funções
void CriaFila(TFila *fila);
bool VerificaFilaVazia(TFila *fila);
int Tamanho(TFila *fila);
void EnfileiraMedico(TFila *fila, Medico item);
void EnfileiraPaciente(TFila *fila, Paciente item);
void inserePacientePrimeiro(TFila *fila, Paciente paciente);
void insereAposElemento(Apontador anterior, Apontador novo, TFila *fila);
void EnfileiraPrioridade(TFila *fila, Paciente paciente);
void DesenfileiraPaciente(TFila *fila, Paciente *item);
void ImprimeFilaMedicos(TFila *fila);
void ImprimeFilaPacientes(TFila *fila);
void InsereMedicos(Medico *medico, TFila *fila);
void menu();
void InserePaciente(Paciente *Item, int triagem);
int Triagem();
void AtualizaUltimo(TFila *fila);
void atualizar(TFila *filaPacientes, TFila *filaPacientesAtendidos, TFila *filamedicos, TFila *filaMedicosDisponiveis);

#endif
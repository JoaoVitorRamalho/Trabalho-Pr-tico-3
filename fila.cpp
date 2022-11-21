#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include "fila.hpp"

using namespace std;

//as primeiras funções são as TADs de fila
//aqui criamos uma fila
void CriaFila(TFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}
//verificando se o inicio da fila for null a fila esta vazia
bool VerificaFilaVazia(TFila *fila)
{
    return (fila->inicio == NULL);
}
//retornando o tamanho da fila
int Tamanho(TFila *fila)
{
    return fila->tamanho;
}
//enfileirando o medico na fila
void EnfileiraMedico(TFila *fila, Medico item)
{
    Apontador novo = new TElemento;

    novo->medico = item;
    novo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}
//cria um novo elemento e insere na fila um novo paciente com os dados cadastrados
void EnfileiraPaciente(TFila *fila, Paciente item)
{
    Apontador novo = new TElemento;
    novo->paciente = item;
    novo->prox = NULL;
    if (VerificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}
//aqui primeiro é feito uma verificação se a fila de pacientes está vazia se não estiver ele insere o paciente no começo da fila
void inserePacientePrimeiro(TFila *fila, Paciente paciente)
{
    Apontador aux = new TElemento;
    aux->paciente = paciente;
    aux->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = aux;
        fila->fim = fila->inicio;
    }
    else
    {
        aux->prox = fila->inicio;
        fila->inicio = aux;
    }
    fila->tamanho++;
}
//essa função servirá para adicionar um paciente com priodade menor que o primeiro da fila
void insereAposElemento(Apontador anterior, Apontador novo, TFila *fila)
{
    novo->prox = anterior->prox;
    anterior->prox = novo;
    fila->tamanho++;
}
//aqui é feito uma verificação de a fila está vazia se estiver o programa adiona ele logo no primro lugar
//se não verifica a qual prioridade ele possui maior que algum paciente da fila, colocando ele na frente de alguem que possui uma prioridade menor que ele porém atrás de alguem que tem uma prioridade maior
void EnfileiraPrioridade(TFila *fila, Paciente paciente)
{
    
    if (VerificaFilaVazia(fila))
    {
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    if (paciente.prioridade < fila->inicio->paciente.prioridade)
    {
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    Apontador anterior = fila->inicio;
    Apontador atual = anterior->prox;
    Apontador novo = new TElemento;
    novo->paciente = paciente;
    novo->prox = NULL;


    while (atual != NULL)
    {
        if (novo->paciente.prioridade < atual->paciente.prioridade)
        {
            insereAposElemento(anterior, novo, fila);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    insereAposElemento(anterior, novo, fila);
    fila->fim = novo;
}
//retira o paciente da fila
void DesenfileiraPaciente(TFila *fila, Paciente *item)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;

    *item = aux->paciente;
    fila->inicio = aux->prox;
    delete aux;
   
}
//verifica se a fila de medicos está vazia se não ele imprime toda a lista de medicos
void ImprimeFilaMedicos(TFila *fila)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Nenhum médico cadastrado!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL)
    {

        cout << "\nNome: " << aux->medico.nome;
        cout << "\nEspecialidade: " << aux->medico.especialidade;
        cout << "\nCRM: " << aux->medico.CRM;
        cout << "\nDisponivel(0-SIM, 1-NAO): " << aux->medico.disponivel
             << endl;
        aux = aux->prox;
    }
    cout << endl;
   
}
//verifica se a fila de medicos está vazia se não ele imprime toda a lista de pacientes
void ImprimeFilaPacientes(TFila *fila)
{

    if (VerificaFilaVazia(fila))
    {
        cout << "Nenhum paciente cadastrado!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL)
    {
        cout << "\nNome: " << aux->paciente.nome;
        cout << "\nEndereço: " << aux->paciente.endereco;
        cout << "\nIdade: " << aux->paciente.idade;
        cout << "\nSexo: " << aux->paciente.sexo;
        cout << "\nPrioridade: " << aux->paciente.prioridade;
        cout << "\nfoi atendido: 0-NÃO 1-SIM " << aux->paciente.atendido;
        if (aux->paciente.atendido == 1)
        {
            cout << "\nTempo de Atendimento: " << aux->paciente.tempo
                 << endl;
        }
        cout << "\nHora que chegou: " << ctime(&aux->paciente.horaChegada);

        aux = aux->prox;
    }
    cout << endl;
}

//como foi solicitado para deixar os médico já pré-definidos aqui o prgrama coloca manualmente os cinco médicos
void InsereMedicos(Medico *medico, TFila *fila)
{
    Medico medicos;
    medicos.nome="Joao";
    medicos.especialidade="Neurologista";
    medicos.CRM="32535";
    EnfileiraMedico(fila,medicos);
    medicos.nome="Erick";
    medicos.especialidade="Urologista";
    medicos.CRM="75578";
    EnfileiraMedico(fila,medicos);
    medicos.nome="Icaro";
    medicos.especialidade="Patologista";
    medicos.CRM="35777";
    EnfileiraMedico(fila,medicos);
    medicos.nome="Cleberson";
    medicos.especialidade="Dermatologista";
    medicos.CRM="12890";
    EnfileiraMedico(fila,medicos);
    medicos.nome="Roberval";
    medicos.especialidade="Otorrinolaringologista";
    medicos.CRM="90045";
    EnfileiraMedico(fila,medicos);
}
//imprime o menu
void menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "         Hospital        \n";
    cout << "--------------------------------\n";
    cout << "1. Realizar o atendimento\n";
    cout << "2. Mostrar os registros\n";
    cout << "3. Atualizar\n";
    cout << "4. Sair\n";

}
//aqui o programa verifica a prioridade dos pacientes e defini assim qual lugar da fila eles serão adiocionados
void InserePaciente(Paciente *Item, int triagem)
{
    int prioridade;
    double tempoAtendimento;
    if (triagem <= 5)
    {
        prioridade = 1;
        tempoAtendimento = 5; 
    }
    else if (triagem > 5 && triagem < 11)
    {
        prioridade = 2;
        tempoAtendimento = 4; 
    }
    else if (triagem > 11 && triagem < 16)
    {
        prioridade = 3;
        tempoAtendimento = 3; 
    }
    else if (triagem > 16 && triagem < 18)
    {
        prioridade = 4;
        tempoAtendimento = 2; 
    }
    else
    {
        prioridade = 5;
        tempoAtendimento = 1; 
    }
    system("cls");
    cout<<"\nCadastrando paciente: ";
    cout << "Nome: ";
    cin>>Item->nome;
    cout<<"Endereço: ";
    cin>>Item->endereco;
    cout<<"Idade: ";
    cin>>Item->idade;
    cout << "sexo: ";
    cin>>Item->sexo;
    Item->prioridade = prioridade;
    Item->horaChegada = time(NULL);
    Item->tempo = tempoAtendimento;
}
//mostra o menu da triagem, recebendo a assim as respostas digitadas pelo usuário
int Triagem()
{
    char respostas[18];
    Paciente teste;
    TFila fila;
    system("cls");
    cout<<"\nFazendo a triagem: ";

    cout << "1: Comprometimento das Vias Aerias?\n";
    cout << "2: Respiração Ineficaz?\n";
    cout << "3: choc?\n";
    cout << "4: Não responde a estimulos?\n";
    cout << "5: Em convulção?\n";
    cout << "6: Dor severa?\n";
    cout << "7: Grande hemorragia incontrolavel?\n";
    cout << "8: Alteração do estado de consiencia?\n";
    cout << "9: temperatura maior ou igual a 39°?\n";
    cout << "10: Trauma craniano severo?\n";
    cout << "11: Dor moderada?\n";
    cout << "12: Pequena hemorragia incontrolavel?\n";
    cout << "13: Vomito percistente?\n";
    cout << "14: temperatura entre 38°  e 39°?\n";
    cout << "15: Idoso ou gravida?\n";
    cout << "16: Dor leve?\n";
    cout << "17: Nausea?\n";
    cout << "18: Temperatura entre 37° e 38°?\n";

    cout << "Responda com S para sim e N para não as perguntas na ordem correta:\n\n";
    for (int i = 1; i <= 5; i++)
    { 
        cout<<"Pergunta (" <<i<<"): ";
        cin>>respostas[i];
        if (respostas[i] == 'S' || respostas[i] == 's')
        {
            return i;
        }
    }
    for (int i = 6; i < 18; i++)
    {
        cout << "Pergunta " << i;
        cin >> respostas[i];
    }
    cout << "Ordem das Respostas \n ";
    for (int i = 0; i < 18; i++)
    {
        cout << respostas[i] << " ";
    }
    for (int i = 6; i < 18; i++)
    {
        if (respostas[i] == 'S' || respostas[i] == 's')
        {
            return i;
        }
    }
    system("PAUSE");
    system("cls");
}

//aqui o programa atualiza o ultimo da fila
void AtualizaUltimo(TFila *fila)
{
    Apontador aux;
    aux = fila->inicio;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    fila->fim = aux;
}
//aqui o programa cria dois apontadores auxiliares para verificar se eles estão disponiveis
//logo após ele verifica o tempo de saida e entrada, para assim saber o tempo que foi gasto no atendimento e em quanto tempo ele foi atendido
//em seguida medico realiza o atendimento e o programa informa quem foi atendido e por qual médico
//após isso ele desenfileira o paciente da fila
void atualizar(TFila *filaPacientes, TFila *filaPacientesAtendidos, TFila *filamedicos, TFila *filaMedicosDisponiveis)
{

    Apontador aux = filaPacientes->inicio;
    Apontador aux2 = filamedicos->inicio;
    aux2->medico.disponivel = true;

    for (int i = 0; i < filamedicos->tamanho; i++)
    {

        aux->paciente.horaSaida = time(NULL);
        aux->paciente.tempo = aux->paciente.horaSaida - aux->paciente.horaChegada;

        cout << "O Paciente: " << aux->paciente.nome << " foi atendido em: " << aux->paciente.tempo << "   segundos" << "pelo médico: "<<aux2->medico.nome << "\n";

        cout << "Paciente atendido com sucesso!\n";
        aux->paciente.atendido = true;
        aux2->medico.disponivel = false;

        if (aux->paciente.atendido == true)
        {
            EnfileiraPrioridade(filaPacientesAtendidos, aux->paciente);
            DesenfileiraPaciente(filaPacientes, &aux->paciente);
        }
        if (filaPacientes->tamanho == filaPacientesAtendidos->tamanho)
        {
            if (aux2->medico.disponivel == true)
            {

                EnfileiraMedico(filaMedicosDisponiveis, aux2->medico);
            }

            break;
        }
        aux2 = aux2->prox;
        aux = aux->prox;
        Sleep(1000);
    }
}
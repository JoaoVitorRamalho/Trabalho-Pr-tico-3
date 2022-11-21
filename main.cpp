#include <iostream>
#include <windows.h>
#include "fila.cpp"
#include <time.h>
#include <ctime>
 
using namespace std;


int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  int opcao;
//criando as filas que serão utilizadas no programa
    TFila filamedicos;
    TFila filaMedicosDisponiveis;
    TFila filaPacientes;
    TFila filaPacientesAtendidos;
    Paciente paciente;
    Paciente paciente2;
    Medico medico;
    //usando a função para criar as filas
    CriaFila(&filamedicos);
    CriaFila(&filaMedicosDisponiveis);
    CriaFila(&filaPacientes);
    CriaFila(&filaPacientesAtendidos);
    //inserindo os médicos
    InsereMedicos(&medico,&filamedicos);
  do
    {
        system("cls");
        //imprimindo o menu
        menu();
        cout << "Opção: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            //aqui o programa limpa a tela e faz a triagem, após isso solicita os dados do paciente
            system("cls");
            char resp, triagem, respostas[18];
            int valor;
            //esse processo se repete até o usuário não querer mais cadastrar pacientes
            do
            {
                triagem = Triagem();
                InserePaciente(&paciente, triagem);
                EnfileiraPrioridade(&filaPacientes, paciente);
                cout<<"Triagem feita com sucesso\n";
                cout<<"Deseja adicionar mais alguma triagem:\n";
                cout<<"Sim.S  Nao.N\n";
                cin >> resp;
            } while (resp != 'N');

            system("PAUSE");

            break;
        //aqui o programa imprime a quantidade de pacientes cadastrados e atendidos, e a quantidade de médicos cadastrados e disponíveis
        //e também imprime a fila de médicos e de pacientes
        case 2:
            cout << "Pacientes Cadastrados: " << Tamanho(&filaPacientes) << "\n";
            cout << "Pacientes Atendidos: " << Tamanho(&filaPacientesAtendidos) << "\n";
            cout << "Medicos Cadastrados: " << Tamanho(&filamedicos) << "\n";
            cout << "Medicos Disponíveis: " << Tamanho(&filaMedicosDisponiveis) << "\n\n";
            cout << "Lista de Pacientes: \n";
            ImprimeFilaPacientes(&filaPacientesAtendidos);
            ImprimeFilaPacientes(&filaPacientes);

            cout << "Lista de Medicos: \n";
            ImprimeFilaMedicos(&filamedicos);
            system("pause");
            system("cls");
            
            break;
        case 3:
        //aqui é feito uma verificação se possui pacientes e médicos em suas filas
            char opcao;
            if (Tamanho(&filaPacientes) == 0)
            {
                cout << "Nao existem pacientes para ser atendidos\n";
            }
            else if (Tamanho(&filamedicos) == 0)
            {
                cout << "Nao existem medicos cadastrados para atender, cadastre no minimo 1 medico\n";
            }
            else
            {
                //se tiver o programa atualiza os dados que a função atualizar retorna e vai atualizando enquanto o usuário desejar
                atualizar(&filaPacientes, &filaPacientesAtendidos, &filamedicos, &filaMedicosDisponiveis);

                cout << "Deseja atualizar?\n";
                cin >> opcao;

                while (opcao == 's')
                {
                    if (Tamanho(&filaPacientesAtendidos) == Tamanho(&filaPacientes))
                    {
                        cout << "Todos os pacientes foram atendidos\n";
                        break;
                    }
                    else
                    {
                        atualizar(&filaPacientes, &filaPacientesAtendidos, &filamedicos, &filaMedicosDisponiveis);
                        cout << "Deseja atualizar:\n";
                        cin >> opcao;
                    }
                    break;
                }
            }
            system("PAUSE");
            break;
        
        case 4:
            cout<<"Saindo";
            system("cls");
            
            break;
        }
    } while (opcao != 4);
 
 
  cout << endl;
  return 0;
}
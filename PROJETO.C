#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILA.h" // Inclua o arquivo de cabeçalho da biblioteca de fila

// Definição da estrutura para uma tarefa
/*struct Data {
    int dia;
    int mes;
    int ano;
}typedef data;

struct Tarefa {
    int codigo;
    char nome[30];
    char projeto[30];
    data inicio;
    data termino;
    int status; // 1 para atrasada, 0 em dia, -1 pendente
}typedef Tarefa;*/

Fila* fila;



// Protótipos de funções

/*void modificarTarefa(struct Tarefa tarefas[], int quantidade);
void concluirTarefa(struct Tarefa tarefas[], int *quantidade);
void atualizarStatus(struct Tarefa tarefas[], int quantidade);
void listarTarefasPendentes(struct Tarefa tarefas[], int quantidade);
void listarTarefasConcluidas(struct Tarefa tarefas[], int quantidade);
void listarTarefasAtrasadas(struct Tarefa tarefas[], int quantidade);
void listarTarefasEmDia(struct Tarefa tarefas[], int quantidade);*/

int main() {
    fila = CriaFila();

    
    Tarefa tarefa[100];

    int quantidadeTarefas = 0;

    int opcao;

    do {
        // Mostra o menu de opções
        printf("\nMenu de Opcoes:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Modificar Tarefa\n");
        printf("3. Concluir Tarefa\n");
        printf("4. Atualizar Status\n");
        printf("5. Listar Tarefas Pendentes\n");
        printf("6. Listar Tarefas Concluidas\n");
        printf("7. Listar Tarefas Atrasadas\n");
        printf("8. Listar Tarefas em Dia\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarTarefa(fila, &quantidadeTarefas);
                break;
            /*case 2:
                modificarTarefa(t, quantidadeTarefas);
                break;
            case 3:
                concluirTarefa(t, &quantidadeTarefas);
                break;
            case 4:
                atualizarStatus(t, quantidadeTarefas);
                break;
            case 5:
                listarTarefasPendentes(t, quantidadeTarefas);
                break;
            case 6:
                listarTarefasConcluidas(t, quantidadeTarefas);
                break;
            case 7:
                listarTarefasAtrasadas(t, quantidadeTarefas);
                break;
            case 8:
                listarTarefasEmDia(t, quantidadeTarefas);
                break;*/
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}



void adicionarTarefa(Fila* fila, int* quantidade) {
    Tarefa novaTarefa;
    
    // Solicite ao usuário que insira os detalhes da nova tarefa
    printf("Digite o codigo da tarefa: ");
    scanf("%d", &novaTarefa.codigo);
    
    printf("Digite o nome da tarefa: ");
    scanf("%s", novaTarefa.nome);
    
    printf("Digite o nome do projeto: ");
    scanf("%s", novaTarefa.projeto);
    
    printf("Digite a data de inicio (dd mm aa): ");
    scanf("%d %d %d", &novaTarefa.inicio.dia, &novaTarefa.inicio.mes, &novaTarefa.inicio.ano);
    
    printf("Digite a data de termino (dd mm aa): ");
    scanf("%d %d %d", &novaTarefa.termino.dia, &novaTarefa.termino.mes, &novaTarefa.termino.ano);
    
    printf("Digite o status (1 para atrasada, 0 em dia, -1 pendente): ");
    scanf("%d", &novaTarefa.status);
    
    // Insira a nova tarefa na fila
    InsereFila(fila, novaTarefa);
    
    // Atualize o contador de tarefas (*quantidade)
    (*quantidade)++;
}


/*void modificarTarefa(Tarefa tarefas[], int quantidade) {
    // Adicionar código para modificar uma tarefa existente
}

void concluirTarefa(Tarefa tarefas[], int *quantidade) {
    // Adicionar código para concluir uma tarefa
    // Atualizar o contador de tarefas (*quantidade)
}

void atualizarStatus(Tarefa tarefas[], int quantidade) {
    // Adicionar código para atualizar o status das tarefas
}

void listarTarefasPendentes(Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas pendentes
}

void listarTarefasConcluidas(Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas concluídas
}

void listarTarefasAtrasadas(Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas atrasadas
}

void listarTarefasEmDia(Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas em dia
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.h"

// Definição da estrutura para uma tarefa
struct Data {
    int dia;
    int mes;
    int ano;
};

struct tarefa {
    int codigo;
    char nome[30];
    char projeto[30];
    struct Data inicio;
    struct Data termino;
    int status; // 1 para atrasada, 0 em dia, -1 pendente
};
typedef struct tarefa Tarefa;


// Protótipos de funções
void adicionarTarefa(Tarefa tarefas[], int *quantidade);
void modificarTarefa(Tarefa tarefas[], int quantidade);
void concluirTarefa(Tarefa tarefas[], int *quantidade);
void atualizarStatus(Tarefa tarefas[], int quantidade);
void listarTarefasPendentes(Tarefa tarefas[], int quantidade);
void listarTarefasConcluidas(Tarefa tarefas[], int quantidade);
void listarTarefasAtrasadas(Tarefa tarefas[], int quantidade);
void listarTarefasEmDia(Tarefa tarefas[], int quantidade);

int main() {
    Tarefa tarefas[100]; // Array para armazenar as tarefas
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
                adicionarTarefa(tarefas, &quantidadeTarefas);
                break;
            case 2:
                modificarTarefa(tarefas, quantidadeTarefas);
                break;
            case 3:
                concluirTarefa(tarefas, &quantidadeTarefas);
                break;
            case 4:
                atualizarStatus(tarefas, quantidadeTarefas);
                break;
            case 5:
                listarTarefasPendentes(tarefas, quantidadeTarefas);
                break;
            case 6:
                listarTarefasConcluidas(tarefas, quantidadeTarefas);
                break;
            case 7:
                listarTarefasAtrasadas(tarefas, quantidadeTarefas);
                break;
            case 8:
                listarTarefasEmDia(tarefas, quantidadeTarefas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

void adicionarTarefa(Tarefa tarefas[], int *quantidade) {
    // Adicionar código para inserir uma nova tarefa
    // Atualizar o contador de tarefas (*quantidade)
}

void modificarTarefa(Tarefa tarefas[], int quantidade) {
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

void listarTarefasConcluida (Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas concluídas
}

void listarTarefasAtrasadas (Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas atrasadas
}

void listarTarefasEmDia (Tarefa tarefas[], int quantidade) {
    // Adicionar código para listar tarefas em dia
}
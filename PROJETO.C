#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FILA.h" // Inclua o arquivo de cabeçalho da biblioteca de fila
#include <locale.h>


Lista* atualizarStatus(Fila* fila, Lista* listaPendentes,int codigo) {
    int novoStatus;
    int aux_int;
    No* atual = NULL;
    if(fila!=NULL){
        atual=fila->ini;
    }

    Fila *aux = CriaFila();
    int encontrou = 0;
     while(atual!=NULL && atual->info.codigo!=codigo){
        atual=atual->prox;
     }
     if(atual==NULL){

        atual=listaPendentes;
        while(atual!=NULL&&atual->info.codigo!=codigo){
        atual=atual->prox;
     }
     }
    // Percorra a fila procurando pela tarefa com o código fornecido

        if (atual!=NULL) {
            encontrou = 1;

            // Solicite ao usuário o novo status
            printf("Digite o novo status (1 para atrasada, 0 em dia, -1 pendente): ");
            aux_int=atual->info.status;
            scanf("%d", &novoStatus);


            // Atualize o status da tarefa
            atual->info.status = novoStatus;
            if (aux_int!=-1){
                // Verifique se a tarefa se tornou pendente
            if (novoStatus == -1) {
                while(fila->ini->info.codigo != codigo){
                    InsereFila(aux,RetiraFila(fila));
                }

                // Mova a tarefa para a lista de tarefas pendentes
                listaPendentes=InsereFinal(listaPendentes, RetiraFila(fila));
                while(aux->ini!=NULL){
                    InsereFila(fila,RetiraFila(aux));
                }
                }

            }
    else if (atual->info.status!= -1){
        No* anterior= listaPendentes;
        No* aux1 = listaPendentes;
        while(aux1->info.codigo!= atual->info.codigo){
             anterior=aux1;
            aux1=aux1->prox;
        }
        if (aux1== listaPendentes){
            listaPendentes=NULL;
        }
        else{
            anterior->prox= aux1->prox;
        }

        InsereFila(fila,aux1->info);
        free(aux1);

    }



        }

        return listaPendentes;
    }

Tarefa adicionarTarefa(Fila*filaAlta,Fila*filaNormal,Fila*filaBaixa,Lista** listarTarefasPendentes, int* quantidade) {
    Tarefa novaTarefa;

    printf("Digite o codigo da tarefa: ");
    scanf("%d", &novaTarefa.codigo);

    printf("Digite o nome da tarefa: ");
    scanf("%s", novaTarefa.nome);

    printf("Digite o nome do projeto: ");
    scanf("%s", novaTarefa.projeto);

    do {
        printf("Digite a data de inicio (dd mm aaaa): ");
        scanf("%d %d %d", &novaTarefa.inicio.dia, &novaTarefa.inicio.mes, &novaTarefa.inicio.ano);

        if (novaTarefa.inicio.dia <= 0 || novaTarefa.inicio.dia > 31 || novaTarefa.inicio.mes <= 0 || novaTarefa.inicio.mes > 12) {
            printf("Data de inicio invalida. Por favor, insira novamente.\n");
        }
    } while (novaTarefa.inicio.dia <= 0 || novaTarefa.inicio.dia > 31 || novaTarefa.inicio.mes <= 0 || novaTarefa.inicio.mes > 12);

    printf("Digite a data de termino (dd mm aaaa): ");
    scanf("%d %d %d", &novaTarefa.termino.dia, &novaTarefa.termino.mes, &novaTarefa.termino.ano);

    if (novaTarefa.termino.dia <= 0 || novaTarefa.termino.dia > 31 || novaTarefa.termino.mes <= 0 || novaTarefa.termino.mes > 12) {
        printf("Data de termino invalida. Por favor, insira novamente.\n");
        return;
    }


    printf("Insira a prioridade da tarefa (1 para Alta Prioridade, 2 para Prioridade Normal, 3 para Baixa Prioridade): ");
    scanf("%d", &novaTarefa.prioridade);
    if (novaTarefa.prioridade == 1) {
        InsereFila(filaAlta, novaTarefa);
         *listarTarefasPendentes=atualizarStatus(filaAlta,*listarTarefasPendentes,novaTarefa.codigo);
    } else if (novaTarefa.prioridade == 2) {
         InsereFila(filaNormal, novaTarefa);
         *listarTarefasPendentes=atualizarStatus(filaNormal,*listarTarefasPendentes,novaTarefa.codigo);
    } else if (novaTarefa.prioridade == 3) {
          InsereFila(filaBaixa, novaTarefa);
         *listarTarefasPendentes=atualizarStatus(filaBaixa,*listarTarefasPendentes,novaTarefa.codigo);
    } else {
        printf("Prioridade inválida. Tarefa não adicionada.\n");
        return;
    }
    (*quantidade)++;

    return novaTarefa;
}

void listarTarefasPorPrioridade(Fila*filaAlta,Fila*filaNormal,Fila*filaBaixa) {
    // A função utiliza as filas globais filaAlta, filaNormal e filaBaixa
    // para listar as tarefas por prioridade.

    Fila* filaAltaAux = CriaFila();
    Fila* filaNormalAux = CriaFila();
    Fila* filaBaixaAux = CriaFila();

    // Percorra a fila de alta prioridade e insira na fila auxiliar
    while (!VaziaFila(filaAlta)) {
        Tarefa t = RetiraFila(filaAlta);
        InsereFila(filaAltaAux, t);
    }

    // Percorra a fila de prioridade normal e insira na fila auxiliar
    while (!VaziaFila(filaNormal)) {
        Tarefa t = RetiraFila(filaNormal);
        InsereFila(filaNormalAux, t);
    }

    // Percorra a fila de baixa prioridade e insira na fila auxiliar
    while (!VaziaFila(filaBaixa)) {
        Tarefa t = RetiraFila(filaBaixa);
        InsereFila(filaBaixaAux, t);
    }

    // Imprima as tarefas por prioridade
    printf("Tarefas por Prioridade (da mais alta para a mais baixa):\n");

    printf("\nAlta Prioridade:\n");
    imprimeFila(filaAltaAux);

    printf("\nPrioridade Normal:\n");
    imprimeFila(filaNormalAux);

    printf("\nBaixa Prioridade:\n");
    imprimeFila(filaBaixaAux);

    // Restaure as filas originais
    while (!VaziaFila(filaAltaAux)) {
        Tarefa t = RetiraFila(filaAltaAux);
        InsereFila(filaAlta, t);
    }

    while (!VaziaFila(filaNormalAux)) {
        Tarefa t = RetiraFila(filaNormalAux);
        InsereFila(filaNormal, t);
    }

    while (!VaziaFila(filaBaixaAux)) {
        Tarefa t = RetiraFila(filaBaixaAux);
        InsereFila(filaBaixa, t);
    }

    // Lembre-se de liberar as filas auxiliares
    liberaFila(filaAltaAux);
    liberaFila(filaNormalAux);
    liberaFila(filaBaixaAux);
}

 Fila* verificarfila (Fila* F1,Fila* F2,Fila* F3, int codigo){
     No*aux= F1->ini;
 while (aux != NULL) {
        if (aux->info.codigo == codigo){
            return F1;
        }
         aux=aux-> prox;}
aux= F2->ini;
 while (aux != NULL) {
        if (aux->info.codigo == codigo){
            return F2;
        }
         aux=aux-> prox;}
aux= F3->ini;
 while (aux != NULL) {
        if (aux->info.codigo == codigo){
            return F3;
        }
         aux=aux-> prox;}

         return NULL;
 }
void modificarTarefa(Fila* fila,Lista *listaPendentes,int codigo) {
    No* atual = fila->ini;
    int encontrou = 0;

    // Percorra a fila procurando pela tarefa com o código fornecido
    while (atual != NULL) {
        if (atual->info.codigo == codigo) {

            encontrou = 1;
            // Solicite ao usuário as informações atualizadas
            printf("Digite o novo nome da tarefa: ");
            scanf("%s", atual->info.nome);

            printf("Digite o novo nome do projeto: ");
            scanf("%s", atual->info.projeto);

            printf("Digite a nova data de inicio (dd mm aa): ");
            scanf("%d %d %d", &atual->info.inicio.dia, &atual->info.inicio.mes, &atual->info.inicio.ano);

            printf("Digite a nova data de termino (dd mm aa): ");
            scanf("%d %d %d", &atual->info.termino.dia, &atual->info.termino.mes, &atual->info.termino.ano);

            printf("Digite o novo status (1 para atrasada, 0 em dia, -1 pendente): ");
            scanf("%d", &atual->info.status);


            break; // Saia do loop após encontrar e modificar a tarefa
        }
        atual = atual->prox;
        }

    if (!encontrou) {
        printf("Tarefa com codigo %d nao encontrada.\n", codigo);
    }
}

// Função para marcar tarefas como atrasadas com base na data atual
void marcarTarefasAtrasadas(Fila* filaAux,Lista*listaPendentes) {
    time_t agora;
    time(&agora); // Obtenha a data atual
    printf("teste");

    No* atual = NULL;
    if (filaAux!=NULL){
            atual=filaAux->ini;}
    while (atual != NULL) {

            // Converta as datas de término da tarefa e a data atual para structs tm
            struct tm* dataTermino;
            dataTermino = localtime(&agora);
            struct tm dataTarefa = {0}; // Inicialize com 0 para evitar lixo de memória
            dataTarefa.tm_year = atual->info.termino.ano - 1900; // Ano - 1900
            dataTarefa.tm_mon = atual->info.termino.mes - 1; // Mês - 1 (janeiro é 0)
            dataTarefa.tm_mday = atual->info.termino.dia; // Dia

            // Compare as datas para verificar se a tarefa está atrasada
            if (difftime(mktime(dataTermino), mktime(&dataTarefa)) > 0) {
                // A tarefa está atrasada, marque como atrasada (status 1)
                atual->info.status = 1;
            }

        atual = atual->prox;
    }
    atual=listaPendentes;
    while (atual != NULL) {

            // Converta as datas de término da tarefa e a data atual para structs tm
            struct tm* dataTermino;
            dataTermino = localtime(&agora);
            struct tm dataTarefa = {0}; // Inicialize com 0 para evitar lixo de memória
            dataTarefa.tm_year = atual->info.termino.ano - 1900; // Ano - 1900
            dataTarefa.tm_mon = atual->info.termino.mes - 1; // Mês - 1 (janeiro é 0)
            dataTarefa.tm_mday = atual->info.termino.dia; // Dia

            // Compare as datas para verificar se a tarefa está atrasada
            if (difftime(mktime(dataTermino), mktime(&dataTarefa)) > 0) {
                // A tarefa está atrasada, marque como atrasada (status 1)
                atual->info.status = 1;

            }

        atual = atual->prox;
    }
}





Lista* concluirTarefa(Fila* fila, Lista* ListaConcluidas,int codigo) {
    No* atual = fila->ini;
    No* anterior = NULL;
    int encontrou = 0;

    // Percorra a fila procurando pela tarefa com o código fornecido
    while (atual != NULL) {
        if (atual->info.codigo == codigo) {
            encontrou = 1;

            // Verifique se a tarefa está atrasada
                // A tarefa não está concluída, mova-a para a fila de tarefas concluídas
                ListaConcluidas=InsereFinal(ListaConcluidas, atual->info);
                printf("Tarefa Concluida .\n");


            // Remova a tarefa da fila
            if (anterior == NULL) {
                fila->ini = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            break;
        }

        anterior = atual;
        atual = atual->prox;
    }







    if (!encontrou) {
        printf("Tarefa com codigo %d nao encontrada.\n", codigo);

    } return ListaConcluidas;
}





void TarefasPendentes( Lista* listaPendentes) {
    printf("Tarefas Pendentes:\n");




    No* atual = listaPendentes;

    while (atual != NULL) {
        printf("Codigo: %d, Nome: %s, Projeto: %s, Prioridade: %d\n",
               atual->info.codigo, atual->info.nome, atual->info.projeto,atual->info.prioridade);
        atual = atual->prox;
    }

    printf("\n");
}


void listarTarefasConcluidas(Lista*ListaConcluidas) {
    printf("Tarefas Concluídas:\n");
    No* atual = ListaConcluidas;

    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Projeto: %s, Status: %d\n",
               atual->info.codigo, atual->info.nome, atual->info.projeto, atual->info.status);
        atual = atual->prox;
    }

    printf("\n");
}

void listarTarefasConcluidasComEAtrasadas(Lista* ListaConcluidas) {
    printf("Tarefas Concluídas com Atraso:\n");
    No* atual = ListaConcluidas;

    while (atual != NULL) {
        if (atual->info.status == 1) { // Tarefa concluída com atraso
            printf("Código: %d, Nome: %s, Projeto: %s, Status: %d\n",
                   atual->info.codigo, atual->info.nome, atual->info.projeto, atual->info.status);
        }
        atual = atual->prox;
    }

    printf("\nTarefas Concluídas sem Atraso:\n");
    atual = ListaConcluidas;

    while (atual != NULL) {
        if (atual->info.status == 0) { // Tarefa concluída sem atraso (em dia)
            printf("Código: %d, Nome: %s, Projeto: %s, Status: %d\n",
                   atual->info.codigo, atual->info.nome, atual->info.projeto, atual->info.status);
        }
        atual = atual->prox;
    }
}


void listarListaCompleta(Lista* listaPendentes,Lista*ListaConcluidos,Fila*filaAlta,Fila*filaNormal,Fila*filaBaixa) {
    printf("\n\nTarefas Concluídas:\n");
    No* atual = ListaConcluidos;

    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Projeto: %s, Status: %d\n",
               atual->info.codigo, atual->info.nome, atual->info.projeto, atual->info.status);
        atual = atual->prox;
    }

    printf("\n");

    printf("Tarefas Pendentes:\n");

    atual = listaPendentes;

    while (atual != NULL) {
        if (atual->info.status == -1) { // Tarefa pendente na fila principal
            printf("Código: %d, Nome: %s, Projeto: %s\n",
                   atual->info.codigo, atual->info.nome, atual->info.projeto);
        }
        atual = atual->prox;
    }


    while (atual != NULL) {
        printf("Código: %d, Nome: %s, Projeto: %s\n",
               atual->info.codigo, atual->info.nome, atual->info.projeto);
        atual = atual->prox;
    }

    printf("\n");
    Fila* filaAltaAux = CriaFila();
    Fila* filaNormalAux = CriaFila();
    Fila* filaBaixaAux = CriaFila();

    // Percorra a fila de alta prioridade e insira na fila auxiliar
    while (!VaziaFila(filaAlta)) {
        Tarefa t = RetiraFila(filaAlta);
        InsereFila(filaAltaAux, t);
    }

    // Percorra a fila de prioridade normal e insira na fila auxiliar
    while (!VaziaFila(filaNormal)) {
        Tarefa t = RetiraFila(filaNormal);
        InsereFila(filaNormalAux, t);
    }

    // Percorra a fila de baixa prioridade e insira na fila auxiliar
    while (!VaziaFila(filaBaixa)) {
        Tarefa t = RetiraFila(filaBaixa);
        InsereFila(filaBaixaAux, t);
    }



    // Imprima as tarefas por prioridade
    printf("Tarefas por Prioridade (da mais alta para a mais baixa):\n");

    printf("\nAlta Prioridade:\n");
    imprimeFila(filaAltaAux);

    printf("\nPrioridade Normal:\n");
    imprimeFila(filaNormalAux);

    printf("\nBaixa Prioridade:\n");
    imprimeFila(filaBaixaAux);

    // Restaure as filas originais
    while (!VaziaFila(filaAltaAux)) {
        Tarefa t = RetiraFila(filaAltaAux);
        InsereFila(filaAlta, t);
    }

    while (!VaziaFila(filaNormalAux)) {
        Tarefa t = RetiraFila(filaNormalAux);
        InsereFila(filaNormal, t);
    }

    while (!VaziaFila(filaBaixaAux)) {
        Tarefa t = RetiraFila(filaBaixaAux);
        InsereFila(filaBaixa, t);
    }

    // Lembre-se de liberar as filas auxiliares
    liberaFila(filaAltaAux);
    liberaFila(filaNormalAux);
    liberaFila(filaBaixaAux);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    Fila* filaAlta = CriaFila();
    Fila* filaNormal = CriaFila();
    Fila* filaBaixa = CriaFila();
    Fila* filaAux =CriaFila();
    Lista* ListaConcluidos=CriaLista();
    Lista* listarTarefasPendentes=CriaLista();//lista das onde a quando atualizar o status para pendente vai receber
    Tarefa tarefaAux;
    No*aux;

    int quantidadeTarefas = 0;
    int opcao;
    int codigo;

    do {
        // Mostra o menu de opções
        printf("\nMenu de Opcoes:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Modificar Tarefa\n");
        printf("3. Concluir Tarefa\n");
        printf("4. Atualizar Status\n");
        printf("5. Listar Tarefas Pendentes\n");
        printf("6. Listar Tarefas Concluidas\n");
        printf("7. Listar Tarefas Concluidas com e sem atraso\n");
        printf("8. Listar Todas as Tarefas\n");
        printf("9. Listar Tarefas por Prioridade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:

                tarefaAux=adicionarTarefa(filaAlta,filaNormal,filaBaixa,&listarTarefasPendentes,&quantidadeTarefas);
                filaAux=verificarfila(filaAlta,filaNormal,filaBaixa,tarefaAux.codigo);
                marcarTarefasAtrasadas(filaAux,listarTarefasPendentes);
                system("cls");
                printf("Tarefa Listada com Sucesso :]\n\n");
                break;
            case 2:
                // Solicite ao usuário o código da tarefa que deseja modificar
                printf("Digite o codigo da tarefa que deseja modificar: ");
                scanf("%d", &codigo);
                filaAux=verificarfila(filaAlta,filaNormal,filaBaixa,codigo);
                modificarTarefa(filaAux,listarTarefasPendentes,codigo);
                system("cls");
                printf("Tarefa modificada com sucesso!\n");
                break;

            case 3:
                // Solicite ao usuário o código da tarefa que deseja modificar
                printf("Digite o codigo da tarefa que deseja concluir: ");
                scanf("%d", &codigo);
                filaAux=verificarfila(filaAlta,filaNormal,filaBaixa,codigo);
                ListaConcluidos=concluirTarefa(filaAux,ListaConcluidos,codigo);
                system("cls");
                printf("Tarefa Concluida .\n");
                break;
            case 4:
                // Solicite ao usuário o código da tarefa que deseja modificar o Status
                printf("Digite o codigo da tarefa que deseja editar Status: ");
                scanf("%d", &codigo);
                filaAux=verificarfila(filaAlta,filaNormal,filaBaixa,codigo);
                if(filaAux== NULL){
                    aux=listarTarefasPendentes;
                    while(aux!= NULL){
                    if (aux->info.codigo==codigo){
                        switch(aux->info.prioridade){
                            case 1:
                                filaAux=filaAlta;
                                break;
                            case 2:
                                filaAux=filaNormal;
                                break;
                            case 3:
                                filaAux=filaBaixa;
                                break;}
                    }
                    aux=aux->prox;
                    }
                }

                listarTarefasPendentes=atualizarStatus(filaAux,listarTarefasPendentes,codigo);
                system("cls");
                printf("Status da tarefa atualizado com sucesso!\n");
                break;
            case 5:
                system("cls");
                TarefasPendentes(listarTarefasPendentes);
                break;
            case 6:
                system("cls");
                listarTarefasConcluidas(ListaConcluidos);
                break;
            case 7:
                system("cls");
                listarTarefasConcluidasComEAtrasadas(ListaConcluidos);
                break;
            case 8:
                system("cls");
                listarListaCompleta(listarTarefasPendentes,ListaConcluidos,filaAlta,filaNormal,filaBaixa);
                break;
            case 9:
                system("cls");
                listarTarefasPorPrioridade(filaAlta,filaNormal,filaBaixa); // Chama a função para listar tarefas por prioridade
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    filaAlta = liberaFila(filaAlta);
    filaNormal = liberaFila(filaNormal);
    filaBaixa = liberaFila(filaBaixa);


    return 0;
}

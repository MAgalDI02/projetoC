#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct tarefa {
    int codigo;
    char nome[30];
    char projeto[30];
    Data inicio;
    Data termino;
    int status; // 1 para atrasada, 0 em dia, -1 pendente
} Tarefa;

typedef struct nos {
    Tarefa info;
    struct nos* prox;
} No;

typedef struct fila {
    No* ini;
    No* fim;
} Fila;

int VaziaFila(Fila* f) {
    if (f->ini == NULL) return 1;
    return 0;
}

Fila* CriaFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim(No* fim, Tarefa t) {
    No* p = (No*)malloc(sizeof(No));
    p->info = t;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}

void InsereFila(Fila* f, Tarefa t) {
    f->fim = ins_fim(f->fim, t);
    if (f->ini == NULL) /* fila antes vazia? */
        f->ini = f->fim;
}

No* retira_ini(No* ini) {
    No* p = ini->prox;
    free(ini);
    return p;
}

Tarefa RetiraFila(Fila* f) {
    Tarefa t;
    if (VaziaFila(f)) {
        printf("Fila vazia.\n");
        // Você pode tratar o erro de outra maneira, se desejar.
        exit(0);
    }
    t = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;
    return t;
}

void imprimeFila(Fila* f) {
    No* q;
    printf("\n\t\t");
    for (q = f->ini; q != NULL; q = q->prox) {
        printf("Código: %d, Nome: %s, Projeto: %s, Status: %d - ", q->info.codigo, q->info.nome, q->info.projeto, q->info.status);
    }
    printf("\n");
}

Fila* liberaFila(Fila* f) {
    No* q = f->ini;
    while (q != NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

#endif // FILA_H_INCLUDED

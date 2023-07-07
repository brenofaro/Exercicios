#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ListaSeqEst.h"


char compare(ITEM x, ITEM y)
{
    return x > y ? 1 : (x < y ? -1 : 0);
}


bool igual(ITEM x, ITEM y)
{
    return compare(x,y) == 0;
}


void inicializar(LISTA *l)
{
    l->tamanho = 0;
}


int tamanho(LISTA *l)
{
    return l->tamanho;
}


bool cheia(LISTA *l)
{
    return tamanho(l) == MAX;
}


bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}


bool inserir(ITEM item, LISTA *l)
{
    if (tamanho(l) == MAX) 
        return false; // lista cheia
    else
       l->itens[l->tamanho++] = item;
    return true;
}


int buscar(ITEM item, LISTA *l)
{
    return buscarEm(item, 0, tamanho(l), l);
}

int buscarEm(ITEM item, int inicio, int fim, LISTA *l){

    for (int pos = inicio; pos < fim; pos++)
       if (igual(item, l->itens[pos]))
           return pos; // achou
    return -1; // nao achou
}


ITEM enesimo(int n, LISTA *l)
{
    if (n >= 0 && n < tamanho(l))
       return (l->itens[n]);
    else
       exit(EXIT_FAILURE);
}


bool alterar(ITEM item, int pos, LISTA *l)
{
    if (pos >= 0 && pos < tamanho(l))
    {
        l->itens[pos] = item;
        return true;
    } 
    return false;
}

void reversa(LISTA *l){
    int i, j, aux;
    j = tamanho(l) - 1;
    
    for (i = 0; i <= (tamanho(l)/2) -1; i++)
    {
        aux = l->itens[i];
        l->itens[i] = l->itens[j];
        l->itens[j] = aux;
        j--;
    }

}


bool inserirNaPos(ITEM item, int i, LISTA *l)
{
    // A posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
    if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
        return false; // lista cheia ou indice invalido

    // Se for inserido no meio, e necessario abrir espaco para o item
    for (int j = tamanho(l); j > i; j--)
        l->itens[j] = l->itens[j-1];

    // Coloca o item em um espaco vago e ajusta o tamanho        
    l->itens[i] = item;
    l->tamanho++;
    return true;
}


bool remover(ITEM item, LISTA *l)
{
    int i, j;
    for (i = 0; i < tamanho(l); i++)
        if (igual(item, l->itens[i]))
        {
            for (j = i; j < l-> tamanho - 1; j++)
               l->itens[j] = l->itens[j + 1];

            l->tamanho--;
            return true; // achou
        }   
    return false; // nao achou
}

bool removerDaPos(ITEM *item, int i, LISTA *l){
    int j;
    if (i < 0 || i > tamanho(l)){
        return false;
    }
    else
    {
        *item = l->itens[i];
        for (j = i; j < l-> tamanho - 1; j++)
            l->itens[j] = l->itens[j + 1];
        l->tamanho--;
        return true;
    }
}


void exibirItem(ITEM i)
{
    printf("%d", i);
}


void exibirLista(LISTA *l)
{
    printf("[");
    for(int i = 0; i < tamanho(l);)
    {
        exibirItem(l->itens[i++]);
        if (i < tamanho(l))
           printf(",");
    }
    printf("]");
}

void exibirListaReversa(LISTA *l){
    printf("[");
    for (int i = tamanho(l) - 1; i >= 0; i--){
        exibirItem(l->itens[i]);
        if (i > 0)
           printf(",");
    }

    printf("]");

}

void limpar(LISTA *l)
{
    l->tamanho = 0;
}

void destruir(LISTA *l)
{
   limpar(l);
}
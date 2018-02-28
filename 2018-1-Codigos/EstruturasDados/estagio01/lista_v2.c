#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct elementos {
	char nome[50];	
} t_elemento;

typedef struct lista {
	t_elemento vetor[MAX];
	int n; //�ndice do �ltimo elemento
} t_lista;


t_lista criar() {
	t_lista lista;
	
	lista.n = -1;
	
	return lista;
}

int isCheia(t_lista * lista) {
    return (lista->n == MAX - 1);
}

int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) )
        return 0;

    //deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}

int getPosicao(t_lista * lista, t_elemento dado) {
    int i;
    for (i=0; i <= lista->n; i++)
        if (compara(lista->vetor[i], dado) == 0)
            return i;

    return -1;
}

int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}

int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}


//--------------------------------------------------- MAIN:
int main() {
	t_lista lista01;
	t_elemento m_elemento;
	int i;
	
	lista01 = criar();
	
	for(i = 0; i < 3; i++) {
		printf("Escreva um nome\n");
		scanf("%s", m_elemento.nome);
		
		printf("nome digita foi [%s]\n", m_elemento.nome);
		
		inserir(&lista01, i, m_elemento);	
	}
	
	for(i = 0; i <= lista01.n; i++) { //
		printf("%s\n", lista01.vetor[i].nome);
	}
	
	printf("Escreva um nome a ser procurado\n");
	scanf("%s", m_elemento.nome);
	printf("nome digitado para busca foi [%s]\n", m_elemento.nome);
	
	i = getPosicao(&lista01, m_elemento);
	
	if(i != - 1) {
		printf("Nome encontrado na posicao [%d]\n", i);
	}
	else {
		printf("O nome nao existe na lista\n");
	}
	
	
	printf("Escreva um nome a ser removido\n");
	scanf("%s", m_elemento.nome);
	printf("nome digitado para remocao foi [%s]\n", m_elemento.nome);
	
	i = getPosicao(&lista01, m_elemento);
	
	if(i != - 1) {
		remover(&lista01, i);
	}
	else {
		printf("O nome nao existe na lista\n");
	}
	
	for(i = 0; i <= lista01.n; i++) { //
		printf("%s\n", lista01.vetor[i].nome);
	}
	
	
	return 0;
}

//--------------------------------------------------- FUN��ES:


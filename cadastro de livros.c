#include <stdio.h>
#include <string.h>

#define TAM_MAX 100
#define MAX_LIVROS 100

typedef struct {
    char titulo[TAM_MAX];
    char autor[TAM_MAX];
    int ano;
} Livro;

Livro estanteDelivros[MAX_LIVROS];
int quantidadeDeLivros = 0;

void cadastrarLivro() {
    if (quantidadeDeLivros >= MAX_LIVROS) {
        printf("Estante cheia! Nao e possivel cadastrar mais livros.\n");
        return;
    }

    Livro novoLivro;

    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, TAM_MAX, stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = 0; // Remove newline

    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, TAM_MAX, stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = 0; // Remove newline

    printf("Digite o ano de publicacao: ");
    scanf("%d", &novoLivro.ano);
    getchar(); // Limpar o buffer do teclado

    estanteDelivros[quantidadeDeLivros++] = novoLivro;
    printf("Livro cadastrado com sucesso!\n");
}
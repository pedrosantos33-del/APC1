#include <stdio.h>

int main() {
    char nome[100];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("\nNome: %s", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}

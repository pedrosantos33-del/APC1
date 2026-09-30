#include <stdio.h>

int main () {
    char nome[100];
    int idade; 
    float renda_mensal;


    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite a renda mensal: ");
    scanf("%f", &renda_mensal);

    printf("nome: %s", nome);
    printf("idade: %d\n", idade);
    printf("renda mensal: %.2f\n", renda_mensal);
}
    
#include <stdio.h>

#define VALOR_REFEICAO 12.50
#define VALOR_CAFE 4.00

int main() {

int refeicoes;
int cafes;

float disponivel;
float gastoRefeicoes;
float gastoCafes;
float total;
float saldo;
float percentual;

printf("Digite a quantidade de refeicoes: ");
scanf("%d", &refeicoes);

printf("Digite a quantidade de cafes: ");
scanf("%d", &cafes);

gastoRefeicoes = refeicoes * VALOR_REFEICAO;
gastoCafes = cafes * VALOR_CAFE;
total = gastoRefeicoes + gastoCafes;

printf("Digite o valor disponivel no cartao: ");
scanf("%f", &disponivel);

saldo = disponivel - total;

percentual = (total / disponivel) * 100;

printf("Gasto com refeicoes: R$ %.2f\n", gastoRefeicoes);
printf("Gasto com cafes: R$ %.2f\n", gastoCafes);
printf("Gasto total: R$ %.2f\n", total);
printf("Saldo restante: R$ %.2f\n", saldo);
printf("Percentual utilizado: %.2f%%\n", percentual);

return 0;


}
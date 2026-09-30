#include <stdio.h>

int main() {
    float peso, altura, IMC;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    // Calcula o IMC
    IMC = peso / (altura * altura);

    printf("IMC: %.2f\n", IMC);

if (IMC < 18.5) {
    printf("Abaixo do peso\n");
} else if (IMC >= 18.5 && IMC < 25) {
    printf("Peso normal\n");
} else if (IMC >= 25 && IMC < 30) {
    printf("Sobrepeso\n");
} else {
    printf("Obesidade\n");
}
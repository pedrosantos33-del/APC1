#include <stdio.h>
#define PI 3.14
const double GRAVIDADE = 9.8; 
// define substitui o valor de PI por 3.14 em todo o código, enquanto const cria uma variável constante que não pode ser alterada.

int main() {
    float raio = 2.0;
    float area = PI * raio * raio;
    printf("A área do círculo de raio %.2f é %.2f\n", raio, area);
    return 0;
}
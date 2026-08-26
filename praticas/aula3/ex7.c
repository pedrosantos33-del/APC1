#include <stdio.h>

int contador = 10;

int main() {
    int contador = 5;

    printf("valor do contador local: %d\n", contador);
    //a variavel local tem prioridade sobre a global, então o valor impresso será 5
    
    return 0;
}
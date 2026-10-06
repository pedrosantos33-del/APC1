#include <stdio.h>

/*
O operador ternário : foi mais vantajoso para definir o bônus de pontualidade,
pois a condição possui apenas duas possibilidades: 5% para status 'S' ou 0% caso contrário.
Já o if aninhado foi indispensável para calcular o desconto base,
pois primeiro foi necessário identificar a faixa de renda e, dentro dela,
verificar a média acadêmica para determinar o percentual correspondente.
*/

int main () {
    char nome[100];
    char status;  
    int idade; 
    float renda_mensal;
    float media_academica; 
    float bonus;
    float desconto_base;
    float desconto_total;



    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite a renda mensal: ");
    scanf("%f", &renda_mensal);

    printf("Digite a media academica: ");
    scanf("%f", &media_academica);

    if (media_academica < 0.0 || media_academica > 10.0) {
    printf("Erro: média acadêmica inválida.\n");
    return 0;
}

    printf("Digite o status de pagamento (S - Sim, N - Nao): ");
    scanf(" %c", &status);

    printf("nome: %s", nome);
    printf("idade: %d\n", idade);
    printf("renda mensal: %.2f\n", renda_mensal);
    printf("media academica: %.2f\n", media_academica);
    printf("status: %c\n", status);


    if (idade < 16 || renda_mensal <= 0) {
    printf("Erro: idade ou renda invalida.\n");
    return 0;
    }

    if (renda_mensal <= 2000) {
    printf("Faixa A - Baixa Renda\n");

    if (media_academica >= 8.5) {
        desconto_base = 50.0;
    }
    else {
        desconto_base = 30.0;
    }
}
else if (renda_mensal <= 5000) {
    printf("Faixa B - Média Renda\n");

    if (media_academica >= 9.0) {
        desconto_base = 25.0;
    }
    else {
        desconto_base = 10.0;
    }
}
else {
    printf("Faixa C - Alta Renda\n");

    if (media_academica >= 9.5) {
        desconto_base = 10.0;
    }
    else {
        desconto_base = 0.0;
    }
}
    bonus = (status == 'S') ? 5.0 : 0.0;
    desconto_total = desconto_base + bonus;

    printf("========================================\n");
    printf("SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno          : %s", nome);
    printf("Media          : %.2f\n", media_academica);
    printf("Desconto Base  : %.1f%%\n", desconto_base);
    printf("Bonus Pontual  : %.1f%%\n", bonus);
    printf("----------------------------------------\n");
    printf("Desconto Total : %.1f%%\n", desconto_total);
    printf("Status         : APROVADO PARA BOLSA\n");


    return 0;
}
    
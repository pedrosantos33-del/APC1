#include <stdio.h>
#include <string.h>
const char *nomes_servicos[7] = {
    "Codigo invalido",
    "Historico escolar",
    "Declaracao de matricula",
    "Declaracao de vinculo",
    "Trancamento",
    "Cancelamento",
    "Colacao de grau"
};


int main(void) {

int codigo_servico;
char nome_servico[50];
char categoria[40];
int prazo;
float taxa_base;
char status[20];
char prioridade;
char nome_prioridade[20];
int guiche;
float acrescimo;
int dia_semana;
char nome_dia[30];
char expediente[20];
float taxa_final;

scanf("%d", &codigo_servico);
scanf(" %c", &prioridade);
scanf("%d", &dia_semana);




switch (codigo_servico) {
    case 1:
        /* fall-through */
    case 2:
        /* fall-through */
    case 3:
        strcpy(categoria, "Documento simples");
        prazo = 2;
        taxa_base = 15.00;
        strcpy(status, "ACEITO");
        break;

    case 4:
        /* fall-through */
    case 5:
        strcpy(categoria, "Interrupcao de vinculo");
        prazo = 10;
        taxa_base = 0.00;
        strcpy(status, "ACEITO");
        break;

    case 6:
        strcpy(categoria, "Ato solene");
        prazo = 15;
        taxa_base = 80.00;
        strcpy(status, "ACEITO");
        break;

    default:
        strcpy(categoria, "N/A");
        prazo = 0;
        taxa_base = 0.00;
        strcpy(status, "RECUSADO");
        codigo_servico = 0;
        break;
}

strcpy(nome_servico, nomes_servicos[codigo_servico]);



switch (prioridade) {
    case 'U':
        /* fall-through */
    case 'u':
        strcpy(nome_prioridade, "Urgente");
        guiche = 1;
        acrescimo = 10.00;
        break;

    case 'N':
        /* fall-through */
    case 'n':
        strcpy(nome_prioridade, "Normal");
        guiche = 2;
        acrescimo = 0.00;
        break;

    case 'B':
        /* fall-through */
    case 'b':
        strcpy(nome_prioridade, "Balcao");
        guiche = 3;
        acrescimo = 0.00;
        break;

    default:
        strcpy(nome_prioridade, "Invalida");
        guiche = 0;
        acrescimo = 0.00;
        break;
}



switch (dia_semana) {
    case 1:
        strcpy(nome_dia, "Domingo");
        break;

    case 2:
        strcpy(nome_dia, "Segunda-feira");
        break;

    case 3:
        strcpy(nome_dia, "Terca-feira");
        break;

    case 4:
        strcpy(nome_dia, "Quarta-feira");
        break;

    case 5:
        strcpy(nome_dia, "Quinta-feira");
        break;

    case 6:
        strcpy(nome_dia, "Sexta-feira");
        break;

    case 7:
        strcpy(nome_dia, "Sabado");
        break;

    default:
        strcpy(nome_dia, "Dia invalido");
        break;
}



switch (dia_semana) {
    case 2:
        /* fall-through */
    case 3:
        /* fall-through */
    case 4:
        /* fall-through */
    case 5:
        strcpy(expediente, "Pleno");
        break;

    case 6:
        strcpy(expediente, "Reduzido");
        break;

    case 1:
        /* fall-through */
    case 7:
        strcpy(expediente, "Fechado");
        break;

    default:
        strcpy(expediente, "Dia invalido");
        break;
}


taxa_final = taxa_base + acrescimo;

printf("========================================\n");
printf("TRIAGEM DE PROTOCOLO ACADEMICO\n");
printf("========================================\n");

printf("Servico : %s\n", nome_servico);
printf("Categoria : %s\n", categoria);
printf("Prazo : %d dias uteis\n", prazo);
printf("Taxa base : R$ %.2f\n", taxa_base);
printf("Prioridade : %s\n", nome_prioridade);
printf("Guiche : %d\n", guiche);
printf("Acrescimo : R$ %.2f\n", acrescimo);
printf("Dia : %s\n", nome_dia);
printf("Expediente : %s\n", expediente);

printf("-----------------------------------------------------------------------\n");

printf("Taxa final : R$ %.2f\n", taxa_final);
printf("Status do servico : %s\n", status);


return 0;

}

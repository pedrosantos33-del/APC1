/*
O menu precisa de do-while para ser exibido pelo menos uma vez.
O while poderia não executar caso sua condição fosse falsa inicialmente.
Na opção 1, o continue é usado quando a senha é negativa.
Ele evita que a senha inválida seja contada como atendida ou par.
Na busca prioritária, o break encerra o laço ao encontrar o resultado.
Se o break fosse omitido, a busca continuaria lendo senhas,
mesmo após encontrar uma prioritária ou receber zero.
*/



#include <stdio.h>

int main() {
    int opcao;

    do {
        printf("\n===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int senha;
                int atendidas = 0;
                int ignoradas = 0;
                int pares = 0;

                printf("Digite as senhas (0 para encerrar): ");
                scanf("%d", &senha);

                while (senha != 0) {
                    if (senha < 0) {
                        ignoradas++;

                        printf("Digite outra senha (0 para encerrar): ");
                        scanf("%d", &senha);

                        continue;
                    }

                    atendidas++;

                    if (senha % 2 == 0) {
                        pares++;
                    }

                    printf("Digite outra senha (0 para encerrar): ");
                    scanf("%d", &senha);
                }

                printf("Atendidas : %d\n", atendidas);
                printf("Ignoradas : %d\n", ignoradas);
                printf("Pares     : %d\n", pares);

                break;
            }

            case 2: {
                int inicio, fim, passo;
                int i;
                int chamadas = 0;

                printf("Inicio: ");
                scanf("%d", &inicio);

                printf("Fim: ");
                scanf("%d", &fim);

                printf("Passo: ");
                scanf("%d", &passo);

                if (passo == 0) {
                    printf("Passo invalido\n");
                } else {
                    if (passo > 0) {
                        for (i = inicio; i <= fim; i += passo) {
                            if (chamadas == 0) {
                                printf("Chamadas: ");
                            }

                            printf("%d ", i);
                            chamadas++;
                        }
                    } else {
                        for (i = inicio; i >= fim; i += passo) {
                            if (chamadas == 0) {
                                printf("Chamadas: ");
                            }

                            printf("%d ", i);
                            chamadas++;
                        }
                    }

                    if (chamadas == 0) {
                        printf("Nenhuma chamada\n");
                    } else {
                        printf("\n");
                    }
                }

                break;
            }

            case 3: {
                int G, S;
                int guiche, senha;

                printf("Guiches (1 a 4): ");
                scanf("%d", &G);

                printf("Senhas por guiche (1 a 5): ");
                scanf("%d", &S);

                if (G < 1 || G > 4 || S < 1 || S > 5) {
                    printf("Grade invalida\n");
                } else {
                    for (guiche = 1; guiche <= G; guiche++) {
                        printf("Guiche %d: ", guiche);

                        for (senha = 1; senha <= S; senha++) {
                            printf("%d", senha);

                            if (senha < S) {
                                printf(" ");
                            }
                        }

                        printf("\n");
                    }
                }

                break;
            }

            case 4: {
                int senha;
                int lidas = 0;

                for (;;) {
                    printf("Senha: ");
                    scanf("%d", &senha);

                    if (senha == 0) {
                        printf("Nao encontrada\n");
                        printf("Lidas : %d\n", lidas);
                        break;
                    }

                    if (senha > 0 && senha % 10 == 0) {
                        printf("Prioritaria : %d\n", senha);
                        printf("Lidas antes : %d\n", lidas);
                        break;
                    }

                    lidas++;
                }

                break;
            }

            case 0:
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    printf("Painel encerrado.\n");

    return 0;
}

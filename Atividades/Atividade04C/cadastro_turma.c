
#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno {
    REPROVADO = 0,
    RECUPERACAO = 1,
    APROVADO = 2
};

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

int main() {

    struct Aluno alunos[MAX];

    int quantidade = 0;
    int opcao;
    int i;
    int encontrou;

    float media;
    float somaMedias;

    int reprovados;
    int recuperacao;
    int aprovados;

    int matriculaBusca;
    char nomeBusca[41];

    do {

        printf("\n===== CADASTRO DE TURMAS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Buscar por trecho do nome\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {

            case 1:

                if (quantidade >= MAX) {
                    printf("\nLimite de alunos atingido!\n");
                }
                else {

                    printf("\nMatricula: ");
                    scanf("%d", &alunos[quantidade].matricula);
                    while (getchar() != '\n');

                    printf("Nome: ");
                    fgets(alunos[quantidade].nome, 41, stdin);

                    alunos[quantidade].nome[
                        strcspn(alunos[quantidade].nome, "\n")
                    ] = '\0';

                    printf("Nota A1: ");
                    scanf("%f", &alunos[quantidade].a1);

                    printf("Nota A2: ");
                    scanf("%f", &alunos[quantidade].a2);

                    while (getchar() != '\n');

                    media = 0.4 * alunos[quantidade].a1
                          + 0.6 * alunos[quantidade].a2;

                    if (media >= 5) {
                        alunos[quantidade].status = APROVADO;
                    }
                    else if (media >= 3) {
                        alunos[quantidade].status = RECUPERACAO;
                    }
                    else {
                        alunos[quantidade].status = REPROVADO;
                    }

                    quantidade++;

                    printf("\nAluno cadastrado com sucesso!\n");
                }

                break;

            case 2:

                if (quantidade == 0) {
                    printf("\nNenhum aluno cadastrado.\n");
                }
                else {

                    printf("\nMATRICULA | NOME | A1 | A2 | MEDIA | STATUS\n");

                    for (i = 0; i < quantidade; i++) {

                        media = 0.4 * alunos[i].a1
                              + 0.6 * alunos[i].a2;

                        printf("%d | %s | %.2f | %.2f | %.2f | ",
                               alunos[i].matricula,
                               alunos[i].nome,
                               alunos[i].a1,
                               alunos[i].a2,
                               media);

                        switch (alunos[i].status) {

                            case REPROVADO:
                                printf("REPROVADO\n");
                                break;

                            case RECUPERACAO:
                                printf("RECUPERACAO\n");
                                break;

                            case APROVADO:
                                printf("APROVADO\n");
                                break;
                        }
                    }
                }

                break;

            case 3:

                printf("\nDigite a matricula: ");
                scanf("%d", &matriculaBusca);

                encontrou = 0;

                for (i = 0; i < quantidade; i++) {

                    if (alunos[i].matricula == matriculaBusca) {

                        media = 0.4 * alunos[i].a1
                              + 0.6 * alunos[i].a2;

                        printf("\nAluno encontrado!\n");
                        printf("Matricula: %d\n", alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("A1: %.2f\n", alunos[i].a1);
                        printf("A2: %.2f\n", alunos[i].a2);
                        printf("Media: %.2f\n", media);

                        switch (alunos[i].status) {

                            case REPROVADO:
                                printf("Status: REPROVADO\n");
                                break;

                            case RECUPERACAO:
                                printf("Status: RECUPERACAO\n");
                                break;

                            case APROVADO:
                                printf("Status: APROVADO\n");
                                break;
                        }

                        encontrou = 1;
                        break;
                    }
                }

                if (encontrou == 0) {
                    printf("\nNao encontrado.\n");
                }

                break;

            case 4:

                printf("\nDigite um trecho do nome: ");
                fgets(nomeBusca, 41, stdin);

                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                encontrou = 0;

                for (i = 0; i < quantidade; i++) {

                    if (strstr(alunos[i].nome, nomeBusca) != NULL) {

                        media = 0.4 * alunos[i].a1
                              + 0.6 * alunos[i].a2;

                        printf("\nMatricula: %d\n", alunos[i].matricula);
                        printf("Nome: %s\n", alunos[i].nome);
                        printf("A1: %.2f\n", alunos[i].a1);
                        printf("A2: %.2f\n", alunos[i].a2);
                        printf("Media: %.2f\n", media);

                        switch (alunos[i].status) {

                            case REPROVADO:
                                printf("Status: REPROVADO\n");
                                break;

                            case RECUPERACAO:
                                printf("Status: RECUPERACAO\n");
                                break;

                            case APROVADO:
                                printf("Status: APROVADO\n");
                                break;
                        }

                        encontrou = 1;
                    }
                }

                if (encontrou == 0) {
                    printf("\nNenhum aluno encontrado.\n");
                }

                break;

            case 5:

                reprovados = 0;
                recuperacao = 0;
                aprovados = 0;
                somaMedias = 0;

                for (i = 0; i < quantidade; i++) {

                    media = 0.4 * alunos[i].a1
                          + 0.6 * alunos[i].a2;

                    somaMedias += media;

                    switch (alunos[i].status) {

                        case REPROVADO:
                            reprovados++;
                            break;

                        case RECUPERACAO:
                            recuperacao++;
                            break;

                        case APROVADO:
                            aprovados++;
                            break;
                    }
                }

                printf("\n===== ESTATISTICAS =====\n");
                printf("Reprovados: %d\n", reprovados);
                printf("Recuperacao: %d\n", recuperacao);
                printf("Aprovados: %d\n", aprovados);

                if (quantidade > 0) {
                    printf("Media geral da turma: %.2f\n",
                           somaMedias / quantidade);
                }
                else {
                    printf("Media geral da turma: 0.00\n");
                }

                break;

            case 0:

                printf("\nEncerrando o programa...\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

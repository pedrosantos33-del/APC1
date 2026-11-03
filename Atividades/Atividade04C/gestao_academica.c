
/*
Uma variável char nome[50] armazena no máximo 49 caracteres úteis,
pois o último espaço é reservado para o caractere nulo '\0',
que indica o final de uma string em C.
Em uma matriz int M[3][4], o primeiro índice representa a linha,
enquanto o segundo índice representa a coluna.
Na memória, C organiza os elementos de uma matriz em ordem de linhas,
armazenando seus valores sequencialmente em posições contíguas.
*/

#include <stdio.h>
#include <string.h>

// PROTOTIPOS DAS FUNCOES
void limparBuffer(void);
void cadastrarAlunos(void);
void estatisticasDesempenho(void);
void matrizNotas(void);
void consultarAlunoDestaque(void);


// FUNCAO PRINCIPAL
int main(void) {

    int opcao;

    do {

        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma\n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Opcao invalida!\n");
            opcao = -1;
        } else {

            limparBuffer();

            switch (opcao) {

                case 1:
                    cadastrarAlunos();
                    break;

                case 2:
                    estatisticasDesempenho();
                    break;

                case 3:
                    matrizNotas();
                    break;

                case 4:
                    consultarAlunoDestaque();
                    break;

                case 0:
                    printf("Sistema encerrado!\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }
        }

    } while (opcao != 0);

    return 0;
}


// FUNCAO PARA LIMPAR O BUFFER
void limparBuffer(void) {

    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}


// OPCAO 1 - CADASTRAR LISTA DE ALUNOS
void cadastrarAlunos(void) {

    char alunos[5][50];
    int i;

    printf("\n===== CADASTRO DE ALUNOS =====\n");

    for (i = 0; i < 5; i++) {

        printf("Digite o nome do aluno %d: ", i + 1);

        fgets(alunos[i], sizeof(alunos[i]), stdin);

        alunos[i][strcspn(alunos[i], "\n")] = '\0';
    }

    printf("\n===== LISTA DE ALUNOS =====\n");

    for (i = 0; i < 5; i++) {

        printf("%d - %s\n", i + 1, alunos[i]);
    }
}


// OPCAO 2 - ESTATISTICAS DE DESEMPENHO
void estatisticasDesempenho(void) {

    float notas_finais[5];
    float soma = 0;
    float media;
    int quantidade = 0;
    int i;

    printf("\n===== ESTATISTICAS DE DESEMPENHO =====\n");

    // Preenchimento do vetor
    for (i = 0; i < 5; i++) {

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas_finais[i]);
    }

    // Calculo da soma
    for (i = 0; i < 5; i++) {

        soma += notas_finais[i];
    }

    // Calculo da media
    media = soma / 5;

    // Contagem de notas maiores ou iguais a media
    for (i = 0; i < 5; i++) {

        if (notas_finais[i] >= media) {

            quantidade++;
        }
    }

    printf("\nMedia geral da turma: %.2f\n", media);

    printf("Alunos com nota maior ou igual a media: %d\n",
           quantidade);
}


// OPCAO 3 - MATRIZ DE NOTAS DA TURMA
void matrizNotas(void) {

    float boletim[3][4];
    float soma;
    float media;
    int i, j;

    printf("\n===== MATRIZ DE NOTAS DA TURMA =====\n");

    // Preenchimento da matriz
    for (i = 0; i < 3; i++) {

        printf("\nAluno %d:\n", i + 1);

        for (j = 0; j < 4; j++) {

            printf("Nota do %d bimestre: ", j + 1);
            scanf("%f", &boletim[i][j]);
        }
    }

    // Exibicao da matriz e das medias
    printf("\n===== BOLETIM DA TURMA =====\n");

    printf("Aluno\t1 BIM\t2 BIM\t3 BIM\t4 BIM\tMedia\n");

    for (i = 0; i < 3; i++) {

        soma = 0;

        printf("%d\t", i + 1);

        for (j = 0; j < 4; j++) {

            printf("%.2f\t", boletim[i][j]);

            soma += boletim[i][j];
        }

        media = soma / 4;

        printf("%.2f\n", media);
    }
}


// OPCAO 4 - CONSULTAR ALUNO EM DESTAQUE
void consultarAlunoDestaque(void) {

    float notas[5];
    float maiorNota;
    int indice;
    int i;

    printf("\n===== CONSULTA DE ALUNO EM DESTAQUE =====\n");

    // Preenchimento do vetor
    for (i = 0; i < 5; i++) {

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Inicializacao da maior nota
    maiorNota = notas[0];
    indice = 0;

    // Pesquisa da maior nota
    for (i = 1; i < 5; i++) {

        if (notas[i] > maiorNota) {

            maiorNota = notas[i];
            indice = i;
        }
    }

    printf("\n===== ALUNO EM DESTAQUE =====\n");

    printf("Maior nota: %.2f\n", maiorNota);

    printf("Indice encontrado: %d\n", indice);

    printf("Posicao do aluno: %d\n", indice + 1);
}

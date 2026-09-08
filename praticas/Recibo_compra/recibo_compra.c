/*
    Aluno: Pedro Henrique Vieira dos Santos
    Matricula: 2622130002
    Curso: Ciencia da computaçao
    Materia: Algoritmos e programação de computadores
    Descrição: o scanf("%s") lê apenas uma palavra, ou seja, ele para de ler quando encontra um espaço em branco.
    Por isso ele nao armazena o nome completo do cliente ou do produto. Para ler uma linha inteira, incluindo espaços em branco, podemos usar a função
    fgets() da biblioteca stdio.h.
    O fgets() permite que a entrada contenha espaços entre as palavras.
    depois uso a função strcspn() da biblioteca string.h para remover a quebra de linha do final da string.
*/

#include <stdio.h>
#include <string.h> //inclui a biblioteca string.h para usar a função strcspn

int main(){ 
char Nome[100];
char Produto[100]; 
long long Codigo; 
int Quantidade; 
float Preco; 
char Categoria; 
float Total;


printf("Digite seu nome: ");
fgets(Nome, sizeof(Nome), stdin); 
Nome[strcspn(Nome, "\n")] = 0; //remove a quebra de linha do final da string 

printf("Digite o codigo do produto: ");
scanf("%lld", &Codigo); //& é importante para passar o endereço da variável para a função scanf
getchar(); //limpa o buffer do teclado para evitar problemas com fgets 

printf("Digite o nome do produto: "); 
fgets(Produto, sizeof(Produto), stdin); 
Produto[strcspn(Produto, "\n")] = 0; //remove a quebra de linha do final da string 

printf("Digite a quantidade do produto: "); 
scanf("%d", &Quantidade); getchar(); //limpa o buffer do teclado para evitar problemas com fgets 

do { 
if (Quantidade <= 0) { 
printf("Quantidade invalida. O valor deve ser maior que zero.\n"); 

printf("Digite a quantidade do produto novamente: "); 
scanf("%d", &Quantidade); 
getchar(); 

} 

} while (Quantidade <= 0);

printf("Digite o preco unitario produto: "); 
scanf("%f", &Preco); 
getchar(); 

printf("Digite a categoria do produto (A, B ou C): "); 
scanf("%c", &Categoria); 
getchar();

Total = Quantidade * Preco;


printf("========================================\n");
printf("           RECIBO DE COMPRA\n");
printf("========================================\n");

printf("%-20s: %s\n", "Nome do cliente", Nome);.
printf("%-20s: %s\n", "Nome do produto", Produto);
printf("%-20s: %lld\n", "Codigo do produto", Codigo);
printf("%-20s: %d\n", "Quantidade", Quantidade);
printf("%-20s: %.2f\n", "Preco unitario", Preco);
printf("%-20s: %.2f\n", "Total", Total);
printf("%-20s: %c\n", "Categoria", Categoria);

printf("========================================\n");
return 0;
 
}

//Lucas Roberto Boccia dos Santos - 22.123.012-1
//Tiago Fagundes dos Santos - 22.123.017-0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {

    struct tarefas t[100];
    int cont = 0;
    cont = le_binario(t);
    int posicao = 0;
    //Variaveis utilizadas no programa, juntamente com a chamada da funcao que abre e le o arquivo binario assim que o programa é iniciado, ja salvando as informacoes do usuario na lista de struct.

    while (1) {

        printf("Menu das Tarefas (Somente entre com numeros): \n");
        printf(" 1 - Inserir tarefa: \n");
        printf(" 2 - Deletar tarefa: \n");
        printf(" 3 - Listar tarefas: \n");
        printf(" 4 - Alterar tarefa: \n");
        printf(" 5 - Filtra tarefa por prioridade: \n");
        printf(" 6 - Filtra tarefa por status: \n");
        printf(" 7 - Filtra tarfea por categoria: \n");
        printf(" 8 - Sair\n");
        printf("Digite o numero da opcao que deseja usar: \n");

        //Funcao do menu de tarefas, roda em while infinito mostrando o menu para o usuario printando as funcoes disponiveis, ate o usuario optar por sair.


        char *p, s_opcao[100];
        int opcao;
        fgets(s_opcao, sizeof(s_opcao), stdin);
        opcao = strtol(s_opcao, &p, 10);

        //Preparacao do fgets para receber input do usuario.

        if (opcao == 1) {
            printf("Voce entrou na funcao inserir tarefas.\n");
            le_valores(&t[cont]);

            //printf("%d\n",t[cont].prioridade); (debug)
            //printf("%s\n",t[cont].categoria); (debug)
            //printf("%s\n",t[cont].descricao); (debug)
            printf("Tarefa cadastrada com sucesso!\n\n");
            cont++;
            //printf("%d\n",cont); (debug)

            //Funcao de registrar tarefas. Chama a funcao "le_valores" que, como explicado no biblioteca.c, recebe as informacoes do usuario e registra a tarefa.

        } else if (opcao == 2) {
            printf("Voce entrou na funcao deletar tarefas.\n\n");
            printf("Entre o numero da tarefa que deseja deletar : ");
            int verifica = deletar(posicao, cont, t);
            if (verifica == 0) {
                cont--;
            }
        }

            //Funcao de deletar tarefas. Chama a funcao "deletar", que, como explicado no biblioteca.c, recebe o input do usuario e deleta a tarefa. Caso o usuario entre com um input invalido, o programa também o informa e
            //retorna para o menu.


        else if (opcao == 3) {
            //printf("%d\n", tarefas.prioridade); (debug)
            //printf("%d\n",cont); (debug)
            listar(cont, t);
        }
            //Funcao que lista tarefas. Chama a funcao "listar", que, como explicado no biblioteca.c, itera sobre a lista de struct e mostra para o usuario todas as informacoes registradas no programa de maneira organizada.

        else if (opcao == 4){
          printf("Voce entrou na funcao alterar tarefas.\n\n");
          printf("Entre o numero da tarefa que deseja alterar : \n");
          alterar(posicao, cont, t);

        }
        else if(opcao == 5){
          printf("Voce entrou na funcao filtrar tarefa por prioridade.\n");
          printf("Entre o numero da prioridade que deseja alterar : \n");
          filtra_prioridade(cont,t);
        }
        else if(opcao == 6){
          printf("Voce entrou na funcao filtrar tarefa por status.\n");
          printf("Entre com o numero do status da tarefa: \n");
          filtra_status(cont,t);
        }
        else if(opcao == 7){
          printf("Voce entrou na funcao filtrar tarefa por categoria.\n");
          printf("Digite a categoria da tarefa: \n");
          filtra_categoria(cont,t);

        }

        else if (opcao == 8) {
            escreve_binario(t, cont);
            printf("Saindo do programa");
            break;
        }
        //Print que escreve as informações em um arquivo binário (verificando se ele foi aberto com sucesso) e sai do programa.

        else  {
          printf("Input invalido. Entre somente com valores inteiros entre 1 e 6.\n\n");
        }

          //Print que informa o usuario que entrou com uma opcao nao disponivel pelo programa.
    }
}
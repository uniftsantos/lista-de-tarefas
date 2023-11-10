//
// Created by uniflusantos on 19/09/2023.
//

#ifndef UNTITLED_BIBLIOTECA_H
#define UNTITLED_BIBLIOTECA_H

struct tarefas{
    int prioridade;
    char categoria[100];
    char descricao[300];
    int status;
};
//Struct usada para o armazenamento das informacoes do programa. Trabalha com 3 variaveis, que guardam as informacoes do usuario de maneira organizada.

void limpa_buffer();
//Declaracao da funcao que previne erros de armazenamento e leitura de dados pelo scanf.

void le_valores(struct tarefas *armazena);
//Declarao da funcao que le e armazena informacoes nas variaveis apropriadas, utilizando de parametro a struct tarefas.

int deletar(int posicao, int cont, struct tarefas *t);
//Declaracao da funcao que deleta tarefas pelo usuario, utilizando de parametros as variaveis posicao, cont e *t.

void listar(int cont, struct tarefas *t);
//Declaracao da funcao que lista as tarefas registradas para o usuario, utilizando de parametros as variaveis e cont e *t.

int le_binario(struct tarefas *t);
//Declaracao da funcao que le o arquivo binario com as informacoes registradas pelo usuario, utilizando de parametro a variavel *t.

void escreve_binario(struct tarefas *t, int cont);
//Declaracao da funcao que salva as informacoes registradas pelo usuario, escrevendo-as em um arquivo binario, que é lido pela funcao anterior quando o programa é iniciado. Uitliza como parametros as variaveis *t e cont.


// passando o parametro da funcao alterar, que são eles a posicao atual da tarefa , cont que indica a quantidade e a struct.
void alterar(int posicao,int cont, struct tarefas *t);


//passando os paremetros das novas funcoes(filtra_prioridade.filtra_status,filtra_categoira,filtra_prioridade_categoria) que são eles o cont que indica a quantidade de tarefas,
//e a struct;
void filtra_prioridade(int cont, struct tarefas *t);

void filtra_status(int cont, struct tarefas *t);

void filtra_categoria(int cont, struct tarefas *t);

void filtra_prioridade_categoria(int cont, struct tarefas *t);

#endif //UNTITLED_BIBLIOTECA_H

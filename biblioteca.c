//
// Created by uniflusantos on 19/09/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"




void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//Funcao para prevenir erros no armazenamento e leitura de informacoes.

void le_valores(struct tarefas *armazena) {

    int var_prioridade;
    int var_status;
    do{
        printf("Digite a prioridade de 1 a 10: ");
        scanf("%d", &var_prioridade);

        if(var_prioridade < 1 || var_prioridade > 10){
            printf("Input Invalido. Entre com um valor entre 0 e 10\n");
        }
    } while (var_prioridade < 1 || var_prioridade > 10);

    armazena->prioridade = var_prioridade;
    limpa_buffer();
    printf("Digite a categoria: ");
    scanf("%[^\n]", armazena->categoria);
    limpa_buffer();
    printf("Digite a descricao: ");
    scanf("%[^\n]", armazena->descricao);
    limpa_buffer();


  do {
      printf("Escolha o status da tarefa:\n");
      printf("Digite 1 para tarefa completa\n");
      printf("Digite 2 para tarefa em andamento\n");
      printf("Digite 3 para tarefa nao iniciada\n");
      scanf("%d", &var_status);

      if(var_status < 1 || var_status > 3) {
          printf("Input inválido. Por favor, entre com um valor entre 1 e 3.\n");
      }
  } while (var_status < 1 || var_status > 3);
  limpa_buffer();

  armazena->status = var_status;



}

//Funcao que recebe as informacoes do usuario e as armazena na variavel apropriada. O programa recebe os inputs por meio da funcao "scanf" e a funcao "armazena" guarda as informacoes nas variaveis da struct. Utilizamos a
//funcao limpa buffer depois de cada scanf para evitar erros no armazenamento e leitura das informacoes. A funcao tambem utiliza um laco "do while" para impedir que o usuario entre com valores abaixo de 0 ou acima de 10
//no campo de prioridade, uma vez que o programa so trabalha com valores nesse intervalo para essa variavel. Caso o usuario entre com um input invalido nesse campo, o programa ira pedir novamente para que entre com outro
//valor de prioridade que atenda ao intervalo entre 0 e 10.

int deletar(int posicao, int cont, struct tarefas *t){


    char *p_posicao, s_posicao[100];
    fgets(s_posicao, sizeof(s_posicao), stdin);
    posicao = strtol(s_posicao, &p_posicao, 10);
    if(p_posicao == s_posicao || *p_posicao != '\n') {
        printf("Input invalido. Entre somente com numeros inteiros.\n\n");
        return 1;
    }
    else if(posicao <= 0 && cont > 1 || posicao > cont && cont > 1){
        printf("Numero invalido! Entre um numero entre 1 e %d\n\n", cont);
        return 1;
    }
    else if(cont == 0){
        printf("Voce nao tem nenhuma tarefa registrada.\n\n");
        return 1;
    }
    else if(posicao <= 0 && cont == 1 || posicao > cont && cont == 1){
        printf("Numero invalido! Voce tem somente 1 tarefa registrada.\n\n");
        return 1;
    }
    else{
        //printf("erro\n");
        //printf("%d\n",posicao - 1);
        //printf("%d\n",cont);
        for(int i = posicao - 1; i < cont ; i++){
            //printf("%d\n", i);
            //printf("%d\n", posicao);
            //printf("%d\n", cont);
            t[i] = t[i + 1];
        }
        printf("Tarefa deletada\n\n");
        return 0;
    }
}

//Funcao de deletar tarefas. Recebe do usuario a posicao que ele quer deletar e soma 1 ao indice (ja que nosso programa, procurando ser mais user friendly, lista as tarefas a partir do 1 ao inves do 0. Caso o usuario informe um numero menor ou igual a
//0, o programa informa que o numero digitado foi invalido e pede para que o usuario insira um numero entre 1 e o numero de tarefas disponiveis. Com o usuario informando um numero valido, o laco for procura por esse numero na lista de tarefas e a deleta,
//rearrumando a lista. Caso o usuario entre com um input valido (como uma letra, por exemplo), o programa o informa e retorna para o menu. Caso o usuario não tem nenhuma tarefa registrada ou só tenha uma, o programa também o
//informa aproriadamente e retorna para o menu.



void listar(int cont, struct tarefas *t){
  if(cont==0){
    printf("Não há tarefas cadastradas.\n\n");
  }
  else{
    printf("Lista de tarefas\n\n");
    for(int x=0;x<cont;x++){
      printf("Tarefa %d\n", x+1);
      printf("Nivel de prioridade: %d\n",t[x].prioridade);
      printf("Categoria: %s\n",t[x].categoria );
      printf("Descricao: %s\n",t[x].descricao);
      if(t[x].status == 1){
        printf("Status: Tarefa Completa!\n\n");
      }
      else if(t[x].status == 2){
      printf("Status: Tarefa em andamento!\n\n");
      }
      else{
        printf("Status: Tarefa nao iniciada!\n\n");
      }
        
    }
  }
}

void alterar(int posicao,int cont, struct tarefas *t){

int var_status;
  char *p_posicao, s_posicao[100];
  fgets(s_posicao, sizeof(s_posicao), stdin);
  posicao = strtol(s_posicao, &p_posicao, 10);
  if(p_posicao == s_posicao || *p_posicao != '\n') {
      printf("Input invalido. Entre somente com numeros inteiros.\n\n");
      //return 1;
  }
  else if(posicao <= 0 && cont > 1 || posicao > cont && cont > 1){
      printf("Numero invalido! Entre um numero entre 1 e %d\n\n", cont);
      //return 1;
  }
  else if(cont == 0){
      printf("Voce nao tem nenhuma tarefa registrada.\n\n");
      //return 1;
  }
  else if(posicao <= 0 && cont == 1 || posicao > cont && cont == 1){
      printf("Numero invalido! Voce tem somente 1 tarefa registrada.\n\n");
      //return 1;
  }
  else{
    int campo = -1;
    printf("Se você deseja alterar a prioridade clique 1, se deseja alterar a categoria clique 2, se deseja alterar a descricao clique 3, se deseja alterar o status digite 4.\n");
    scanf("%d",&campo);
    limpa_buffer();
    if (campo==1){
      int var_prioridade,var_status;
      printf("Alterando tarefa.\n");

      do{
          printf("Digite a prioridade de 1 a 10: ");
          scanf("%d", &var_prioridade);

          if(var_prioridade < 1 || var_prioridade > 10){
              printf("Input Invalido. Entre com um valor entre 1 e 10\n");
          }
      } while (var_prioridade < 1 || var_prioridade > 10);

      t[posicao - 1].prioridade = var_prioridade;
      printf("Prioridade alterada com sucesso.\n\n");
      //return 0;
    }
    else if(campo == 2){
      printf("Digite a categoria: ");
      scanf("%[^\n]",t[posicao - 1].categoria);
      limpa_buffer();
      printf("Categoria alterada com sucesso.\n\n");
      //return 0;
    }
    else if (campo == 3){
      printf("Digite a descricao: ");
      scanf("%[^\n]",t[posicao - 1].descricao);
      limpa_buffer();
      printf("Descricao alterada com sucesso.\n\n");
      //return 0;
    }
    else if(campo == 4){
      do {
        printf("Escolha o status da tarefa:\n");
        printf("Digite 1 para tarefa completa\n");
        printf("Digite 2 para tarefa em andamento\n");
        printf("Digite 3 para tarefa nao iniciada\n");
        scanf("%d", &var_status);

        if(var_status < 1 || var_status > 3) {
            printf("Input inválido. Por favor, entre com um valor entre 1 e 3.\n");
        }
      } while (var_status < 1 || var_status > 3);
      limpa_buffer();

      t[posicao-1].status = var_status;
      //printf("Digite o status: ");
      //scanf("%d",&t[posicao - 1].status);
      //limpa_buffer();
      printf("Status alterada com sucesso.\n\n");
    }
    else{
      printf("opcao inválida!\n");
    }



  }

}

void filtra_prioridade(int cont, struct tarefas *t){
  int var_prioridade,verifica =0;
  printf("Digite a prioridade que voce deseja filtrar: ");
  scanf("%d",&var_prioridade);
  limpa_buffer();
  printf("Filtrar tarefa em prioridade nota: %d\n\n",var_prioridade);
  int erro=-1;
  if(cont == 0){
    printf("Nao ha tarefas registradas.\n\n");
    
  }
  else{
  FILE *f = fopen("prioridades.txt", "wb");
  fprintf(f, "Filtrar tarefas em prioridade nota: %d \n\n",var_prioridade);
  for(int i =0; i<cont;i++){
    if(t[i].prioridade == var_prioridade){
      verifica ++;
      fprintf(f,"Tarefa %d\n", i+1);
      fprintf(f,"Nivel de prioridade: %d\n",t[i].prioridade);
      fprintf(f,"Categoria: %s\n",t[i].categoria);
      fprintf(f,"Descricao: %s\n",t[i].descricao);


      
      printf("Tarefa %d\n", i+1);
      printf("Nivel de prioridade: %d\n",t[i].prioridade);
      printf("Categoria: %s\n",t[i].categoria );
      printf("Descricao: %s\n",t[i].descricao);
      if(t[i].status == 1){
        printf("Status: Tarefa Completa!\n\n");
        fprintf(f,"Status: Tarefa Completa!\n\n");
      }
      else if(t[i].status == 2){
        printf("Status: Tarefa em andamento!\n\n");
        fprintf(f,"Status: Tarefa em andamento!\n\n");
      }
      else{
        printf("Status: Tarefa nao iniciada!\n\n");
        fprintf(f,"Status: Tarefa nao iniciada!\n\n");
      }
    }
    else if (i == cont -1 && verifica == 0 ){
      erro =1;

    }

  }
    
  fclose(f);
    
  if(erro == 1){
    printf("nao existem tarefas com essa prioridade.\n\n");
  }



  }

};

void filtra_status(int cont, struct tarefas *t){
  int var_status,verifica =0;
  printf("Escolha o status que voce deseja filtrar: clique 1 para tarefa completa, clique 2 para tarefa em andamento e clique 3 para tarefa nao iniciada ");
  scanf("%d",&var_status);
  limpa_buffer();
  if(var_status>=1 && var_status<=3){

    printf("Filtrar tarefa com status atual em: %d\n\n",var_status);
    int erro=-1;
    if(cont == 0){
        printf("Nao ha tarefas registradas.\n\n");
    }
    else{
    for(int i =0; i<cont;i++){
        if(t[i].status == var_status){
        verifica ++;
        printf("Tarefa %d\n", i+1);
        printf("Nivel de prioridade: %d\n",t[i].prioridade);
        printf("Categoria: %s\n",t[i].categoria );
        printf("Descricao: %s\n",t[i].descricao);
          if(t[i].status == 1){
            printf("Status: Tarefa Completa!\n\n");
          }
          else if(t[i].status == 2){
          printf("Status: Tarefa em andamento!\n\n");
          }
          else{
            printf("Status: Tarefa nao iniciada!\n\n");
          }
        }
        else if (i == cont -1 && verifica == 0 ){
        erro =1;

        }

    }
        if(erro == 1){
        printf("nao existem tarefas com esse status.\n\n");
        }



    }
  }

  else{
    printf("Opcao invalida\n\n");
  }
};

void filtra_categoria(int cont, struct tarefas *t){
  int verifica=0,erro=1;
  char categ[100];
  printf("Digite a categoria da tarefa: \n");
  fgets(categ, sizeof(categ), stdin);
  categ[strcspn(categ, "\n")] = '\0';

  //scanf( "%s", categ);
  //limpa_buffer();
  printf("\n Filtrar por %s\n\n",categ);
  //printf(s_posicao);
  if(cont == 0){
    printf("Nao ha tarefas registradas.\n\n");
  }
  else{
  FILE*v = fopen("categoria.txt", "wb");
  fprintf(v, "\n Filtra tarefas com a categoria : %s \n\n",categ);
  
  for(int i =0; i<cont;i++){
    if(strcmp(t[i].categoria, categ) == 0){
      verifica ++;
    
      fprintf(v,"Tarefa %d\n", i+1);
      fprintf(v,"Nivel de prioridade: %d\n",t[i].prioridade);
      fprintf(v,"Categoria: %s\n",t[i].categoria);
      fprintf(v,"Descricao: %s\n",t[i].descricao);



      printf("Tarefa %d\n", i+1);
      printf("Nivel de prioridade: %d\n",t[i].prioridade);
      printf("Categoria: %s\n",t[i].categoria );
      printf("Descricao: %s\n",t[i].descricao);
      if(t[i].status == 1){
        printf("Status: Tarefa Completa!\n\n");
        fprintf(v,"Status: Tarefa Completa!\n\n");
      }
      else if(t[i].status == 2){
      printf("Status: Tarefa em andamento!\n\n");
      fprintf(v,"Status: Tarefa em andamento!\n\n");
      }
      else{
        printf("Status: Tarefa nao iniciada!\n\n");
        fprintf(v,"Status: Tarefa nao iniciada!\n\n");

      }
      erro=0;
    }
  }

  fclose(v);
  
    if(erro == 1){
      printf("nao existem tarefas com essa prioridade.\n\n");
    }



  }
  
}

void filtra_prioridade_categoria(int cont, struct tarefas *t){
  int var_prioridade,verifica = 0;
  printf("Digite a prioridade que voce deseja filtrar: \n");
  scanf("%d",&var_prioridade);
  limpa_buffer();
  
  char categ[100];
  printf("Digite a categoria da tarefa: \n");
  fgets(categ, sizeof(categ), stdin);
  categ[strcspn(categ, "\n")] = '\0';
  
  
  printf("Filtrar tarefa em prioridade nota: %d e categoria : %s\n\n",var_prioridade,categ);
  int erro=-1;
  if(cont == 0){
    printf("Nao ha tarefas registradas.\n\n");
  }
  else{
  for(int i =0; i<cont;i++){
    if(t[i].prioridade == var_prioridade && strcmp(t[i].categoria, categ) == 0 ){
      verifica ++;
      printf("Tarefa %d\n", i+1);
      printf("Nivel de prioridade: %d\n",t[i].prioridade);
      printf("Categoria: %s\n",t[i].categoria );
      printf("Descricao: %s\n",t[i].descricao);
      if(t[i].status == 1){
        printf("Status: Tarefa Completa!\n\n");
      }
      else if(t[i].status == 2){
      printf("Status: Tarefa em andamento!\n\n");
      }
      else{
        printf("Status: Tarefa nao iniciada!\n\n");
      }
    }
    else if (i == cont -1 && verifica == 0 ){
      erro = 1;

    }

  }
    if(erro == 1){
      printf("nao existem tarefas com essa prioridade.\n\n");
    }



  }
  
}



//Funcao que lista as tarefas e suas informacoes para o usuario. Utiliza um laco for com a variavel "x" para iterar sobre a lista de struct, e assim, fornece ao usuario todas as tarefas que estão registradas de maneira
//organizada. Também mostrando para o usuario o numero da tarefa, (por meio da expressao "x+1"), facilitando a utilizacao da funcao de deletar tarefas.

int le_binario(struct tarefas *t) {
    FILE *arquivo_binario = fopen("binario.txt", "rb");
    int y = 0;
    if (arquivo_binario) {
        while (fread(&t[y], sizeof(struct tarefas), 1, arquivo_binario) == 1) {
            y++;
        }
        return y;

    }
  return 0;
}


//Funcao que le um arquivo binario com as informacoes registradas pelo usuario assim que o programa é iniciado, evitando assim que as informacoes se percam quando o usuario sai e entra novamente no programa. Para isso,
//declaramos a variavel "FILE *arquivo_binario*, que, por meio da funcao fopen, abre o arquivo binario com as informacoes escritas pela funcao "escreve_binario" e realiza a leitura, salvando elas na strucutre da maneira
//como que estavam na utilizacao anterior do programa. O laco while aumenta uma variavel "y", que, na main.c, será recebida pela variavel "cont", que´é o contador de tarefas utilizado em outras funcoes. Por exemplo, caso
//a funcao "le_binario" leia 3 tarefas, o valor do contador (variavel cont) será atualizado para 3, garantindo o funcionamento normal do programa.


void escreve_binario(struct tarefas *t, int cont) {
    FILE *arquivo_binario;
    arquivo_binario = fopen("binario.txt", "wb");
    //printf("%p\n", arquivo_binario);
    if (arquivo_binario) {
        //printf("entrou\n");

        //printf("%d\n", t->prioridade);
        fwrite(t, sizeof(struct tarefas), cont, arquivo_binario);

        fclose(arquivo_binario);
    }

}
//Funcao que, ao usuario escolher sair do programa, registra todas as informacoes salvas em um arquivo binario, para que assim, quando o usuario decidir utilizar o programa novamente, suas informacoes estejam salvas.
//Para fazer isso, declaramos a variavel "FILE *arquivo_binario", assim como na funcao anterior, e ela, por meio da funcao fopen, com o mode "wb", escreve todas as informacoes salvas no programa para um arquivo binario,
//que é lido ao iniciar programa pela funcao "le_binario", por fim, antes de parar a execucao da programa, a funcao "fclose" fecha o arquivo, agora salvo com todas as informacoes do usuario.
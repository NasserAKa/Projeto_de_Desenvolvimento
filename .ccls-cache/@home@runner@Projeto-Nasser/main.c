#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct mensalistas{
  char nome[30];
  int telefone;
  int rg;
  char placa[10];
  float valor;
  int situMes;//0 para o mes nao pago e 1 para o mes pago
  char obs[300];
}mensal;

typedef struct diaristas{
  char placa[10];
  int horaEntrada;
  int minEntrada;
}diaria;

void leituraListaM();
void leituraListaD();
void pesquisaListaM();
void buscarListaD();
void imprimirListaM();
void imprimirListaD();

int main() {
  int menu ;

  printf("\n \nMenu: \n1 - Inserir um mensalista na lista mensalistas \n2 - Inserir um diarista na lista de diaristas \n3 - Pesquisar um mensalista \n4 - Buscar um diarista \n5 - Imprimir a lista de mensalistas \n6 - Imprimir a lista dos diaristas \n7 - Encerrar programa");

  while(menu != 7){
  printf("\n \nEscolha uma opcao: ");
  scanf("%d", &menu);
  
  if(menu == 7){
    break;
  }
    
  if(menu == 1){
    leituraListaM();
    }
    
  if(menu == 2){
    leituraListaD();
    }

  if(menu == 3){
     pesquisaListaM();
     }

  if(menu == 4){
     buscarListaD();
    }
    
  if(menu == 5){
    imprimirListaM();
      }

    if(menu == 6){
    imprimirListaD();
      }
      }return 0;
    }

void leituraListaM(){
  FILE *arquivo;
  int m, mes;
  mensal listaM[70];

   if((arquivo = fopen("listaM.txt", "a+")) == NULL){
    printf("Erro para abrir o arquivo");
  }
  
  printf("\nDigite a quantidade de pessoas que deseja cadastrar: ");
    scanf("%d", &m);
    getchar();
  
    for(int i =0;i<m;i++){
      printf("\nDigite o nome da pessoa %d: ", i+1);
      gets(listaM[i].nome);

      printf("\nDigite o telefone da pessoa %d: ", i+1);
      scanf("%d", &listaM[i].telefone);

      printf("\nDigite o RG da pessoa %d: ", i+1);
      scanf("%d", &listaM[i].rg);
      getchar();

      printf("\nDigite a placa do veiculo da pessoa %d: ", i+1);
      gets(listaM[i].placa);

      printf("\nDigite o valor da mensalidade da pessoa %d: ", i+1);
      scanf("%f", &listaM[i].valor);
      
      printf("\nDigite 0 se a pessoa nao pagou a mensalidade e 1 se a mensalidade foi paga: ");
      scanf("%d", &listaM[i].situMes);
      getchar();

      printf("\nDigite uma observaçao referente a pessoa %d: ", i+1);
      gets(listaM[i].obs);

      fprintf(arquivo, "%s %d %d %s %.2f %d %s\n", listaM[i].nome, listaM[i].telefone, listaM[i].rg, listaM[i].placa, listaM[i].valor, listaM[i].situMes, listaM[i].obs);
      }
  fclose(arquivo);
}

void leituraListaD(){
  FILE *arquivo1;
  int a;
  diaria listaD[30];

  if((arquivo1 = fopen("listaD.txt", "a+")) == NULL){
    printf("Erro para abrir o arquivo");
  }
  
  printf("\nDigite a quantidade de pessoas que deseja cadastrar: ");
    scanf("%d", &a);
    getchar();

  for(int i =0;i<a;i++){
    printf("\nDigite a placa do veiculo da pessoa : ");
    gets(listaD[i].placa);

    printf("Digite a hora de chegada no formato(00:00): ");
    scanf("%d:%d", &listaD[i].horaEntrada, &listaD[i].minEntrada);

    fprintf(arquivo1, "%s %d %d\n", listaD[i].placa, listaD[i].horaEntrada, listaD[i].minEntrada);
    }
  fclose(arquivo1);
  }

void pesquisaListaM(){
  FILE *arquivo;
  int n, comp, mes;
  char nome[30];
  mensal listaM[70];
  
  if((arquivo = fopen("listaM.txt", "r")) == NULL){
    printf("Erro para abrir o arquivo");
  }
  
  printf("\nDigite o nome do mensalista: ");
  scanf("%s", &nome);
    int i = 0;
      while(!feof(arquivo)){
       fscanf(arquivo, "%s %d %d %s %f %d %s\n", &listaM[i].nome, &listaM[i].telefone, &listaM[i].rg, &listaM[i].placa, &listaM[i].valor, &listaM[i].situMes, &listaM[i].obs);

      comp = strcmp(listaM[i].nome, nome);
      if(comp == 0){
        printf("Nome: %s \nTelefone: %d \nRG: %d \nPlaca do veiculo: %s \nValor Mensalidade: %.2f \n", listaM[i].nome, listaM[i].telefone, listaM[i].rg, listaM[i].placa, listaM[i].valor);

          if(listaM[i].situMes == 0){
            printf("Mes atual nao pago!\n");
            }
          if(listaM[i].situMes == 1){
            printf("Mes atual pago!\n");
            }
        }i++;
      }fclose(arquivo);
}


void buscarListaD(){
  FILE *arquivo1;
  char placa[10];
  int comp1, minSaida, horaSaida, tempo = 0;
  float total, valor;
  diaria listaD[30];
  
  if((arquivo1 = fopen("listaD.txt", "r")) == NULL){
    printf("Erro para abrir o arquivo");
  }
  
  printf("\nDigite a placa do veiculo que esta saindo: ");
  scanf("%s", &placa);
    int i = 0;
      while(!feof(arquivo1)){
        fscanf(arquivo1, "%s %d %d\n", &listaD[i].placa, &listaD[i].horaEntrada, &listaD[i].minEntrada);
        
      comp1 = strcmp(placa, listaD[i].placa);
      if(comp1 == 0){
        printf("Digite a hora de saida no formato(00:00): ");
        scanf("%d:%d", &horaSaida, &minSaida);

        if( listaD[i].minEntrada > minSaida){
          listaD[i].minEntrada += 60;
          listaD[i].horaEntrada --;
        }
        tempo = (horaSaida - listaD[i].horaEntrada)*60;
        tempo += (minSaida -  listaD[i].minEntrada);
        valor = tempo * 0.05;

        printf("\nO valor a ser pago referente ao veiculo de placa %s é %.2f.\n", listaD[i].placa, valor);

        } 
      }i++;
  fclose(arquivo1);
}


void imprimirListaM(){
  FILE *arquivo;
  mensal listaM[70];
  int mes;
  char situacao;

  if((arquivo = fopen("listaM.txt", "r")) == NULL){
    printf("Erro para abrir o arquivo");
  }
  int i = 0;
  while(!feof(arquivo)){
       fscanf(arquivo, "%s %d %d %s %f %d %s\n", &listaM[i].nome, &listaM[i].telefone, &listaM[i].rg, &listaM[i].placa, &listaM[i].valor, &listaM[i].situMes, &listaM[i].obs);


        printf("\nNome: %s \nTelefone: %d \nRG: %d \nPlaca do veiculo: %s \nValor Mensalidade: %.2f \nSituacao: %d \nObs: %s\n", listaM[i].nome, listaM[i].telefone, listaM[i].rg, listaM[i].placa, listaM[i].valor, listaM[i].situMes, listaM[i].obs);
        }i++;
  fclose(arquivo);
}

void imprimirListaD(){
  FILE *arquivo1;
  diaria listaD[30];

  if((arquivo1 = fopen("listaD.txt", "r")) == NULL){
    printf("Erro para abrir o arquivo");
  }

  int i = 0;
while(!feof(arquivo1)){
        fscanf(arquivo1, "%s %d %d\n", &listaD[i].placa, &listaD[i].horaEntrada, &listaD[i].minEntrada);

        printf("\nPlaca: %s \nHora de entrada: %d:%d\n", listaD[i].placa, listaD[i].horaEntrada, listaD[i].minEntrada);
        }
  }
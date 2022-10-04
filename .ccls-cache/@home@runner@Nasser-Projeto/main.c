#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n = 1;
  char placa[n];
  int stop = 0;
  int hr, min;
  int hrs, mins;
  int tempo, m = 2;
  float totalMensal[m], totalDiario = 0, totalMensal2 = 0;
  float valor;
for(int i = 0;i < m;i++){stop = 0;totalDiario = 0;
    while(stop != 1){
   
      printf("\nDigite a placa do veiculo no formato (xxx-0000): ");
      scanf("%s", &placa[stop]);
      getchar();

      printf("Digite a hora de chegada no formato(00:00): ");
      scanf("%d:%d", &hr, &min);

  
      printf("Digite a hora de saída no formato(00:00): ");
      scanf("%d:%d", &hrs, &mins);

      if(min > mins){
      min += 60;
      hr--;
      }
      tempo = (hrs - hr)*60;
      tempo += (mins - min);
      valor = tempo * 0.05;
    
      printf("\nO valor a ser pago referente ao veículo de placa %s é %.2f.\n", placa, valor);

      totalDiario += valor;
      printf("\nDeseja encerrar o dia? Digite (1) e para continuar digite (0):");
      scanf("%d", &stop);
      }

printf("\nO valor recebido no dia é %.2f\n", totalDiario);
  totalMensal[i] = totalDiario;
  totalMensal2 += totalDiario;
  }

  printf("\nTotal mensal por dia:\n");
for(int i = 0;i < m;i++){
  printf("Dia %d: %.2f\n", i+1, totalMensal[i]);
  }
printf("\nTotal mensal: %.2f", totalMensal2);
  
  
  return 0;
    }

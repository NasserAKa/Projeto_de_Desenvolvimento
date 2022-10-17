#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n = 8;
  char placa[n];
  int stop = 0;
  int horario_entrada, minuto_de_entrada;
  int horario_saida, minuto_de_saida;
  int tempo, m = 30;
  float totalMensal[m], totalDiario = 0, totalMensal2 = 0;
  float valor;
for(int i = 0;i < m;i++){stop = 0;totalDiario = 0;
    while(stop != 1){
   
      printf("\nDigite a placa do veiculo no formato (xxx-0000): ");
      scanf("%s", &placa[stop]);
      getchar();

      printf("Digite a hora de chegada no formato(00:00): ");
      scanf("%d:%d", &horario_entrada, & minuto_de_entrada);

  
      printf("Digite a hora de saida no formato(00:00): ");
      scanf("%d:%d", &horario_saida, &minuto_de_saida);

      if( minuto_de_entrada > minuto_de_saida){
       minuto_de_entrada += 60;
      horario_entrada--;
      }
      tempo = (horario_saida - horario_entrada)*60;
      tempo += (minuto_de_saida -  minuto_de_entrada);
      valor = tempo * 0.05;
    
      printf("\nO valor a ser pago referente ao veiculo de placa %s é %.2f.\n", placa, valor);

      totalDiario += valor;
      printf("\nDeseja encerrar o dia? Digite (1) para encerrar ou (o) para continuar: ");
      scanf("%d", &stop);
      }

printf("\nO valor recebido no dia e %.2f\n", totalDiario);
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

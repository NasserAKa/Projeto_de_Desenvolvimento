#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n = 1;
  char placa[n];
  int stop = 0;
  int hr, min;
  int hrs, mins;

  while(stop != 1){
   
      printf("\nDigite a placa do veiculo no formato (xxx-0000): ");
      scanf("%s", &placa[stop]);
      getchar();

      printf("Digite a hora de chegada no formato(00:00): ");
      scanf("%d:%d", &hr, &min);

  
      printf("Digite a hora de saída no formato(00:00): ");
      scanf("%d:%d", &hrs, &mins);
    
    printf("\nDeseja encerrar o dia? Digite (1) e para continuar digite (0):");
      scanf("%d", &stop);
      }
  return 0;
    }

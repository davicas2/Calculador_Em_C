#include <stdio.h>

void DecimalParaBinario(int c){

  int binario[8];
  int i = 0;

  if(c==0){
    printf("Reposta: 0\n");
    return;
  }

  if(c > 1)

  while(c>0){
    binario[i] = c % 2;
    c = c / 2;
    i++;
  }
  printf("Repsota:");
  for (int j = i - 1; j >= 0; j--){
    printf("%d", binario[j]);
  }
  printf("\n\n");
}

void DecimalParaOcta(int c){

  int octa[16];
  int i = 0;

  if(c==0){
    printf("Reposta: 0\n");
    return;
  }

  if(c > 1)

  while(c>0){
    octa[i] = c % 8;
    c = c / 8;
    i++;
  }
  printf("Repsota:");
  for (int j = i - 1; j >= 0; j--){
    printf("%d", octa[j]);
  }
  printf("\n\n");
}

int main(void) {

  int a = 0, b, c, d;
  int respb = 0;

  while(a!=4){
  printf("Qual operação voce deseja fazer\n1-De base 2 para outra base\n2- De base 10 para base com sinal com 16 bits(complemento 2)\n3-Float e Double\n4-Sair\n");
  scanf("%d", &a);

  if (a == 1){
    printf("Qual base voce deseja escolher\n1-Binario(Base 2 )\n2-Octa(Base 8)\n3-Hexa(Base 16)\n4-Codigo BCD\n");
    scanf("%d", &b);
    if(b==1){
      printf("Qual o numero que deseja converter\n");
      scanf("%d", &c);
      DecimalParaBinario(c); 
      }
    if(b==2){
      printf("Qual o numero deseja converter\n");
      scanf("%d" , &c);
      DecimalParaOcta(c);
    }
    }
  if(a==4){
    break;
  }
  }
} 

#include <stdio.h>

void DecimalParaBinario(int c){

  int binario[32];
  int i = 0;

  if(c==0){
    printf("Reposta: 0\n");
    return;
  }

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

  int octa[32];
  int i = 0;

  if(c==0){
    printf("Reposta: 0\n");
    return;
  }

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

void DecimalParaHexa(int c){

  char octa[32];
  int i = 0;

  if(c==0){
    printf("Reposta: 0\n");
    return;
  }

  while(c>0){
    int resp = c % 16;  
    if (resp < 10) {
      octa[i] = '0' + resp;  
    } else {
      octa[i] = 'A' + (resp - 10);  
    }
    c = c / 16;
    i++;
    }

  

  printf("Repsota:");

  for (int j = i - 1; j >= 0; j--){
    printf("%c", octa[j]);
  }
  printf("\n\n");
}

void DecimalParaBCD(int c) {
    int bcd[40];
    int i = 0;

    if (c == 0) {
        printf("Resposta: 0000\n");
        return;
    }

    while (c > 0) {
        int resp = c % 10;
        c = c / 10;
        for (int j = 3; j >= 0; j--) {
            if (resp % 2 == 1) {
                bcd[i++] = 1; 
            } else {
                bcd[i++] = 0; 
            }
            resp /= 2; 
        }
    }

    printf("Resposta: ");
    for (int j = i - 1; j >= 0; j--) { 
        printf("%d", bcd[j]); 
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
    if(b==3){
      printf("Qual o numero deseja converter\n");
      scanf("%d" , &c);
      DecimalParaHexa(c);
    }
    if(b==4){
      printf("Qual o numero deseja converter\n");
      scanf("%d" , &c);
      DecimalParaBCD(c);
    }
  }
    
  if(a==4){
    break;
  }
    
  }    
} 

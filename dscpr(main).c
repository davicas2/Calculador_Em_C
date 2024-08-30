#include <stdio.h>

void DecimalParaBinario(int c) {
    int binario[32];
    int i = 0;

    if (c == 0) {
        printf("Resposta: 0\n");
        return;
    }

    while (c > 0) {
        binario[i] = c % 2;
        c = c / 2;
        i++;
    }
    printf("Resposta: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

void DecimalParaOcta(int c) {
    int octa[32];
    int i = 0;

    if (c == 0) {
        printf("Resposta: 0\n");
        return;
    }

    while (c > 0) {
        octa[i] = c % 8;
        c = c / 8;
        i++;
    }
    printf("Resposta: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octa[j]);
    }
    printf("\n\n");
}

void DecimalParaHexa(int c) {
    char hexa[32];
    int i = 0;

    if (c == 0) {
        printf("Resposta: 0\n");
        return;
    }

    while (c > 0) {
        int resp = c % 16;
        if (resp < 10) {
            hexa[i] = '0' + resp;
        } else {
            hexa[i] = 'A' + (resp - 10);
        }
        c = c / 16;
        i++;
    }

    printf("Resposta: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
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
            bcd[i++] = (resp % 2);
            resp /= 2;
        }
    }

    printf("Resposta: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bcd[j]);
    }
    printf("\n\n");
}

void DecimalParaComplemento2(int c) {
    int bits = 16;
    int binario[16];

    if (c < 0) {
        c = (1 << bits) + c;
    }

    for (int i = bits - 1; i >= 0; i--) {
        binario[i] = c % 2;
        c = c / 2;
    }

    printf("Resposta (complemento a 2): ");
    for (int i = 0; i < bits; i++) {
        printf("%d", binario[i]);
    }
    printf("\n\n");
}


    printf("\n");

    // Separar e imprimir os campos
    int sinal = (bytes[7] >> 7) & 1;
    int expoente = ((bytes[7] & 0x7F) << 4) | (bytes[6] >> 4);
    int fracao = ((bytes[6] & 0x0F) << 16) | (bytes[5] << 8) | bytes[4];

    printf("  Sinal: %d\n", sinal);
    printf("  Expoente: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf("\n");

    printf("  Fração: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf("\n\n");
}

int main(void) {
    int escolha = 0, base;
    int numeroInteiro;
    float numeroFloat;
    double numeroDouble;

    while (escolha != 4) {
        printf("Escolha a operação desejada:\n");
        printf("1 - Converter de base 10 para outra base\n");
        printf("2 - Converter de base 10 para base com sinal com 16 bits (complemento 2)\n");
        printf("3 - Converter e exibir float e double\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Escolha a base desejada:\n");
            printf("1 - Binário (Base 2)\n");
            printf("2 - Octal (Base 8)\n");
            printf("3 - Hexadecimal (Base 16)\n");
            printf("4 - Código BCD\n");
            scanf("%d", &base);
            printf("Digite o número que deseja converter:\n");
            scanf("%d", &numeroInteiro);

            switch (base) {
                case 1:
                    DecimalParaBinario(numeroInteiro);
                    break;
                case 2:
                    DecimalParaOcta(numeroInteiro);
                    break;
                case 3:
                    DecimalParaHexa(numeroInteiro);
                    break;
                case 4:
                    DecimalParaBCD(numeroInteiro);
                    break;
                default:
                    printf("Opção inválida.\n\n");
            }
        } else if (escolha == 2) {
            printf("Digite o número que deseja converter:\n");
            scanf("%d", &numeroInteiro);
            DecimalParaComplemento2(numeroInteiro);
        }  else if (escolha == 4) {
            printf("Sair\n");
            break;
        } else {
            printf("Opção inválida.\n\n");
        }
    }

    return 0;
}

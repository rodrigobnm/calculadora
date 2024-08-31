// ALUNO: RODRIGO BARRETO NUNES DE MIRANDA
// atividade da calculadora
// OBS: Código feito no replit, por conta disso os commits feitos juntos.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// parte 1 (26.08.2024) . 17:00
void converterParaBinario(int numero) {
    int binario[32];
    int i = 0;
    
    printf("Convertendo %d para binario:\n", numero);
    
    while (numero > 0) {
        binario[i] = numero % 2;
        printf("%d / 2 = %d, resto = %d\n", numero, numero / 2, binario[i]);
        numero = numero / 2;
        i++;
    }

    printf("Resultado em binario: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void converterParaOctal(int numero) {
    int octal[32];
    int i = 0;
    
    printf("Convertendo %d para octal:\n", numero);
    
    while (numero > 0) {
        octal[i] = numero % 8;
        printf("%d / 8 = %d, resto = %d\n", numero, numero / 8, octal[i]);
        numero = numero / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void converterParaHexadecimal(int numero) {
    char hexadecimal[32];
    int i = 0;
    
    printf("Convertendo %d para hexadecimal:\n", numero);
    
    while (numero > 0) {
        int resto = numero % 16;
        hexadecimal[i] = (resto < 10) ? (resto + '0') : (resto - 10 + 'A');
        printf("%d / 16 = %d, resto = %c\n", numero, numero / 16, hexadecimal[i]);
        numero = numero / 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void converterParaBCD(int numero) {
    int bcd[16];
    int i = 0;

    printf("Convertendo %d para BCD:\n", numero);

    while (numero > 0) {
        int digito = numero % 10;
        printf("Dígito %d: ", digito);
        for (int j = 3; j >= 0; j--) {
            bcd[i++] = (digito >> j) & 1;
            printf("%d", (digito >> j) & 1);
        }
        printf("\n");
        numero = numero / 10;
    }
    printf("Resultado em BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bcd[j]);
    }
    printf("\n");
}

// parte 2 (27.08.2024) . 16:00
void converterParaComplemento2(int numero) {
    int complemento2[16];
    int negativo = 0;
    if (numero < 0) {
        negativo = 1;
        numero = abs(numero);
    }
    int i = 0;


    printf("Convertendo %d para complemento a 2 (16 bits):\n", numero);


    while (numero > 0) {
        complemento2[i] = numero % 2;
        printf("%d / 2 = %d, resto = %d\n", numero, numero / 2, complemento2[i]);
        numero = numero / 2;
        i++;
    }


    while (i < 16) {
        complemento2[i] = 0;
        i++;
    }


    if (negativo) {
        printf("Invertendo bits para complemento de 2:\n");
        for (int j = 0; j < 16; j++) {
            complemento2[j] = complemento2[j] == 0 ? 1 : 0;
        }

        printf("Adicionando 1 ao valor invertido:\n");
        int c = 1;
        for (int j = 0; j < 16; j++) {
            int soma = complemento2[j] + c;
            complemento2[j] = soma % 2;
            c = soma / 2;
            printf("%d", complemento2[j]);
        }
        printf("\n");
    }


    printf("Resultado em complemento a 2: ");
    for (int j = 15; j >= 0; j--) {
        printf("%d", complemento2[j]);
    }
    printf("\n");
}

// Parte 3 (30.08.2024) . 21:30
void exibirBitsFloat(float numero) {
    unsigned int bits;
    unsigned int sinal, expoente, fracao;

    bits = *((unsigned int*)&numero);

    sinal = (bits >> 31) & 0x1;
    expoente = (bits >> 23) & 0xFF;
    fracao = bits & 0x7FFFFF;

    printf("Sinal: %u\n", sinal);
    printf("Expoente: %u (sem vies)\n", expoente);
    printf("Expoente com vies: %d\n", expoente - 127);
    printf("Fracao: 0x%X\n", fracao);
}

void exibirBitsDouble(double numero) {
    unsigned long long bits;
    unsigned long long sinal, expoente, fracao;

    bits = *((unsigned long long*)&numero);

    sinal = (bits >> 63) & 0x1;
    expoente = (bits >> 52) & 0x7FF;
    fracao = bits & 0xFFFFFFFFFFFFF;

    printf("Sinal: %llu\n", sinal);
    printf("Expoente: %llu (sem vies)\n", expoente);
    printf("Expoente com vies: %lld\n", expoente - 1023);
    printf("Fracao: 0x%llX\n", fracao);
}


int main() {
    int opcao, numero, repete = 1;

        printf("Digite um numero em base 10: ");
        scanf("%d", &numero);
    while (repete == 1){

        printf("Escolha a conversao desejada:\n");
        printf("1 - Base 2\n");
        printf("2 - Base 8\n");
        printf("3 - Base 16\n");
        printf("4 - Codigo BCD\n");
        printf("5 - Base 2 com sinal (Complemento a 2, 16 bits)\n");
        printf("6 - Converter para float\n");
        printf("7 - Converter para double\n");
        printf("8 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                converterParaBinario(numero);
                break;
            case 2:
                converterParaOctal(numero);
                break;
            case 3:
                converterParaHexadecimal(numero);
                break;
            case 4:
                converterParaBCD(numero);
                break;
            case 5:
                converterParaComplemento2(numero);
                break;
            case 6: {
                float numFloat = (float)numero;
                printf("Convertendo %d para float:\n", numero);
                exibirBitsFloat(numFloat);
                break;
            }
            case 7: {
                double numDouble = (double)numero;
                printf("Convertendo %d para double:\n", numero);
                exibirBitsDouble(numDouble);
                break;
            }
            case 8:
                repete = 2;
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

// ALUNO: RODRIGO BARRETO NUNES DE MIRANDA
// atividade da calculadora

#include <stdio.h>
#include <stdlib.h>

// parte 1 (26.08.2024) .
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

int main() {
    int opcao, numero, repete = 1;

    while (repete == 1){
        printf("Digite um numero em base 10: ");
        scanf("%d", &numero);

        printf("Escolha a conversao desejada:\n");
        printf("1 - Base 2\n");
        printf("2 - Base 8\n");
        printf("3 - Base 16\n");
        printf("4 - Codigo BCD\n");
        printf("5 - Sair\n");
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
                repete = 2;
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

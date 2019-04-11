#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l1,l2,l3;
}NUM;

int* retornaColuna(int num){
    int* col = (int*) malloc(sizeof(int) * 3);
    switch(num){
    case 0:
        col[0] = 1;
        col[1] = 6;
        col[2] = 5;
    break;
    case 1:
        col[0] = 0;
        col[1] = 2;
        col[2] = 2;
    break;
    case 2:
        col[0] = 1;
        col[1] = 3;
        col[2] = 4;
    break;
    case 3:
        col[0] = 1;
        col[1] = 3;
        col[2] = 3;
    break;
    case 4:
        col[0] = 0;
        col[1] = 5;
        col[2] = 2;
        break;
    case 5:
        col[0] = 1;
        col[1] = 4;
        col[2] = 3;
        break;
    case 6:
        col[0] = 1;
        col[1] = 4;
        col[2] = 5;
        break;
    case 7:
        col[0] = 1;
        col[1] = 2;
        col[2] = 2;
        break;
    case 8:
        col[0] = 1;
        col[1] = 5;
        col[2] = 5;
        break;
    case 9:
        col[0] = 1;
        col[1] = 5;
        col[2] = 3;
        break;
    default:
        break;
    }

    return col;
}

int qntDigits(int num){
    int digits = 0;
    //int divisao = num;
    while(num >= 1){
        digits++;
        num = num/10;
    }
    return digits;
}

int* retornaDigitos(int num, int quant){
    int* digts = (int*)malloc(sizeof(int)*quant);
    int i=0;
    int resto;
    while(num >= 1){
        resto = num%10;
        num = num/10;
        digts[quant-i-1]= resto;
        i++;
    }

    return digts;
}

int** retornaLCDNumber(int num){
    int quant = qntDigits(num);
    int** mat = (int**) malloc(sizeof(int*)*quant);
    for(int i = 0; i < quant; i++){
        mat[i] = (int*)malloc(sizeof(int)*3);
    }

    int* digitos = retornaDigitos(num, quant);

    for(int i = 0; i < quant; i++){
        mat[i] = retornaColuna(digitos[i]);
    }

    return mat;
}

void printLine(int num){
    switch(num){
        case 0:
            printf("   ");
            break;
        case 1:
            printf("._.");
            break;
        case 2:
            printf(" .|");
            break;
        case 3:
            printf("._|");
            break;
        case 4:
            printf("|_.");
            break;
        case 5:
            printf("|_|");
            break;
        case 6:
            printf("| |");
            break;
        default:
            break;
    }
}

void printarLCD(int** mat, int quant){
    for(int i = 0; i < 3; i++){
        for(int j=0; j< quant;j++){
            printLine(mat[j][i]);
        }
        printf("\n");
    }

}

int main()
{
    int** mat;
    int number;
    scanf("%d", &number);

    mat = retornaLCDNumber(number);

    printarLCD(mat, qntDigits(number));

}

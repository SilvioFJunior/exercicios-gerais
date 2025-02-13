#include "data.h"

int verificaDataValida(int dia, int mes, int ano){
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if (dia >= 1 && dia <= 31){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if (dia >= 1 && dia <= 30){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (mes == 2 && verificaBissexto(ano)){
        if (dia >= 1 && dia <= 29){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (mes == 2 && !verificaBissexto(ano)){
        if (dia >= 1 && dia <= 29){
            return 1;
        }
        else {
            return 0;
        }
    }
}

void imprimeMesExtenso(int mes){
    if (mes == 1){
        printf("Janeiro");
    }
    else if (mes == 2){
        printf("Fevereiro");
    }
    else if (mes == 3){
        printf("Marco");
    }
    else if (mes == 4){
        printf("Abril");
    }
    else if (mes == 5){
        printf("Maio");
    }
    else if (mes == 6){
        printf("Junho");
    }
    else if (mes == 7){
        printf("Julho");
    }
    else if (mes == 8){
        printf("Agosto");
    }
    else if (mes == 9){
        printf("Setembro");
    }
    else if (mes == 10){
        printf("Outubro");
    }
    else if (mes == 11){
        printf("Novembro");
    }
    else if (mes == 12){
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d", ano);
}

int verificaBissexto(int ano){
    if (ano % 4 == 0){
        return 1;
    }
    else {
        return 0;
    }
}

int numeroDiasMes(int mes, int ano){
    if (mes == 1){
        return 31;
    }
    else if (mes == 3){
        return 31;
    }
    else if (mes == 4){
        return 30;
    }
    else if (mes == 5){
        return 31;
    }
    else if (mes == 6){
        return 30;
    }
    else if (mes == 7){
        return 31;
    }
    else if (mes == 8){
        return 31;
    }
    else if (mes == 9){
        return 30;
    }
    else if (mes == 10){
        return 31;
    }
    else if (mes == 11){
        return 30;
    }
    else if (mes == 12){
        return 31;
    }
    else if (mes == 2 && verificaBissexto(ano)){
        return 29;
    }
    else if (mes == 2 && !verificaBissexto(ano)){
        return 28;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if (ano1 > ano2){
        return 1;
    }
    else if (ano1 == ano2 && mes1 > mes2){
        return 1;
    }
    else if (ano1 == ano2 && mes1 == mes2 && dia1 > dia2){
        return 1;
    }
    else {
        return -1;
    }
}
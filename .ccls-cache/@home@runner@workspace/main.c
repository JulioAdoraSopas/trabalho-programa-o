#include <stdio.h>
#include <stdlib.h>

char jogo [3][3];
char jogador1[50], jogador2[50];

void inicializarMatriz(){
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j < 3; j++){
            jogo[i][j] = 'a';
        }
    }

}

int eValido(char letra){

if (letra == 'x' || letra == '0')
    return 1;
else
    return 0;
}

int coordenadaEhValida (int x, int y){
    if(x >= 0 && x < 3) {
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}
    int posicaoVazia(int x, int y){
        if(jogo [x][y] !='x' && jogo [x][y] !='0')
            return 1;
        return 0;
    }
//função 1
int ganhouLinhas(){
    int i, j, igual = 1;
    for(i=0; i < 3; i++){
        for (j = 0; j < 2; j++){
            if(eValido (jogo[i][j])) && jogo[i][j] == jogo[i][j+1])
              igual ++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}
//função 2
int ganhouColunas(){
    int i, j, igual = 1;
    for(i=0; i < 3; i++){
        for (j = 0; j < 2; j++){
            if(eValido (jogo[j][i])) && jogo[j][i] == jogo[j][i+1])
              igual ++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}
//função 3
int ganhoudiagprincipal(){
    int i, igual = 1;
    for(i=0;1<2; i++){
        if(eValido(jogo[1][1])&& jogo[i][i] == jogo [i+1][i+1])
        igual++;
    }
    if(igual == 3)
        return 1;
    else
         return 0;
}
//função 4
int ganhoudiagsecundaria(){
    int i, igual = 1;
    for(i=0;1<2; i++){
        if(eValido(jogo[i][3-i-1])&& jogo[i][3-1-1] == jogo [i+1][3-i-2])
        igual++;
    }
    if(igual == 3)
        return 1;
    else
         return 0;
}
void imprimir(){
    int l, c;
    printf("\t0 1 2\n");
    for(1=0 < 3; l ++){
        print("%d", l);
        for (c=0; < 3; c++){
            if(eValido(jogo[l][c])){
                if(c<2)
                printf(" %c |", jogo[l][c]);
           else 
                printf(" %c  ", jogo[l][c]);
            }
        else {
            if(c<2)
              printf("   |");
        else  
              printf("    ");
        }
        printf("\n\t----------\n");
    }
}

void jogar (){
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do{
    do{
        imprimir();
        printf("Digite a coordenada que deseja jogar: ");
        scanf("%d%d", &x, &y);
        valida = coordenadaEhValida(x, y);
        if(valida == 1)
            valida += posicaoVazia(x, y);
    } while(valida != 2);

    if(ordem == 1)
    jogo [x][y]='x';
    else
    jogo [x][y]='0';

    jogadas++;

    ordem++;
    if(ordem == 3)
        ordem = 1;
    ganhou += ganhouLinhas ();
    ganhou += ganhouColunas ();
    ganhou += ganhoudiagprincipal ();
    ganhou += ganhoudiagsecundaria ();


    }while(ganhou==0 && jogadas < 9);
    if (ganhou !=0){
        if (ordem - 1 == 1)
      printf("\nParabens, %s, voce venceu!...\n\n,", jogador1);
    else 
        rintf("\nParabens, %s, voce venceu!...\n\n,", jogador2);
    }
    else 
     printf("\nNinguem ganhou...\n\n");




}

int main(){

    int op;

printf("Jogador 1. Digite seu nome: ");
fgets(jogador1, 50, stdin);

printf("Jogador 2. Digite seu nome: ");
fgets(jogador2, 50, stdin);

do{
inicializarMatriz();
jogar();
printf("Deseja jogar novamente?\n1 - Sim\n 2- Nao\n");
scanf("%d", &op);

}while(op == 1);

return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao! *\n");
    printf("*******************************************\n\n");

    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    int numero_secreto = numero_grande % 100;

    int chute;
    int ganhou = 0;
    int tentativas = 1;
    int pontos = 1000;

    while (ganhou == 0) {
        printf("\nTentativa %d\n", tentativas);
        printf("Qual eh o seu chute? ");
        scanf_s("%d", &chute);

        while (chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n\n");
            printf("Qual eh o seu chute? ");
            scanf_s("%d", &chute);
        }

        if (chute == numero_secreto) {
            printf("Parabens, voce acertou!\n");
            printf("Jogue de novo, voce eh um bom jogador!\n");
            ganhou = 1;
            break;

        }
        else if (chute > numero_secreto) {
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else {
            printf("Seu chute foi menor que o numero secreto!\n");
        }
        printf("Mas nao desanime, tente novamente!\n");
        tentativas++;

        int pontos_perdidos = tentativas * 10;
        pontos = pontos - pontos_perdidos;
    }

    printf("\nVoce finalizou com %d pontos!", pontos);
    printf("\nVoce acertou em %d tentativas!\n", tentativas);
    printf("Fim de jogo!\n");
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int chute, numero_secreto;
int ganhou = 0;
int tentativas = 1;
int pontos = 1000;

int cria_numero() {
    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    numero_secreto = numero_grande % 100;
    printf("Numero: %d", numero_secreto);
}

int chuta() {
    cria_numero();
    while (ganhou == 0) {
        printf("\nTentativa %d\n", tentativas);

        while (1) {
            printf("Qual eh o seu chute? ");
            if (scanf_s("%d", &chute) != 1) {
                printf("Entrada invalida! Digite apenas numeros.\n");

                while (getchar() != '\n');
                continue;
            }

            if (chute < 0) {
                printf("Voce nao pode chutar numeros negativos!\n");

                continue;
            }
            break;
        }

        if (chute == numero_secreto) {
            system("cls");

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
}

int main() {
    int x = 0;
    int opcao;

    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao! *\n");
    printf("*******************************************\n\n");

    do {
        printf("Digite o numero conforme o menu:\n");
        printf("0 para iniciar o jogo\n");
        printf("1 para ver as regras do jogo\n");
        printf("2 para fechar o jogo\n");

        if (scanf_s("%d", &opcao) != 1) {
            printf("\nEntrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
        case 0:
            chuta(&numero_secreto);

            printf("\nVoce finalizou com %d pontos.", pontos);
            printf("\nVoce acertou em %d tentativas.\n\n", tentativas);

            tentativas = 1;
            ganhou = 0;
            pontos = 1000;
            chute;

            break;
        case 1:
            system("cls");

            printf("[1] O numero secreto eh um numero entre 0 e 100.\n");
            printf("[2] O jogador deve chutar numeros ate chegar no numero secreto.\n");
            printf("[3] O jogador comeca o jogo com 1000 pontos, que diminuirao conforme erra os chutes.\n\n");

            break;
        case 2:
            x = 1;

            break;
        default:
            printf("\nOpcao invalida.\n");
        }
    } while (x == 0);

    return 0;
}
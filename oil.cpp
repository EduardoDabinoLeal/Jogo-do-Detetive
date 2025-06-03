#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcao = 0;
    int tentativas = 5;
    int pistaEscolhida;
    char suspeito[20];
    int acertou = 0;


    char culpado[] = "Giovane";

    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("      JOGO: DETETIVE - ENCONTRE O CULPADO!\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("Suspeitos:\n");
    printf("1 - Joao (usa chapeu, 30 anos, baixo)\n");
    printf("2 - Nicole (usa vestido, 34 anos, baixo)\n");
    printf("3 - Ney (usa oculos, 32 anos, alto)\n");
    printf("4 - Ana (usa toca, 29 anos, baixo)\n");
    printf("5 - Guilherme (usa bone, 35 anos,alto)\n");
    printf("6 - Luiza (usa brinco, 31 anos, baixo)\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");

    while(tentativas > 0 && acertou == 0) {
        printf("\nVoce tem %i tentativa(s) restante(s).\n", tentativas);
        printf("Escolha uma opcao:\n");
        printf("1 - Pedir uma pista\n");
        printf("2 - Tentar adivinhar quem eh o culpado\n");
        printf("3 - Sair do jogo\n");
        printf("Digite sua opcao: ");
        scanf("%i", &opcao);

        switch(opcao) {
            case 1:
                printf("\nExistem 3 pistas disponiveis. Escolha o numero da pista (1, 2 ou 3): ");
                scanf("%i", &pistaEscolhida);

                if(pistaEscolhida == 1) {
                    printf("\n~~Pista 1: O culpado tem mais de 30 anos.~~\n");
                } else if(pistaEscolhida == 2) {
                    printf("\n~~Pista 2: O culpado usa acessorio de cabeça.~~\n");
                } else if(pistaEscolhida == 3) {
                    printf("\n~~Pista 3: O culpado eh alto.~~\n");
                } else {
                    printf("Pista invalida! Escolha 1, 2 ou 3.\n");
                }
                break;

            case 2:
                printf("\nDigite o nome do suspeito (letras iniciais maiusculas, ex: Joao): ");
                scanf("%s", suspeito);

                if(strcmp(suspeito, culpado) == 0) {
                    printf("\nParabens! Voce acertou. O culpado eh %s!\n", culpado);
                    acertou = 1;
                } else {
                    printf("\nNao eh %s. Tente novamente!\n", suspeito);
                    tentativas--;
                }
                break;

            case 3:
                printf("\nSaindo do jogo... Ate mais!\n");
                tentativas = 0;
                break;

            default:
                printf("\nOpcao invalida! Escolha 1, 2 ou 3.\n");
                break;
        }
    }

    if(acertou == 0 && tentativas == 0) {
        printf("\nSuas tentativas acabaram. O culpado era %s. Fim de jogo!\n", culpado);
    }

    return 0;
}

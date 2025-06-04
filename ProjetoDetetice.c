#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração das variáveis
    int opcao = 0;
    int tentativas = 5;
    int pistaEscolhida;
    char suspeito[20];
    int acertou = 0;

    // Nome do culpado
    char culpado[] = "Giovane";

    // Início do jogo
    printf("======================================================\n");
    printf("      JOGO: DETETIVE - ENCONTRE O CULPADO!\n");
    printf("======================================================\n");
    printf("Suspeitos:\n");
    printf("1 - Joao (usa chapeu, 25 anos)\n");
    printf("2 - Gabriela (usa vestido, 20 anos)\n");
    printf("3 - Ricardo (usa oculos, 50 anos)\n");
    printf("4 - Roberta (usa toca, 35 anos)\n");
    printf("5 - Giovane (usa bone, 30 anos)\n");
    printf("6 - Joana (usa brinco, 30 anos)\n");
    printf("======================================================\n");

    // Loop principal do jogo
    while(tentativas > 0 && acertou == 0) {
        printf("\nVoce tem %i tentativa(s) restante(s).\n", tentativas);
        printf("\nEscolha uma opcao:\n\n");
        printf("1 - Pedir uma pista\n");
        printf("2 - Tentar adivinhar quem eh o culpado\n");
        printf("3 - Sair do jogo\n");
        printf("\nDigite sua opcao: ");
        scanf("%i", &opcao);

        switch(opcao) {
            case 1:
                printf("\nExistem 3 pistas disponiveis. Escolha o numero da pista (1, 2 ou 3): ");
                scanf("%i", &pistaEscolhida);

                if(pistaEscolhida == 1) {
                    printf("\n~~Pista 1: O culpado tem mais de 25 anos.~~\n");
                } else if(pistaEscolhida == 2) {
                    printf("\n~~Pista 2: O culpado usa acessorio de cabeça.~~\n");
                } else if(pistaEscolhida == 3) {
                    printf("\n~~Pista 3: O nome do culpado comeca com G.~~\n");
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

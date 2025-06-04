#include <stdio.h>
#include <stdlib.h>

int compararStrings(char str1[], char str2[]) {
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0') {
        if(str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int opcao = 0;
    int tentativas = 5;
    int pistaEscolhida;
    char suspeito[20];
    int acertou = 0;

    char culpado[] = "Ney";
//entrada
    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("      JOGO: DETETIVE - ENCONTRE O CULPADO!\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");

//desafio
    printf("__________________________________");
    printf("\n-Descubra quem que traiu a Luiza.-\n");
    printf("----------------------------------");
//suspeitos
    printf("\nSuspeitos:\n");
    printf("1 - Joao (usa chapeu, 30 anos, baixo, 1.70m, tem barba)\n");
    printf("2 - Nicole (usa vestido, 34 anos, baixo, 1.72m, nao tem barba)\n");
    printf("3 - Ney (usa boina, 32 anos, alto, 1.85m, tem barba)\n");
    printf("4 - Ana (usa toca, 29 anos, baixa, 1.50m, nao tem barba)\n");
    printf("5 - Guilherme (usa bone, 35 anos, alto, 1.82m, nao tem barba)\n");
    printf("6 - Pibba ( usa durag , 31 anos, medio, 1.75m, tem barba)\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::\n");

    while(tentativas > 0 && acertou == 0) {
        printf("\nVoce tem %i tentativa restante(s).\n", tentativas);
        printf("\nEscolha uma opcao:\n");
        printf("1 - Pedir uma pista\n");
        printf("2 - Tentar adivinhar quem eh o culpado\n");
        printf("3 - Sair do jogo\n");
        printf("Digite sua opcao: ");
        scanf("%i", &opcao);

        switch(opcao) {
            case 1:
                printf("\nExistem 4 pistas disponiveis. Escolha o numero da pista (1, 2, 3 ou 4): ");
                scanf("%i", &pistaEscolhida);

                if(pistaEscolhida == 1) {
                    printf("\n~~Pista 1: O culpado tem mais de 30 anos.~~\n");
                } else if(pistaEscolhida == 2) {
                    printf("\n~~Pista 2: O culpado usa acessorio de cabeca.~~\n");
                } else if(pistaEscolhida == 3) {
                    printf("\n~~Pista 3: O culpado eh alto.~~\n");
                } else if(pistaEscolhida ==4)  {
                    printf("\n~~Pista 4: O culpado tem barba.~~\n");
                } else if(pistaEscolhida != 1, 2, 3, 4){
                    printf("Pista invalida! Escolha 1, 2, 3 ou 4.\n");
                }
                tentativas--;
                break;

            case 2:
                printf("\nDigite o nome do suspeito (letras iniciais maiusculas, ex: Joao): ");
                scanf("%s", suspeito);

                if(compararStrings(suspeito, culpado) == 1) {
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

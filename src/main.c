#include <stdio.h>

int mensagemInicial(void) {
    int continuar;

    printf("Ola, digite 1 para iniciar um pedido\n");
    printf("Digite 0 para encerrar a sessao\n");
    scanf("%d", &continuar);

    return continuar;
}

float informarDistancia(void) {
    float distancia;

    printf("\nIndique a distancia da entrega em km: ");
    scanf("%f", &distancia);

    return distancia;
}

float informarPeso(void) {
    float peso;

    printf("\nIndique o peso em kg: ");
    scanf("%f", &peso);

    return peso;
}

int exibirModalidade(void) {
    int modalidade;

    printf("\nIndique a modalidade:\n");
    printf("1 - Economica - sem valor adicional\n");
    printf("2 - Expressa - 15%% adicional\n");
    printf("3 - Prioritaria - 30%% adicional\n");
    printf("Modalidade desejada: ");
    scanf("%d", &modalidade);

    return modalidade;
}

void exibirMensagemProtecao(void) {
    printf("\nDeseja protecao adicional?\n");
    printf("0 - Nao\n");
    printf("1 - Sim (R$ 7,50)\n");
}

int main(void) {
    int continuar;
    int modalidade;
    float distancia;
    float peso;

    do {
        continuar = mensagemInicial();

        if (continuar == 1) {
            distancia = informarDistancia();
            peso = informarPeso();
            modalidade = exibirModalidade();

            exibirMensagemProtecao();
        }

    } while (continuar == 1);

    printf("\nAtendimento encerrado.\n");

    return 0;
}



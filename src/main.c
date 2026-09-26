#include <stdio.h>


#define VALOR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA 4.00

int mensagemInicial(void) {
    int continuar;

    do {
        printf("Ola, digite 1 para iniciar um pedido\n");
        printf("Digite 0 para encerrar a sessao\n");
        scanf("%d", &continuar);

        if (continuar != 0 && continuar != 1) {
            printf("Digite uma opcao valida.\n");
        }

    } while (continuar != 0 && continuar != 1);

    return continuar;
}

float informarDistancia(void) {
    float distancia;

    do {
        printf("\nIndique a distancia da entrega em km: ");
        scanf("%f", &distancia);
        if (distancia <= 0) {
            printf("Indique uma distancia valida (maior que zero).\n");
        }
    } while (distancia <= 0);

    return distancia;
}

float calcularValorBase(float distancia) {
    float valorBase; 
    if (distancia > 0 && distancia <= 5) {
        valorBase = 8.0;
    } else if (distancia > 5 && distancia <= 15) {
        valorBase = 12.0;
    } else if (distancia > 15 && distancia <= 30) {
        valorBase = 18.0;
    } else {
        valorBase = 25.0;
    }
    
    return valorBase;
}

float calcularDistancia(float distancia, float valorBase) {
    return valorBase + (distancia * VALOR_KM);
}

float informarPeso(void) {
    float peso;

    do {
        printf("\nIndique o peso em kg: ");
        scanf("%f", &peso);
        if (peso <= 0) {
            printf("Informe um peso acima de 0 kg.\n");
        }
    } while (peso <= 0);

    return peso;
}

float calcularPeso(float peso, float subTotalInicial) {
    float adicionalPeso;
    
    if (peso <= 2) {
        adicionalPeso = 0;
    } else if (peso <= 5) {
        adicionalPeso = subTotalInicial * 0.05;
    } else if (peso <= 10) {
        adicionalPeso = subTotalInicial * 0.10;
    } else {
        adicionalPeso = subTotalInicial * 0.20;
    }
    
    return adicionalPeso;
}

int exibirModalidade(void) {
    int modalidade;

    do {
        printf("\nIndique a modalidade:\n");
        printf("1 - Economica - sem valor adicional\n");
        printf("2 - Expressa - 15%% adicional\n");
        printf("3 - Prioritaria - 30%% adicional\n");
        printf("Modalidade desejada: ");
        scanf("%d", &modalidade);
        
        if (modalidade < 1 || modalidade > 3) {
            printf("Escolha um numero valido para modalidade (1, 2 ou 3).\n");
        }
    } while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

float calcularModalidade(int modalidade, float subTotalInicial) {
    float adicionalModalidade = 0;
    
    switch (modalidade) {
        case 1:
            adicionalModalidade = 0;
            break;
        case 2:
            adicionalModalidade = subTotalInicial * 0.15;
            break;
        case 3:
            adicionalModalidade = subTotalInicial * 0.30;
            break;
    }
    
    return adicionalModalidade;
}

float validaProtecao(void) {
    int protecao;
    float adicionalProtecao = 0;

    do {
        printf("\nDeseja protecao adicional?\n");
        printf("0 - Nao\n");
        printf("1 - Sim (R$ 7,50)\n");
        scanf("%d", &protecao);

        if (protecao != 0 && protecao != 1) {
            printf("Escolha uma opcao valida (0 ou 1).\n");
        }

    } while (protecao != 0 && protecao != 1);

    if (protecao == 1) {
        adicionalProtecao = VALOR_PROTECAO;
    }

    return adicionalProtecao;
}

int calcularAdicionalTentativas(void) {
    int tentativasAdicionais;
    
    do {
        printf("\nIndique a quantidade de tentativas adicionais: ");
        scanf("%d", &tentativasAdicionais);
        if (tentativasAdicionais < 0) {
            printf("Insira um valor maior ou igual a zero.\n");
        }
    } while (tentativasAdicionais < 0);
    
    return tentativasAdicionais * VALOR_TENTATIVA;
}

float calculoSubFinal(float subTotalInicial, float adicionalPeso, float adicionalModalidade, float adicionalProtecao, int adicionalTentativas) {
    return subTotalInicial + adicionalPeso + adicionalModalidade + adicionalProtecao + adicionalTentativas;
}

int continuarPedido(void) {
    int continuar;

    do {
        printf("\nDeseja fazer um novo pedido?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        scanf("%d", &continuar);

        if (continuar != 0 && continuar != 1) {
            printf("Digite uma opcao valida.\n");
        }

    } while (continuar != 0 && continuar != 1);

    return continuar;
}

float verificarMaior(float valorAtual, float maiorValor) {
    if (valorAtual > maiorValor) {
        return valorAtual;
    }
    return maiorValor;
}

float verificarMenor(float valorAtual, float menorValor) {
    if (valorAtual < menorValor) {
        return valorAtual;
    }
    return menorValor;
}

int main(void) {
    int continuar;
    int modalidade;
    float distancia;
    float valorBase;
    float subTotalInicial;
    float peso;
    float adicionalPeso; 
    float adicionalModalidade = 0;
    float adicionalProtecao;
    float subValorFinal;
    int pedidos = 0;
    int adicionalTentativas;
    int totalAdicionalTentativas = 0;
    int contadorEconomico = 0, contadorExpresso = 0, contadorPrioridade = 0;
    float maiorValor = 0, menorValor = 0;
    float valorFinal = 0;
    
    continuar = mensagemInicial();
    
    if (continuar == 1) {  
        do {
            distancia = informarDistancia();
            valorBase = calcularValorBase(distancia);
            subTotalInicial = calcularDistancia(distancia, valorBase);
            
            peso = informarPeso();
            adicionalPeso = calcularPeso(peso, subTotalInicial);
            
            modalidade = exibirModalidade();
            adicionalModalidade = calcularModalidade(modalidade, subTotalInicial);
            
            if (modalidade == 1) {
                contadorEconomico++;
            } else if (modalidade == 2) {
                contadorExpresso++;
            } else {
                contadorPrioridade++;
            }
            
            adicionalProtecao = validaProtecao();
            adicionalTentativas = calcularAdicionalTentativas();
            totalAdicionalTentativas += adicionalTentativas;
            
            subValorFinal = calculoSubFinal(subTotalInicial, adicionalPeso, adicionalModalidade, adicionalProtecao, adicionalTentativas);
            
            printf("\nValor final desse pedido: R$ %.2f\n", subValorFinal);
            
            if (pedidos == 0) {
                maiorValor = subValorFinal;
                menorValor = subValorFinal;
            } else {
                maiorValor = verificarMaior(subValorFinal, maiorValor);
                menorValor = verificarMenor(subValorFinal, menorValor);
            }

            continuar = continuarPedido();
            pedidos++;
            valorFinal += subValorFinal;

        } while (continuar == 1);
    }

    printf("\nAtendimento encerrado.\n");
    
    if (pedidos > 0) {
        printf("\n=== Resumo do atendimento ===\n");
        printf("Quantidade de pedidos realizados: %d\n", pedidos);
        printf("Valor total acumulado de tentativas adicionais: R$ %d,00\n", totalAdicionalTentativas);
        printf("Valor total calculado na sessao: R$ %.2f\n", valorFinal);
        printf("Valor medio das entregas: R$ %.2f\n", valorFinal / pedidos);
        printf("Quantidade de entregas Economicas: %d\n", contadorEconomico);
        printf("Quantidade de entregas Expressas: %d\n", contadorExpresso);
        printf("Quantidade de entregas Prioridade: %d\n", contadorPrioridade);
        printf("Maior valor de entrega encontrado: R$ %.2f\n", maiorValor);
        printf("Menor valor de entrega encontrado: R$ %.2f\n", menorValor);
    } else {
        printf("Nenhum pedido foi realizado nesta sessao.\n");
    }

    return 0;
}

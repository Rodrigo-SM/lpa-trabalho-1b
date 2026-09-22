#include <stdio.h>

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

    printf("\nIndique a distancia da entrega em km: ");
    scanf("%f", &distancia);

    return distancia;
}

float calcularValorBase(float distancia){
	int valorBase; 
	if(distancia > 0 && distancia <= 5){
		valorBase = 8;
	} else if ( distancia > 5 && distancia <= 15){
		valorBase = 12;
	} else if (distancia > 15 && distancia <= 30){
		valorBase = 18;
	} else if( distancia > 30){
		valorBase = 25;
	}
	
	return valorBase;
}

float calcularDistancia(float distancia , int valorBase){
	float subTotalInicial;
	
	subTotalInicial = valorBase + (distancia * 1.2);
	

	return subTotalInicial;
}

float informarPeso(void) {
    float peso;

    printf("\nIndique o peso em kg: ");
    scanf("%f", &peso);

    return peso;
}

float calcularPeso(float peso, float subTotalInicial){
	float adicionalPeso;
	
	if(peso > 0 && peso <= 2){
		adicionalPeso = 0;
	} else if (peso > 2 && peso <= 5){
		adicionalPeso = subTotalInicial * 0.05;
	} else if (peso > 5 && peso <= 10){
		adicionalPeso = subTotalInicial * 0.1;
	} else {
		adicionalPeso = subTotalInicial * 0.2;
	}
	
	return adicionalPeso;
}

int exibirModalidade(void) {
    int modalidade;

    do{
    printf("\nIndique a modalidade:\n");
    printf("1 - Economica - sem valor adicional\n");
    printf("2 - Expressa - 15%% adicional\n");
    printf("3 - Prioritaria - 30%% adicional\n");
    printf("Modalidade desejada: ");
    scanf("%d", &modalidade);
    
    if(modalidade < 1 || modalidade > 3){
    	printf("\nEscolha um numero valido para modalidade\n");
	}
    
	} while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

float calcularModalidade(int modalidade , float subTotalInicial){
	float adicionalModalidade;
	
	switch(modalidade){
		case 1:
			adicionalModalidade = 0;
			break;
		case 2:
			adicionalModalidade = subTotalInicial * 0.15;
			break;
		case 3:
			adicionalModalidade = subTotalInicial * 0.3;
			break;
	}
	
	return adicionalModalidade;
}


float validaProtecao() {
    int protecao;
    float adicionalProtecao = 0;

    do {
        printf("\nDeseja protecao adicional?\n");
        printf("0 - Nao\n");
        printf("1 - Sim (R$ 7,50)\n");
        scanf("%d", &protecao);

        if (protecao > 1 || protecao < 0) {
            printf("Escolha uma opcao valida.\n");
        }

    } while (protecao > 1 || protecao < 0);

    if (protecao == 1) {
        adicionalProtecao = 7.5;
    }

    return adicionalProtecao;
}

float calculoSubFinal (float subTotalInicial , float adicionalPeso , float adicionalModalidade , float adicionalProtecao){
	float subValorFinal = subTotalInicial + adicionalPeso + adicionalModalidade + adicionalProtecao;
	
	return subValorFinal;
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


int main(void) {
    int continuar;
    int modalidade;
    float distancia;
    int valorBase;
    float subTotalInicial;
    float peso;
    float adicionalPeso; 
    float adicionalModalidade = 0;
    float adicionalProtecao;
    float subValorFinal;
    
    
    continuar = mensagemInicial();
    
    
    
	if(continuar == 1){  
    	do {
    				
       
            distancia = informarDistancia();
            valorBase = calcularValorBase(distancia);
            subTotalInicial = calcularDistancia(distancia , valorBase);
            
            
            peso = informarPeso();
           	adicionalPeso = calcularPeso(peso , subTotalInicial);
           	
           	
            modalidade = exibirModalidade();

		
			adicionalModalidade = calcularModalidade(modalidade , subTotalInicial);
           
           
            adicionalProtecao = validaProtecao();
            
            subValorFinal = calculoSubFinal(subTotalInicial , adicionalPeso , adicionalModalidade , adicionalProtecao);
            
            continuar = continuarPedido();
        	
     	}while (continuar == 1);
	}
    printf("\nAtendimento encerrado.\n");
	printf("Valor final %.2f", subValorFinal);

    return 0;
}



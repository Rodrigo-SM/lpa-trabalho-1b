# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição

Este trabalho consiste no desenvolvimento de um programa em linguagem C para simular o cálculo de entregas.

O programa permite cadastrar pedidos de entrega individualmente, informando a distância, o peso, a modalidade, a proteção adicional e a quantidade de tentativas adicionais.

A partir dessas informações, o programa calcula o valor final de cada pedido e, ao final da sessão, apresenta um resumo com os principais dados das entregas realizadas.

## Funcionalidades

* Iniciar ou encerrar uma sessão de atendimento.
* Informar e validar a distância da entrega.
* Calcular o valor-base de acordo com a distância.
* Calcular o subtotal inicial da entrega.
* Informar e validar o peso da entrega.
* Calcular o adicional de acordo com o peso.
* Selecionar e validar a modalidade da entrega.
* Calcular o adicional da modalidade.
* Selecionar proteção adicional.
* Calcular o valor referente à proteção.
* Informar a quantidade de tentativas adicionais.
* Calcular o valor das tentativas adicionais.
* Calcular e exibir o valor final de cada pedido.
* Permitir realizar mais de um pedido na mesma sessão.
* Contabilizar a quantidade de pedidos por modalidade.
* Calcular o valor total acumulado da sessão.
* Calcular o valor médio das entregas.
* Identificar o maior e o menor valor de entrega da sessão.

## Organização da solução

O programa foi dividido em funções, cada uma responsável por uma parte específica do processo de cadastro ou cálculo da entrega.

* `mensagemInicial()` — apresenta o menu inicial e permite iniciar ou encerrar a sessão.
* `informarDistancia()` — solicita e valida a distância da entrega.
* `calcularValorBase()` — determina o valor-base de acordo com a distância.
* `calcularDistancia()` — calcula o subtotal inicial utilizando o valor-base e a distância.
* `informarPeso()` — solicita e valida o peso da entrega.
* `calcularPeso()` — calcula o adicional referente ao peso.
* `exibirModalidade()` — apresenta as modalidades e valida a opção escolhida.
* `calcularModalidade()` — calcula o adicional correspondente à modalidade.
* `validaProtecao()` — solicita e valida a escolha de proteção adicional.
* `calcularAdicionalTentativas()` — solicita a quantidade de tentativas adicionais e calcula seu valor.
* `calculoSubFinal()` — soma o subtotal inicial e todos os adicionais para obter o valor final.
* `continuarPedido()` — pergunta se o usuário deseja realizar outro pedido.
* `verificarMaior()` — verifica e atualiza o maior valor de entrega.
* `verificarMenor()` — verifica e atualiza o menor valor de entrega.

A função `main()` é responsável por coordenar a execução do programa, chamando as demais funções, controlando as repetições e acumulando os dados necessários para o resumo final.

## Compilação

O programa foi desenvolvido em linguagem C.

Para compilar utilizando o GCC, execute o seguinte comando no terminal:

```bash
gcc main.c -o main
```

Esse comando compila o arquivo `main.c` e gera o programa executável `main.exe`.

## Execução

Após a compilação, execute o programa pelo terminal:

```bash
main.exe
```

O programa será executado no terminal e solicitará os dados necessários para o cálculo de cada entrega.

## Uso de Inteligência Artificial

Foi utilizada a ferramenta ChatGPT como apoio durante o desenvolvimento do trabalho.

A ferramenta foi utilizada principalmente para esclarecer dúvidas sobre linguagem C, funções, parâmetros, valores de retorno e organização do código.

Também foram utilizados exemplos de perguntas para compreender erros e verificar se determinadas partes da implementação estavam de acordo com os requisitos do trabalho.

As sugestões recebidas foram analisadas e adaptadas ao código desenvolvido, com alterações e correções realizadas durante o processo de implementação.

## Fontes consultadas


* Documentação e Referência C - *cppreference.com* e *cplusplus.com* .
* Comparações e Soluções de Dúvidas Técnicas - *Stack Overflow* .


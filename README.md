# O que é esse repositório?

Aqui esta o codigo da implementação do algoritmo [memplas](https://www.sciencedirect.com/science/article/abs/pii/S0020025516303516) (algoritmo evolucionário) e que adicionei um componente Path Relinking para o problema Quota Car Traveling Salesman (QCars). Eu utilizei a linguagem C++.

Este código é uma melhoramento do repositório do meu [TCC](https://github.com/tiagofunk/TCC-Algoritmo-MemPlas-Com-Path-Relinking-Problema-QCars) e é apresentado neste [artigo](https://sol.sbc.org.br/index.php/eniac/article/view/12142).

# Conteúdo das pastas

- Experiments: logs originais do experimento do artigo e script de execução do experimento.
- Instances: cenários de execução que o algoritmo será submetido.
- Project: Pasta com o código fonte.
- Script: Pasta com scripts de execução dos experimentos. Anteriormente eram vários sheel scripts, hoje contém apenas um script Python.


# Como executar o código fonte?

Execute com:

    python pymake.py build

Vai ser criado um executável com nome de memplas, para executar:

    ./memplas 1 1 1 <instance> -strategy <s> --sizePopulation <sp> --elite  <e> --limitIterations <li> --sizePlasmideo <spl> --cross <c> --selectionStrategy <ss> --intermediaryStrategy <is>

Onde:
-   instance: Arquivo com cenário de execusão.
-   s: Modo de execusão. 'm' para executar memplas apenas, 'pr' para Path Relinking apenas ou 'mpr' para executar ambos.
-   sp: Tamanho da população.
-   e: Tamanho da população de elite.
-   li: Número de iterações do algoritmo.
-   spl: Tamanho dos plasmídeos do memplas.
-   c: Taxa de cruzamento da população.
-   ss: Indica qual estratégia está sendo utilizada na seleção da solução inicial e final no Path Relinking.
-   is: Indica qual estratégia intermediária do Path Relinking é utilizada.

Exemplo de comando de execução:

    ./src/memplas 1 1 1 ../Instances/Angola12n.pcar --strategy mpr --sizePopulation 10 --elite 0.4 --limitIterations 500 --sizePlasmideo 0.5 --cross 0.85 --selectionStrategy a --intermediaryStrategy stef

# Como executar um experimento?

Na pasta Scripts contém o arquivo executor.py, execute-o:

    python executor.py

O script vai executar 30 execuções de cada instância e vai salvar em um log.
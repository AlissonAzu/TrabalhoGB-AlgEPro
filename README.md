# Analise Comparativa dos Metodos de Ordenacao

Universidade do Vale do Rio dos Sinos - Ciencia da Computacao  
Trabalho 2 - Algoritmos e Estruturas de Dados

## Integrantes

- Alisson Grings
- Henrique Freitas
- Artur Costa Gernhardt

## Metodologia

Foram realizadas 10 execucoes para cada combinacao de cenario, metodo e tamanho de array. O tempo foi medido em nanossegundos. A media final considera apenas os valores dentro do intervalo media +/- desvio padrao, descartando outliers conforme descrito no enunciado.

## Cenario 1: Crescente (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 5544 | 200 | 8229 | 3800 | 933 | 56614 | 1422 |
| 256 | 25033 | 400 | 19300 | 6675 | 2100 | 114138 | 3033 |
| 512 | 81200 | 600 | 74414 | 15163 | 4700 | 230888 | 5933 |
| 1024 | 320243 | 1100 | 292211 | 67629 | 13400 | 468425 | 12589 |
| 2048 | 1272175 | 2100 | 1160133 | 84840 | 23000 | 968375 | 26000 |
| 4096 | 5082713 | 4200 | 4864600 | 232000 | 50344 | 1919063 | 56456 |
| 8192 | 22185833 | 8300 | 18632478 | 497850 | 110000 | 3853875 | 118413 |
| 16384 | 81833244 | 16622 | 74538271 | 1087211 | 240522 | 8475511 | 258322 |
| 32768 | 328498533 | 33975 | 297661722 | 2187943 | 515356 | 16612389 | 537011 |
| 65536 | 1301516378 | 66356 | 1184632911 | 4636300 | 1104400 | 33099700 | 1129400 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 2: Decrescente (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 22986 | 6300 | 7233 | 2363 | 1311 | 56167 | 1911 |
| 256 | 44978 | 24278 | 21856 | 6163 | 3000 | 122767 | 12700 |
| 512 | 177222 | 95533 | 82567 | 13325 | 6789 | 239967 | 32325 |
| 1024 | 705711 | 379625 | 321189 | 31244 | 15022 | 489911 | 26200 |
| 2048 | 2797267 | 1507456 | 1268600 | 74600 | 33167 | 993267 | 47500 |
| 4096 | 11179500 | 6008578 | 5035475 | 229638 | 74867 | 1972313 | 147678 |
| 8192 | 44660614 | 24013143 | 20073538 | 503067 | 158411 | 3998111 | 252344 |
| 16384 | 179218122 | 96357050 | 80388556 | 1059000 | 342963 | 8260789 | 471413 |
| 32768 | 722504113 | 387631678 | 321855589 | 2220056 | 751944 | 16591678 | 1004822 |
| 65536 | 2871177663 | 1546182311 | 1290268633 | 4644978 | 1579725 | 33032422 | 2164267 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 3: Aleatorio (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 18471 | 3244 | 5989 | 2638 | 3467 | 57311 | 1667 |
| 256 | 36400 | 12111 | 23089 | 6256 | 3938 | 127613 | 29263 |
| 512 | 151078 | 51656 | 86463 | 16388 | 10056 | 244725 | 14867 |
| 1024 | 577863 | 193111 | 321744 | 38888 | 31025 | 515525 | 22167 |
| 2048 | 2289544 | 770511 | 1239233 | 122125 | 121000 | 1042333 | 41163 |
| 4096 | 8799444 | 3028557 | 4790156 | 290700 | 352600 | 2111567 | 247300 |
| 8192 | 34527811 | 12159578 | 18827100 | 661775 | 861488 | 4306111 | 442133 |
| 16384 | 138706767 | 49821488 | 74749889 | 1470967 | 2145425 | 8971767 | 863871 |
| 32768 | 568932988 | 200292383 | 300536978 | 3151933 | 4805286 | 18166078 | 1910678 |
| 65536 | 2877083663 | 871087829 | 1195519588 | 6688343 | 14399250 | 36262900 | 3955013 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 4: Aleatorio (com repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 9356 | 6214 | 5763 | 2575 | 1611 | 57944 | 1800 |
| 256 | 37025 | 12738 | 21925 | 6350 | 4000 | 125011 | 12256 |
| 512 | 164050 | 50000 | 85238 | 13925 | 10256 | 246275 | 15078 |
| 1024 | 587200 | 196014 | 334567 | 32638 | 54429 | 510333 | 49689 |
| 2048 | 2249150 | 762900 | 1226363 | 105250 | 118725 | 1025467 | 47613 |
| 4096 | 8700989 | 2986522 | 4760938 | 306280 | 392333 | 2111638 | 223022 |
| 8192 | 34372000 | 11983889 | 18757386 | 662700 | 955000 | 4301456 | 440500 |
| 16384 | 138273114 | 48684322 | 75794840 | 1441383 | 2372600 | 8922383 | 873914 |
| 32768 | 564412214 | 196484778 | 299254011 | 3141389 | 5372033 | 18085738 | 1801044 |
| 65536 | 3003680488 | 779673457 | 1199250700 | 6802933 | 15642111 | 36291663 | 3984333 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Complexidade dos algoritmos

| Algoritmo | Melhor caso | Caso medio | Pior caso | Espaco |
|-----------|-------------|------------|-----------|--------|
| Bubble Sort | O(n) | O(n2) | O(n2) | O(1) |
| Insertion Sort | O(n) | O(n2) | O(n2) | O(1) |
| Selection Sort | O(n2) | O(n2) | O(n2) | O(1) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Shell Sort | O(n log n) | O(n log2 n) | O(n2) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n2) | O(log n) |

A notacao O descreve como o tempo de execucao cresce conforme o tamanho do array aumenta. O(n2) significa que dobrar o array quadruplica o tempo, e e exatamente isso que se observa nas tabelas para Bubble Sort, Insertion Sort e Selection Sort em arrays grandes. Ja O(n log n) cresce muito mais devagar, o que explica por que Heap Sort e Merge Sort se mantem rapidos mesmo para n=65536.

## Observacoes

**Cenario crescente:** o Insertion Sort se destaca por ser o mais rapido entre os algoritmos simples, pois quando o array ja esta ordenado ele apenas percorre os elementos sem fazer trocas. O Bubble Sort tambem se beneficia desse cenario, mas ainda e muito mais lento que os algoritmos O(n log n). O Quick Sort apresenta desempenho pior nesse cenario com pivos mal escolhidos, porem a implementacao com mediana de tres ameniza esse problema.

**Cenario decrescente:** e o pior caso para Bubble Sort e Insertion Sort, que precisam mover cada elemento ate o inicio do array a cada passo. O Bubble Sort chega a ser consideravelmente mais lento nesse cenario comparado ao crescente. Heap Sort e Merge Sort nao sofrem variacao significativa pois sua complexidade e O(n log n) independente da entrada.

**Cenario aleatorio sem repeticao:** representa o caso medio para a maioria dos algoritmos. O Quick Sort tende a ser o mais rapido na pratica por ter constantes menores que o Merge Sort, mesmo ambos sendo O(n log n). O Shell Sort surpreende positivamente para tamanhos intermediarios. Os algoritmos O(n2) ja mostram diferenca grande de tempo em relacao aos demais a partir de n=1024.

**Cenario aleatorio com repeticao:** o comportamento e muito semelhante ao aleatorio sem repeticao. Os valores repetidos nao causam impacto significativo nos algoritmos O(n log n). Para os algoritmos O(n2) os tempos ficam proximos ao cenario aleatorio, sem piora expressiva.

De forma geral, para arrays pequenos ate 512 elementos a diferenca entre os algoritmos e pequena e qualquer um atende bem. A partir dai os algoritmos O(n2) ficam cada vez mais inviáveis, e para uso real em arrays grandes o Merge Sort e o Quick Sort sao as melhores opcoes.

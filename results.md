# Analise Comparativa dos Metodos de Ordenacao

Universidade do Vale do Rio dos Sinos - Ciencia da Computacao  
Trabalho 2 - Algoritmos e Estruturas de Dados

## Metodologia

Foram realizadas 10 execucoes para cada combinacao de cenario, metodo e tamanho de array. O tempo foi medido em nanossegundos. A media final considera apenas os valores dentro do intervalo media +/- desvio padrao, descartando outliers conforme descrito no enunciado.

## Cenario 1: Crescente (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 7988 | 244 | 7443 | 4313 | 1333 | 78517 | 1400 |
| 256 | 21013 | 300 | 19250 | 6725 | 2100 | 114211 | 3022 |
| 512 | 81314 | 1100 | 77150 | 15478 | 4700 | 231389 | 11911 |
| 1024 | 321122 | 1100 | 291988 | 68575 | 10400 | 479389 | 25122 |
| 2048 | 1273289 | 4213 | 1157156 | 79163 | 23000 | 951988 | 25989 |
| 4096 | 5083675 | 4144 | 4686088 | 232638 | 50378 | 1941244 | 56489 |
| 8192 | 20311989 | 16650 | 19159375 | 495643 | 112600 | 3862500 | 118611 |
| 16384 | 81548789 | 16633 | 74045914 | 1055544 | 238567 | 8257644 | 260189 |
| 32768 | 325510867 | 33257 | 296369320 | 2182700 | 515222 | 16582700 | 534889 |
| 65536 | 1311622900 | 66325 | 1189798757 | 4614333 | 1102278 | 33097100 | 1145325 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 2: Decrescente (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 23729 | 12633 | 11800 | 4688 | 2588 | 56511 | 1822 |
| 256 | 44900 | 24211 | 21871 | 5625 | 3000 | 123044 | 12689 |
| 512 | 176333 | 95163 | 82629 | 12750 | 6800 | 238675 | 16622 |
| 1024 | 699944 | 377388 | 339000 | 29688 | 15033 | 515467 | 26256 |
| 2048 | 2788738 | 1503978 | 1265156 | 71263 | 33033 | 979863 | 47500 |
| 4096 | 11141322 | 6037689 | 5022600 | 239675 | 144471 | 1989000 | 146744 |
| 8192 | 44867775 | 24067575 | 20094238 | 498756 | 199433 | 3998011 | 253478 |
| 16384 | 180837775 | 96413844 | 80544986 | 1059900 | 345563 | 8267088 | 471325 |
| 32768 | 721000086 | 388550500 | 324470250 | 2216033 | 759950 | 16641356 | 1001111 |
| 65536 | 2887951463 | 1551839300 | 1291617471 | 4641933 | 1574800 | 33150775 | 2160189 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 3: Aleatorio (sem repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 9288 | 3233 | 5700 | 2744 | 3467 | 115500 | 1789 |
| 256 | 39933 | 13375 | 23025 | 6111 | 4511 | 125322 | 11922 |
| 512 | 150544 | 51188 | 85038 | 14175 | 10113 | 250613 | 15011 |
| 1024 | 593433 | 190457 | 324017 | 34113 | 28644 | 505875 | 42800 |
| 2048 | 2252533 | 761833 | 1251643 | 116463 | 142467 | 1028888 | 81283 |
| 4096 | 8823767 | 3059125 | 4942522 | 302350 | 356622 | 2087638 | 223583 |
| 8192 | 34659033 | 12601113 | 18761086 | 668111 | 891689 | 4313944 | 438044 |
| 16384 | 139888300 | 49936478 | 74626422 | 1450089 | 2231322 | 8959850 | 864500 |
| 32768 | 570025686 | 202212489 | 297560156 | 3120322 | 6472622 | 18068489 | 1850025 |
| 65536 | 2852238838 | 869751729 | 1189939500 | 6659589 | 14560267 | 36084789 | 3869838 |

*Tempos em nanossegundos (media filtrada de 10 execucoes)*

## Cenario 4: Aleatorio (com repeticao)

| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |
|---|-------------|----------------|----------------|-----------|------------|------------|------------|
| 128 | 9775 | 3238 | 5625 | 2700 | 1633 | 57656 | 1711 |
| 256 | 37167 | 13033 | 22778 | 5875 | 3844 | 124789 | 12278 |
| 512 | 150867 | 105975 | 85986 | 14000 | 11267 | 245156 | 15500 |
| 1024 | 586183 | 188444 | 320175 | 32200 | 67086 | 508867 | 23222 |
| 2048 | 2259200 | 758488 | 1221763 | 106513 | 134900 | 1021488 | 37300 |
| 4096 | 8790200 | 3041878 | 4873200 | 298113 | 374611 | 2180533 | 230125 |
| 8192 | 34414511 | 12104811 | 18747256 | 660783 | 972389 | 4579143 | 433133 |
| 16384 | 136914556 | 48309989 | 74495071 | 1503450 | 2345356 | 8943856 | 841614 |
| 32768 | 565157100 | 194176550 | 299120983 | 3144963 | 5116167 | 18109838 | 1840867 |
| 65536 | 2941262171 | 774734586 | 1198629414 | 6739038 | 16332888 | 36162063 | 3859767 |

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

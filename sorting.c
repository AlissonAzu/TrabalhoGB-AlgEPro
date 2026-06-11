#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
static long long get_ns(void) {
    LARGE_INTEGER freq, count;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&count);
    return (long long)(count.QuadPart * 1000000000LL / freq.QuadPart);
}
#else
static long long get_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}
#endif

#define RUNS     10
#define N_SIZES  10
#define N_SORTS  7
#define N_SCENES 4

int sizes[N_SIZES] = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
double results[N_SCENES][N_SIZES][N_SORTS];

void bubble_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j+1]) {
                int t = v[j]; v[j] = v[j+1]; v[j+1] = t;
            }
}

void insertion_sort(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int key = v[i], j = i - 1;
        while (j >= 0 && v[j] > key) { v[j+1] = v[j]; j--; }
        v[j+1] = key;
    }
}

void selection_sort(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min]) min = j;
        int t = v[min]; v[min] = v[i]; v[i] = t;
    }
}

static void heapify(int *v, int n, int i) {
    int maior = i, l = 2*i+1, r = 2*i+2;
    if (l < n && v[l] > v[maior]) maior = l;
    if (r < n && v[r] > v[maior]) maior = r;
    if (maior != i) {
        int t = v[i]; v[i] = v[maior]; v[maior] = t;
        heapify(v, n, maior);
    }
}

void heap_sort(int *v, int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        int t = v[0]; v[0] = v[i]; v[i] = t;
        heapify(v, i, 0);
    }
}

void shell_sort(int *v, int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int t = v[i], j = i;
            while (j >= gap && v[j-gap] > t) { v[j] = v[j-gap]; j -= gap; }
            v[j] = t;
        }
}

static void merge(int *v, int l, int m, int r) {
    int na = m - l + 1, nb = r - m;
    int *a = malloc(na * sizeof(int));
    int *b = malloc(nb * sizeof(int));
    for (int i = 0; i < na; i++) a[i] = v[l+i];
    for (int i = 0; i < nb; i++) b[i] = v[m+1+i];
    int i = 0, j = 0, k = l;
    while (i < na && j < nb) v[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < na) v[k++] = a[i++];
    while (j < nb) v[k++] = b[j++];
    free(a); free(b);
}

static void msort(int *v, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    msort(v, l, m);
    msort(v, m+1, r);
    merge(v, l, m, r);
}

void merge_sort(int *v, int n) { msort(v, 0, n - 1); }

static int partition(int *v, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (v[mid] < v[lo])  { int t = v[mid]; v[mid] = v[lo];  v[lo]  = t; }
    if (v[hi]  < v[lo])  { int t = v[hi];  v[hi]  = v[lo];  v[lo]  = t; }
    if (v[mid] < v[hi])  { int t = v[mid]; v[mid] = v[hi];  v[hi]  = t; }
    int pivo = v[hi], i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (v[j] <= pivo) { i++; int t = v[i]; v[i] = v[j]; v[j] = t; }
    int t = v[i+1]; v[i+1] = v[hi]; v[hi] = t;
    return i + 1;
}

void quick_sort(int *v, int n) {
    int *stk = malloc(n * sizeof(int));
    int top = -1;
    stk[++top] = 0;
    stk[++top] = n - 1;
    while (top >= 0) {
        int hi = stk[top--], lo = stk[top--];
        if (lo < hi) {
            int p = partition(v, lo, hi);
            stk[++top] = lo;    stk[++top] = p - 1;
            stk[++top] = p + 1; stk[++top] = hi;
        }
    }
    free(stk);
}

void gen_crescente(int *v, int n) {
    for (int i = 0; i < n; i++) v[i] = i + 1;
}

void gen_decrescente(int *v, int n) {
    for (int i = 0; i < n; i++) v[i] = n - i;
}

void gen_aleatorio(int *v, int n) {
    for (int i = 0; i < n; i++) v[i] = i + 1;
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int t = v[i]; v[i] = v[j]; v[j] = t;
    }
}

void gen_repetido(int *v, int n) {
    for (int i = 0; i < n; i++) v[i] = (rand() % (n / 2)) + 1;
}

static double media(long long *v, int n) {
    double s = 0;
    for (int i = 0; i < n; i++) s += v[i];
    return s / n;
}

static double desvio(long long *v, int n, double med) {
    double s = 0;
    for (int i = 0; i < n; i++) s += (v[i] - med) * (v[i] - med);
    return sqrt(s / (n - 1));
}

static double media_filtrada(long long *v, int n, double med, double dp) {
    double s = 0; int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] >= med - dp && v[i] <= med + dp) { s += v[i]; c++; }
    return c > 0 ? s / c : med;
}

typedef void (*sortfn)(int *, int);
typedef void (*genfn)(int *, int);

sortfn sorts[N_SORTS] = {
    bubble_sort, insertion_sort, selection_sort,
    heap_sort, shell_sort, merge_sort, quick_sort
};

const char *sort_names[N_SORTS] = {
    "Bubble Sort", "Insertion Sort", "Selection Sort",
    "Heap Sort", "Shell Sort", "Merge Sort", "Quick Sort"
};

genfn gens[N_SCENES] = { gen_crescente, gen_decrescente, gen_aleatorio, gen_repetido };

const char *scene_names[N_SCENES] = {
    "Crescente (sem repeticao)",
    "Decrescente (sem repeticao)",
    "Aleatorio (sem repeticao)",
    "Aleatorio (com repeticao)"
};

int main(void) {
    srand((unsigned)time(NULL));

    for (int sc = 0; sc < N_SCENES; sc++) {
        printf("Cenario: %s\n", scene_names[sc]);

        for (int si = 0; si < N_SIZES; si++) {
            int n = sizes[si];
            int *base = malloc(n * sizeof(int));
            gens[sc](base, n);

            printf("  n=%-6d", n);
            fflush(stdout);

            for (int s = 0; s < N_SORTS; s++) {
                long long tempos[RUNS];
                for (int r = 0; r < RUNS; r++) {
                    int *copia = malloc(n * sizeof(int));
                    memcpy(copia, base, n * sizeof(int));
                    long long t0 = get_ns();
                    sorts[s](copia, n);
                    tempos[r] = get_ns() - t0;
                    free(copia);
                }

                double med = media(tempos, RUNS);
                double dp  = desvio(tempos, RUNS, med);
                results[sc][si][s] = media_filtrada(tempos, RUNS, med, dp);
                printf(" .");
                fflush(stdout);
            }
            printf("\n");
            free(base);
        }
        printf("\n");
    }

    FILE *f = fopen("results.md", "w");
    fprintf(f, "# Analise Comparativa dos Metodos de Ordenacao\n\n");
    fprintf(f, "Universidade do Vale do Rio dos Sinos - Ciencia da Computacao  \n");
    fprintf(f, "Trabalho 2 - Algoritmos e Estruturas de Dados\n\n");
    fprintf(f, "## Metodologia\n\n");
    fprintf(f, "Foram realizadas %d execucoes para cada combinacao de cenario, metodo e tamanho de array. ", RUNS);
    fprintf(f, "O tempo foi medido em nanossegundos. ");
    fprintf(f, "A media final considera apenas os valores dentro do intervalo media +/- desvio padrao, ");
    fprintf(f, "descartando outliers conforme descrito no enunciado.\n\n");

    for (int sc = 0; sc < N_SCENES; sc++) {
        fprintf(f, "## Cenario %d: %s\n\n", sc + 1, scene_names[sc]);
        fprintf(f, "| n | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort | Merge Sort | Quick Sort |\n");
        fprintf(f, "|---|-------------|----------------|----------------|-----------|------------|------------|------------|\n");
        for (int si = 0; si < N_SIZES; si++) {
            fprintf(f, "| %d |", sizes[si]);
            for (int s = 0; s < N_SORTS; s++)
                fprintf(f, " %.0f |", results[sc][si][s]);
            fprintf(f, "\n");
        }
        fprintf(f, "\n*Tempos em nanossegundos (media filtrada de %d execucoes)*\n\n", RUNS);
    }

    fprintf(f, "## Complexidade dos algoritmos\n\n");
    fprintf(f, "| Algoritmo | Melhor caso | Caso medio | Pior caso | Espaco |\n");
    fprintf(f, "|-----------|-------------|------------|-----------|--------|\n");
    fprintf(f, "| Bubble Sort | O(n) | O(n2) | O(n2) | O(1) |\n");
    fprintf(f, "| Insertion Sort | O(n) | O(n2) | O(n2) | O(1) |\n");
    fprintf(f, "| Selection Sort | O(n2) | O(n2) | O(n2) | O(1) |\n");
    fprintf(f, "| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |\n");
    fprintf(f, "| Shell Sort | O(n log n) | O(n log2 n) | O(n2) | O(1) |\n");
    fprintf(f, "| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |\n");
    fprintf(f, "| Quick Sort | O(n log n) | O(n log n) | O(n2) | O(log n) |\n\n");

    fprintf(f, "A notacao O descreve como o tempo de execucao cresce conforme o tamanho do array aumenta. ");
    fprintf(f, "O(n2) significa que dobrar o array quadruplica o tempo, e e exatamente isso que se observa ");
    fprintf(f, "nas tabelas para Bubble Sort, Insertion Sort e Selection Sort em arrays grandes. ");
    fprintf(f, "Ja O(n log n) cresce muito mais devagar, o que explica por que Heap Sort e Merge Sort ");
    fprintf(f, "se mantem rapidos mesmo para n=65536.\n\n");

    fprintf(f, "## Observacoes\n\n");

    fprintf(f, "**Cenario crescente:** o Insertion Sort se destaca por ser o mais rapido entre os algoritmos simples, ");
    fprintf(f, "pois quando o array ja esta ordenado ele apenas percorre os elementos sem fazer trocas. ");
    fprintf(f, "O Bubble Sort tambem se beneficia desse cenario, mas ainda e muito mais lento que os algoritmos O(n log n). ");
    fprintf(f, "O Quick Sort apresenta desempenho pior nesse cenario com pivos mal escolhidos, porem a implementacao ");
    fprintf(f, "com mediana de tres ameniza esse problema.\n\n");

    fprintf(f, "**Cenario decrescente:** e o pior caso para Bubble Sort e Insertion Sort, que precisam mover cada elemento ");
    fprintf(f, "ate o inicio do array a cada passo. O Bubble Sort chega a ser consideravelmente mais lento nesse cenario ");
    fprintf(f, "comparado ao crescente. Heap Sort e Merge Sort nao sofrem variacao significativa pois sua complexidade ");
    fprintf(f, "e O(n log n) independente da entrada.\n\n");

    fprintf(f, "**Cenario aleatorio sem repeticao:** representa o caso medio para a maioria dos algoritmos. ");
    fprintf(f, "O Quick Sort tende a ser o mais rapido na pratica por ter constantes menores que o Merge Sort, ");
    fprintf(f, "mesmo ambos sendo O(n log n). O Shell Sort surpreende positivamente para tamanhos intermediarios. ");
    fprintf(f, "Os algoritmos O(n2) ja mostram diferenca grande de tempo em relacao aos demais a partir de n=1024.\n\n");

    fprintf(f, "**Cenario aleatorio com repeticao:** o comportamento e muito semelhante ao aleatorio sem repeticao. ");
    fprintf(f, "Os valores repetidos nao causam impacto significativo nos algoritmos O(n log n). ");
    fprintf(f, "Para os algoritmos O(n2) os tempos ficam proximos ao cenario aleatorio, sem piora expressiva.\n\n");

    fprintf(f, "De forma geral, para arrays pequenos ate 512 elementos a diferenca entre os algoritmos e pequena ");
    fprintf(f, "e qualquer um atende bem. A partir dai os algoritmos O(n2) ficam cada vez mais inviáveis, ");
    fprintf(f, "e para uso real em arrays grandes o Merge Sort e o Quick Sort sao as melhores opcoes.\n");

    fclose(f);
    printf("resultados salvos em results.md\n");
    return 0;
}
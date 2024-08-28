#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define V 10

// Function declarations
void gerarMatrizAleatoria(int matriz[][V], int tamanho, int valorMin, int valorMax);
int menorDistancia(int dist[], bool conjuntoSPT[]);
void dijkstra(int grafo[V][V], int origem, int destino, int *dist, int *pred);
void gerarArquivoDot(int grafo[V][V], const char *nomeArquivo, int predOrigem[], int predDestino[], int origem, int destino);
void imprimirSolucao(int dist[], int n);
void imprimirCaminho(int pred[], int destino);

int main() {
    int tamanho = V;
    int valorMin, valorMax;
    int origem = 0;  
    int destino = 0; 

    srand(time(NULL));

    printf("Digite o valor mínimo: ");
    scanf("%d", &valorMin);
    printf("Digite o valor máximo: ");
    scanf("%d", &valorMax);

    int matriz[V][V];
    gerarMatrizAleatoria(matriz, tamanho, valorMin, valorMax);

    printf("Matriz Gerada:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Digite de ida: ");
    scanf("%d", &origem);
    printf("Digite o de volta: ");
    scanf("%d", &destino);


    // Arrays to store the results
    int distOrigem[V], predOrigem[V];
    int distDestino[V], predDestino[V];

    // Run Dijkstra's algorithm from origem to destino
    dijkstra(matriz, origem, destino, distOrigem, predOrigem);

    // Run Dijkstra's algorithm from destino to origem
    dijkstra(matriz, destino, origem, distDestino, predDestino);

    printf("Melhor rota de %d para %d: ", origem, destino);
    imprimirCaminho(predOrigem, destino);
    printf("\n");

    printf("Melhor rota de %d para %d: ", destino, origem);
    imprimirCaminho(predDestino, origem);
    printf("\n");

    gerarArquivoDot(matriz, "grafo.dot", predOrigem, predDestino, origem, destino);

    // Automating the generation of a PNG using system call
    system("dot -Tpng grafo.dot -o grafo.png");

    return 0;
}

// Function to generate a matrix with random values
void gerarMatrizAleatoria(int matriz[][V], int tamanho, int valorMin, int valorMax) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = valorMin + rand() % (valorMax - valorMin + 1);
        }
    }
}

// Function to find the vertex with the minimum distance value
int menorDistancia(int dist[], bool conjuntoSPT[]) {
    int min = INT_MAX, indiceMin;
    for (int v = 0; v < V; v++) {
        if (!conjuntoSPT[v] && dist[v] <= min) {
            min = dist[v];
            indiceMin = v;
        }
    }
    return indiceMin;
}

// Function to print the path using predecessor array
void imprimirCaminho(int pred[], int destino) {
    if (pred[destino] == -1) {
        printf("%d ", destino);
        return;
    }

    imprimirCaminho(pred, pred[destino]);
    printf("%d ", destino);
}

// Function to implement Dijkstra's algorithm
void dijkstra(int grafo[V][V], int origem, int destino, int *dist, int *pred) {
    bool conjuntoSPT[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        conjuntoSPT[i] = false;
        pred[i] = -1;
    }

    dist[origem] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = menorDistancia(dist, conjuntoSPT);
        conjuntoSPT[u] = true;

        for (int v = 0; v < V; v++) {
            if (!conjuntoSPT[v] && grafo[u][v] && dist[u] != INT_MAX && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
                pred[v] = u;
            }
        }
    }
}

// Function to generate a DOT file for graph visualization
void gerarArquivoDot(int grafo[V][V], const char *nomeArquivo, int predOrigem[], int predDestino[], int origem, int destino) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Não foi possível criar o arquivo %s\n", nomeArquivo);
        return;
    }

    bool arestasCaminhoCurto[V][V] = {false};

    // Mark edges for the shortest path from origem to destino
    int atual = destino;
    while (atual != origem && predOrigem[atual] != -1) {
        int predecessor = predOrigem[atual];
        arestasCaminhoCurto[predecessor][atual] = true;
        atual = predecessor;
    }

    // Mark edges for the shortest path from destino to origem
    atual = origem;
    while (atual != destino && predDestino[atual] != -1) {
        int predecessor = predDestino[atual];
        arestasCaminhoCurto[predecessor][atual] = true;
        atual = predecessor;
    }

    fprintf(arquivo, "digraph G {\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (grafo[i][j] != 0) {
                if (arestasCaminhoCurto[i][j]) {
                    fprintf(arquivo, "    %d -> %d [label=%d color=red];\n", i, j, grafo[i][j]);
                } else {
                    fprintf(arquivo, "    %d -> %d [label=%d];\n", i, j, grafo[i][j]);
                }
            }
        }
    }
    fprintf(arquivo, "}\n");
    fclose(arquivo);
}

// Function to print the solution
void imprimirSolucao(int dist[], int n) {
    printf("Vértice   Distância da Origem\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

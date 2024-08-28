# Algoritmo de Dijkstra em C
Este repositório contém uma implementação do algoritmo de Dijkstra em linguagem C, desenvolvido como parte de um trabalho acadêmico. O algoritmo de Dijkstra é uma técnica clássica de teoria dos grafos, utilizada para encontrar o caminho mais curto entre um vértice de origem e os demais vértices de um grafo ponderado e direcionado.

O que é o Algoritmo de Dijkstra?
Criado por Edsger W. Dijkstra em 1956, este algoritmo é amplamente utilizado em redes de computadores e sistemas de navegação GPS, entre outras aplicações. Ele funciona assumindo um conjunto de nós ou vértices conectados por arestas, onde cada aresta tem um peso ou custo associado. O objetivo do algoritmo é calcular o menor caminho total da origem até um determinado destino ou até todos os outros vértices do grafo.

Como o Algoritmo Funciona?
Inicialização: Começa-se definindo a distância da origem a si mesma como zero e todas as outras distâncias como infinitas.

Exploração dos Vértices: Iterativamente, escolhe-se o vértice com a menor distância acumulada, atualizando as distâncias de seus vizinhos.

Atualização das Distâncias: Para cada vizinho do vértice atual, calcula-se a possível nova distância (soma da distância atual e o peso da aresta para o vizinho). Se essa nova distância for menor do que a conhecida anteriormente, ela é atualizada.

Repetição: O processo é repetido até que todos os vértices tenham sido visitados ou a menor distância para o destino tenha sido encontrada.

Estrutura do Código
Entrada: Um grafo representado por uma matriz de adjacência ou lista de adjacência, e o vértice inicial.
Saída: O menor caminho do vértice inicial para todos os outros vértices, ou um vértice específico.
Complexidade: O algoritmo de Dijkstra tem complexidade O(V^2) para grafos densos quando implementado com matrizes de adjacência, e O((V + E) log V) com listas de adjacência e filas de prioridade.
Requisitos
Compilador C (GCC, por exemplo)
Conhecimento básico em manipulação de grafos e estruturas de dados em C
Como Executar
Clone o repositório:

bash
Copiar código
git clone <link_do_repositorio>
Compile o código:

Copiar código
gcc dijkstra.c -o dijkstra
Execute o programa:

bash
Copiar código
./dijkstra
Este projeto é uma excelente oportunidade para entender conceitos fundamentais de algoritmos e estruturas de dados, aplicando-os a problemas reais de otimização de rotas e redes.

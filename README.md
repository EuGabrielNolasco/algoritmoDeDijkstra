
# Algoritmo de Dijkstra em C
Este repositório contém uma implementação do algoritmo de Dijkstra, desenvolvido em linguagem C, como parte de um projeto acadêmico. O algoritmo de Dijkstra é uma solução eficiente para encontrar o caminho mais curto entre um nó de origem e todos os outros nós em um grafo ponderado e direcionado.

Descrição do Algoritmo
O algoritmo de Dijkstra foi proposto por Edsger W. Dijkstra em 1956 e é amplamente utilizado em várias aplicações, como roteamento de redes, sistemas de navegação GPS e análise de grafos. O algoritmo é baseado em uma abordagem gulosa (greedy), onde itera sobre os nós do grafo, atualizando progressivamente as distâncias mais curtas encontradas a partir do nó de origem até os outros nós.

Funcionamento
Inicialização: O algoritmo começa definindo a distância do nó de origem para ele mesmo como zero, enquanto todas as outras distâncias são inicialmente definidas como infinitas.

Exploração dos Nós: Seleciona-se o nó com a menor distância acumulada que ainda não foi visitado. Este nó é então considerado como o nó atual.

Atualização das Distâncias: Para cada vizinho do nó atual, calcula-se a distância total do nó de origem até ele através do nó atual. Se esta nova distância for menor do que a distância conhecida anteriormente, ela é atualizada.

Iteração: Repete-se o processo até que todos os nós tenham sido visitados ou que o caminho mais curto para o destino específico tenha sido encontrado.

Complexidade
Usando Matriz de Adjacência: O algoritmo tem uma complexidade de tempo de 
𝑂
(
𝑉
2
)
O(V 
2
 ), onde 
𝑉
V é o número de vértices.
Usando Lista de Adjacência e Fila de Prioridade: A complexidade melhora para 
𝑂
(
(
𝑉
+
𝐸
)
log
⁡
𝑉
)
O((V+E)logV), onde 
𝐸
E é o número de arestas.
Estrutura do Código
Entrada: O programa recebe um grafo representado por uma matriz de adjacência ou lista de adjacência, e o vértice inicial.
Saída: A saída do programa é o menor caminho do vértice inicial para todos os outros vértices no grafo.
Requisitos
Um compilador C, como GCC.
Conhecimento básico em estruturas de dados e manipulação de grafos.
Como Executar

Clone o repositório:
git clone <link_do_repositorio>

Compile o código fonte:
gcc dijkstra.c -o dijkstra

Execute o programa:
./dijkstra

Contribuições
Contribuições são bem-vindas! Se você deseja melhorar o código ou adicionar novas funcionalidades, sinta-se à vontade para enviar um pull request.

Licença
Este projeto está licenciado sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.


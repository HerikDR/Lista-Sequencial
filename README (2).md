
Estrutura de dados : Lista Sequencial com Redimensionamento Dinâmico
-------------------------------------------------------------------------------------------
O trabalho está separado em duas etapas:
- Implementação simples utilizando uma lista estática;
- Implementação final da lista dinâmica.

Ambas versões são possíveis adicionar, remover e visualizar os elementos presentes na lista. Diferencialmente, a lista dinâmica possibilida ao programador uma fácil manipulação do dimensionamento, conforme necessário.

**Funções implementadas:**

- func **iniciar** : É definido a capacidade inicial da lista (0), tendo no máximo até 50 elementos antes que seja alterado.
- func **deletarlista** : Aplica a função "free" para liberar o espaço alocado da lista.
- func **alterartamanho** : Altera o valor da capacidade de alocação dos elementos, caso não seja possível a alteração uma mensagem será exibida.
- func **inserir** : Verifica se a lista está cheia, se sim, o tamanho da lista é duplicado. Caso contrário, o elemento será inserido. Os elementos que estão após a posição de alocação são deslocados para frente.
- func **remover** : Caso o usuário tentar remover um elemento fora de alcance, uma errata será exibida. Caso suficientes elementos sejam removidos e inferir 25% da capacidade, o tamanho da lista é reduzida pela metade. 
- func **imprimir** : Percorre a lista e exibe todos os elementos.
- func **main** : Executa todas as funções em casos, semelhante a um CRUD. Nele você pode escolher qual operação deseja realizar.


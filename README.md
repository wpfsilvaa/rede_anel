# Simulação de Rede em Anel com Eleição de Coordenador

Este projeto é uma simulação de uma rede em anel que inclui funcionalidades como criação da rede, envio de mensagens entre os nós e eleição de um coordenador com base em uma chave associada a cada nó. Ele foi desenvolvido em linguagem C, utilizando estruturas de dados dinâmicas para gerenciar os nós da rede.

---

## Funcionalidades

1. **Criação de Rede em Anel**  
   A função `criarRedeAnel` cria uma rede em anel composta por nós, cada um identificado por um ID único e uma chave gerada aleatoriamente.

2. **Impressão da Estrutura da Rede**  
   A função `imprimirAnel` exibe no terminal os IDs e as chaves de cada nó presente na rede.

3. **Envio de Mensagens**  
   A função `enviarMensagem` permite que uma mensagem seja transmitida entre todos os nós do anel.

4. **Eleição de Coordenador**  
   A função `elegerCoordenador` implementa um algoritmo de eleição baseado na chave dos nós, elegendo o nó com a maior chave como coordenador.

---

## Estrutura de Dados

A estrutura `Node` representa um nó da rede:

```c
typedef struct Node {
    int id;                // Identificador único do nó
    int chave;             // Chave associada ao nó
    struct Node *next;     // Ponteiro para o próximo nó
} Node;
```

---

## Algoritmos Implementados

1. **Criação de Nós**
   - Função `criarNo`: Cria dinamicamente um novo nó com um ID e chave fornecidos.

2. **Verificação de Chave Duplicada**
   - Função `verificarChaveDuplicada`: Garante que todas as chaves na rede sejam únicas.

3. **Criação da Rede**
   - Função `criarRedeAnel`: Gera `n` nós e conecta-os formando uma rede circular (anel).

4. **Envio de Mensagens**
   - Função `enviarMensagem`: Percorre o anel enviando uma mensagem para cada nó.

5. **Eleição do Coordenador**
   - Função `elegerCoordenador`: Itera pela rede em busca do nó com a maior chave, elegendo-o como coordenador.

---

## Como Usar

### Compilação
Certifique-se de ter um compilador C instalado (como `gcc`). Compile o programa com o seguinte comando:

```bash
gcc -o rede_anel rede_anel.c
```

### Execução
Após a compilação, execute o programa:

```bash
./rede_anel
```

---

## Exemplo de Saída

### Estrutura do Anel
O programa imprime os IDs e as chaves de cada nó no anel:

```
Estrutura do anel:
Nó ID: 0, Chave: 42
Nó ID: 1, Chave: 67
Nó ID: 2, Chave: 19
...
```

### Envio de Mensagem
Uma mensagem é enviada a todos os nós no anel:

```
Nó 0 recebeu a mensagem: Mensagem de teste
Nó 1 recebeu a mensagem: Mensagem de teste
...
```

### Eleição de Coordenador
O processo de eleição é descrito no terminal, mostrando os candidatos e o coordenador final:

```
Passando pelo nó 1, chave 67. Coordenador Atual ID: 0 CHAVE: 42
Novo candidato a coordenador:
::ID 1
::Chave: 67

::::::::::O coordenador eleito é ID: 1 com a chave: 67 ::::::::::
```

---

## Modificações e Melhorias

- **Gerenciamento de Memória**:  
  Adicionar uma função para liberar a memória alocada para os nós ao final da execução.
  
- **Parâmetros Dinâmicos**:  
  Permitir que o número de nós seja fornecido como entrada pelo usuário.

- **Melhoria na Eleição**:  
  Implementar variações no algoritmo de eleição, como o algoritmo de eleição de anel.

---

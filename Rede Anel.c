#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int id;
    int chave;
    struct Node *next;
} Node;

Node* criarNo(int id, int chave);
Node* criarRedeAnel(int n);
void imprimirAnel(Node *head);
void enviarMensagem(Node *head, const char *mensagem);
Node* elegerCoordenador(Node *head);
int verificarChaveDuplicada(Node *head, int id);

Node* criarNo(int id, int chave) {
    Node *novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo nó.\n");
        exit(1);
    }
    novoNo->id = id;
    novoNo->chave = chave;
    novoNo->next = NULL;
    return novoNo;
}

int verificarChaveDuplicada(Node *head, int chave) {
    Node *current = head;
    if (current == NULL) return 0;
    do {
        if (current->chave == chave) return 1;
        current = current->next;
    } while (current != head);
    return 0;
}

Node* criarRedeAnel(int n) {
    int chave = 0;
    if (n <= 0) return NULL;
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < n; i++) {
        int id = i;
        do {
            chave = rand() % 100;
        } while (verificarChaveDuplicada(head, chave));
        Node *novoNo = criarNo(id, chave);
        if (head == NULL) {
            head = novoNo;
            current = novoNo;
            current->next = head;
        } else {
            current->next = novoNo;
            novoNo->next = head;
            current = novoNo;
        }
    }

    return head;
}

void imprimirAnel(Node *head) {
    if (head == NULL) return;

    Node *current = head;
    do {
        printf("Nó ID: %d, Chave: %d\n", current->id, current->chave);
        current = current->next;
    } while (current != head);
}

void enviarMensagem(Node *head, const char *mensagem) {
    if (head == NULL) return;

    Node *current = head;
    do {
        printf("Nó %d recebeu a mensagem: %s\n", current->id, mensagem);
        current = current->next;
    } while (current != head);
}

Node* elegerCoordenador(Node *head) {
    if (head == NULL) return NULL;

    Node *coordenador = head;
    printf("Coordenador Atual ID: %d CHAVE: %d",coordenador->id, coordenador->chave);
    Node *current = head->next;

    do {
        printf("\nPassando pelo nó %d, chave %d. Coordenador Atual ID: %d CHAVE: %d", current->id, current -> chave, coordenador->id, coordenador->chave);
        if (current->chave > coordenador->chave) {
            coordenador = current;
            printf("\n\nNovo candidato a coordenador:\n::ID %d\n::Chave: %d\n");
        }
        current = current->next;
    } while (current != head);

    printf("\n\n::::::::::O coordenador eleito é ID: %d com a chave: %d ::::::::::\n\n", coordenador->id, coordenador->chave);
    return coordenador;
}

int main() {
    int n = 20;
    srand(time(NULL));
    Node *anel = criarRedeAnel(n);

    printf("Estrutura do anel:\n");
    imprimirAnel(anel);

    printf("\nEnviando mensagem no anel...\n");
    enviarMensagem(anel, "Mensagem de teste");

    printf("\nProcesso de eleição...\n");
    elegerCoordenador(anel);

    return 0;
}

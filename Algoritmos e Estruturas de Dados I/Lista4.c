/*
 * Lista 4
 *  Algoritmos e Estruturas de Dados I
 * Lista Ligada (ou Encadeada)
 */

#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define     UX          uintmax_t
#define     IX          intmax_t
#define     U32         uint32_t
#define     U0          void

#define     Fn          static
#define     In          inline
#define     Reg         register
#define     Cst         const

typedef struct Node Node;
typedef struct DNode DNode;

struct Node {

    IX               Data;
    struct Node     *Next;
    
};

struct DNode {

    IX               Data;

    struct DNode    *Prev;
    struct DNode    *Next;

};

/*
 * Lista de Funções
 */

Fn  Node    *New_List       (void);                     /* Ex 02 */
Fn  Node    *New_Node       (Cst IX);                   /* Ex 03 */

Fn  Node    *Insert_Beg     (Node*, Cst IX);            /* Ex 04 */
Fn  Node    *Insert_End     (Node*, Cst IX);            /* Ex 05 */
Fn  Node    *Insert_End_R   (Node*, Cst IX);            /* Ex 06 */

Fn  In U0    Print          (Node*);                    /* Ex 07 */
Fn  In U0    Print_Inv      (Node*);                    /* Ex 08 */

Fn  Node    *Search         (Node*, Cst IX);            /* Ex 09 */

Fn  U0       Insert_After   (Node*, Cst IX);            /* Ex 10 */
Fn  Node    *Insert_After_R (Node*, Cst IX, Cst IX);    /* Ex de sala */

Fn  Node    *Remove         (Node*, Cst IX);            /* Ex 11 NOT */
Fn  Node    *Remove_R       (Node*, Cst IX);            /* Ex 12 NOT */

Fn  U32      Size           (Node*);                    /* Ex 13_1 */
Fn  U32      Size_R         (Node*);                    /* Ex 13_2 */

Fn  IX       Sum            (Node*);                    /* Ex 14_1 */
Fn  IX       Sum_R          (Node*);                    /* Ex 14_2 */

Fn  Node    *Invert         (Node*);                    /* Ex 15 NOT */
Fn  U0       Free           (Node*);                    /* Ex 16 */
Fn  Node    *Concat         (Node*, Node*);             /* Ex 17 NOT */ 

Fn  Node    *Array2List     (IX*, Cst U32);             /* Ex 18 */
Fn  U0       List2Array     (Node*, IX*, U32*);         /* Ex 19 */

/* Listas duplamente ligadas */

Fn  In U0    Print_After    (DNode*, U32);              /* Ex 21 */
Fn  In U0    Print_Before   (DNode*, U32);              /* Ex 22 */

Fn  In U0    Print_23       (DNode*);                   /* Ex 23 */
Fn  U0       Print_23_R     (DNode*);                   /* Ex 24 NOT */

Fn  Node    *Bubble         (DNode*);                   /* Ex 31 NOT */

/*
 * Exercício 02 - O(1)
 * Retorna uma lista ligada vazia (nula).
 */

Fn Node
*New_List(void)
{
    Node *List = NULL;

    return List;
}

/*
 * Exercício 03 - O(1)
 * Cria um nodo com o elemento Data.
 */

Fn Node
*New_Node(Cst IX Data)
{
    Node *New;

    if ((New = (Node *) malloc(sizeof(Node))) == NULL)
        err(errno, "malloc");

    New->Data = Data;
    New->Next = NULL;

    return New;
}

/*
 * Exercício 04 - O(1)
 * Insere um elemento no início da lista.
 */

Fn Node
*Insert_Beg(Node* List, Cst IX Data)
{
    Node *New = New_Node(Data);

    New->Next = List;

    return New;
}

/*
 * Exercício 05 - O(n)
 * Insere um elemento no final da lista.
 */

Fn Node
*Insert_End(Node *List, Cst IX Data)
{
    Node *Head = List;

    Node *New = New_Node(Data);

    while (Head->Next != NULL)
        Head = Head->Next;

    Head->Next = New;

    return List;
}

/*
 * Exercício 06 - Função Recursiva - O(n)
 * Insere um elemento no final da lista.
 */

Fn Node
*Insert_End_R(Node *List, Cst IX Data)
{
    if (List->Next == NULL)
    {
        Node *New = New_Node(Data);

        List->Next = New;

        return New;
    }

    Insert_End_R(List->Next, Data);

    return List;
}

/*
 * Exercício 07 - Função Recursiva - O(n)
 * Imprime em ordem os elementos de uma lista.
 */

Fn In U0
Print(Node *List)
{
    if (List == NULL)
        return;
    
    printf("%" PRIiMAX "\n", List->Data);

    Print(List->Next);
}

/*
 * Exercício 08 - O(n)
 * Imprime em ordem inversa os elementos de uma lista.
 */

Fn In U0
Print_Inv(Node *List)
{
    if (List == NULL)
        return;

    Print(List->Next);

    printf("%" PRIiMAX "\n", List->Data);
}

/*
 * Exercício 09 - O(n)
 * Procura o elemento Data na lista e return um ptr para o nodo ou NULL
 * caso não encontre.
 */

Fn Node
*Search(Node *List, Cst IX Data)
{
    Node *Head = List;

    while (Head != NULL)
    {
        if (Head->Data == Data)
            return Head;

        Head = Head->Next;
    }

    return NULL;
}

/*
 * Exercício 10 - O(1)
 * Insere um elemento logo apoś o nodo R.
 */

Fn U0
Insert_After(Node *R, Cst IX Data)
{
    Node *New = New_Node(Data);

    New->Next = R->Next->Next;

    R->Next   = New;
}

/*
 * Exercício de Sala - Função Recursiva - O(n)
 * Insere um elemento Data na posição N da lista.
 */

Fn Node
*Insert_After_R(Node *List, Cst IX Data, Cst IX N)
{
    if (N == 0)
    {
        Node *New = New_Node(Data);

        New->Next = List;

        return New;
    }

    List->Next = Insert_After_R(List->Next, Data, N-1);

    return List;
}

/*
 * Exercício 11
 * Remove da lista todas as ocorrências de Data.
 */

Fn Node
*Remove(Node* List, Cst IX Data)
{
    (void) List; (void) Data; return NULL;
}

/*
 * Exercício 12 - Função Recursiva
 * Remove da lista todas as ocorrências de Data.
 */

Fn Node
*Remove_R(Node *List, Cst IX Data)
{
    (void) List; (void) Data; return NULL;
}

/*
 * Exercício 13_1 - O(n)
 * Retorna o tamanho de uma lista.
 */

Fn U32
Size(Node *List)
{
    Node    *Head = List;
    Reg U32  i;

    for (i = 0; Head != NULL; i++)
        Head = Head->Next;

    return i;
}

/*
 * Exercício 13_2 - Função Recursiva - O(n)
 * Retorna o tamanho de uma lista.
 */

Fn U32
Size_R(Node *List)
{
    if (List == NULL)
        return 0;

    return (1 + Size(List->Next));
}

/*
 * Exercício 14_1 - O(n)
 * Retorna a soma dos seus elementos.
 */

Fn IX
Sum(Node *List)
{
    Node    *Head = List;
    Reg IX   ret  = 0;

    while (Head != NULL)
    {
        ret += Head->Data;
        Head = Head->Next;
    }

    return ret;
}

/*
 * Exercício 14_2 - Função Recursiva - O(n)
 * Retorna a soma dos seus elementos.
 */

Fn IX
Sum_R(Node *List)
{
    if (List == NULL)
        return 0;

    return (List->Data + Sum_R(List->Next));
}

/*
 * Exercício 15 - Função Recursiva
 * Inverte a ordem dos elementos de uma lista.
 */

Fn Node
*Invert(Node *List)
{
    (void) List; return NULL;
}

/*
 * Exercício 16 - Função Recursiva - O(n)
 * Libera uma lista.
 */

Fn U0
Free(Node *List)
{
    if (List == NULL)
        return;

    Free(List->Next);

    free(List);
}

/*
 * Exercício 17
 * Concatena duas listas.
 */

Fn Node
*Concat(Node *L1, Node *L2)
{
    (void) L1; (void) L2; return NULL;
}

/*
 * Exercício 18 - O(n)
 * Cria uma lista contendo os elementos de um vetor V de tamanho N.
 */

Fn Node
*Array2List(IX *V, Cst U32 N)
{
    Node    *List = New_List();
    Reg U32  i;

    for (i = 0; i < N; i++)
        Insert_End(List, V[i]);

    return List;
}

/*
 * Exercício 19 - O(n)
 * Cria um vetor contendo os elementos de uma lista.
 */

Fn U0
List2Array(Node *List, IX *V, U32 *N)
{
    Node    *Head = List;
    Reg U32  i;

    for (i = 0; Head != NULL; i++)
    {
        if ((V = reallocarray(V, i, sizeof(Node))) == NULL)
            err(errno, "reallocarray");

        V[i] = Head->Data;
        Head = Head->Next;
    }

    *N = i;
}

/*
 * Exercício 21 - O(n)
 * Imprime N elementos consecutivos iniciando pelo ptr List.
 */

Fn In U0
Print_After(DNode *List, U32 N)
{
    DNode *Head = List;

    for (; (N > 0) && (Head != NULL); N--)
    {
        printf("%" PRIiMAX "\n", Head->Data);

        Head = Head->Next;
    }
}

/*
 * Exercício 22 - O(n)
 * Imprime N elementos anteriores ao elemento apontado por List.
 */

Fn In U0
Print_Before(DNode *List, U32 N)
{
    DNode *Head = List;

    for (; (N > 0) && (Head != NULL); N--)
    {
        printf("%" PRIiMAX "\n", Head->Data);

        Head = Head->Prev;
    }
}

/*
 * Exercício 23 - O(n)
 * Imprime em ordem e em seguida imprime inversamente.
 */

Fn In U0
Print_23(DNode *List)
{
    DNode *Head = List;

    while (Head != NULL)
    {
        printf("%" PRIiMAX "\n", Head->Data);

        Head = Head->Next;
    }

    while (Head != List)
    {
        printf("%" PRIiMAX "\n", Head->Data);

        Head = Head->Prev;
    }
}

/*
 * Exercício 24 - Função Recursiva
 * Imprime em ordem e em seguida imprime inversamente.
 */

Fn U0
Print_23_R(DNode *List)
{
    (void) List;
}

/*
 * Exercício 31
 * Ordena uma lista duplamente ligada utilizando o BubbleSort.
 */

Fn Node
*Bubble(DNode *List)
{
    DNode   *Head;

    while (Head != NULL)
    {
        (void) 1;
    }

    /*
    for (i = 0; i < N; i++)
        for (j = i; j < N; j++)
            if (V[i] > V[j])
                Swap(&(V[0]), i, j);
    */
}

int
main(int argc, const char *argv[])
{
    (void) argc; (void) argv;

    return 0;
}


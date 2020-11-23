#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define vertex int

static int **MATRIXint( int r, int c, int val);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa um grafo. O campo adj é um ponteiro para a matriz de adjacências do grafo. O campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */
struct graph {
   int V; 
   int A; 
   int **adj; 
};
/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o endereço de um graph. */
typedef struct graph *Graph;

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinit() constrói um grafo com vértices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit( int V) { 
   Graph G = (struct graph *) malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint( int r, int c, int val) { 
   int **m = (int **) malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = (int *)malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */
void GRAPHshow( Graph G) { 
   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

int menu()
{
	setlocale(LC_ALL,"portuguese");
	
    int opcao;

    printf(" Menu de opções: \n\n");
    printf(" (1) Carregar textos \n");
    printf(" (2) Exibir palavras ordenadas  \n");
    printf(" (3) Pesquisar textos  \n");
    printf(" (4) Sair\n");
    printf("\n\n Selecione a opção : ");
    scanf("%d", &opcao);
    printf("\n\n");

    return opcao;
}

int main(){

  int op;

  do{
		op = menu();
		
		switch (op){
			
			case 1:{
				
			break;
			}
			case 2:{
				
			break;
			}
			case 3:{	
	     			
			break;
			}
			case 4:{
				
				printf(" Sair\n\n");
				
			break;
			}
			default:{
				
				printf(" Opção inválida!\n\n");	
				
			break;
			}			
		}
		
		system("pause");
    system("cls");
        
	}while(op!=4);
	Graph g1 = GRAPHinit(3);
  GRAPHinsertArc( g1, 0, 1);
  GRAPHinsertArc( g1, 0, 2);
	GRAPHshow(g1);
	return 0;
}
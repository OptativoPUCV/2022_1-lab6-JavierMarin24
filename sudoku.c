#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  
  int i,j,k;
  int valor;
  //revisión por columnas
  for(j=0; j<9 ;j++)
    {
       int *array=(int *)calloc(10,sizeof(int));
        for(i=0 ; i<9 ; i++)
        {
          //int *array=(int *)calloc(10,sizeof(int));
          valor = n->sudo[i][j];
          if(array[valor] == 1)
          {
            return 0 ;
          }
          else
          {
            if(valor!=0)
            {
              array[valor] = 1;
            }
          }
      
        } 
       /* for(int k = 0 ; k<10 ; k++)
        {
          array[k]=0;
        }  */ 
    
    }
    //revisión por filas
    for(i=0; i<9 ; i++)
    {
      int *array=(int *)calloc(10,sizeof(int));
      for(j=0; j<9 ; j++)
      {
        valor = n->sudo[i][j];
        if(array[valor] == 1)
        {
          return 0 ;
        }
        else
        {
          if(valor!=0)
          {
           array[valor] = 1 ;      
          }
          
        }
      }
      /*for(int k = 0 ; k<10 ; k++)
      {
        array[k]=0;
      }  */
    }
  //Revisión por submatriz
    for(k=0 ; k<9 ; k++)
    {
      int array[10] = {};
      for(int p=0;p<9;p++)
      {
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        valor = n->sudo[i][j];
        if(valor != 0 && array[valor] == 1)
        {
          return 0;
        }
        else
        {
          if(valor != 0)
          {
            array[valor] = 1;
          }
        } 
      }  
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j, valor ;
    for(i=0 ; i<9 ; i++)
    {
      //int valor = 1;
      for(j=0 ; j<9 ;j++)
      {
        if(n->sudo[i][j] == 0)
        {
          for(valor=1 ; valor<10 ; valor++)
          {
            n->sudo[i][j] = valor;
            if(is_valid(n))
            {
              Node* adj = copy(n);
              pushBack(list, adj);
            }
          } 
            n->sudo[i][j] =0;
            return list;      
        }

      }
      
    }
    return list;
}


int is_final(Node* n){
  int i,j;
  if(n == NULL) return 10;
  for(i=0 ; i<9 ; i++)
  {
    for(j=0; j<9 ;j++)
    {
      if(n->sudo[i][j]==0) return 0;
        
    }
  }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack* stack;
  stack=createStack();
  push(stack, initial);
  *cont = 0;
  while(get_size(stack) != 0)
    {
      Node* nodo;
      nodo= top(stack);
      pop(stack);
      *cont = *cont -1;
      if(is_final(nodo)==10) return NULL;
      if(is_final(nodo)==1)
      {
        return nodo;
      }
      List* adj = get_adj_nodes(nodo);
      Node* copia = first(adj);
      while( copia != NULL)
        {
          push(stack, copia);
          copia = next(adj);
          *cont = *cont +1;
        }
    }
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
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
  int array[10];
  int i,j,k;
  int valor;
  //revisión por columnas
  for(j=0; j<9 ;j++)
    {
      for(i=0 ; i<9 ; i++)
      {
        valor = n->sudo[i][j];
        if(array[valor-1] == 1)
        {
          return 0 ;
        }
        else
        {
          if(valor!=0)
          {
            array[valor-1] = 1;
          }
        }
    
      } 
      for(int k = 0 ; k<10 ; k++)
      {
        array[k]=0;
      }   
    
    }
    //revisión por filas
    for(i=0; i<9 ; i++)
    {
      for(j=0; j<9 ; j++)
      {
        valor = n->sudo[i][j];
        if(array[valor-1] == 1)
        {
          return 0 ;
        }
        else
        {
          if(valor!=0)
          {
           array[valor-1] = 1 ;      
          }
          
        }
      }
      for(int k = 0 ; k<10 ; k++)
      {
        array[k]=0;
      }  
    }
    for(k=0 ; k<9 ; k++)
    {
      array [10]={}
      for(int p=0;p<9;p++)
      {
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        valor = n->sudo[i][j];
        if(valor != 0 && array¨[valor-1] == 1)
        {
          return 0;
        }
        else
        {
          if(valor != 0)
          {
            array[valor-1] = 1;
          }
        }
        
        
       
    }
  
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j ;
    unsigned int valor;
    for(i=0 ; i<9 ; i++)
    {
      for(j=0 ; j<9 ;j++)
      {
        if(n->sudo[i][j] == 0)
        {
          for(valor=1 ; valor<10 ; valor++)
          {
            n->sudo[i][j] = valor;
            Node* adj = copy(n);
            pushBack(list, adj);
          }
        }

      }
      
    }
    n->sudo[i][j] =0;
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
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
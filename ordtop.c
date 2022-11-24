#include <stdio.h>
#include <stdlib.h>
void ordtop(int *vertnapt,int **arestas,int *ordenados, int lin, int nv, int ord, int *vertices);
int main (){
    int ord = 0;
    int nv = 0;
    int lin = 0;
    int *vertices, **arestas, *ordenados;
    scanf("%d", &nv);
    int am = (nv*(nv-1))/2;
    vertices = malloc(sizeof(int)*nv);
    ordenados = calloc(nv, sizeof(int)*nv);
    arestas = calloc(am, sizeof(int)*am);
    for(int i=0; i<nv; i++){
        vertices[i] = i+1;
    }
    for(int i=0; i<am; i++){
        arestas[i] = calloc(1, sizeof(int)*am);
    }
    for(int i=0; i<am; i++){
        scanf("%d", &arestas[i][0]);
        lin++;
        if(arestas[i][0] == EOF){
            lin--;
            break;
        }
        for(int j=1; j<2; j++){
            scanf("%d", &arestas[i][j]);
        }
    }
    int vertnapt[nv];
    for(int i=0; i<nv; i++){
        vertnapt[i] = vertices[i];
    }
    for(int i=0; i<nv; i++){
        for(int j=0; j<lin; j++){
            if(vertnapt[i] == arestas[j][1]){
            vertnapt[i] = 0;
            }
        }
    }
    ordtop(vertnapt, arestas, ordenados, lin, nv, ord, vertices);
    for(int i=0;i<nv;i++){
        printf("%d ", ordenados[i]);
    }
}
void ordtop(int *vertnapt,int **arestas,int *ordenados, int lin, int nv, int ord, int *vertices){
    int ctrl = 0;
    int cand = 0;
    for(int i=0; i<nv; i++){
        if(vertnapt[i]!=0){
            ordenados[ord] = vertnapt[i];
            ord++;
            vertnapt[i] = 0;
            }
        }
    for(int i=0; i<lin; i++){
        for(int j=0; j<nv; j++){
            if(arestas[i][0] == ordenados[j]){
                arestas[i][0] = 0;
            }
        }
    }
    while(arestas[ctrl][0] == 0){
        ctrl++;
    }
    cand = arestas[ctrl][0];
    for(int i=0; i<lin;i++){
        if(cand == arestas[i][1] && arestas[i][0] != 0){
            cand = arestas[i][0];
        }
    }
    ordenados[ord] = cand;
    ord++;
    if(ord < nv - 1){
        ordtop(vertnapt, arestas, ordenados, lin, nv, ord, vertices);
    }
    if(ord == nv - 1){
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++){
                if(ordenados[j] == vertices[i]){
                    vertices[i] = 0;
                }
            }
        }
        for(int i=0;i<nv;i++){
            if(vertices[i]!= 0){
                ordenados[ord] = vertices[i];
                ord++;
            }
        }
    }
}

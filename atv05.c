#include <stdio.h>

int comparacoes = 0;
int trocas = 0;

void reset(){
    comparacoes = 0;
    trocas = 0;
}

void mostrar(int v[], int n){
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);
    printf("\n");
}

/* Bubble Sort */
void bubble(int v[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comparacoes++;
            if(v[j] > v[j+1]){
                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
                trocas++;
            }
        }
    }
}

/* Selection Sort */
void selection(int v[], int n){
    for(int i=0;i<n-1;i++){
        int menor=i;
        for(int j=i+1;j<n;j++){
            comparacoes++;
            if(v[j] < v[menor])
                menor=j;
        }

        int t=v[i];
        v[i]=v[menor];
        v[menor]=t;
        trocas++;
    }
}

/* Insertion Sort */
void insertion(int v[], int n){
    for(int i=1;i<n;i++){
        int chave=v[i];
        int j=i-1;

        while(j>=0 && v[j]>chave){
            comparacoes++;
            v[j+1]=v[j];
            j--;
            trocas++;
        }

        v[j+1]=chave;
    }
}

/* Quick Sort */

int part(int v[], int ini, int fim){
    int pivo=v[fim];
    int i=ini-1;

    for(int j=ini;j<fim;j++){
        comparacoes++;
        if(v[j]<pivo){
            i++;
            int t=v[i];
            v[i]=v[j];
            v[j]=t;
            trocas++;
        }
    }

    int t=v[i+1];
    v[i+1]=v[fim];
    v[fim]=t;
    trocas++;

    return i+1;
}

void quick(int v[], int ini, int fim){
    if(ini<fim){
        int p=part(v,ini,fim);
        quick(v,ini,p-1);
        quick(v,p+1,fim);
    }
}

/* Merge Sort */

void merge(int v[], int l, int m, int r){
    int temp[100];
    int i=l,j=m+1,k=0;

    while(i<=m && j<=r){
        comparacoes++;
        if(v[i]<v[j])
            temp[k++]=v[i++];
        else
            temp[k++]=v[j++];
    }

    while(i<=m) temp[k++]=v[i++];
    while(j<=r) temp[k++]=v[j++];

    for(i=l,k=0;i<=r;i++,k++)
        v[i]=temp[k];
}

void mergeSort(int v[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    }
}

/* Shell Sort */

void shell(int v[], int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=v[i];
            int j=i;

            while(j>=gap && v[j-gap]>temp){
                comparacoes++;
                v[j]=v[j-gap];
                j-=gap;
                trocas++;
            }

            v[j]=temp;
        }
    }
}

/* Heap Sort */

void heapify(int v[], int n, int i){
    int maior=i;
    int e=2*i+1;
    int d=2*i+2;

    if(e<n && v[e]>v[maior])
        maior=e;

    if(d<n && v[d]>v[maior])
        maior=d;

    if(maior!=i){
        int t=v[i];
        v[i]=v[maior];
        v[maior]=t;
        trocas++;

        heapify(v,n,maior);
    }
}

void heap(int v[], int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(v,n,i);

    for(int i=n-1;i>0;i--){
        int t=v[0];
        v[0]=v[i];
        v[i]=t;
        trocas++;

        heapify(v,i,0);
    }
}

int main(){

    int v[100];
    int n=0;
    int qtd,op;

    printf("Escolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("4 - Quick Sort\n");
    printf("5 - Merge Sort\n");
    printf("6 - Shell Sort\n");
    printf("7 - Heap Sort\n");

    printf("Opcao: ");
    scanf("%d",&op);

    printf("\nQuantos valores deseja inserir? ");
    scanf("%d",&qtd);

    for(int i=0;i<qtd;i++){

        printf("\nDigite o valor: ");
        scanf("%d",&v[n]);

        n++;

        reset();

        if(op==1) bubble(v,n);
        if(op==2) selection(v,n);
        if(op==3) insertion(v,n);
        if(op==4) quick(v,0,n-1);
        if(op==5) mergeSort(v,0,n-1);
        if(op==6) shell(v,n);
        if(op==7) heap(v,n);

        printf("Estrutura atual: ");
        mostrar(v,n);

        printf("Comparacoes: %d\n",comparacoes);
        printf("Trocas: %d\n",trocas);
    }

    return 0;
}
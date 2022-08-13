#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct no{
    struct no *prox;
    int val;

};

int vazia(struct no *i){
    if (i==NULL)
        return(1);
    else
        return(0);
}

void insere (struct no **i, struct no **f, int elem){
    struct no *novo;
    novo = (struct no *) malloc (sizeof(struct no));
    novo->val = elem;

    if ((*f) == NULL){
        (*f) = (*i) = novo;
        (*f) ->prox = NULL;
    }else{
        (*f) ->prox = novo;
        (*f) = novo;
        (*f) ->prox = NULL;
    }
}

int retira(struct no **i, struct no **f){
    int elem;
    if((*i)==NULL){
            printf("Vazia");
            return 0;

    }else{
        elem = (*i)->val;
        (*i) = (*i)->prox;
        if((*i)==NULL){
            (*f)=NULL;
        };
        return elem;
    }
}

void consulta(struct no *i, struct no *sec){
    int pos = 1;
    printf("Posicão        Senha         Tipo\n\n");
    if(vazia(i)){

    }else{

        do{
            printf("%03d            %03d           Preferencial\n",pos, i->val);
            i = i->prox;
            pos++;
        }while(i!=NULL);
    }

    if(vazia(sec)){

    }else{
        do{
            printf("%03d            %03d           Normal\n",pos, sec->val);
            sec = sec->prox;
            pos++;
        }while(sec!=NULL);
        printf("\n");

    }
}

#endif // FILA_H_INCLUDED

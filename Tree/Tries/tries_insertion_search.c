#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALPHABET_SIZE 26

struct Trie{
    int value;
    struct Trie *children[26];
};

struct Trie *newNode(){
    struct Trie *temp=(struct Trie *)malloc(sizeof(struct Trie));
    temp->value=0;
    int i;
    for(i=0;i<ALPHABET_SIZE;i++){
        temp->children[i]=NULL;
    }
    return temp;
}

int indexof(char c){
    return ((int)c-(int)'a');
}

struct Trie *insert(struct Trie *root,char key[]){
    struct Trie *temp;
    if(root==NULL){
        root=newNode();
        temp=root;
    }
    int n=strlen(key);
    int i;
    for(i=0;i<n;i++){
            //printf("%d ",indexof(key[i]));
        if(root->children[indexof(key[i])])
            root=root->children[indexof(key[i])];
        else{
            root->children[indexof(key[i])]=newNode();
            root=root->children[indexof(key[i])];
        }
    }
    root->value=-1;
    return temp;
}

char charof(int i){
    return 'a'+i;
}

printTrie(struct Trie *root){
    if(root==NULL){
        return;
    }

    int i;
    for(i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]){
            printf("%c",charof(i));
            printTrie(root->children[i]);
            printf("\n");
        }
        //printf("\n");
    }
}

int searchTrie(struct Trie *root,char key[]){

    int n=strlen(key);
    int i;
    for(i=0;i<n;i++){
        if(root->children[indexof(key[i])]){
            root=root->children[indexof(key[i])];
        }
        else
            return 0;

    }
    if(root->value==-1)
        return 1;
    return 0;
}


main(){
    struct Trie *root=insert(NULL,"abc");
    insert(root,"abcde");
    //printf("%d \n",root->children[0]->children[1]->children[2]->value);
    //printTrie(root);

    printf("item search status %d\n ",searchTrie(root,"abcde"));


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct Trie {
    struct Trie *children[ALPHABET_SIZE];
    int count;
};
struct Trie *createNode() {
    struct Trie *newnode = (struct Trie *) malloc(sizeof(struct Trie));
    newnode->count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
   newnode->children[i] = NULL;
    }
    return newnode;
}
void insert(struct Trie **ppTrie, char *word) {
    struct Trie *temp1 = *ppTrie;
                         if (temp1 == NULL) {
        *ppTrie = createNode();
        temp1 = *ppTrie;
    }
    for (int i = 0; i < strlen(word); i++) {
     int index = word[i] - 'a';
          if (temp1->children[index] == NULL) {
     temp1->children[index] = createNode();
        }
     temp1 = temp1->children[index];
    }
    temp1->count++;
}
int numberOfOccurances(struct Trie *pTrie, char *word) {
    struct Trie *temp2 = pTrie;
for (int i = 0; i < strlen(word); i++) {
  
      int index = word[i] - 'a';
if (temp2->children[index] == NULL) {
       return 0;
  
        }
        temp2 = temp2->children[index];
    }
    return temp2->count;
}

struct Trie *deallocateTrie(struct Trie *pTrie) {
  if (pTrie != NULL) {
for (int i = 0; i < ALPHABET_SIZE; i++) {
  
   pTrie->children[i] = deallocateTrie(pTrie->children[i]);
        
                          }
 free(pTrie);
    }
return NULL;
}

int main(void) {
    struct Trie *trie = NULL;
    int numWords = 5;
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    // Insert each word into the trie and print the number of occurrences
    for (int i = 0; i < numWords; i++) {
        insert(&trie, pWords[i]);
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }

    // Deallocate the trie
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }
    return 0;
}
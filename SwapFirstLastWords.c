#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>


char **ChangeThePlace(char** text, int n) {
    char **new_text = (char**)malloc(n*sizeof(char *));
    for (int i = 0; i < n; i++) {
        new_text[i] = (char*) malloc(128*sizeof(char));
    }
    
    int first_word_lenght = 0; int last_word_lenght = 0;
    for (int line = 0; line < n; line++) {
        first_word_lenght = FirstWordLenght(text[line]);
        last_word_lenght = LastWordLenght(text[line]);
        
        for (int i = 0; i < last_word_lenght; i++) {
            new_text[line][i] = text[line][strlen(text[line]) - last_word_lenght + i];
        } 
        
        int diff = 0;
        diff = first_word_lenght - last_word_lenght; 
        
        for (int i = last_word_lenght; i < strlen(text[line]) - first_word_lenght; i++) {
            new_text[line][i] = text[line][diff + i];
        }
        
        for (int i = strlen(text[line]) - first_word_lenght; i < strlen(text[line]); i++) {
            new_text[line][i] = text[line][i - (strlen(text[line]) - first_word_lenght)];
        }
    }
    return new_text;
}


int LastWordLenght(char* text) {
    int last_len = 0; 
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            last_len = 0;
        }
        else {
            last_len += 1;
        }
        
    }
    return last_len;
}


int FirstWordLenght(char* text) {
    int first_len = 0; 
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            return first_len;
        }
        else {
            first_len += 1;
        }
        
    }
    return first_len;
}


void TextInput(char** text, int n) {
    for (int i = 0; i < n; i++) {
        gets(text[i]);
    }
}


char **TextArrayAlloc(int n) {
    char **text = (char**)malloc(n*sizeof(char *));
    for (int i = 0; i < n; i++){
        text[i] = (char*) malloc(128*sizeof(char));
    }

    return text;
}


void TextOutput(char** text, int n) {
    for (int i = 0; i < n; i++){
        puts(text[i]);
    }
}


void ArrayFree(char** text, int n) {
    for (int i = 0; i < n; i++) {
        free(text[i]);
    }
    free(text);
}




void main() {
    printf("\n");
    printf("Swap The First And Last Word In Places \n");
    printf("\n");
  
    int n;
    printf("Number Of String: ");
    scanf("%d%*c", &n);
  
    char** text = TextArrayAlloc(n);
    TextInput(text, n);
  
    printf("\n");
    printf("Result: \n");
    TextOutput(ChangeThePlace(text, n), n);
  
    ArrayFree(text, n);
}

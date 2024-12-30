#include <stdio.h>
#include <string.h>

void read(char *sentence, char *word) {
    printf("Enter a sentence: ");
    scanf(" %[^\n]%*c", sentence);
    printf("Enter the word to delete: ");
    scanf("%s", word);
}

void deleteWord(char *sentence, const char *word) {
    char temp[1000];
    int i = 0, j = 0, k;
    int wordLen = strlen(word);
    int sentenceLen = strlen(sentence);
    int found = 0;

    while (i < sentenceLen) {
        k = 0;
        while (k < wordLen && sentence[i + k] == word[k]) {
            k++;
        }

        if (k == wordLen && (sentence[i + k] == ' ' || sentence[i + k] == '\0')) {
            i += k;
            found = 1;
        } else {
            temp[j++] = sentence[i++];
        }
    }

    temp[j] = '\0';

    if (found) {
        strcpy(sentence, temp);
    } else {
        printf("The word '%s' was not found in the sentence.\n", word);
    }
}

void displaySentence(const char *sentence) {
    printf("Modified sentence: %s\n", sentence);
}

int main() {
    char sentence[1000], word[100];

    read(sentence, word);
    deleteWord(sentence, word);
    displaySentence(sentence);

    return 0;
}

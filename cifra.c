#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void Change(char *text, int pivot) {
    pivot = pivot % 26;
    if (pivot < 0) pivot += 26;
for(int ui = 0; text[ui] != '\0'; ui++){
 text[ui] = toupper((unsigned char)text[ui]);
}
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + pivot) % 26) + 'A';
        }
    }
}


int main() {
    int size, change;

    printf("How's the length of the message?\n");
    scanf("%d", &size);
    do{
    if (size <= 0 || size > 10000) {
    printf("Invalid size\nPut another input\n");
    scanf("%d", &size);
    }else{
        break;
    }
}while(1);

    getchar();

    char *text = malloc((size + 1) * sizeof(char));
    if(text == NULL){
        printf("malloc failed - not enough memory");
        return 1;
    }

    printf("Put the text here:\n");
    fgets(text, size + 1, stdin);

    printf("Now put the change for the cipher:\n");
    scanf("%d", &change);

    Change(text, change);

    printf("Your new text:\n%s", text);

    free(text);
    return 0;
}

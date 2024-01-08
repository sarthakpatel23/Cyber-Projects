#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main() {
    char text[1000], ch;
    int key, a;

    do {
        printf("\nPress 1 for encryption");
        printf("\nPress 2 for decryption");
        printf("\nPress 0 for exit");
        printf("\nEnter the digit: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("\nEnter a message to encrypt: ");
                scanf(" %[^\n]", text); 
                printf("\nEnter the key: ");
                scanf("%d", &key);

                for (int i = 0; text[i] != '\0'; ++i) {
                    ch = text[i];

                    if (isalnum(ch)) {
                        if (islower(ch)) {
                            ch = (ch - 'a' + key) % 26 + 'a';
                        }
                        if (isupper(ch)) {
                            ch = (ch - 'A' + key) % 26 + 'A';
                        }
                        if (isdigit(ch)) {
                            ch = (ch - '0' + key + 10) % 10 + '0';
                        }
                    }
                    else if (ch == ' ') {
                    } else {
                        printf("\nInvalid Message");
                        break;
                    }

                    text[i] = ch;
                }

                printf("\nEncrypted message: %s", text);
                break;

            case 2:
                printf("\nEnter a message to decrypt: ");
                scanf(" %[^\n]", text); 
                printf("\nEnter the key: ");
                scanf("%d", &key);

                for (int i = 0; text[i] != '\0'; ++i) {
                    ch = text[i];

                    if (isalnum(ch)) {
                        if (islower(ch)) {
                            ch = (ch - 'a' - key + 26) % 26 + 'a';
                        }
                        if (isupper(ch)) {
                            ch = (ch - 'A' - key + 26) % 26 + 'A';
                        }
                        if (isdigit(ch)) {
                            ch = (ch - '0' - key + 10) % 10 + '0';
                        }
                    }
                    else if (ch == ' ') {
                    } else {
                        printf("\nInvalid Message");
                        break;
                    }

                    text[i] = ch;
                }

                printf("\nDecrypted message: %s", text);
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("\nInvalid selection");
                break;
        }

    } while (a != 0);

    return 0;
}

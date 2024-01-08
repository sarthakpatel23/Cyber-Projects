#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int i, e;
    char password[50];

    do {
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;

        printf("\nPress 1 for password checking");
        printf("\nPress 0 for exit");
        printf("\nEnter the digit: ");
        scanf("%d", &e);

        getchar();

        switch (e) {
            case 1:
                printf("\nEnter the password: ");
                scanf("%s", password);

                if (strlen(password) < 8) {
                    printf("The password is too short\n");
                } else {
                    for (i = 0; i < strlen(password); i++) {
                        if (islower(password[i])) {
                            a = 1;
                        } else if (isupper(password[i])) {
                            b = 1;
                        } else if (isdigit(password[i])) {
                            c = 1;
                        } else {
                            d = 1;
                        }
                    }

                    if (a && b && c && d) {
                        printf("Strong password\n");
                    } else {
                        printf("Weak password\n");
                    }
                }
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("\nInvalid selection\n");
                break;
        }

    } while (e != 0);

    return 0;
}

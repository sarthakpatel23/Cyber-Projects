#include <stdio.h>
#include <string.h>

void encryptImage(FILE *inputFile, FILE *outputFile, char *key) {
    int ch, i = 0;
    
    while ((ch = fgetc(inputFile)) != EOF) {
        ch ^= key[i % strlen(key)];
        fputc(ch, outputFile);
        i++;
    }
}

void decryptImage(FILE *encryptedFile, FILE *decryptedFile, char *key) {
    int ch, i = 0;
    size_t key_length = strlen(key);

    while ((ch = fgetc(encryptedFile)) != EOF) {
        ch ^= key[i % key_length];
        fputc(ch, decryptedFile);
        i++;
    }
}

int main() {
    int a;
    char key[] = "encryption_key";

    do {
        printf("\nPress 1 for Encryption of image");
        printf("\nPress 2 for Decryption of image");
        printf("\nPress 0 to exit");
        printf("\nEnter the digit: ");
        scanf("%d", &a);

        switch (a) {
            case 1: {
                FILE *inputImage = fopen("C:\\Users\\Sarthak\\Desktop\\internship\\image1.jpg", "rb");
                FILE *encryptedImage = fopen("C:\\Users\\Sarthak\\Desktop\\internship\\encryptedimage1.jpg", "wb");

                if (inputImage == NULL || encryptedImage == NULL) {
                    perror("Error opening files");
                    return 1;
                }

                encryptImage(inputImage, encryptedImage, key);

                fclose(inputImage);
                fclose(encryptedImage);
                printf("Image Encryption is done check in assgined loctaion.\n");
                break;
            }
            
            case 2: {
                FILE *encryptedImage = fopen("C:\\Users\\Sarthak\\Desktop\\internship\\encryptedimage1.jpg", "rb");
                FILE *decryptedImage = fopen("C:\\Users\\Sarthak\\Desktop\\internship\\decrypted_image1.jpg", "wb");

                if (encryptedImage == NULL || decryptedImage == NULL) {
                    perror("Error opening files");
                    return 1;
                }

                decryptImage(encryptedImage, decryptedImage, key);

                fclose(encryptedImage);
                fclose(decryptedImage);
                printf("Image Decryption is done check in assgined loctaion.\n");
                break;
            }

            case 0:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid Selection\n");
                break;
        }
    } while (a != 0);

    return 0;
}

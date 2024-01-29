#include <stdio.h>
#include "toy.h"

int main() {
    short A[TK_K * TK_K * TK_N];
    short t[TK_K * TK_N];
    short s[TK_K * TK_N];
    short u[TK_K * TK_N];
    short v[TK_N];

    // Key generation
    toy_gen(A, t, s);

    // Encryption
    int plain ; 
    printf("Enter plaintext: ");
    scanf_s("%d", &plain);
    toy_enc(A, t, plain, u, v);

    // Decryption
    int decryptedText = toy_dec(s, u, v);

    printf("Encrypted values (u, v):\n");
    for (int i = 0; i < TK_K; ++i) {
        printf("%d ", u[i]);
    }
    printf("\n");
    for (int i = 0; i < TK_N; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Decrypted plaintext: %d\n", decryptedText);

    return 0;
}

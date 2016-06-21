#include <stdio.h>

void imprimirResponsavelPeloFeedback(int feedback);

int main (void) {
    int casos,
        quantidadeDeFeedbacks,
        feedback;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &quantidadeDeFeedbacks);

        while (quantidadeDeFeedbacks-- > 0) {
            scanf("%d", &feedback);

            imprimirResponsavelPeloFeedback(feedback);
        }
    }


    return 0;
}

void imprimirResponsavelPeloFeedback(int feedback) {
    switch (feedback) {
        case 1:
            printf("Rolien\n");
            break;
        case 2:
            printf("Naej\n");
            break;
        case 3:
            printf("Elehcim\n");
            break;
        case 4:
            printf("Odranoel\n");
            break;
    }
}

#include <stdio.h>
#include <string.h>

void process01(char *linha);
void process02(char *linha);
void process03(char *linha);

int main (void) {
  int n, i;
  char linha[1001];

  scanf("%d\n", &n);

  for (i = 0; i < n; i++) {
    scanf("%[^\n]\n", linha);

    process01(linha);
    process02(linha);
    process03(linha);

    printf("%s\n", linha);
  }

  return 0;
}

void process01(char *linha) {
  int i = 0;
  while(linha[i] != 0) {
    if ((linha[i] >= 'a' && linha[i]<= 'z')
        || (linha[i] >= 'A' && linha[i] <= 'Z')) {
      linha[i] = linha[i] + 3;
    }

    i++;
  }
}

void process02(char *linha) {
  size_t length = strlen(linha);
  char buffer;
  int i;
  for (i = 0; i < length / 2; i++) {
    buffer = linha[i];
    linha[i] = linha[length - i - 1];
    linha[length - i - 1] = buffer;
  }
}


void process03(char *linha) {
  size_t length = strlen(linha);
  int i;

  for (i = length / 2; i < length; i++) {
    linha[i] = linha[i] - 1;
  }
}

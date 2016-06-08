#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int compare(const void *a, const void *b);

int main (void) {
  int n, q;
  int wcase = 0;
  int i, j;
  
  int current;
  
  int values[SIZE];
  
  int index_i;
  
  int *foundAt;
  
  
  scanf("%d %d", &n, &q);
  
  while (q != 0 || n != 0) {
    wcase++;
    printf("CASE# %d:\n", wcase); 
    

    /* Read N */
    for (i = 0; i < n; i++) {
      scanf("%d", &values[i]);    
    }  
    
    qsort(values, n, sizeof(int), compare);   
    
    
    /* Find Q */
    for (i = 0; i < q; i++) {
      scanf("%d", &current);
      
      
      /* Caso o último for menor que o valor procurado */
      if (values[n - 1] < current) {
        printf("%d not found\n", current);
        continue;
      }
      
      
      foundAt = bsearch(&current, values, n, sizeof(int), compare);    
      if (foundAt == NULL) {
        printf("%d not found\n", current);
      }
      else {
        j = (foundAt - values);
        
        while (--j > -1 && values[j] == current);
        
        printf("%d found at %d\n", current, j + 2);        
      }      
    }
    
    scanf("%d %d", &n, &q);
  }
  
  return 0;
}


int compare(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}
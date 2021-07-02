#include <stdio.h>
#include <stdlib.h>
int CheckPrimo(n){
  int r = 0, p;
  if (n<2)
    n = 4;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
       r++;
    }
  }
  if (r==0) {
    p = 1;
  }else {
    p = 0;
  }
  return p;
};
int main(void) {
  float a, b, m = 0, r = 0;
  printf("Checagem: %d\n", CheckPrimo(0));
  printf("Escreva dois números inteiros: ");
  scanf("%f %f", &a, &b);

  if (b<a){
    int c = b;
    b = a;
    a=c;
  }

  int i = 1;
  FILE* f = fopen("votos.txt", "w");
  while(a+1<b){
    if (CheckPrimo(a+1)){
      m = a+1;
      i+=1;
      fprintf(f, "%f ", m);
    }
    a+=1;
  };
  fclose(f);

  i = 0;
  FILE* g = fopen("votos.txt", "r");
  while(fscanf(f, "%f ", &m) != EOF){
    r+=m;
    i+=1;
    printf("Primo %.2f\n", m);
  }
  fclose(g);
  printf("A média é %.2f\n", r/i);
  return 0;
}
#include <stdio.h>

#define LOWER -40
#define UPPER 300
#define STEP 20

float convertC(float fahr); 
float convertF(float cels);

int main() {
  float fahr, cels;
  printf("FAHRENHEIT TO CELSIUS CONVERSION TABLE\n");
  printf("%3s\t%6s\n", "F", "C");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%3.0f\t%6.1f\n", fahr, convertC(fahr));
  }
  printf("CELSIUS TO FAHRENHEIT CONVERSION TABLE\n");
  printf("%3s\t%6s\n", "C", "F");
  for (cels = UPPER; cels >= LOWER; cels = cels - STEP) {
    printf("%3.0f\t%6.1f\n", cels, convertF(cels));
  }

  return 0;
}

float convertC(float fahr) {
  return (5.0 / 9.0) * (fahr - 32);
}

float convertF(float cels) {
  return ((9.0 / 5.0) * cels) + 32.0;
}
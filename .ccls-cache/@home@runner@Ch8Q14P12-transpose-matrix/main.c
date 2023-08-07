// This program transposes the contents of a matrix

#include <stdio.h>
#include <stdlib.h>

// Declare Functions
void getInput ();
void transposeMatrix ();
void printOutput ();

// Declare Global Variables
int gMatrixWidth;
int gMatrixHeight;
int *gInputMatrixPtr;
int *gOutputMatrixPtr;

int main(void) {

  getInput ();

  transposeMatrix ();

  printOutput ();
  
  return 0;
}

// define Functions
void getInput () {
  printf ("Enter matrix width and height: ");
  scanf ("%d %d", &gMatrixWidth, &gMatrixHeight);
  printf ("\n");

  // Create variable array
  gInputMatrixPtr = malloc (gMatrixWidth * gMatrixHeight * sizeof (int));
  gOutputMatrixPtr = malloc (gMatrixWidth * gMatrixHeight * sizeof (int));

  // Fill gInputMatrixPtr
  printf ("Enter matrix contents\n");
  for (int i = 0; i < gMatrixHeight; i++) {
    printf ("Line %d: ", i);
    for (int j = 0; j < gMatrixWidth; j++) {
      scanf ("%d",&gInputMatrixPtr[i * gMatrixWidth + j]);
    }
  }
  printf ("\n");
}

void transposeMatrix () {
  for (int i = 0; i < gMatrixHeight; i++) {
    for (int j = 0; j < gMatrixWidth; j++) {
      gOutputMatrixPtr[j * gMatrixHeight + i] = gInputMatrixPtr[i * gMatrixWidth + j];
    }
  }
}

void printOutput (void) {
  printf ("Output Matrix\n");
  for (int i = 0; i < gMatrixWidth; i ++) {
    printf ("Line %d: ", i);
    for (int j = 0; j < gMatrixHeight; j++) {
      printf ("%d ", gOutputMatrixPtr[i * gMatrixHeight + j]);
    }
    printf ("\n");
  }
}
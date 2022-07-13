//Author: Tony Pham, Date: 07/29/2021, Functions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//usage help menu
void helpme() {
	printf("Usage: stats infile [outfile]\n");
}

void swap(float *x, float *y){
  int temp = *x;
  *x = *y;
  *y= temp;
}

void sort(float arr[], int n){
  int i, j, min;
  for (i = 0; i < n - 1; i++){
    min = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min])
        min = j;
    swap(&arr[min], &arr[i]);
  }
}

//used sort function to arrage array in order for median function
float median(float arr[], int n){
  sort(arr, n);
  float med;
  med = 0;
  //different formula whether array is even or odd
  if(n % 2 == 1){
    n = (n+1) / 2 - 1;
    return (float)arr[n];
  }
  else{
    med = (arr[n/2] + arr[(n/2) - 1]) / 2;
    return med;
  }
}

//mean function
//i variable can not be initialized in for loop functions in c99
float mean(float arr[], int n){
  float sum;
  sum = 0;
  int i;
  for(i = 0; i < n; i++){
    sum+= arr[i];
  }
  sum = sum / (float)n;
  return (float)sum;
}


//uses the mean function to find the variance
//i variable can not be initialized in for loop functions in c99, so had to move outside
float variance(float arr[], int n){
  float sum;
  sum = 0;
  sum = mean(arr, n);
  sum = sum * n;

  float sqDiff;
  float differ;
  sqDiff = 0;
  differ = 0;
  int i;
  for(i = 0; i < n; i++){
    differ = arr[i] - (sum/(float)n);
    sqDiff = sqDiff + pow(differ, 2);
  }
  sqDiff = sqDiff / (float)n;
  return sqDiff;
}

//simply square rooting the variance to find standardDeviation
float standardDev(float arr[], int n ){
  float standD;
  standD = 0;
  standD = variance(arr, n);
  standD = sqrt(standD);
  return standD;
}

//moved from main.c to functions.h to make main.c look cleaner
//this function is used when there is only infile argument
void parseCommands(int argc, char** argv, FILE **inputFile){
  const int ARR_SIZE = 1000;
  float array1 [ARR_SIZE];

  int i = 0;
  int count = 0;

  float average;
  average = 0;

  float sumaverage;
  sumaverage = 0;

  float variant;
  variant = 0;

  float standardDeviation;
  standardDeviation = 0;
  
  FILE *inputFilePointer;
  int inputFileCharacter;

  inputFilePointer = fopen(argv[1], "r");
  while(inputFileCharacter != EOF){
    fscanf(inputFilePointer, "%f", &array1[i]);
    i++;
    count++;
    inputFileCharacter = fgetc(inputFilePointer);
  }

  sumaverage = mean(array1, count);
  printf("Mean = %f \n", sumaverage);

  variant = variance(array1, count);
  printf("Variance = %f \n", variant);
      
  average = median(array1, count);
  printf("Median = %f \n", average);

  standardDeviation = standardDev(array1, count);
  printf("Standard Deviation = %f \n", standardDeviation);

  fclose(inputFilePointer);
}

//this function is used when outfile is also an arguement
void parseCommands2(int argc, char** argv, FILE **inputFile){
  const int ARR_SIZE = 1000;
  float array1 [ARR_SIZE];

  int i = 0;
  int count = 0;

  float average;
  average = 0;

  float sumaverage;
  sumaverage = 0;

  float variant;
  variant = 0;

  float standardDeviation;
  standardDeviation = 0;
  
  FILE *inputFilePointer;
  int inputFileCharacter;
  FILE *outputFilePointer;
  int outputFileCharacter;

  inputFilePointer = fopen(argv[1], "r");
  outputFilePointer = fopen(argv[2], "w");
  while(inputFileCharacter != EOF){
    fscanf(inputFilePointer, "%f", &array1[i]);
    i++;
    count++;
    inputFileCharacter = fgetc(inputFilePointer);
  }

  sumaverage = mean(array1, count);
  fprintf(outputFilePointer, "Mean = %f \n", sumaverage);

  variant = variance(array1, count);
  fprintf(outputFilePointer, "Variance = %f \n", variant);
      
  average = median(array1, count);
  fprintf(outputFilePointer, "Median = %f \n", average);

  standardDeviation = standardDev(array1, count);
  fprintf(outputFilePointer, "Standard Deviation = %f \n", standardDeviation);

  fclose(inputFilePointer);
  fclose(outputFilePointer);
}

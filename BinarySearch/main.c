//
//  main.c
//  BinarySearch
//
//  Created by Oliver Andrews on 2015-05-05.
//  Copyright (c) 2015 Oliver Andrews. All rights reserved.
//

#include <stdio.h>

typedef struct {
    int numberIndex;
    int numberOccurance;
}Range;

Range binarySearch(Range, int, int[], int, int);
int findMidPoint(int, int);


int main(int argc, const char * argv[]) {
    
    
    int numbers[] = {1,2,3,4,5,10,12,12,12,20,21,23,45,67};
    int arrayLength = sizeof(numbers)/sizeof(int);
    Range range;
    Range result = binarySearch(range, 12, numbers, 0, arrayLength);
    
    printf("%d,%d", result.numberIndex, result.numberOccurance);
    
    
    return 0;
}

int findMidPoint(int min, int max){
    int midpoint = (min+max)/2;
    return midpoint;
}

Range binarySearch(Range range, int key, int a[], int min, int max){
    if (min > max) {
        range.numberIndex = -1;
        range.numberOccurance = 0;
        return range;
    } else {
        int midIndex = findMidPoint(min, max);
        
        if (a[midIndex] < key) {
            return binarySearch(range, key, a, midIndex + 1, max);
        } else if (a[midIndex] > key) {
            return binarySearch(range, key, a, min, midIndex -1);
        } else {
            while (a[midIndex -1] == key) {
                midIndex--;
            }
            range.numberIndex = midIndex;
            range.numberOccurance = 1;
            while (a[midIndex +1] == key) {
                midIndex++;
                range.numberOccurance++;f
            }
            return range;
        }
    }
}





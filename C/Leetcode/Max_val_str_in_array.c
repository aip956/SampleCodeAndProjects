// 2496. Maximum Value of a String in an Array
// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/

#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>

int maximumValue(char ** strs, int strsSize){
    int max = 0;
    // printf("%d\n", strsSize);
    for (int i = 0; i < strsSize; i++) {
        int length = 0;
        int all_nums = 1;
        // printf("i, elem: %d %s\n", i, strs[i]);
        // printf("strs[i]: %s\n", strs[i]);
        for (int j = 0; strs[i][j] != '\0'; j++) {
            length ++;
            // printf("j,length: %d %d\n", j, length);
            // printf("j, isDig: %d %d\n", j, isdigit(strs[i][j]));
            if (isdigit(strs[i][j]) == 0 && all_nums == 1) {
                all_nums = 0;
                }
            // printf("j, all_nums: %d %d\n", j, all_nums);
        };
        if (all_nums == 1) {
            int temp = atoi(strs[i]);
            // printf("strsi -> num: %d\n", temp);
            if (temp > max) {
                max = temp;
                // printf("32max: %d\n", max);
            };
        }
        else {
            if (length > max) {
                max = length;
                // printf("38max: %d\n", max);
            }
        }
    // printf("41max: %d\n", max);
}
// printf("43max: %d\n", max);
return max;
};


int main() {
// char* strs[5] = {"alic3","bob","3","4","00000"};
char* strs[4] = {"1","01","001","0001"};
maximumValue(strs, 4);
return 0;
}

/*
For each string/element in array
Int max
    Is it all numbers?
        Yes: Convert to integer;
            Is integer > max?
                Yes, max = integer
        No: determine length of string
            Is length > max?
                Yes, max = length
*/
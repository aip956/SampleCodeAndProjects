#include <stdio.h>
#include <stddef.h>
#include <string.h>


char* my_strstr(char* haystack, char* needle) {
    int i = 0, j = 0, k = 0, m = 0, count = 0;
    int haystackstart;
    int jvsk;
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
        if (len2 == 0) {
            return haystack;
        }
        for (j = 0; haystack[j] !='\0'; j++) {
            //  printf("25,haystack[j], j: %c %d\n", haystack[j], j);
            //  printf("26,haystack[k], k: %c %d\n", needle[k], k);
            //  printf("27,count, %d\n", count);
            count = 0;
            if (haystack[j] == needle[0]) {
                // printf("30,haystack[j], j, haystack[0], 0: %c %d %c\n", haystack[j], j, needle[0]);
                haystackstart = j;
                // printf("32,haystackstart: %d\n", haystackstart);
                    jvsk = j;
                    // printf("37,jvsk: %d\n", jvsk);    
                    for (k = 0; k < len2; k++) {
                    // printf("33,k: %d\n", k);
                        if (haystack[jvsk] == needle[k]) {
                        // printf("35,haystack[jvsk], j, haystack[k], k: %c %d %c %d\n", haystack[jvsk], jvsk, needle[k], k);
                            jvsk++;
                            count++;
                                if (count == len2) {
                                return &haystack[haystackstart];
                                break;
                                }
                        }  // Ends line 28 loop
                    } // Ends line 26 loop
            } // Ends line 20 loop
        } //Ends line 15 loop
    return NULL;  
}

int main() {
    char str[100] = "mississippi";
    char subStr[100] = "issip";
  
printf("my_strstr -> %s\n", my_strstr(str, subStr));
printf("str: %s\n", str);
  return 0;
}

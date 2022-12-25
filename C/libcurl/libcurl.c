#include <stdio.h>
#include <curl/curl.h>
// #include <mongoc/mongoc.h>

// void function_pt(void *buffer, size_t size, size_t nmemb, void *userp) {
//     printf("%d\n, size");
// };
size_t write_data(char *buffer, size_t itemsize, size_t nitems, void *userp){
    char secret_code [4] = {0};
    int j = 0;
    size_t bytes = itemsize * nitems;
    printf("New chunk: (%zu bytes)\n", bytes);
    printf("# Items: %zu\n", nitems);
    for (int i = 0; i < nitems; i++) {
        printf("Item %d: %c\n", i, buffer[i]);
        printf("Asci: %d\n", buffer[i]);
        if (buffer[i] > 47 && buffer[i] < 56){
            secret_code[j] = buffer[i];
            printf("j, code[i]: %d, %c\n", j, secret_code[j]);
            j++;
        }
        
    }
    return bytes;

}

int main (void) {
    CURL *curl;
    CURLcode response;
    curl_global_init(CURL_GLOBAL_ALL);
    
    
    curl = curl_easy_init();
    if (curl) {
        // curl_easy_setopt(curl, CURLOPT_URL, "http://calapi.inadiutorium.cz/api/v0/en/calendars/general-en/2021/03");
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.random.org/integers/?num=4&min=0&max=7&col=4&base=10&format=plain&rnd=new");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        response = curl_easy_perform(curl);
        if (response != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response)); 
        } 
        // printf("%u\n", response);
        // else {
        //     printf("hello");
            // printf("%u\n", response);
        // }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;

}



// gcc -o libcurl libcurl.c -lcurl  
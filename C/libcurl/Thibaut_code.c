#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>
#include "header.h"
// #include "play_functions.h"

void my_bzero(void *s, size_t n) {
    char *byte = s;
    while (n > 0) {
        *byte++ = '\0';
        n -= 1;
    }
}

// char* save_data(char* buffer, t_game_state* game_state_ptr) {
//     printf("12buffer: %s\n", buffer);
//     printf("12Length: %d\n", game_state_ptr->length);
//     printf("14code: %s\n", game_state_ptr->secret);
//     int j = 0;
//     for (int i = 0; i < 10; i++) {
//         printf("Item %d: %c\n", i, buffer[i]);
//         printf("Asci: %d\n", buffer[i]);
//         if (buffer[i] >= '0' && buffer[i] < '8'){
//             game_state_ptr->secret[j] = buffer[i];
//             printf("19j, code[i]: %d, %c\n", j, game_state_ptr->secret[j]);
//             j++;
//             printf("23j: %d\n", j);
//         }
//     }
//     game_state_ptr->secret[j] = '\0';
//     // for (int j = 0; j < 6; j++) {

//     //     printf("25j, code[j]: %d, %c\n", j, game_state_ptr->secret[j]);
//     // }
//     printf("30code: %s\n", game_state_ptr->secret);
//     return game_state_ptr->secret;
// }

size_t write_data(char *buffer, size_t itemsize, int nitems, t_game_state* game_state){
    // char secret_code [6] = {0};
    // printf("buffer: %s\n", buffer);
    // printf("nitems: %d\n", nitems);
    printf("write_data ->length: %d\n", game_state->length);
    printf("write_data ->secret: %s\n", game_state->secret);
    int j = 0;
    size_t bytes = itemsize * nitems;
    printf("bytes: (%zu bytes)\n", bytes);
    // save_data(buffer, game_state);

    for (int i = 0; i < nitems; i++) {
        // printf("Item %d: %c\n", i, buffer[i]);
        // printf("Asci: %d\n", buffer[i]);
        if (buffer[i] >= '0' && buffer[i] < '8'){
            // secret_code[j] = buffer[i];
            game_state->secret[j] = buffer[i];
            // printf("j, code[i]: %d, %c\n", j, secret_code[j]);
            // printf("j, struct: %d, %c\n", j, game_state->secret[j]);
            j++;
        }
    }
    // printf("50code: %s\n", secret_code);
    // printf("51code: %s\n", game_state->secret);
    // for (int j = 0; j < nitems; j++) {

    //     printf("j, code[j]: %d, %c\n", j, game_state->secret[j]);
    // }
    printf("end write_data ->secret: %s\n", game_state->secret);
    return bytes;

}

void make_secret (t_game_state* game_state) {
    CURL *curl;
    CURLcode response;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    // char url[512] = "https://www.random.org/integers/?num=2&min=0&max=7&col=4&base=10&format=plain&rnd=new";
    char url[512] = {0};
    // int min, max;

    // if (...) {
    //     min = 3;
    // }
    snprintf(url, 512, "https://www.random.org/integers/?num=%d&min=%d&max=%d&col=4&base=10&format=plain&rnd=new", 3, min, max);
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        printf("make_secret ->length: %d\n", game_state->length);
        printf("make_secret ->secret: %s\n", game_state->secret);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, game_state);
        response = curl_easy_perform(curl);
        if (response != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response)); 
        } 
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int make_length (char** av, int ac) {
    int length = 4;
    char level = *av[1];
    printf("make_length: \n");
    printf("level: %c\n", level);
    printf("av: %c\n", *av[1]);
    
    // if e, length = 3
    // if m, length = 4
    // if h, length = 5
    if (ac > 1) {
        switch(level) {
            case 'e':
                length = 3;
                break;
            case 'm':
                length = 4;
                break;
            case 'h':
                length = 5;
                break;
        };
    printf("98Length: %d\n", length);   
    };
    return length;
}

int make_tries (char** av, int ac) {
    int tries = 10;
    // if ac > 1
    // if e, tries = 10
    // if m, tries = 10
    // if h, tries = 7
    if (ac > 1) {
        if (*av[1] == 'h') {
            tries = 7;
        };
    };
    return tries;
}

void prep_init_state(int ac, char** av, t_game_state* game_state) {
    // t_game_state game_state = {
    //     .secret = {0},
    //     .tries = 10, //make_tries(av, ac),
    //     .length = 6 //make_length(av, ac),
    // };
    game_state->tries = 10;
    game_state->length = 6;
    my_bzero(game_state->secret, 6);

    // t_game_state *game_state_ptr = &game_state;
    // printf("127Length: %d\n", game_state_ptr->length);
    printf("prep_init_state ->length: %d\n", game_state->length);
    printf("prep_init_state ->secret: %s\n", game_state->secret);
    make_secret(game_state);
}

int main(int ac, char** av) {
    t_game_state game_state;
    prep_init_state(ac, av, &game_state);

    // printf("\nmain .tries: %d\n", game_state.tries);
    printf("\nmain .length: %d\n", game_state.length);
    printf("main .secret: %s\n", game_state.secret);
    // for (int index = 0; index < 6; index++) {
    //     printf("code[%d]: %d, %c\n", index, game_state.secret[index], game_state.secret[index]);
    // }
    return 0;
}

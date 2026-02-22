#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdlib.h>
#include <string.h>

struct music {
    char s_name[30];
    struct music *next_song;
    struct music *prev_song; // Added for Doubly Linked List
};

// Helper to create a new node
struct music* create_node(char* name) {
    struct music* new_node = (struct music*)malloc(sizeof(struct music));
    strcpy(new_node->s_name, name);
    new_node->next_song = NULL;
    new_node->prev_song = NULL;
    return new_node;
}

int main() {
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);

    if (result != MA_SUCCESS)
    {
        return -1;
    }

    struct music *m1 = (struct music *)malloc(sizeof(struct music));
    strcpy(m1->s_name, "./songs/inkem.mp3");
    m1->next_song = NULL;
    
    struct music *m2 = (struct music *)malloc(sizeof(struct music));
    strcpy(m2->s_name, "./songs/indila.mp3");
    m2->next_song = m1;

    struct music *m3 = (struct music *)malloc(sizeof(struct music));
    strcpy(m3->s_name, "./songs/jhoom.mp3");
    m3->next_song = m2;

    m1->prev_song = m2;

    struct music *current = m3;
    char command;

    printf("Controls: [n] Next, [p] Previous, [q] Quit\n");

    while (current != NULL) {
        ma_sound sound;
        if (ma_sound_init_from_file(&engine, current->s_name, 0, NULL, NULL, &sound) == MA_SUCCESS) {
            ma_sound_start(&sound);
            printf("\nPlaying: %s\n", current->s_name);
            
            // In a real UI/Electron app, you wouldn't use scanf. 
            // This is a placeholder for the IPC signal you'll receive later.
            printf("Enter command: ");
            scanf(" %c", &command); 

            ma_sound_uninit(&sound);

            if (command == 'n') {
                if (current->next_song) current = current->next_song;
                else printf("End of playlist.\n");
            } 
            else if (command == 'p') {
                if (current->prev_song) current = current->prev_song;
                else printf("This is the first song.\n");
            } 
            else if (command == 'q') {
                break;
            }
        }
    }

    ma_engine_uninit(&engine);
    return 0;
}

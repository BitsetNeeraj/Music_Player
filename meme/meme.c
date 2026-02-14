
#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
#include "../miniaudio.h"
#include <stdlib.h>
#include <string.h>

struct music
{
    char s_name[30];
    struct music *next_song;
};

int main()
{

    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);

    if (result != MA_SUCCESS)
    {
        return -1;
    }

    struct music *m1 = (struct music *)malloc(sizeof(struct music));
    strcpy(m1->s_name, "./rakhMC.mp3");
    m1->next_song = NULL;
    
    struct music *m2 = (struct music *)malloc(sizeof(struct music));
    strcpy(m2->s_name, "./music.mpeg");
    m2->next_song = m1;

    struct music *m3 = (struct music *)malloc(sizeof(struct music));
    strcpy(m3->s_name, "./kya.mpeg");
    m3->next_song = m2;

    struct music *m4 = (struct music *)malloc(sizeof(struct music));
    strcpy(m4->s_name, "./gudgud.mp3");
    m4->next_song = m3;

    struct music *m5 = (struct music *)malloc(sizeof(struct music));
    strcpy(m5->s_name, "./achha.mp3");
    m5->next_song = m4;

    struct music *m6 = (struct music *)malloc(sizeof(struct music));
    strcpy(m6->s_name, "./gira.mp3");
    m6->next_song = m5;

    struct music *m7 = (struct music *)malloc(sizeof(struct music));
    strcpy(m7->s_name, "./hehe.mpeg");
    m7->next_song = m6;

    struct music *m8 = (struct music *)malloc(sizeof(struct music));
    strcpy(m8->s_name, "./ambh.mp3");
    m8->next_song = m7;

    struct music *start = m8;
    while (start != NULL)
    {
        ma_sound sound;
        ma_uint64 lengthInFrames;
        float durationInSeconds;

        // initializing the sound from the files
        if (ma_sound_init_from_file(&engine, start->s_name, 0, NULL, NULL, &sound) == MA_SUCCESS)
        {

            // 2. calculating the length of the sound
            ma_sound_get_length_in_pcm_frames(&sound, &lengthInFrames);
            durationInSeconds = (float)lengthInFrames / ma_engine_get_sample_rate(&engine);

            // 3. starting the sound
            ma_sound_start(&sound);
            printf("Playing: %s (%.2f seconds)\n", start->s_name, durationInSeconds);

            // 4. pausing the code to finish the song first then other
            ma_sleep((ma_uint32)(durationInSeconds * 1000));

            // 5. uninitalizing the each sound after it get finished
            ma_sound_uninit(&sound);
        }

        printf("Finished song, moving to next...\n");
        start = start->next_song;
    }
    printf("quit...");

    // finally uninitalizing the engine that i init at starting of the code
    ma_engine_uninit(&engine);
    return 0;
}
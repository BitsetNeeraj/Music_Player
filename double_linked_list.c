
#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <stdlib.h>
#include <string.h>

struct music
{
    char s_name[30];
    struct music *next_song;
    struct music *prev_song;
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
    strcpy(m1->s_name, "./songs/inkem.mp3");
    m1->next_song = NULL;
    
    struct music *m2 = (struct music *)malloc(sizeof(struct music));
    strcpy(m2->s_name, "./songs/jhoom.mp3");
    m2->next_song = m1;

    struct music *m3 = (struct music *)malloc(sizeof(struct music));
    strcpy(m3->s_name, "./songs/indila.mp3");
    m3->next_song = m2;

    m1->prev_song = m2;
    m2->prev_song = m3;
    m3->prev_song = NULL;

    struct music *start = m3;
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

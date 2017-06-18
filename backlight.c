#include <stdio.h>
#include <stdlib.h>

#define BACKLIGHT "/sys/class/backlight/intel_backlight/brightness"
#define BACKLIGHT_MAX "/sys/class/backlight/intel_backlight/max_brightness"
#define STEP 75

int main(int argc, char *argv[]) 
{
    int brightness, max;
    int inc = -STEP;
    FILE *backlight, *backlight_max;

    /* Read current level. */
    if((backlight = fopen(BACKLIGHT, "r")) == NULL) {
        perror("Could not open "BACKLIGHT);
        exit(EXIT_FAILURE);
    }
    fscanf(backlight, "%d", &brightness);
    fclose(backlight);
    /* Check so we do not try to increase over max level. */
    if (argv[1][0] == 'u') {
        if((backlight_max = fopen(BACKLIGHT_MAX, "r")) == NULL) {
            perror("Could not read max brightness level "BACKLIGHT_MAX);
            exit(EXIT_FAILURE);
        }
        fscanf(backlight_max, "%d", &max);
        if(brightness == max)
            exit(EXIT_SUCCESS);
        inc = STEP;
    }
    
    if (argv[1][0] == 'd' && !brightness)
        /* Backlight is already at lowest level, exit */
        exit(EXIT_SUCCESS);

    /* Set new level */
    if((backlight = fopen(BACKLIGHT, "w")) == NULL) {
        perror("Could not open "BACKLIGHT);
        exit(EXIT_FAILURE);
    }
    fprintf(backlight, "%d\n", brightness+inc);
    exit(EXIT_SUCCESS);
}

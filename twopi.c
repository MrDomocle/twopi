#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define PROGRESS_LEN 50
#define PROGRESS_STEP_DURATION 5e4

void rotate();

int main(int argc, char* argv[]) {
    int count = 1;
    double twopi = 2 * 3.141592653589793;
    int opt;
    while ( (opt = getopt(argc, argv, "he:n:")) != -1 ) {
        switch (opt) {
                case 'h':
                    printf("twopi [options]\n");
                    printf("TwoPi: instantaneously rotates your entire computer through 2*pi radians.\n");
                    printf("Options:\n");
                    printf("    -h: print this help\n");
                    printf("    -n(number): number of times to rotate. Default: 1\n");
                    printf("    -e(number): engineer level (0 to 2)\n");
                    printf("            Levels of engineer:\n");
                    printf("            0: double precision pi (default)\n");
                    printf("            1: 22/7 approximation\n");
                    printf("            2: 21/7 approximation\n");
                    return 0;
                break;
                case 'n':
                    count = atoi(optarg);
                break;
                case 'e':
                    switch (atoi(optarg)) {
                        case 1:
                            twopi = 2 * 22/7.0;
                        break;
                        case 2:
                            twopi = 2 * 21/7.0;
                        break;
                    }
                break;
        }
    }
    
    double angle;
    for (int i = 0; i < count; i++) {
        rotate();
        angle += twopi;
        printf("Rotated through %.4f rad\n",angle);
    }
    usleep(5e5);
    printf("Done!\n");
    return 0;
}

void rotate() {
    printf("Rotating");
    for (int i = 0; i < PROGRESS_LEN; i++) {
        printf(".");
        fflush(stdout);
        usleep(PROGRESS_STEP_DURATION);
    }
    printf("\n");
}

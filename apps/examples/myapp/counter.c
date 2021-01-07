#include "counter.h"

static double TimeSpecToSeconds(struct timespec* ts){
    return (double)ts -> tv_sec + (double)ts->tv_sec / 1000000000.0;
}


int start_counter()
{
    struct timespec start;
    struct timespec end;
    double elapsed_secs;

    int N = 1000;
    int i = 1;

    printf("Hello world! I am good at counting! Here I go... \n");
    clock_gettime(CLOCK_MONOTONIC, &start);
    printf("Start time %f \n", TimeSpecToSeconds(&start));
    while (i <= N) {
            printf("myapp seconds since called: %d\n", i);
            i = i + 1;
	    sleep(1);
    }
    printf("Done counting to 1000!\n");
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("End time %f \n", TimeSpecToSeconds(&end));
    elapsed_secs = TimeSpecToSeconds(&end) - TimeSpecToSeconds(&start);
    printf("See... I counted to 1000 in seconds");

    return 0;
}

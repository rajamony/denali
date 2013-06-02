#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    struct timeval tp;
    int min = atoi (argv[1]);
    int max = atoi (argv[2]);

    gettimeofday (&tp, NULL);
    double fraction = ((double) tp.tv_usec)/1e6;

    double howlong = min + fraction * (double) (max - min);

    if (howlong < 0)
        howlong = 0;
    if (howlong > 60)
	howlong = 60;

    useconds_t us = (useconds_t) (howlong * 1e6);
    printf ("Sleeping for %u micro-seconds\n", us);
    usleep (us);

    return 0;
}

//
// Created by rvali on 3/27/2019.
//

#include "stop_watch.h"
#include "utils.h"

static void* g_start_timer(void *args)
{
    void (*function_pointer)();

    int seconds = ((struct data_struct*) args)->seconds;
    function_pointer = ((struct data_struct*) args)->func_ptr;

    printf("=== go to sleep for %d\n", seconds);

    sleep(seconds);

    (void) (*function_pointer)();

    pthread_exit(NULL);

    return 0;
}

void start_stopwatch(struct data_struct *g_data_struct)
{
    pthread_t thread_id;
    int rc;

    int seconds = g_data_struct->seconds;
    printf("=== start_stopwatch(): %d\n", seconds);

//    rc =  pthread_create(&thread_id, NULL, g_start_timer, (void *) g_data_struct);
//    if(rc)
//        printf("=== Failed to create thread\n");
}

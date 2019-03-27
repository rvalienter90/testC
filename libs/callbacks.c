//
// Created by rvali on 3/27/2019.
//

#include "callbacks.h"
#include "stop_watch.h"
#include "utils.h"
/* call this when the time expires */
void timeout_cb()
{
    printf("=== your time is up run some job here ===\n");
}
int test_callback()
{
    struct data_struct *g_data_struct =
            (struct data_struct*) calloc(1, sizeof(*g_data_struct));

    if(!g_data_struct)
    {
        printf("=== failed to allocate memory ===\n");
        return 0;
    }

    g_data_struct->seconds = 3;
    g_data_struct->func_ptr = timeout_cb;

    //  printf("=== timeout_cb: %p\n", timeout_cb);

    start_stopwatch(g_data_struct);

    // free(g_data_struct);
    printf("=== End of Program - all threads in ===\n");

    pthread_exit(NULL);

    return 0;
}
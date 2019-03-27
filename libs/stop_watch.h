//
// Created by rvali on 3/27/2019.
//

#ifndef TEST_STOP_WATCH_H
#define TEST_STOP_WATCH_H
/* stop_watch.h */
struct data_struct
{
    int seconds;
    void (*func_ptr)(void);
};
void start_stopwatch(struct data_struct *g_data_struct);

#endif //TEST_STOP_WATCH_H

#ifndef _LOOP_H
 #define _LOOP_H

#include "app_data.h"

void loop(App_datas* datas);
void events(App_datas* datas, int i);
void log_msg(const char* restrict str);

#endif
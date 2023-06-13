#include "app_data.h"
#include "loop.h"

/**
 * @brief test function
*/
int say_hello(App_datas* datas)
{
    log_msg("I said Hello !!!\n");
    return 0;
}

/**
 * @brief this function literaly does nothing.
 * It is only used for debug features.
*/
int do_nothing(App_datas* datas)
{
    return 0;
}
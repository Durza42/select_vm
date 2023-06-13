#ifndef _APP_DATAS_H
#define _APP_DATAS_H

/// shortcut to get window's heigh
#define WIN_SIZE_H(win) (getmaxy(win))
/// shortcut to get window's width
#define WIN_SIZE_W(win) (getmaxx(win))

#include <stdlib.h>
#include <stdbool.h>

typedef struct App_datas App_datas;

#include "VM.h"
#include "fields.h"

/// maximum number of VM that this program can manage
#define MAX_NB_VM 4

/// max number of fields this program can manage
#define NB_MAX_FIELDS 64

/**
 * @brief main datas stored by this application. Using a struct to pass it between functions
 */
struct App_datas
{
    /// @brief list of every VM
    VM VMs[MAX_NB_VM];
    /// @brief max number of VM this program can manage
    size_t nb_vms;

    /// @brief list of the fields
    Field fields[NB_MAX_FIELDS];
    /// @brief number of fields 
    int nb_fields;

    /// @brief the id of the currently selected field
    int current_field;
};

bool add_VM(App_datas* datas, char* restrict name);
bool add_field(App_datas* datas, Func* foo, const int y, const int x, int next_id[4]);
int reverse(const int dir);

#endif
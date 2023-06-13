#include <string.h>
#include <ncurses.h>
#include "app_data.h"
#include "msg.h"
#include "loop.h"

/**
 * @brief adds one virtual machine to the list of shown VMs
 * 
 * @param datas the actual list of virtual machines used by the program
 * @param name the name of the new VM
 * @return true if the VM has been successfuly added
 * @return false if an error occured
 */
bool add_VM(App_datas* datas, char* restrict name)
{
    if(datas -> nb_vms + 1 >= MAX_NB_VM)
        return false;

    if(strlen(name) >= MAX_VM_NAME_LEN)
        name[MAX_VM_NAME_LEN - 1] = '\0';

    strncpy(datas -> VMs[datas -> nb_vms].name, name, strlen(name) + 1);
    ++datas -> nb_vms;

    return true;
}

/**
 * @brief adds a new field
 * 
 * @param datas a pointer to the datas of the application
 * @param y the line of the new field
 * @param x the column of the new field
 * @param next the list of every other fields accessible from thisone.
 * It contains 4 elements, corresponding to the 4 dimentions.
 * Every dimention contains the id of the field accessible in this way, or -1 if no field is accessible this way.
 * @return true if the field has been successfuly added
 * @return false if an error occured
 */
bool add_field(App_datas* datas, Func* foo, const int y, const int x, int next_id[4])
{
    if(datas -> nb_fields >= NB_MAX_FIELDS)
        return false;

    const int id_new_field = datas -> nb_fields;
    ++(datas -> nb_fields);

    datas -> fields[id_new_field].id = id_new_field;
    datas -> fields[id_new_field].x = x;
    datas -> fields[id_new_field].y = y;

    log_msg("\n##########\n");
    log_msg("current id: ");
    char c = '0' + id_new_field;
    log_msg(&c);
    log_msg("\nnext_ids : \n");

    for(int i = 0 ; i < 4 ; ++i)
    {
        datas -> fields[id_new_field].next_id[i] = next_id[i];

        c = '0' + next_id[i];
        log_msg(&c);
        log_msg(" ; ");

        if(next_id[i] == -1)
            continue;

        // if A goes to B upward, B must goes to A downward.
        datas -> fields[next_id[i]].next_id[reverse(i)] = id_new_field;
    }

    datas -> fields[id_new_field].action = foo;

    return true;
}

/**
 * @brief compute the opposite direction of a given direction
 * 
 * @param dir the given direction
 * @return int the opposite direction
 */
int reverse(const int dir)
{
    if(dir == -1)
        return -1;

    return (dir + 2) % 4;
}
#include <string.h>
#include <ncurses.h>
#include "app_data.h"
#include "msg.h"

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
bool add_field(App_datas* datas, const int y, const int x, int next[4])
{
    if(datas -> nb_fields >= NB_MAX_FIELDS)
        return false;

    ++datas -> nb_fields;

    datas -> fields[datas -> nb_fields].id = datas -> nb_fields;
    datas -> fields[datas -> nb_fields].x = x;
    datas -> fields[datas -> nb_fields].y = y;

    for(int i = 0 ; i < 4 ; ++i)
    {
        datas -> fields[datas -> nb_fields].next_id[i] = next[i];
        if(next[i] == -1)
            continue;
        // if if A goes to B upward, B must goes to A downward.
        datas -> fields[next[i]].next_id[reverse(i)] = datas -> fields[datas -> nb_fields].id;
    }
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
    else
        return (dir + 2) % 4;
}
#ifndef _VM_H
#define _VM_H

/// max length of a VM's name
#define MAX_VM_NAME_LEN 32

/**
 * @brief main elements to characterize one VM
 */
typedef struct VM VM;
struct VM
{
    /// @brief VM's name
    char name[MAX_VM_NAME_LEN];
};

#endif
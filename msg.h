#ifndef _MSG_H
 #define _MSG_H

/// message displayed to introduce the virtual machines list
#define MSG_list_VM "currently launched virtual machines:"
/// y pos of the message displayed to introduce the virtual machines list
#define MSG_list_VM_y(win) 1
/// x pos of the message displayed to introduce the virtual machines list
#define MSG_list_VM_x(win) 3

/// message displayed to add virtual machine
#define MSG_add_VM "+ [add virtual machine]"
/// y pos of the message displayed to add virtual machine
#define MSG_add_VM_y(win) (WIN_SIZE_H(win) - 2)
/// x pos of the message displayed to add virtual machine
#define MSG_add_VM_x(win) 3

/// x pos of the name of the first VM
#define MSG_name_VM_x(win) (MSG_list_VM_x(win) + 2)
/// y pos of the name of the first VM
#define MSG_first_name_VM_y(win) (MSG_list_VM_y(win) + 3)

#ifdef _DEBUG
 #define DEBUG_MSG_y(win) (getmaxy(win) - 1)
 #define DEBUG_MSG_x(win) (0)
#endif

#endif
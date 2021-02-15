#ifndef __ALIPAY_BT_H__
#define __ALIPAY_BT_H__

// offsets for 1.1.2.05 non-latin
#define ALIPAY_TASK_CREATE_ADDR 0x08033028 + 1
#define ALIPAY_TASK_DELETE_ADDR 0x08033054 + 1
#define ALIPAY_SET_MSG_HANDLER_ADDR 0x0804A104 + 1
#define ALIPAY_SEND_HOST_DATA_ADDR 0x0801509C + 1

/*
// offsets for 1.1.5.36 latin
#define ALIPAY_TASK_CREATE_ADDR 0x080323f4 + 1
#define ALIPAY_TASK_DELETE_ADDR 0x08032420 + 1
#define ALIPAY_SET_MSG_HANDLER_ADDR 0x080492F0 + 1
#define ALIPAY_SEND_HOST_DATA_ADDR 0x080150B0 + 1
*/

typedef void (*pf_alipay_task_create)();
typedef void (*pf_alipay_task_delete)();
typedef void (*pf_alipay_set_msg_handler)(void *handler);
typedef int (*pf_alipay_send_host_data)(void *buf, int len);

pf_alipay_task_create alipay_task_create = (pf_alipay_task_create)ALIPAY_TASK_CREATE_ADDR;
pf_alipay_task_delete alipay_task_delete = (pf_alipay_task_delete)ALIPAY_TASK_DELETE_ADDR;
pf_alipay_set_msg_handler alipay_set_msg_handler = (pf_alipay_set_msg_handler)ALIPAY_SET_MSG_HANDLER_ADDR;
pf_alipay_send_host_data alipay_send_host_data = (pf_alipay_send_host_data)ALIPAY_SEND_HOST_DATA_ADDR;

/*
first, define a message handler with the signature:
 void custom_msg_handler(byte *data, int len);

then, to hook the message handler, init:
 alipay_task_create();
 alipay_set_msg_handler(custom_msg_handler);

send to host:
 alipay_send_host_data(data, len);

on exit, deinit:
 alipay_task_delete();
 alipay_set_msg_handler(NULL);
*/
#endif
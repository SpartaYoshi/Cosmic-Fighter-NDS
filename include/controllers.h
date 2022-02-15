#ifndef _controllers
#define _controllers
/**********************************************************
 * controllers.h
 **********************************************************/

extern void enable_interrupts();
extern void configure_control_registers();
extern void define_interrupt_vector_table();
extern void disable_interrupts();

extern void interrupts_setting();

#endif
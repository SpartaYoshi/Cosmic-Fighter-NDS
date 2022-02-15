/**********************************************************
 * controllers.c
 **********************************************************/

/* 
 * Añadir los includes que sean necesarios
 **/
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "keypad_screen.h"
#include "timers.h"


/* 
 * Habilitar las interrupciones. En el Controlador de Interrupciones
 **/
void enable_interrupts() { 	
	
	IME = 0; 							// Disable interruption
	
	IE = IE | 0x1008; 					// Enabled bits: IRQ_KEYS, IRQ_TIMER0
	
	IME = 1; 							// Enable interruption
  
} // enable_interrupts()






/* 
 * Programar los registros de control. Aquí es donde se configuran los 
 * registros de control de los periféricos.
 **/
void configure_control_registers() { 

	KEYS_CNT = 0x400E;					// Registro de Control del teclado			(B, START, SELECT)
  
	TIMER0_CNT = 0x00C1;				// Registro de Control del Temporizador		(freq = 64)
	TIMER0_DAT = 39322;					//											(20 ticks / s)

} // configure_control_registers()







/* 
 * Este procedimiento inicializa el vector de interrupciones para que 
 * el gestor de interrupciones sepa que rutina de atencion tiene que 
 * ejecutar cuando le llega una peticion de interrupcion.
 **/
void define_interrupt_vector_table() { 
	irqSet(IRQ_KEYS, keypad_handler);  // Rutina de Atencion al Teclado
	irqSet(IRQ_TIMER0, timer_handler); // Rutinas de Atencion a los Temporizador
} // DefinirVectorInterrupciones()










/* 
 * Inhibe las interrupciones. En el Controlador de Interrupciones
 **/
void disable_interrupts() { 

	IME = 0; 							// Disable interruption
	
	IE = IE & 0xFFFFEFF7;				// Disable bits: IRQ_KEYS, IRQ_TIMER0
	
	IME = 1; 							// Enable interruption

} // disable_interrupts()










void interrupts_setting() {

  enable_interrupts();
  configure_control_registers();
  define_interrupt_vector_table();
 
}  // interrupts_setting()




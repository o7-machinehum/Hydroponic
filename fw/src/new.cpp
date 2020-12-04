#ifdef __cplusplus
extern "C" {
#endif

#include "stddef.h"
#include "FreeRTOS.h"
// #include "stm32l4xx_hal.h"

extern void HardFault_Handler();

void error(void)
{
  while(1){
    // NVIC_SystemReset(); 
  }
}

// 
// void vApplicationStackOverflowHook( TaskHandle_t xTask,
//                                     signed char *pcTaskName )
// {
//   error();
// }
// 
// void vApplicationMallocFailedHook()
// {
//   error();
// }

void* operator new( size_t size )
{
  void* out = pvPortMalloc( size ); 
	
  if(out)
    return out;
  else
    error();
}

void operator delete( void * ptr )
{
	vPortFree ( ptr );
}

void operator delete( void * ptr , unsigned in)
{
	vPortFree ( ptr );
}

#ifdef __cplusplus
}
#endif

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : FreeRTOS applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "app.h"
//#include "cli_app.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
  static StaticTask_t exampleTaskTCB;
  static StackType_t exampleTaskStack[ configMINIMAL_STACK_SIZE ];

#if 0
  osThreadId_t cmdLineTaskHandle; // new command line task
const osThreadAttr_t cmdLineTask_attributes = {
  .name = "cmdLineTask", // defined in cli_app.c
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
#endif
/* Private function prototypes -----------------------------------------------*/
static void exampleTask( void * parameters ) __attribute__( ( noreturn ) );


/* Private application code --------------------------------------------------*/
/*-----------------------------------------------------------*/

static void exampleTask( void * parameters )
{
    /* Unused parameters. */
    ( void ) parameters;

    for( ; ; )
    {
        /* Example Task Code */
        vTaskDelay( 100 ); /* delay 100 ticks */
    }
}
/*-----------------------------------------------------------*/


/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */

void FREERTOS_Init(void) {

  /* add mutexes, ... */
  /* add semaphores, ... */
  /* start timers, add new ones, ... */
  /* add queues, ... */

  /* creation of defaultTask */
  ( void ) xTaskCreateStatic( exampleTask,
                              "example",
                              configMINIMAL_STACK_SIZE,
                              NULL,
                              configMAX_PRIORITIES - 1U,
                              &( exampleTaskStack[ 0 ] ),
                              &( exampleTaskTCB ) );



  //defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* add threads, ... */
  //cmdLineTaskHandle = osThreadNew(vCommandConsoleTask, NULL, &cmdLineTask_attributes);

  /* add events, ... */

}
/**
* @brief Function implementing the defaultTask thread.
* @param argument: Not used
* @retval None
*/
void StartDefaultTask(void *argument)
{
  (void)argument;
  /* Infinite loop */
  for(;;)
  {
//    osDelay(500);
    /* Toggle the green LED */
    BSP_LED_Toggle(LED_GREEN);
  }
}

/* Private application code --------------------------------------------------*/

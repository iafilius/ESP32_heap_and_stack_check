/* A demo to demo some concepts:
 *  Heap R-DAM/IRAM
 *  Task(s) stack high watermark
 *  Using multicore/tasks devided multiple core's
 *  Serial output synchronization using Mutex Semaphores
 *  show key values of compiler/date/time/ arduino IDE/ESP32 arduino core version  etc. 
 *  
 *  Issues:
 *  The stack/heap information should go into a macro for preventing duplicate code. using a funciton, shows just that function in ESP_LOGI functions
 *  This demo does no actual work, but easy to use some concepts
 */

/* 
 *  Resources Used
 https://www.esp32.com/viewtopic.php?t=1556
 https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/system/heap_debug.html
 https://www.esp8266.com/viewtopic.php?f=32&t=3900
 https://www.esp32.com/viewtopic.php?f=2&t=44
 https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/system/system.html
 http://exploreembedded.com/wiki/Read_Task_Info_%3A_vTaskList()
 https://www.freertos.org/a00021.html#vTaskList
 https://www.hackster.io/feilipu/using-freertos-semaphores-in-arduino-ide-b3cd6c
 https://github.com/espressif/esp-idf/blob/master/docs/en/api-reference/system/heap_debug.rst#id20
*/

// ./hardware/esp32/1.0.1-rc2/tools/sdk/include/freertos/freertos/FreeRTOS.h
//#define configUSE_TRACE_FACILITY 1
//#define configUSE_STATS_FORMATTING_FUNCTIONS 1

#include <esp_system.h>
#include <esp_spi_flash.h>
#include <freertos/task.h>
#include <core_version.h>
#include <esp_flash_encrypt.h>

//# ARDUINO_RUNNING_CORE isn't exported anywhere else..
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif


// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;

// Use handles to controll/find the tasks afterwards, pointer set with xCreateTask
TaskHandle_t TaskHandle1 = NULL;
TaskHandle_t TaskHandle2 = NULL;
TaskHandle_t TaskHandle3 = NULL;
TaskHandle_t TaskHandle4 = NULL;

void setup() {
int previous_number_of_taks=uxTaskGetNumberOfTasks();   // This returns 8 tasks, while calls to uxTaskGetNumberOfTasks provide 7. why is that?

      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);

      ESP_LOGI(TAG, "Before Starting Serial: ESP.getFreeHeap: %d",ESP.getFreeHeap());
   Serial.begin(112500);
      ESP_LOGI(TAG, "After Startign Serial: ESP.getFreeHeap: %d",ESP.getFreeHeap());
      ESP_LOGI(TAG, "After Serial.begin: Previous Number of tasks: %d , Total currentNumber of tasks: %d", previous_number_of_taks,uxTaskGetNumberOfTasks());

      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Total currentNumber of tasks: %d",uxTaskGetNumberOfTasks());
      delay(200);
      ESP_LOGI(TAG, "Task Setup : Priority: %d, Named: %s, State: %s", uxTaskPriorityGet(NULL),       pcTaskGetTaskName(NULL),       eTaskState_To_String(eTaskGetState(xTaskGetCurrentTaskHandle())) );

   // print as much as possible version information, for easy generating a bugreport
   Serial.println("ESP32 serial, heap/debug ...  demo");
   printf( "Compiled: " __DATE__ ", " __TIME__ ", Compiler: " __VERSION__ " Arduino: %d File: " __FILE__"\n", ARDUINO);
   printf("ESP.getSdkVersion: %s, tskKERNEL_VERSION: %s\n",ESP.getSdkVersion(),tskKERNEL_VERSION_NUMBER);
   //Serial.println(esp_get_idf_version());
   printf("ARDUINO ESP32 Version: %s\n",ARDUINO_ESP32_RELEASE);

   #ifdef CONFIG_FREERTOS_CHECK_STACKOVERFLOW_NONE
   printf("Stack Check validation mechanism: CONFIG_FREERTOS_CHECK_STACKOVERFLOW_NONE\n"); 
   #endif
   #ifdef CONFIG_FREERTOS_CHECK_STACKOVERFLOW_PTRVAL
   printf("Stack Check validation mechanism: %d\n",CONFIG_FREERTOS_CHECK_STACKOVERFLOW_PTRVAL);
   #endif
   #ifdef CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY
   printf("Stack Check validation mechanism: CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY\n");
   #endif

   //printf("Resulting Stack Check mechanism#: %d\n",configCHECK_FOR_STACK_OVERFLOW);

  // In make menuconfig, under Component config there is a menu Heap memory debugging. The setting :ref:`CONFIG_HEAP_CORRUPTION_DETECTION` can be set to one of three levels:
  #ifdef CONFIG_HEAP_POISONING__DISABLED
    printf("Heap validation mechanmism: CONFIG_HEAP_POISONING__DISABLED\n");
  #endif
  #ifdef CONFIG_HEAP_POISONING_LIGHT
    printf("Heap validation mechanmism: CONFIG_HEAP_POISONING_LIGHT\n");
  #endif
  #ifdef CONFIG_HEAP_POISONING_COMPREHENSIVE
    printf("Heap validation mechanmism: CONFIG_HEAP_POISONING_COMPREHENSIVE\n");
  #endif

  
  /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("ARDUINO_RUNNING_CORE=%d\n",ARDUINO_RUNNING_CORE);

    printf("Setup() Running on Core: %d\n",xPortGetCoreID());



  // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
  // because it is sharing a resource, such as the Serial port.
  // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

 printf("Stack constants: Minimal size : %dUnit(s), Unit width: %dByte(s)\n",configMINIMAL_STACK_SIZE, sizeof(StackType_t));
 //printf("Heap constants: Application: %d, total: %d\n",configAPPLICATION_ALLOCATED_HEAP,configTOTAL_HEAP_SIZE);
 printf("Heap constants: Application: %d, total: <gives an _heap_start was not declared error>\n",configAPPLICATION_ALLOCATED_HEAP);
 printf("Stack predefined constants:\n Main: %d\n IPC: %d \n ADP SYNK: %d\n TIMER: %d\n FREETOS IDLE %d\n PTHREAD MIN: %d\n MB Serial: %d\n TCPIP: %d\n BTC: %d\n MB Controller: %d\n EMAC: %d\n SYSTEM Event: %d\n FREETOS ISR: %d\n ESP32 PTHREAD: %d\n",
        CONFIG_MAIN_TASK_STACK_SIZE,
        CONFIG_IPC_TASK_STACK_SIZE,
        CONFIG_A2DP_SINK_TASK_STACK_SIZE,
        CONFIG_TIMER_TASK_STACK_SIZE,
        CONFIG_FREERTOS_IDLE_TASK_STACKSIZE,
        CONFIG_PTHREAD_STACK_MIN,
        CONFIG_MB_SERIAL_TASK_STACK_SIZE,
        CONFIG_TCPIP_TASK_STACK_SIZE,
        CONFIG_BTC_TASK_STACK_SIZE,
        CONFIG_MB_CONTROLLER_STACK_SIZE,
        CONFIG_EMAC_TASK_STACK_SIZE,
        CONFIG_SYSTEM_EVENT_TASK_STACK_SIZE,
        CONFIG_FREERTOS_ISR_STACKSIZE,
        CONFIG_ESP32_PTHREAD_TASK_STACK_SIZE_DEFAULT);


 //printf("Size of TaskHandle_t: %d\n",sizeof(TaskHandle_t));   // see if it would be an easy option to brute force.
 printf("ESP Flash encryption enabled: %d\n",esp_flash_encryption_enabled());
 
// Set/set Verbose level on ESP-IDF level
// seems hardcoded to Arduino IDE settings, but not managable by esp_log_level_set()!!
// https://github.com/espressif/arduino-esp32/commit/409c75da042192ba5dbeb13cbde6c41e0674ed6e
    ESP_LOGI(TAG, "Redirect ESP32 ULOG to Arduino logging functions (CONFIG_ARDUHAL_ESP_LOG): %d",CONFIG_ARDUHAL_ESP_LOG);

    esp_log_level_set("*", ESP_LOG_NONE);  
    ESP_LOGE("TAG", "1Error");
    ESP_LOGW("TAG", "1Warning");
    ESP_LOGI("TAG", "1Info");
    ESP_LOGD("TAG", "1Debug");
    ESP_LOGV("TAG", "1Verbose");

    //esp_log_level_set("*", ESP_LOG_VERBOSE);  
    ESP_LOGE("TAG", "Error");
    ESP_LOGW("TAG", "Warning");
    ESP_LOGI("TAG", "Info");
    ESP_LOGD("TAG", "Debug");
    ESP_LOGV("TAG", "Verbose");

    log_v("Verbose");
    log_d("Debug");
    log_i("Info");
    log_w("Warning");
    log_e("Error");

  xTaskCreate(
                    DebugTask,       /* Task function. */
                    "DebugTask1",     /* String with name of task. */
                    10000,             /* Stack size in bytes (for ESP32), RTOS standard is word. */
                    NULL,              /* Parameter passed as input of the task */
                    3,                 /* Priority of the task. */
                    &TaskHandle1);             /* Task handle. may be NULL*/
 
  xTaskCreate(
                    DebugTask,       /* Task function. */
                    "DebugTask2",     /* String with name of task. */
                    5000,             /* Stack size in bytes (for ESP32), RTOS standard is words. */
                    NULL,              /* Parameter passed as input of the task */
                    4,                 /* Priority of the task. */
                    &TaskHandle2);             /* Task handle, may be NULL*/

  xTaskCreatePinnedToCore(
                    DebugTask,       /* Task function. */
                    "DebugTask3",     /* String with name of task. */
                    5000,             /* Stack size in bytes (for ESP32), RTOS standard is words. */
                    NULL,              /* Parameter passed as input of the task */
                    5,                 /* Priority of the task. */
                    &TaskHandle3,             /* Task handle, may be NULL*/
                    0);             /* CPU index */

  xTaskCreatePinnedToCore(
                    DebugTask,       /* Task function. */
                    "DebugTask4",     /* String with name of task. */
                    5000,             /* Stack size in bytes (for ESP32), RTOS standard is words. */
                    NULL,              /* Parameter passed as input of the task */
                    6,                 /* Priority of the task. */
                    &TaskHandle4,             /* Task handle, may be NULL*/
                    1);             /* CPU index */

}
//configASSERT(TaskHandle4)

void loop() {
  // put your main code here, to run repeatedly:

  //ShowSystemInfo();

  if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
  {
      ESP_LOGI(TAG, "Running on core: %d",xPortGetCoreID());
    
      // the current size of free heap memory
      ESP_LOGI(TAG, "Current  free heap left %d", esp_get_free_heap_size());
      // the minimum size of free heap memory that was available during program execution.
      ESP_LOGI(TAG, "minimum free heap size: %d",esp_get_minimum_free_heap_size());
      ESP_LOGI(TAG, "minimum free heap size Ever: %d",xPortGetMinimumEverFreeHeapSize());
    
      // Another way to check heap, but what is the difference with  esp_get_free_heap_size() ??
      ESP_LOGI(TAG, "ESP.getFreeHeap: %d",ESP.getFreeHeap());
     
      // https://esp32.com/viewtopic.php?t=3802
      ESP_LOGI(TAG, "D-RAM left %d", heap_caps_get_free_size(MALLOC_CAP_8BIT));
      ESP_LOGI(TAG, "I+D-RAM left %d", heap_caps_get_free_size(MALLOC_CAP_32BIT));
      ESP_LOGI(TAG, "DMA(capable)-RAM left %d", heap_caps_get_free_size(MALLOC_CAP_DMA));
      ESP_LOGI(TAG, "SPI-RAM left %d", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));

      ESP_LOGI(TAG, "Largest block D-RAM left %d", heap_caps_get_largest_free_block(MALLOC_CAP_8BIT));
      ESP_LOGI(TAG, "Largest block I+D-RAM left %d", heap_caps_get_largest_free_block(MALLOC_CAP_32BIT));
      ESP_LOGI(TAG, "Largest block DMA(capable)-RAM left %d", heap_caps_get_largest_free_block(MALLOC_CAP_DMA));
      ESP_LOGI(TAG, "Largest block SPI-RAM left %d", heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM));

      
      bool ret=heap_caps_check_integrity_all(true);
      ESP_LOGI(TAG,"Result of all_caps heap integrity check: %d",ret);

      ret=heap_caps_check_integrity(MALLOC_CAP_8BIT,true);
      ESP_LOGI(TAG,"Result of MALLOC_CAP_8BIT heap integrity check: %d",ret);
      ret=heap_caps_check_integrity(MALLOC_CAP_32BIT,true);
      ESP_LOGI(TAG,"Result of MALLOC_CAP_32BIT heap integrity check: %d",ret);

      //multi_heap_info_t after;
      //heap_caps_get_info(&after, MALLOC_CAP_8BIT);
      heap_caps_print_heap_info(MALLOC_CAP_8BIT);

      heap_caps_dump(MALLOC_CAP_8BIT);
    
      //get free pages number which can be mmap
      ESP_LOGI(TAG, "SPI flash mmap free data pages %d", spi_flash_mmap_get_free_pages(SPI_FLASH_MMAP_DATA));
      ESP_LOGI(TAG, "SPI flash mmap free instruction pages %d", spi_flash_mmap_get_free_pages(SPI_FLASH_MMAP_INST));
    
      //xPortGetFreeHeapSizeTagged(MALLOC_CAP_32BIT);
    
      // To find out if you can reduce the FreeRTOS stack size of the currently executing task to free some memory you can query the high watermark like this: 
      ESP_LOGI(TAG, "task stack high watermark Idle[0] : %d, Stack start: %p", uxTaskGetStackHighWaterMark(xTaskGetIdleTaskHandleForCPU(0)),pxTaskGetStackStart(xTaskGetIdleTaskHandleForCPU(0)));
      ESP_LOGI(TAG, "task stack high watermark Idle[1] : %d, Stack start: %p", uxTaskGetStackHighWaterMark(xTaskGetIdleTaskHandleForCPU(1)),pxTaskGetStackStart(xTaskGetIdleTaskHandleForCPU(1)));

      ESP_LOGI(TAG, "task stack high watermark loop : %d, Stack start: %p", uxTaskGetStackHighWaterMark(NULL),pxTaskGetStackStart(NULL));
      ESP_LOGI(TAG, "task stack high watermark Task1: %d, Stack start: %p", uxTaskGetStackHighWaterMark(TaskHandle1),pxTaskGetStackStart(TaskHandle1));
      ESP_LOGI(TAG, "task stack high watermark Task2: %d, Stack start: %p", uxTaskGetStackHighWaterMark(TaskHandle2),pxTaskGetStackStart(TaskHandle2));
      ESP_LOGI(TAG, "task stack high watermark Task3: %d, Stack start: %p", uxTaskGetStackHighWaterMark(TaskHandle3),pxTaskGetStackStart(TaskHandle3));
      ESP_LOGI(TAG, "task stack high watermark Task4: %d, Stack start: %p", uxTaskGetStackHighWaterMark(TaskHandle4),pxTaskGetStackStart(TaskHandle4));

      // Strange, priority of loop seems to glued to priority of Task1
      ESP_LOGI(TAG, "Task Priority Idle[0] : %d, Named: %s, State: %s", uxTaskPriorityGet(xTaskGetIdleTaskHandleForCPU(0)),       pcTaskGetTaskName(xTaskGetIdleTaskHandleForCPU(0)),       eTaskState_To_String(eTaskGetState(xTaskGetIdleTaskHandleForCPU(0))));
      ESP_LOGI(TAG, "Task Priority Idle[1] : %d, Named: %s, State: %s", uxTaskPriorityGet(xTaskGetIdleTaskHandleForCPU(1)),       pcTaskGetTaskName(xTaskGetIdleTaskHandleForCPU(1)),       eTaskState_To_String(eTaskGetState(xTaskGetIdleTaskHandleForCPU(1))));

      TaskHandle_t xTaskGetHandle( const char *pcNameToQuery );
      //xTaskGetHandle("network_event");
      //ESP_LOGI(TAG, "Task Priority _network_event_task_handle : %d, Named: %s, State: %s", uxTaskPriorityGet(_network_event_task_handle),       pcTaskGetTaskName("network_event"),       eTaskState_To_String(eTaskGetState(pcTaskGetTaskName("network_event") )));
      //ESP_LOGI(TAG, "Task Priority _network_event_task_handle : %d, Named: %s, State: %s", uxTaskPriorityGet(_network_event_task_handle),       pcTaskGetTaskName(_network_event_task_handle),       eTaskState_To_String(eTaskGetState(pcTaskGetTaskName(_network_event_task_handle))));
      //ESP_LOGI(TAG, "Task Priority loopTaskHandle : %d, Named: %s, State: %s", uxTaskPriorityGet(loopTaskHandle),       pcTaskGetTaskName(loopTaskHandle),       eTaskState_To_String(eTaskGetState(pcTaskGetTaskName(loopTaskHandle))));

      ESP_LOGI(TAG, "Task Priority loop : %d, Named: %s, State: %s", uxTaskPriorityGet(NULL),       pcTaskGetTaskName(NULL),       eTaskState_To_String(eTaskGetState(xTaskGetCurrentTaskHandle())));
      ESP_LOGI(TAG, "Task Priority Task1: %d, Named: %s, State: %s", uxTaskPriorityGet(TaskHandle1),pcTaskGetTaskName(TaskHandle1),eTaskState_To_String(eTaskGetState(TaskHandle1)));
      ESP_LOGI(TAG, "Task Priority Task2: %d, Named: %s, State: %s", uxTaskPriorityGet(TaskHandle2),pcTaskGetTaskName(TaskHandle2),eTaskState_To_String(eTaskGetState(TaskHandle2)));
      ESP_LOGI(TAG, "Task Priority Task3: %d, Named: %s, State: %s", uxTaskPriorityGet(TaskHandle3),pcTaskGetTaskName(TaskHandle3),eTaskState_To_String(eTaskGetState(TaskHandle3)));
      ESP_LOGI(TAG, "Task Priority Task4: %d, Named: %s, State: %s", uxTaskPriorityGet(TaskHandle4),pcTaskGetTaskName(TaskHandle4),eTaskState_To_String(eTaskGetState(TaskHandle4)));

      ESP_LOGI(TAG, "Total Number of tasks: %d", uxTaskGetNumberOfTasks());

      Serial.println("");

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
  }
  vTaskDelay(2000/ portTICK_RATE_MS);
}




void DebugTask( void * parameter ){


  //ESP_LOGI(TAG, "New Task was created on core: %d",xPortGetCoreID());


  while (true) {

      if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
      {

      ESP_LOGI(TAG, "Running on core: %d",xPortGetCoreID());
      
      Serial.println("");

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
      }

      vTaskDelay(2000/ portTICK_RATE_MS);

  }    

    vTaskDelete(NULL);
}



/*
// from https://www.freertos.org/uxTaskGetSystemState.html
// lacking vTaskList() and vTaskGetRunTimeStats() in current build...
void vTaskGetRunTimeStats( signed char *pcWriteBuffer )

<snip, try later
*/


const char * eTaskState_To_String(eTaskState status) {
// See eTaskState type definition in task
  switch (status) {
      case 0:
        return("eRunning");
      case 1:
        return("eReady");
      case 2:
        return("eBlocked");
      case 3:
        return("eSuspended");
      case 4:
        return("eDeleted");
      default:
       return("Unknown State");
    }

}

# ESP32_heap_and_stack_check
ESP32 Arduino based stack and heap information capability demo, using mutex for serialized logging to Serial port from various tasks

Sample output
```
Compiled: Jan  6 2019, 18:35:49, Compiler: 5.2.0 Arduino: 10808 File: C:\Users\m99i941\Arduino\ESP32_heap_check_debug_demo\ESP32_heap_check_debug_demo.ino
ESP.getSdkVersion: v3.3-beta1-44-gda2116f55-dirty, tskKERNEL_VERSION: V8.2.0
ARDUINO ESP32 Version: 1_0_1_RC2
Stack Check validation mechanism: CONFIG_FREERTOS_CHECK_STACKOVERFLOW_CANARY
Heap validation mechanmism: CONFIG_HEAP_POISONING_LIGHT
This is ESP32 chip with 2 CPU cores, WiFi/BT/BLE, silicon revision 1, 4MB external flash
ARDUINO_RUNNING_CORE=1
Setup() Running on Core: 1
Stack constants: Minimal size : 768Unit(s), Unit width: 1Byte(s)
Heap constants: Application: 1, total: <gives an _heap_start was not declared error>
Stack predefined constants:
 Main: 4096
 IPC: 1024 
 ADP SYNK: 2048
 TIMER: 4096
 FREETOS IDLE 1024
 PTHREAD MIN: 768
 MB Serial: 2048
 TCPIP: 2560
 BTC: 8192
 MB Controller: 4096
 EMAC: 3072
 SYSTEM Event: 2048
 FREETOS ISR: 1536
 ESP32 PTHREAD: 2048
ESP Flash encryption enabled: 0
[I][ESP32_heap_check_debug_demo.ino:169] setup(): Redirect ESP32 ULOG to Arduino logging functions (CONFIG_ARDUHAL_ESP_LOG): 1
[E][ESP32_heap_check_debug_demo.ino:172] setup(): 1Error
[W][ESP32_heap_check_debug_demo.ino:173] setup(): 1Warning
[I][ESP32_heap_check_debug_demo.ino:174] setup(): 1Info
[D][ESP32_heap_check_debug_demo.ino:175] setup(): 1Debug
[E][ESP32_heap_check_debug_demo.ino:179] setup(): Error
[W][ESP32_heap_check_debug_demo.ino:180] setup(): Warning
[I][ESP32_heap_check_debug_demo.ino:181] setup(): Info
[D][ESP32_heap_check_debug_demo.ino:182] setup(): Debug
[D][ESP32_heap_check_debug_demo.ino:186] setup(): Debug
[I][ESP32_heap_check_debug_demo.ino:187] setup(): Info
[W][ESP32_heap_check_debug_demo.ino:188] setup(): Warning
[E][ESP32_heap_check_debug_demo.ino:189] setup(): Error
[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 1

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 1

[I][ESP32_heap_check_debug_demo.ino:235] loop(): Running on core: 1
[I][ESP32_heap_check_debug_demo.ino:238] loop(): Current  free heap left 263936
[I][ESP32_heap_check_debug_demo.ino:240] loop(): minimum free heap size: 258060
[I][ESP32_heap_check_debug_demo.ino:241] loop(): minimum free heap size Ever: 258060
[I][ESP32_heap_check_debug_demo.ino:244] loop(): ESP.getFreeHeap: 347780
[I][ESP32_heap_check_debug_demo.ino:247] loop(): D-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:248] loop(): I+D-RAM left 347780
[I][ESP32_heap_check_debug_demo.ino:249] loop(): DMA(capable)-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:250] loop(): SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:252] loop(): Largest block D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:253] loop(): Largest block I+D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:254] loop(): Largest block DMA(capable)-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:255] loop(): Largest block SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:259] loop(): Result of all_caps heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:262] loop(): Result of MALLOC_CAP_8BIT heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:264] loop(): Result of MALLOC_CAP_32BIT heap integrity check: 1
Heap summary for capabilities 0x00000004:
  At 0x3ffbdb28 len 52 free 4 allocated 0 min_free 4
    largest_free_block 4 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffb8000 len 6688 free 3796 allocated 2620 min_free 3676
    largest_free_block 3796 alloc_blocks 14 free_blocks 1 total_blocks 15
  At 0x3ffb0000 len 25480 free 2140 allocated 23228 min_free 2140
    largest_free_block 2140 alloc_blocks 4 free_blocks 1 total_blocks 5
  At 0x3ffae6e0 len 6192 free 1076 allocated 5036 min_free 1076
    largest_free_block 1076 alloc_blocks 2 free_blocks 1 total_blocks 3
  At 0x3ffaff10 len 240 free 0 allocated 120 min_free 0
    largest_free_block 0 alloc_blocks 5 free_blocks 1 total_blocks 6
  At 0x3ffb6388 len 7288 free 0 allocated 6876 min_free 0
    largest_free_block 0 alloc_blocks 23 free_blocks 1 total_blocks 24
  At 0x3ffb9a20 len 16648 free 6328 allocated 9684 min_free 552
    largest_free_block 4980 alloc_blocks 36 free_blocks 4 total_blocks 40
  At 0x3ffc1088 len 126840 free 121776 allocated 5000 min_free 121776
    largest_free_block 121776 alloc_blocks 1 free_blocks 1 total_blocks 2
  At 0x3ffe0440 len 15072 free 15024 allocated 0 min_free 15024
    largest_free_block 15024 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffe4350 len 113840 free 113792 allocated 0 min_free 113792
    largest_free_block 113792 alloc_blocks 0 free_blocks 1 total_blocks 1
  Totals:
    free 263936 allocated 52564 min_free 258040 largest_free_block 121776
Heap start 0x3ffbdb38 end 0x3ffbdb54
First free block 0x3ffbdb40
Block 0x3ffbdb38 data size 0x00000004 bytes next block 0x3ffbdb40 FREE. Next free 0x3ffbdb40
Block 0x3ffbdb40 data size 0x00000010 bytes next block 0x3ffbdb54 FREE. Next free 0x3ffbdb54
Block 0x3ffbdb54 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb8010 end 0x3ffb9a18
First free block 0x3ffb8b34
Block 0x3ffb8010 data size 0x00000004 bytes next block 0x3ffb8018 FREE. Next free 0x3ffb8b34
Block 0x3ffb8018 data size 0x00000030 bytes next block 0x3ffb804c
Block 0x3ffb804c data size 0x00000170 bytes next block 0x3ffb81c0
Block 0x3ffb81c0 data size 0x0000005c bytes next block 0x3ffb8220
Block 0x3ffb8220 data size 0x0000015c bytes next block 0x3ffb8380
Block 0x3ffb8380 data size 0x00000014 bytes next block 0x3ffb8398
Block 0x3ffb8398 data size 0x00000018 bytes next block 0x3ffb83b4
Block 0x3ffb83b4 data size 0x0000005c bytes next block 0x3ffb8414
Block 0x3ffb8414 data size 0x0000008c bytes next block 0x3ffb84a4
Block 0x3ffb84a4 data size 0x0000005c bytes next block 0x3ffb8504
Block 0x3ffb8504 data size 0x0000005c bytes next block 0x3ffb8564
Block 0x3ffb8564 data size 0x00000170 bytes next block 0x3ffb86d8
Block 0x3ffb86d8 data size 0x00000170 bytes next block 0x3ffb884c
Block 0x3ffb884c data size 0x00000170 bytes next block 0x3ffb89c0
Block 0x3ffb89c0 data size 0x00000170 bytes next block 0x3ffb8b34
Block 0x3ffb8b34 data size 0x00000ee0 bytes next block 0x3ffb9a18 FREE. Next free 0x3ffb9a18
Block 0x3ffb9a18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb0010 end 0x3ffb6380
First free block 0x3ffb5b14
Block 0x3ffb0010 data size 0x00000004 bytes next block 0x3ffb0018 FREE. Next free 0x3ffb5b14
Block 0x3ffb0018 data size 0x00000030 bytes next block 0x3ffb004c
Block 0x3ffb004c data size 0x0000200c bytes next block 0x3ffb205c
Block 0x3ffb205c data size 0x0000271c bytes next block 0x3ffb477c
Block 0x3ffb477c data size 0x00001394 bytes next block 0x3ffb5b14
Block 0x3ffb5b14 data size 0x00000868 bytes next block 0x3ffb6380 FREE. Next free 0x3ffb6380
Block 0x3ffb6380 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffae6f0 end 0x3ffaff08
First free block 0x3ffafac4
Block 0x3ffae6f0 data size 0x00000004 bytes next block 0x3ffae6f8 FREE. Next free 0x3ffafac4
Block 0x3ffae6f8 data size 0x00000030 bytes next block 0x3ffae72c
Block 0x3ffae72c data size 0x00001394 bytes next block 0x3ffafac4
Block 0x3ffafac4 data size 0x00000440 bytes next block 0x3ffaff08 FREE. Next free 0x3ffaff08
Block 0x3ffaff08 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffaff20 end 0x3ffafff8
First free block 0x3ffafff0
Block 0x3ffaff20 data size 0x00000004 bytes next block 0x3ffaff28 FREE. Next free 0x3ffafff0
Block 0x3ffaff28 data size 0x00000010 bytes next block 0x3ffaff3c
Block 0x3ffaff3c data size 0x00000014 bytes next block 0x3ffaff54
Block 0x3ffaff54 data size 0x00000018 bytes next block 0x3ffaff70
Block 0x3ffaff70 data size 0x0000001c bytes next block 0x3ffaff90
Block 0x3ffaff90 data size 0x0000005c bytes next block 0x3ffafff0
Block 0x3ffafff0 data size 0x00000004 bytes next block 0x3ffafff8 FREE. Next free 0x3ffafff8
Block 0x3ffafff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb6398 end 0x3ffb7ff8
First free block 0x3ffb7fec
Block 0x3ffb6398 data size 0x00000004 bytes next block 0x3ffb63a0 FREE. Next free 0x3ffb7fec
Block 0x3ffb63a0 data size 0x0000012c bytes next block 0x3ffb64d0
Block 0x3ffb64d0 data size 0x000000bc bytes next block 0x3ffb6590
Block 0x3ffb6590 data size 0x000001b8 bytes next block 0x3ffb674c
Block 0x3ffb674c data size 0x0000120c bytes next block 0x3ffb795c
Block 0x3ffb795c data size 0x00000170 bytes next block 0x3ffb7ad0
Block 0x3ffb7ad0 data size 0x00000014 bytes next block 0x3ffb7ae8
Block 0x3ffb7ae8 data size 0x00000018 bytes next block 0x3ffb7b04
Block 0x3ffb7b04 data size 0x00000018 bytes next block 0x3ffb7b20
Block 0x3ffb7b20 data size 0x0000005c bytes next block 0x3ffb7b80
Block 0x3ffb7b80 data size 0x00000014 bytes next block 0x3ffb7b98
Block 0x3ffb7b98 data size 0x0000005c bytes next block 0x3ffb7bf8
Block 0x3ffb7bf8 data size 0x0000005c bytes next block 0x3ffb7c58
Block 0x3ffb7c58 data size 0x00000018 bytes next block 0x3ffb7c74
Block 0x3ffb7c74 data size 0x00000014 bytes next block 0x3ffb7c8c
Block 0x3ffb7c8c data size 0x0000005c bytes next block 0x3ffb7cec
Block 0x3ffb7cec data size 0x00000018 bytes next block 0x3ffb7d08
Block 0x3ffb7d08 data size 0x0000005c bytes next block 0x3ffb7d68
Block 0x3ffb7d68 data size 0x0000005c bytes next block 0x3ffb7dc8
Block 0x3ffb7dc8 data size 0x0000005c bytes next block 0x3ffb7e28
Block 0x3ffb7e28 data size 0x00000170 bytes next block 0x3ffb7f9c
Block 0x3ffb7f9c data size 0x00000014 bytes next block 0x3ffb7fb4
Block 0x3ffb7fb4 data size 0x00000018 bytes next block 0x3ffb7fd0
Block 0x3ffb7fd0 data size 0x00000018 bytes next block 0x3ffb7fec
Block 0x3ffb7fec data size 0x00000008 bytes next block 0x3ffb7ff8 FREE. Next free 0x3ffb7ff8
Block 0x3ffb7ff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb9a30 end 0x3ffbdb20
First free block 0x3ffba42c
Block 0x3ffb9a30 data size 0x00000004 bytes next block 0x3ffb9a38 FREE. Next free 0x3ffba42c
Block 0x3ffb9a38 data size 0x0000040c bytes next block 0x3ffb9e48
Block 0x3ffb9e48 data size 0x0000005c bytes next block 0x3ffb9ea8
Block 0x3ffb9ea8 data size 0x0000040c bytes next block 0x3ffba2b8
Block 0x3ffba2b8 data size 0x00000170 bytes next block 0x3ffba42c
Block 0x3ffba42c data size 0x00000480 bytes next block 0x3ffba8b0 FREE. Next free 0x3ffba910
Block 0x3ffba8b0 data size 0x0000005c bytes next block 0x3ffba910
Block 0x3ffba910 data size 0x00001380 bytes next block 0x3ffbbc94 FREE. Next free 0x3ffbd338
Block 0x3ffbbc94 data size 0x0000040c bytes next block 0x3ffbc0a4
Block 0x3ffbc0a4 data size 0x00000170 bytes next block 0x3ffbc218
Block 0x3ffbc218 data size 0x0000040c bytes next block 0x3ffbc628
Block 0x3ffbc628 data size 0x00000170 bytes next block 0x3ffbc79c
Block 0x3ffbc79c data size 0x000000fc bytes next block 0x3ffbc89c
Block 0x3ffbc89c data size 0x0000080c bytes next block 0x3ffbd0ac
Block 0x3ffbd0ac data size 0x00000170 bytes next block 0x3ffbd220
Block 0x3ffbd220 data size 0x0000001c bytes next block 0x3ffbd240
Block 0x3ffbd240 data size 0x00000018 bytes next block 0x3ffbd25c
Block 0x3ffbd25c data size 0x00000018 bytes next block 0x3ffbd278
Block 0x3ffbd278 data size 0x0000005c bytes next block 0x3ffbd2d8
Block 0x3ffbd2d8 data size 0x0000005c bytes next block 0x3ffbd338
Block 0x3ffbd338 data size 0x00000020 bytes next block 0x3ffbd35c FREE. Next free 0x3ffbda78
Block 0x3ffbd35c data size 0x00000034 bytes next block 0x3ffbd394
Block 0x3ffbd394 data size 0x00000034 bytes next block 0x3ffbd3cc
Block 0x3ffbd3cc data size 0x00000034 bytes next block 0x3ffbd404
Block 0x3ffbd404 data size 0x00000034 bytes next block 0x3ffbd43c
Block 0x3ffbd43c data size 0x00000034 bytes next block 0x3ffbd474
Block 0x3ffbd474 data size 0x00000034 bytes next block 0x3ffbd4ac
Block 0x3ffbd4ac data size 0x00000074 bytes next block 0x3ffbd524
Block 0x3ffbd524 data size 0x000001a0 bytes next block 0x3ffbd6c8
Block 0x3ffbd6c8 data size 0x0000008c bytes next block 0x3ffbd758
Block 0x3ffbd758 data size 0x0000008c bytes next block 0x3ffbd7e8
Block 0x3ffbd7e8 data size 0x0000008c bytes next block 0x3ffbd878
Block 0x3ffbd878 data size 0x0000008c bytes next block 0x3ffbd908
Block 0x3ffbd908 data size 0x00000028 bytes next block 0x3ffbd934
Block 0x3ffbd934 data size 0x00000028 bytes next block 0x3ffbd960
Block 0x3ffbd960 data size 0x00000028 bytes next block 0x3ffbd98c
Block 0x3ffbd98c data size 0x00000028 bytes next block 0x3ffbd9b8
Block 0x3ffbd9b8 data size 0x00000028 bytes next block 0x3ffbd9e4
Block 0x3ffbd9e4 data size 0x00000030 bytes next block 0x3ffbda18
Block 0x3ffbda18 data size 0x0000005c bytes next block 0x3ffbda78
Block 0x3ffbda78 data size 0x000000a4 bytes next block 0x3ffbdb20 FREE. Next free 0x3ffbdb20
Block 0x3ffbdb20 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffc1098 end 0x3ffdfff8
First free block 0x3ffc2438
Block 0x3ffc1098 data size 0x00000004 bytes next block 0x3ffc10a0 FREE. Next free 0x3ffc2438
Block 0x3ffc10a0 data size 0x00001394 bytes next block 0x3ffc2438
Block 0x3ffc2438 data size 0x0001dbbc bytes next block 0x3ffdfff8 FREE. Next free 0x3ffdfff8
Block 0x3ffdfff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe0450 end 0x3ffe3f18
First free block 0x3ffe0458
Block 0x3ffe0450 data size 0x00000004 bytes next block 0x3ffe0458 FREE. Next free 0x3ffe0458
Block 0x3ffe0458 data size 0x00003abc bytes next block 0x3ffe3f18 FREE. Next free 0x3ffe3f18
Block 0x3ffe3f18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe4360 end 0x3ffffff8
First free block 0x3ffe4368
Block 0x3ffe4360 data size 0x00000004 bytes next block 0x3ffe4368 FREE. Next free 0x3ffe4368
Block 0x3ffe4368 data size 0x0001bc8c bytes next block 0x3ffffff8 FREE. Next free 0x3ffffff8
Block 0x3ffffff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
[I][ESP32_heap_check_debug_demo.ino:273] loop(): SPI flash mmap free data pages 63
[I][ESP32_heap_check_debug_demo.ino:274] loop(): SPI flash mmap free instruction pages 113
[I][ESP32_heap_check_debug_demo.ino:279] loop(): task stack high watermark Idle[0] : 384, Stack start: 0x3ffbbca0
[I][ESP32_heap_check_debug_demo.ino:280] loop(): task stack high watermark Idle[1] : 604, Stack start: 0x3ffbc224
[I][ESP32_heap_check_debug_demo.ino:282] loop(): task stack high watermark loop : 6388, Stack start: 0x3ffb0058
[I][ESP32_heap_check_debug_demo.ino:283] loop(): task stack high watermark Task1: 8552, Stack start: 0x3ffb2068
[I][ESP32_heap_check_debug_demo.ino:284] loop(): task stack high watermark Task2: 3688, Stack start: 0x3ffb4788
[I][ESP32_heap_check_debug_demo.ino:285] loop(): task stack high watermark Task3: 3688, Stack start: 0x3ffae738
[I][ESP32_heap_check_debug_demo.ino:286] loop(): task stack high watermark Task4: 3700, Stack start: 0x3ffc10ac
[I][ESP32_heap_check_debug_demo.ino:289] loop(): Task Priority Idle[0] : 0, Named: IDLE0, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:290] loop(): Task Priority Idle[1] : 0, Named: IDLE1, State: eReady
[I][ESP32_heap_check_debug_demo.ino:298] loop(): Task Priority loop : 5, Named: loopTask, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:299] loop(): Task Priority Task1: 3, Named: DebugTask1, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:300] loop(): Task Priority Task2: 4, Named: DebugTask2, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:301] loop(): Task Priority Task3: 5, Named: DebugTask3, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:302] loop(): Task Priority Task4: 6, Named: DebugTask4, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:304] loop(): Total Number of tasks: 11

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 1

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:235] loop(): Running on core: 1
[I][ESP32_heap_check_debug_demo.ino:238] loop(): Current  free heap left 263936
[I][ESP32_heap_check_debug_demo.ino:240] loop(): minimum free heap size: 258028
[I][ESP32_heap_check_debug_demo.ino:241] loop(): minimum free heap size Ever: 258028
[I][ESP32_heap_check_debug_demo.ino:244] loop(): ESP.getFreeHeap: 347780
[I][ESP32_heap_check_debug_demo.ino:247] loop(): D-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:248] loop(): I+D-RAM left 347780
[I][ESP32_heap_check_debug_demo.ino:249] loop(): DMA(capable)-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:250] loop(): SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:252] loop(): Largest block D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:253] loop(): Largest block I+D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:254] loop(): Largest block DMA(capable)-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:255] loop(): Largest block SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:259] loop(): Result of all_caps heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:262] loop(): Result of MALLOC_CAP_8BIT heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:264] loop(): Result of MALLOC_CAP_32BIT heap integrity check: 1
Heap summary for capabilities 0x00000004:
  At 0x3ffbdb28 len 52 free 4 allocated 0 min_free 4
    largest_free_block 4 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffb8000 len 6688 free 3796 allocated 2620 min_free 3664
    largest_free_block 3796 alloc_blocks 14 free_blocks 1 total_blocks 15
  At 0x3ffb0000 len 25480 free 2140 allocated 23228 min_free 2140
    largest_free_block 2140 alloc_blocks 4 free_blocks 1 total_blocks 5
  At 0x3ffae6e0 len 6192 free 1076 allocated 5036 min_free 1076
    largest_free_block 1076 alloc_blocks 2 free_blocks 1 total_blocks 3
  At 0x3ffaff10 len 240 free 0 allocated 120 min_free 0
    largest_free_block 0 alloc_blocks 5 free_blocks 1 total_blocks 6
  At 0x3ffb6388 len 7288 free 0 allocated 6876 min_free 0
    largest_free_block 0 alloc_blocks 23 free_blocks 1 total_blocks 24
  At 0x3ffb9a20 len 16648 free 6328 allocated 9684 min_free 552
    largest_free_block 4980 alloc_blocks 36 free_blocks 4 total_blocks 40
  At 0x3ffc1088 len 126840 free 121776 allocated 5000 min_free 121776
    largest_free_block 121776 alloc_blocks 1 free_blocks 1 total_blocks 2
  At 0x3ffe0440 len 15072 free 15024 allocated 0 min_free 15024
    largest_free_block 15024 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffe4350 len 113840 free 113792 allocated 0 min_free 113792
    largest_free_block 113792 alloc_blocks 0 free_blocks 1 total_blocks 1
  Totals:
    free 263936 allocated 52564 min_free 258028 largest_free_block 121776
Heap start 0x3ffbdb38 end 0x3ffbdb54
First free block 0x3ffbdb40
Block 0x3ffbdb38 data size 0x00000004 bytes next block 0x3ffbdb40 FREE. Next free 0x3ffbdb40
Block 0x3ffbdb40 data size 0x00000010 bytes next block 0x3ffbdb54 FREE. Next free 0x3ffbdb54
Block 0x3ffbdb54 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb8010 end 0x3ffb9a18
First free block 0x3ffb8b34
Block 0x3ffb8010 data size 0x00000004 bytes next block 0x3ffb8018 FREE. Next free 0x3ffb8b34
Block 0x3ffb8018 data size 0x00000030 bytes next block 0x3ffb804c
Block 0x3ffb804c data size 0x00000170 bytes next block 0x3ffb81c0
Block 0x3ffb81c0 data size 0x0000005c bytes next block 0x3ffb8220
Block 0x3ffb8220 data size 0x0000015c bytes next block 0x3ffb8380
Block 0x3ffb8380 data size 0x00000014 bytes next block 0x3ffb8398
Block 0x3ffb8398 data size 0x00000018 bytes next block 0x3ffb83b4
Block 0x3ffb83b4 data size 0x0000005c bytes next block 0x3ffb8414
Block 0x3ffb8414 data size 0x0000008c bytes next block 0x3ffb84a4
Block 0x3ffb84a4 data size 0x0000005c bytes next block 0x3ffb8504
Block 0x3ffb8504 data size 0x0000005c bytes next block 0x3ffb8564
Block 0x3ffb8564 data size 0x00000170 bytes next block 0x3ffb86d8
Block 0x3ffb86d8 data size 0x00000170 bytes next block 0x3ffb884c
Block 0x3ffb884c data size 0x00000170 bytes next block 0x3ffb89c0
Block 0x3ffb89c0 data size 0x00000170 bytes next block 0x3ffb8b34
Block 0x3ffb8b34 data size 0x00000ee0 bytes next block 0x3ffb9a18 FREE. Next free 0x3ffb9a18
Block 0x3ffb9a18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb0010 end 0x3ffb6380
First free block 0x3ffb5b14
Block 0x3ffb0010 data size 0x00000004 bytes next block 0x3ffb0018 FREE. Next free 0x3ffb5b14
Block 0x3ffb0018 data size 0x00000030 bytes next block 0x3ffb004c
Block 0x3ffb004c data size 0x0000200c bytes next block 0x3ffb205c
Block 0x3ffb205c data size 0x0000271c bytes next block 0x3ffb477c
Block 0x3ffb477c data size 0x00001394 bytes next block 0x3ffb5b14
Block 0x3ffb5b14 data size 0x00000868 bytes next block 0x3ffb6380 FREE. Next free 0x3ffb6380
Block 0x3ffb6380 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffae6f0 end 0x3ffaff08
First free block 0x3ffafac4
Block 0x3ffae6f0 data size 0x00000004 bytes next block 0x3ffae6f8 FREE. Next free 0x3ffafac4
Block 0x3ffae6f8 data size 0x00000030 bytes next block 0x3ffae72c
Block 0x3ffae72c data size 0x00001394 bytes next block 0x3ffafac4
Block 0x3ffafac4 data size 0x00000440 bytes next block 0x3ffaff08 FREE. Next free 0x3ffaff08
Block 0x3ffaff08 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffaff20 end 0x3ffafff8
First free block 0x3ffafff0
Block 0x3ffaff20 data size 0x00000004 bytes next block 0x3ffaff28 FREE. Next free 0x3ffafff0
Block 0x3ffaff28 data size 0x00000010 bytes next block 0x3ffaff3c
Block 0x3ffaff3c data size 0x00000014 bytes next block 0x3ffaff54
Block 0x3ffaff54 data size 0x00000018 bytes next block 0x3ffaff70
Block 0x3ffaff70 data size 0x0000001c bytes next block 0x3ffaff90
Block 0x3ffaff90 data size 0x0000005c bytes next block 0x3ffafff0
Block 0x3ffafff0 data size 0x00000004 bytes next block 0x3ffafff8 FREE. Next free 0x3ffafff8
Block 0x3ffafff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb6398 end 0x3ffb7ff8
First free block 0x3ffb7fec
Block 0x3ffb6398 data size 0x00000004 bytes next block 0x3ffb63a0 FREE. Next free 0x3ffb7fec
Block 0x3ffb63a0 data size 0x0000012c bytes next block 0x3ffb64d0
Block 0x3ffb64d0 data size 0x000000bc bytes next block 0x3ffb6590
Block 0x3ffb6590 data size 0x000001b8 bytes next block 0x3ffb674c
Block 0x3ffb674c data size 0x0000120c bytes next block 0x3ffb795c
Block 0x3ffb795c data size 0x00000170 bytes next block 0x3ffb7ad0
Block 0x3ffb7ad0 data size 0x00000014 bytes next block 0x3ffb7ae8
Block 0x3ffb7ae8 data size 0x00000018 bytes next block 0x3ffb7b04
Block 0x3ffb7b04 data size 0x00000018 bytes next block 0x3ffb7b20
Block 0x3ffb7b20 data size 0x0000005c bytes next block 0x3ffb7b80
Block 0x3ffb7b80 data size 0x00000014 bytes next block 0x3ffb7b98
Block 0x3ffb7b98 data size 0x0000005c bytes next block 0x3ffb7bf8
Block 0x3ffb7bf8 data size 0x0000005c bytes next block 0x3ffb7c58
Block 0x3ffb7c58 data size 0x00000018 bytes next block 0x3ffb7c74
Block 0x3ffb7c74 data size 0x00000014 bytes next block 0x3ffb7c8c
Block 0x3ffb7c8c data size 0x0000005c bytes next block 0x3ffb7cec
Block 0x3ffb7cec data size 0x00000018 bytes next block 0x3ffb7d08
Block 0x3ffb7d08 data size 0x0000005c bytes next block 0x3ffb7d68
Block 0x3ffb7d68 data size 0x0000005c bytes next block 0x3ffb7dc8
Block 0x3ffb7dc8 data size 0x0000005c bytes next block 0x3ffb7e28
Block 0x3ffb7e28 data size 0x00000170 bytes next block 0x3ffb7f9c
Block 0x3ffb7f9c data size 0x00000014 bytes next block 0x3ffb7fb4
Block 0x3ffb7fb4 data size 0x00000018 bytes next block 0x3ffb7fd0
Block 0x3ffb7fd0 data size 0x00000018 bytes next block 0x3ffb7fec
Block 0x3ffb7fec data size 0x00000008 bytes next block 0x3ffb7ff8 FREE. Next free 0x3ffb7ff8
Block 0x3ffb7ff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb9a30 end 0x3ffbdb20
First free block 0x3ffba42c
Block 0x3ffb9a30 data size 0x00000004 bytes next block 0x3ffb9a38 FREE. Next free 0x3ffba42c
Block 0x3ffb9a38 data size 0x0000040c bytes next block 0x3ffb9e48
Block 0x3ffb9e48 data size 0x0000005c bytes next block 0x3ffb9ea8
Block 0x3ffb9ea8 data size 0x0000040c bytes next block 0x3ffba2b8
Block 0x3ffba2b8 data size 0x00000170 bytes next block 0x3ffba42c
Block 0x3ffba42c data size 0x00000480 bytes next block 0x3ffba8b0 FREE. Next free 0x3ffba910
Block 0x3ffba8b0 data size 0x0000005c bytes next block 0x3ffba910
Block 0x3ffba910 data size 0x00001380 bytes next block 0x3ffbbc94 FREE. Next free 0x3ffbd338
Block 0x3ffbbc94 data size 0x0000040c bytes next block 0x3ffbc0a4
Block 0x3ffbc0a4 data size 0x00000170 bytes next block 0x3ffbc218
Block 0x3ffbc218 data size 0x0000040c bytes next block 0x3ffbc628
Block 0x3ffbc628 data size 0x00000170 bytes next block 0x3ffbc79c
Block 0x3ffbc79c data size 0x000000fc bytes next block 0x3ffbc89c
Block 0x3ffbc89c data size 0x0000080c bytes next block 0x3ffbd0ac
Block 0x3ffbd0ac data size 0x00000170 bytes next block 0x3ffbd220
Block 0x3ffbd220 data size 0x0000001c bytes next block 0x3ffbd240
Block 0x3ffbd240 data size 0x00000018 bytes next block 0x3ffbd25c
Block 0x3ffbd25c data size 0x00000018 bytes next block 0x3ffbd278
Block 0x3ffbd278 data size 0x0000005c bytes next block 0x3ffbd2d8
Block 0x3ffbd2d8 data size 0x0000005c bytes next block 0x3ffbd338
Block 0x3ffbd338 data size 0x00000020 bytes next block 0x3ffbd35c FREE. Next free 0x3ffbda78
Block 0x3ffbd35c data size 0x00000034 bytes next block 0x3ffbd394
Block 0x3ffbd394 data size 0x00000034 bytes next block 0x3ffbd3cc
Block 0x3ffbd3cc data size 0x00000034 bytes next block 0x3ffbd404
Block 0x3ffbd404 data size 0x00000034 bytes next block 0x3ffbd43c
Block 0x3ffbd43c data size 0x00000034 bytes next block 0x3ffbd474
Block 0x3ffbd474 data size 0x00000034 bytes next block 0x3ffbd4ac
Block 0x3ffbd4ac data size 0x00000074 bytes next block 0x3ffbd524
Block 0x3ffbd524 data size 0x000001a0 bytes next block 0x3ffbd6c8
Block 0x3ffbd6c8 data size 0x0000008c bytes next block 0x3ffbd758
Block 0x3ffbd758 data size 0x0000008c bytes next block 0x3ffbd7e8
Block 0x3ffbd7e8 data size 0x0000008c bytes next block 0x3ffbd878
Block 0x3ffbd878 data size 0x0000008c bytes next block 0x3ffbd908
Block 0x3ffbd908 data size 0x00000028 bytes next block 0x3ffbd934
Block 0x3ffbd934 data size 0x00000028 bytes next block 0x3ffbd960
Block 0x3ffbd960 data size 0x00000028 bytes next block 0x3ffbd98c
Block 0x3ffbd98c data size 0x00000028 bytes next block 0x3ffbd9b8
Block 0x3ffbd9b8 data size 0x00000028 bytes next block 0x3ffbd9e4
Block 0x3ffbd9e4 data size 0x00000030 bytes next block 0x3ffbda18
Block 0x3ffbda18 data size 0x0000005c bytes next block 0x3ffbda78
Block 0x3ffbda78 data size 0x000000a4 bytes next block 0x3ffbdb20 FREE. Next free 0x3ffbdb20
Block 0x3ffbdb20 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffc1098 end 0x3ffdfff8
First free block 0x3ffc2438
Block 0x3ffc1098 data size 0x00000004 bytes next block 0x3ffc10a0 FREE. Next free 0x3ffc2438
Block 0x3ffc10a0 data size 0x00001394 bytes next block 0x3ffc2438
Block 0x3ffc2438 data size 0x0001dbbc bytes next block 0x3ffdfff8 FREE. Next free 0x3ffdfff8
Block 0x3ffdfff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe0450 end 0x3ffe3f18
First free block 0x3ffe0458
Block 0x3ffe0450 data size 0x00000004 bytes next block 0x3ffe0458 FREE. Next free 0x3ffe0458
Block 0x3ffe0458 data size 0x00003abc bytes next block 0x3ffe3f18 FREE. Next free 0x3ffe3f18
Block 0x3ffe3f18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe4360 end 0x3ffffff8
First free block 0x3ffe4368
Block 0x3ffe4360 data size 0x00000004 bytes next block 0x3ffe4368 FREE. Next free 0x3ffe4368
Block 0x3ffe4368 data size 0x0001bc8c bytes next block 0x3ffffff8 FREE. Next free 0x3ffffff8
Block 0x3ffffff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
[I][ESP32_heap_check_debug_demo.ino:273] loop(): SPI flash mmap free data pages 63
[I][ESP32_heap_check_debug_demo.ino:274] loop(): SPI flash mmap free instruction pages 113
[I][ESP32_heap_check_debug_demo.ino:279] loop(): task stack high watermark Idle[0] : 384, Stack start: 0x3ffbbca0
[I][ESP32_heap_check_debug_demo.ino:280] loop(): task stack high watermark Idle[1] : 604, Stack start: 0x3ffbc224
[I][ESP32_heap_check_debug_demo.ino:282] loop(): task stack high watermark loop : 6388, Stack start: 0x3ffb0058
[I][ESP32_heap_check_debug_demo.ino:283] loop(): task stack high watermark Task1: 8552, Stack start: 0x3ffb2068
[I][ESP32_heap_check_debug_demo.ino:284] loop(): task stack high watermark Task2: 3688, Stack start: 0x3ffb4788
[I][ESP32_heap_check_debug_demo.ino:285] loop(): task stack high watermark Task3: 3688, Stack start: 0x3ffae738
[I][ESP32_heap_check_debug_demo.ino:286] loop(): task stack high watermark Task4: 3700, Stack start: 0x3ffc10ac
[I][ESP32_heap_check_debug_demo.ino:289] loop(): Task Priority Idle[0] : 0, Named: IDLE0, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:290] loop(): Task Priority Idle[1] : 0, Named: IDLE1, State: eReady
[I][ESP32_heap_check_debug_demo.ino:298] loop(): Task Priority loop : 6, Named: loopTask, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:299] loop(): Task Priority Task1: 3, Named: DebugTask1, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:300] loop(): Task Priority Task2: 4, Named: DebugTask2, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:301] loop(): Task Priority Task3: 5, Named: DebugTask3, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:302] loop(): Task Priority Task4: 6, Named: DebugTask4, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:304] loop(): Total Number of tasks: 11

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 1

[I][ESP32_heap_check_debug_demo.ino:235] loop(): Running on core: 1
[I][ESP32_heap_check_debug_demo.ino:238] loop(): Current  free heap left 263936
[I][ESP32_heap_check_debug_demo.ino:240] loop(): minimum free heap size: 258028
[I][ESP32_heap_check_debug_demo.ino:241] loop(): minimum free heap size Ever: 258028
[I][ESP32_heap_check_debug_demo.ino:244] loop(): ESP.getFreeHeap: 347780
[I][ESP32_heap_check_debug_demo.ino:247] loop(): D-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:248] loop(): I+D-RAM left 347780
[I][ESP32_heap_check_debug_demo.ino:249] loop(): DMA(capable)-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:250] loop(): SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:252] loop(): Largest block D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:253] loop(): Largest block I+D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:254] loop(): Largest block DMA(capable)-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:255] loop(): Largest block SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:259] loop(): Result of all_caps heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:262] loop(): Result of MALLOC_CAP_8BIT heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:264] loop(): Result of MALLOC_CAP_32BIT heap integrity check: 1
Heap summary for capabilities 0x00000004:
  At 0x3ffbdb28 len 52 free 4 allocated 0 min_free 4
    largest_free_block 4 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffb8000 len 6688 free 3796 allocated 2620 min_free 3664
    largest_free_block 3796 alloc_blocks 14 free_blocks 1 total_blocks 15
  At 0x3ffb0000 len 25480 free 2140 allocated 23228 min_free 2140
    largest_free_block 2140 alloc_blocks 4 free_blocks 1 total_blocks 5
  At 0x3ffae6e0 len 6192 free 1076 allocated 5036 min_free 1076
    largest_free_block 1076 alloc_blocks 2 free_blocks 1 total_blocks 3
  At 0x3ffaff10 len 240 free 0 allocated 120 min_free 0
    largest_free_block 0 alloc_blocks 5 free_blocks 1 total_blocks 6
  At 0x3ffb6388 len 7288 free 0 allocated 6876 min_free 0
    largest_free_block 0 alloc_blocks 23 free_blocks 1 total_blocks 24
  At 0x3ffb9a20 len 16648 free 6328 allocated 9684 min_free 552
    largest_free_block 4980 alloc_blocks 36 free_blocks 4 total_blocks 40
  At 0x3ffc1088 len 126840 free 121776 allocated 5000 min_free 121776
    largest_free_block 121776 alloc_blocks 1 free_blocks 1 total_blocks 2
  At 0x3ffe0440 len 15072 free 15024 allocated 0 min_free 15024
    largest_free_block 15024 alloc_blocks 0 free_blocks 1 total_blocks 1
  At 0x3ffe4350 len 113840 free 113792 allocated 0 min_free 113792
    largest_free_block 113792 alloc_blocks 0 free_blocks 1 total_blocks 1
  Totals:
    free 263936 allocated 52564 min_free 258028 largest_free_block 121776
Heap start 0x3ffbdb38 end 0x3ffbdb54
First free block 0x3ffbdb40
Block 0x3ffbdb38 data size 0x00000004 bytes next block 0x3ffbdb40 FREE. Next free 0x3ffbdb40
Block 0x3ffbdb40 data size 0x00000010 bytes next block 0x3ffbdb54 FREE. Next free 0x3ffbdb54
Block 0x3ffbdb54 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb8010 end 0x3ffb9a18
First free block 0x3ffb8b34
Block 0x3ffb8010 data size 0x00000004 bytes next block 0x3ffb8018 FREE. Next free 0x3ffb8b34
Block 0x3ffb8018 data size 0x00000030 bytes next block 0x3ffb804c
Block 0x3ffb804c data size 0x00000170 bytes next block 0x3ffb81c0
Block 0x3ffb81c0 data size 0x0000005c bytes next block 0x3ffb8220
Block 0x3ffb8220 data size 0x0000015c bytes next block 0x3ffb8380
Block 0x3ffb8380 data size 0x00000014 bytes next block 0x3ffb8398
Block 0x3ffb8398 data size 0x00000018 bytes next block 0x3ffb83b4
Block 0x3ffb83b4 data size 0x0000005c bytes next block 0x3ffb8414
Block 0x3ffb8414 data size 0x0000008c bytes next block 0x3ffb84a4
Block 0x3ffb84a4 data size 0x0000005c bytes next block 0x3ffb8504
Block 0x3ffb8504 data size 0x0000005c bytes next block 0x3ffb8564
Block 0x3ffb8564 data size 0x00000170 bytes next block 0x3ffb86d8
Block 0x3ffb86d8 data size 0x00000170 bytes next block 0x3ffb884c
Block 0x3ffb884c data size 0x00000170 bytes next block 0x3ffb89c0
Block 0x3ffb89c0 data size 0x00000170 bytes next block 0x3ffb8b34
Block 0x3ffb8b34 data size 0x00000ee0 bytes next block 0x3ffb9a18 FREE. Next free 0x3ffb9a18
Block 0x3ffb9a18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb0010 end 0x3ffb6380
First free block 0x3ffb5b14
Block 0x3ffb0010 data size 0x00000004 bytes next block 0x3ffb0018 FREE. Next free 0x3ffb5b14
Block 0x3ffb0018 data size 0x00000030 bytes next block 0x3ffb004c
Block 0x3ffb004c data size 0x0000200c bytes next block 0x3ffb205c
Block 0x3ffb205c data size 0x0000271c bytes next block 0x3ffb477c
Block 0x3ffb477c data size 0x00001394 bytes next block 0x3ffb5b14
Block 0x3ffb5b14 data size 0x00000868 bytes next block 0x3ffb6380 FREE. Next free 0x3ffb6380
Block 0x3ffb6380 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffae6f0 end 0x3ffaff08
First free block 0x3ffafac4
Block 0x3ffae6f0 data size 0x00000004 bytes next block 0x3ffae6f8 FREE. Next free 0x3ffafac4
Block 0x3ffae6f8 data size 0x00000030 bytes next block 0x3ffae72c
Block 0x3ffae72c data size 0x00001394 bytes next block 0x3ffafac4
Block 0x3ffafac4 data size 0x00000440 bytes next block 0x3ffaff08 FREE. Next free 0x3ffaff08
Block 0x3ffaff08 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffaff20 end 0x3ffafff8
First free block 0x3ffafff0
Block 0x3ffaff20 data size 0x00000004 bytes next block 0x3ffaff28 FREE. Next free 0x3ffafff0
Block 0x3ffaff28 data size 0x00000010 bytes next block 0x3ffaff3c
Block 0x3ffaff3c data size 0x00000014 bytes next block 0x3ffaff54
Block 0x3ffaff54 data size 0x00000018 bytes next block 0x3ffaff70
Block 0x3ffaff70 data size 0x0000001c bytes next block 0x3ffaff90
Block 0x3ffaff90 data size 0x0000005c bytes next block 0x3ffafff0
Block 0x3ffafff0 data size 0x00000004 bytes next block 0x3ffafff8 FREE. Next free 0x3ffafff8
Block 0x3ffafff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb6398 end 0x3ffb7ff8
First free block 0x3ffb7fec
Block 0x3ffb6398 data size 0x00000004 bytes next block 0x3ffb63a0 FREE. Next free 0x3ffb7fec
Block 0x3ffb63a0 data size 0x0000012c bytes next block 0x3ffb64d0
Block 0x3ffb64d0 data size 0x000000bc bytes next block 0x3ffb6590
Block 0x3ffb6590 data size 0x000001b8 bytes next block 0x3ffb674c
Block 0x3ffb674c data size 0x0000120c bytes next block 0x3ffb795c
Block 0x3ffb795c data size 0x00000170 bytes next block 0x3ffb7ad0
Block 0x3ffb7ad0 data size 0x00000014 bytes next block 0x3ffb7ae8
Block 0x3ffb7ae8 data size 0x00000018 bytes next block 0x3ffb7b04
Block 0x3ffb7b04 data size 0x00000018 bytes next block 0x3ffb7b20
Block 0x3ffb7b20 data size 0x0000005c bytes next block 0x3ffb7b80
Block 0x3ffb7b80 data size 0x00000014 bytes next block 0x3ffb7b98
Block 0x3ffb7b98 data size 0x0000005c bytes next block 0x3ffb7bf8
Block 0x3ffb7bf8 data size 0x0000005c bytes next block 0x3ffb7c58
Block 0x3ffb7c58 data size 0x00000018 bytes next block 0x3ffb7c74
Block 0x3ffb7c74 data size 0x00000014 bytes next block 0x3ffb7c8c
Block 0x3ffb7c8c data size 0x0000005c bytes next block 0x3ffb7cec
Block 0x3ffb7cec data size 0x00000018 bytes next block 0x3ffb7d08
Block 0x3ffb7d08 data size 0x0000005c bytes next block 0x3ffb7d68
Block 0x3ffb7d68 data size 0x0000005c bytes next block 0x3ffb7dc8
Block 0x3ffb7dc8 data size 0x0000005c bytes next block 0x3ffb7e28
Block 0x3ffb7e28 data size 0x00000170 bytes next block 0x3ffb7f9c
Block 0x3ffb7f9c data size 0x00000014 bytes next block 0x3ffb7fb4
Block 0x3ffb7fb4 data size 0x00000018 bytes next block 0x3ffb7fd0
Block 0x3ffb7fd0 data size 0x00000018 bytes next block 0x3ffb7fec
Block 0x3ffb7fec data size 0x00000008 bytes next block 0x3ffb7ff8 FREE. Next free 0x3ffb7ff8
Block 0x3ffb7ff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffb9a30 end 0x3ffbdb20
First free block 0x3ffba42c
Block 0x3ffb9a30 data size 0x00000004 bytes next block 0x3ffb9a38 FREE. Next free 0x3ffba42c
Block 0x3ffb9a38 data size 0x0000040c bytes next block 0x3ffb9e48
Block 0x3ffb9e48 data size 0x0000005c bytes next block 0x3ffb9ea8
Block 0x3ffb9ea8 data size 0x0000040c bytes next block 0x3ffba2b8
Block 0x3ffba2b8 data size 0x00000170 bytes next block 0x3ffba42c
Block 0x3ffba42c data size 0x00000480 bytes next block 0x3ffba8b0 FREE. Next free 0x3ffba910
Block 0x3ffba8b0 data size 0x0000005c bytes next block 0x3ffba910
Block 0x3ffba910 data size 0x00001380 bytes next block 0x3ffbbc94 FREE. Next free 0x3ffbd338
Block 0x3ffbbc94 data size 0x0000040c bytes next block 0x3ffbc0a4
Block 0x3ffbc0a4 data size 0x00000170 bytes next block 0x3ffbc218
Block 0x3ffbc218 data size 0x0000040c bytes next block 0x3ffbc628
Block 0x3ffbc628 data size 0x00000170 bytes next block 0x3ffbc79c
Block 0x3ffbc79c data size 0x000000fc bytes next block 0x3ffbc89c
Block 0x3ffbc89c data size 0x0000080c bytes next block 0x3ffbd0ac
Block 0x3ffbd0ac data size 0x00000170 bytes next block 0x3ffbd220
Block 0x3ffbd220 data size 0x0000001c bytes next block 0x3ffbd240
Block 0x3ffbd240 data size 0x00000018 bytes next block 0x3ffbd25c
Block 0x3ffbd25c data size 0x00000018 bytes next block 0x3ffbd278
Block 0x3ffbd278 data size 0x0000005c bytes next block 0x3ffbd2d8
Block 0x3ffbd2d8 data size 0x0000005c bytes next block 0x3ffbd338
Block 0x3ffbd338 data size 0x00000020 bytes next block 0x3ffbd35c FREE. Next free 0x3ffbda78
Block 0x3ffbd35c data size 0x00000034 bytes next block 0x3ffbd394
Block 0x3ffbd394 data size 0x00000034 bytes next block 0x3ffbd3cc
Block 0x3ffbd3cc data size 0x00000034 bytes next block 0x3ffbd404
Block 0x3ffbd404 data size 0x00000034 bytes next block 0x3ffbd43c
Block 0x3ffbd43c data size 0x00000034 bytes next block 0x3ffbd474
Block 0x3ffbd474 data size 0x00000034 bytes next block 0x3ffbd4ac
Block 0x3ffbd4ac data size 0x00000074 bytes next block 0x3ffbd524
Block 0x3ffbd524 data size 0x000001a0 bytes next block 0x3ffbd6c8
Block 0x3ffbd6c8 data size 0x0000008c bytes next block 0x3ffbd758
Block 0x3ffbd758 data size 0x0000008c bytes next block 0x3ffbd7e8
Block 0x3ffbd7e8 data size 0x0000008c bytes next block 0x3ffbd878
Block 0x3ffbd878 data size 0x0000008c bytes next block 0x3ffbd908
Block 0x3ffbd908 data size 0x00000028 bytes next block 0x3ffbd934
Block 0x3ffbd934 data size 0x00000028 bytes next block 0x3ffbd960
Block 0x3ffbd960 data size 0x00000028 bytes next block 0x3ffbd98c
Block 0x3ffbd98c data size 0x00000028 bytes next block 0x3ffbd9b8
Block 0x3ffbd9b8 data size 0x00000028 bytes next block 0x3ffbd9e4
Block 0x3ffbd9e4 data size 0x00000030 bytes next block 0x3ffbda18
Block 0x3ffbda18 data size 0x0000005c bytes next block 0x3ffbda78
Block 0x3ffbda78 data size 0x000000a4 bytes next block 0x3ffbdb20 FREE. Next free 0x3ffbdb20
Block 0x3ffbdb20 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffc1098 end 0x3ffdfff8
First free block 0x3ffc2438
Block 0x3ffc1098 data size 0x00000004 bytes next block 0x3ffc10a0 FREE. Next free 0x3ffc2438
Block 0x3ffc10a0 data size 0x00001394 bytes next block 0x3ffc2438
Block 0x3ffc2438 data size 0x0001dbbc bytes next block 0x3ffdfff8 FREE. Next free 0x3ffdfff8
Block 0x3ffdfff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe0450 end 0x3ffe3f18
First free block 0x3ffe0458
Block 0x3ffe0450 data size 0x00000004 bytes next block 0x3ffe0458 FREE. Next free 0x3ffe0458
Block 0x3ffe0458 data size 0x00003abc bytes next block 0x3ffe3f18 FREE. Next free 0x3ffe3f18
Block 0x3ffe3f18 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
Heap start 0x3ffe4360 end 0x3ffffff8
First free block 0x3ffe4368
Block 0x3ffe4360 data size 0x00000004 bytes next block 0x3ffe4368 FREE. Next free 0x3ffe4368
Block 0x3ffe4368 data size 0x0001bc8c bytes next block 0x3ffffff8 FREE. Next free 0x3ffffff8
Block 0x3ffffff8 data size 0x00000000 bytes next block 0x00000000 FREE. Next free 0x00000000
[I][ESP32_heap_check_debug_demo.ino:273] loop(): SPI flash mmap free data pages 63
[I][ESP32_heap_check_debug_demo.ino:274] loop(): SPI flash mmap free instruction pages 113
[I][ESP32_heap_check_debug_demo.ino:279] loop(): task stack high watermark Idle[0] : 384, Stack start: 0x3ffbbca0
[I][ESP32_heap_check_debug_demo.ino:280] loop(): task stack high watermark Idle[1] : 604, Stack start: 0x3ffbc224
[I][ESP32_heap_check_debug_demo.ino:282] loop(): task stack high watermark loop : 6388, Stack start: 0x3ffb0058
[I][ESP32_heap_check_debug_demo.ino:283] loop(): task stack high watermark Task1: 8552, Stack start: 0x3ffb2068
[I][ESP32_heap_check_debug_demo.ino:284] loop(): task stack high watermark Task2: 3688, Stack start: 0x3ffb4788
[I][ESP32_heap_check_debug_demo.ino:285] loop(): task stack high watermark Task3: 3688, Stack start: 0x3ffae738
[I][ESP32_heap_check_debug_demo.ino:286] loop(): task stack high watermark Task4: 3700, Stack start: 0x3ffc10ac
[I][ESP32_heap_check_debug_demo.ino:289] loop(): Task Priority Idle[0] : 0, Named: IDLE0, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:290] loop(): Task Priority Idle[1] : 0, Named: IDLE1, State: eReady
[I][ESP32_heap_check_debug_demo.ino:298] loop(): Task Priority loop : 6, Named: loopTask, State: eRunning
[I][ESP32_heap_check_debug_demo.ino:299] loop(): Task Priority Task1: 3, Named: DebugTask1, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:300] loop(): Task Priority Task2: 4, Named: DebugTask2, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:301] loop(): Task Priority Task3: 5, Named: DebugTask3, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:302] loop(): Task Priority Task4: 6, Named: DebugTask4, State: eBlocked
[I][ESP32_heap_check_debug_demo.ino:304] loop(): Total Number of tasks: 11

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 0

[I][ESP32_heap_check_debug_demo.ino:327] DebugTask(): Running on core: 1

[I][ESP32_heap_check_debug_demo.ino:235] loop(): Running on core: 1
[I][ESP32_heap_check_debug_demo.ino:238] loop(): Current  free heap left 263936
[I][ESP32_heap_check_debug_demo.ino:240] loop(): minimum free heap size: 258028
[I][ESP32_heap_check_debug_demo.ino:241] loop(): minimum free heap size Ever: 258028
[I][ESP32_heap_check_debug_demo.ino:244] loop(): ESP.getFreeHeap: 347780
[I][ESP32_heap_check_debug_demo.ino:247] loop(): D-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:248] loop(): I+D-RAM left 347780
[I][ESP32_heap_check_debug_demo.ino:249] loop(): DMA(capable)-RAM left 263936
[I][ESP32_heap_check_debug_demo.ino:250] loop(): SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:252] loop(): Largest block D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:253] loop(): Largest block I+D-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:254] loop(): Largest block DMA(capable)-RAM left 121776
[I][ESP32_heap_check_debug_demo.ino:255] loop(): Largest block SPI-RAM left 0
[I][ESP32_heap_check_debug_demo.ino:259] loop(): Result of all_caps heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:262] loop(): Result of MALLOC_CAP_8BIT heap integrity check: 1
[I][ESP32_heap_check_debug_demo.ino:264] loop(): Result of MALLOC_CAP_32BIT heap integrity check: 1

```

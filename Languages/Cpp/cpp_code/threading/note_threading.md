- Different from multi-processing, which utilizes multiple cores from the CPU to process the task, multi-threading aims to increase utilization of a single core by using *thread-level parallelism*, as well as *instruction-level parallelism*.
- Multithreading paradigm has become more popular as efforts to further exploit instructon-level parallelism have stalled since the late 1990s. This allow the concept of *throughput computing (HTC)* to re-emerge from the more specialized field of transaction processing.
- Two major techniques for throughput computing are *multithreading* and *multiprocessing*, which the two are complementing each others.

- working simultaneously
- simple example, printing 100 + and 100 -, whichever faster will print first, ++++--------++++++++--++++++++++ it's possible to see something like that

- "terminate called without an active exception" error: when a thread object goes out of scope and it is in joinable state, the program is terminated

- Create thread working in the background to minimize loadtime


- !! `system("pause>nul");` equivalent behaviour in Linux `system("read x 2 > /dev/null");
- system independent: `std::cin.get();`

https://stackoverflow.com/questions/15039322/systempause-clarification
https://askubuntu.com/questions/1015274/simple-c-thread-program-cant-be-compiled

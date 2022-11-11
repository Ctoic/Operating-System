# In this repo I'm going to Include source code for creating threads and processes.

## Process 
A process is program in its execution state.
Concept of Process has two facets.

A Process is:
A Unit of resource ownership:

1. A virtual address space for the process image
2. Control of some resources (files, I/O devices...)


A Unit of execution:

1. process is an execution path through one or
    more programs 
    2. may be interleaved with other processes
    execution state (Ready, Running, Blocked...) and dispatching
    priority
## Threads
A light weight process which sharres common memory when created. 
THreads are sharing memory.
Certain threads will modifies same variables.

## Race Condition
For checking the race condition we created three threads and also created a function which increments itself everrytime it is called by a thread. Thus our mail functions increases and it gives us the desired value as lng as we provided the desired value. But when we created a looop inside the mail funciton and mad the value too high like I incremented a Millions time then it is not providing the desired output. Thus we came to the race condition.
1. Read the value in mails
2. Increament the value 
3. Writing back to the memory 
This works fine when we are working with a single thread but when we intriduce multiple thread then it will gives us a garbage value which is not the desired output.
| Read Mails | #1    | #2    |
| :---:   | :---: | :---: |
| Increament | 301   | 283   |
| :---:   | :---: | :---: | 
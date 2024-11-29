// Context switching refers to the process where a computer's CPU switches 
// from executing one process or thread to executing another. This mechanism 
// is a key feature of multitasking systems, allowing multiple processes to 
// share the CPU and enabling efficient utilization of system resources.



// How Context Switching Works?

// Save the State of the Current Process:
// When the CPU decides to switch from one process to another, it saves the current process's state (e.g., program counter, registers, and other execution-related information) in a data structure called the Process Control Block (PCB).

// Load the State of the Next Process:
// The CPU retrieves the state of the next process to be executed from its PCB and restores it to resume execution.

// Switch Execution:
// The CPU starts executing the instructions of the new process.
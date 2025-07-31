---
typ: zettel
tags:
  - Programmieren
date: 2025-07-11
context:
  - "42"
rank: "01"
project: get_next_line
---
## how to debug using gdb
1. comple with g flag`cc -g main.c -o executable`
2. run the executable (or binary) `gdb ./executable` 
3. Inside gdb
	1.  `layout next` or better `layout src`
4. Using breakpoints
	1. put a breakpoint: `break main`
	2. `run`
	3. next `n` go to the next line - does not go to a function
	4. variables
		1. `print` or `p` variable name (one time)
		2. `watch` variable name
	5. q to exit the program
5. finish to exit a code entered and return to the line where you recently stepped in
6. show sourcecode around line 11 `list 11` (laysrc)
7. set a breakpoint at leine 11. `break 11`
8. start program execution `run`
9. step through the code `n` or `next` for lines
10. step through the code and call the next funcion `s` or `step`
https://youtu.be/gFCQ37jVN3g?feature=shared

## most important commands
# 🔑 Most Important GDB Commands

|                                  |              |                                                                      |
| -------------------------------- | ------------ | -------------------------------------------------------------------- |
| Command                          | Shortcut     | Description                                                          |
| `run`                            | `r`          | Start or restart the program. Can include arguments: `run arg1 arg2` |
| `break function` or `break line` | `b`          | Set a breakpoint at a function or specific line number               |
| `next`                           | `n`          | Step over the next line of code (does not enter function calls)      |
| `step`                           | `s`          | Step into the next line of code (enters function calls)              |
| `continue`                       | `c`          | Continue execution until next breakpoint or program ends             |
| `print variable`                 | `p variable` | Print the current value of a variable                                |
| `list`                           | `l`          | Show the source code around the current execution point              |
| `backtrace`                      | `bt`         | Show the call stack (function call history)                          |
| `info breakpoints`               | `i b`        | List all set breakpoints                                             |
| `delete breakpoint_number`       | `d`          | Delete a specific breakpoint                                         |
| `watch variable`                 |              | Set a watchpoint to stop execution when a variable changes           |
| `quit`                           | `q`          | Exit GDB                                                             |
| `layout src`                     |              | Show source code in TUI mode                                         |
| `layout asm`                     |              | Show assembly code                                                   |
| `layout regs`                    |              | Show CPU registers and source code                                   |
| `ptype variable`                 |              | Show the type definition of a variable                               |
| `disassemble`                    |              | Show the assembly code of the current function                       |
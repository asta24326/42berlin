# 42 Berlin Common Core Portfolio 🚀

![42 Berlin](https://img.shields.io/badge/42-Berlin-000000?style=for-the-badge&logo=42&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-blue?style=for-the-badge)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Shell](https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white)

## 🏫 About 42 Berlin
**42 Berlin** is part of the global 42 Network of tuition-free, innovative coding schools. The program follows a unique peer-to-peer learning methodology with no teachers, no classes, and a project-based curriculum that emphasizes practical software engineering skills.

**Key Features:**
- 🆓 **Tuition-free** education
- 👥 **Peer-to-peer learning** methodology
- 🎯 **Project-based** curriculum
- ⏰ **Self-paced** learning
- 🌍 **Global network** of campuses

## 📚 Curriculum Overview
The 42 Common Core curriculum is divided into "circles" (levels), each containing progressively challenging projects that build upon previous knowledge.

## 💪 Skills Acquired

### Technical Skills
- **Low-level Programming**: Memory management, pointers, data structures
- **Systems Programming**: Process management, IPC, multithreading
- **Algorithms**: Sorting, searching, optimization techniques
- **Graphics Programming**: 3D mathematics, raycasting, rendering
- **Network Programming**: Sockets, protocols, client-server architecture
- **Shell Scripting**: Automation, system administration
- **Software Design**: Clean code, project architecture, testing

### Soft Skills
- **Problem Solving**: Breaking down complex problems
- **Peer Learning**: Code reviews, pair programming, collaboration
- **Time Management**: Self-paced project completion
- **Debugging**: Systematic error finding and resolution
- **Documentation**: Clear code comments and READMEs

## 🚀 Projects by Circle

### Circle 0: Foundations & Basics ✅
| Project | Language | Description | Status | Grade |
|---------|----------|-------------|--------|-------|
| **[libft](https://github.com/asta24326/Libft)** | C | Recreation of 45+ standard C library functions including memory manipulation, string operations, linked lists, and printf utilities. First project focusing on understanding memory allocation, pointers, and basic data structures. | ✅ Completed | 100/100 |

### Circle 1: Unix & File I/O ✅
| Project | Language | Description | Status | Grade |
|---------|----------|-------------|--------|-------|
| **[ft_printf](https://github.com/asta24326/ft_printf)** | C | Recreation of printf() function from stdio.h supporting conversions: c, s, p, d, i, u, x, X, %. Implements variable arguments, formatting flags, width, precision, and return value counting. Teaches variadic functions and formatted output. | ✅ Completed | 100/100 |
| **[born2beroot](https://github.com/asta24326/Born2beroot)** | Bash+UNIX | Introduction to system administration using virtualization. Configures Debian/ Rocky Linux VM with LVM partitioning, SSH, UFW firewall, sudo policies, password policies, and monitoring scripts. Covers Linux fundamentals and server administration. | ✅ Completed | 100/100 |
| **[get_next_line](https://github.com/asta24326/get_next_line)** | C | Function that reads a line from a file descriptor, handling multiple file descriptors simultaneously with static variables. Teaches file I/O, buffer management, and memory-efficient reading of arbitrary length lines. | ✅ Completed | 115/100 |

### Circle 2: Algorithms & Data Structures ✅
| Project | Language | Description | Status | Grade |
|---------|----------|-------------|--------|-------|
| **[pipex](https://github.com/asta24326/Pipex)** | C + Bash | Recreation of shell pipe (`\|`) behavior using processes, pipes, and file descriptors. Simulates `cmd1 \| cmd2` with input/output redirection, handling multiple commands and error management. Focuses on process creation and IPC. | ✅ Completed | 100/100 |
| **[push_swap](https://github.com/asta24326/Push_swap)** | C | Sorting algorithm optimization project using two stacks with limited operations. Implements various sorting algorithms (radix, quick sort, etc.) to minimize operations. Tests algorithm efficiency and problem-solving skills. | ✅ Completed | 100/100 |
| **[so_long](https://github.com/asta24326/So_long)** | C | 2D game using MiniLibX graphics library. Features sprite rendering, collision detection, player movement, collectibles counting, and map parsing from .ber files. Introduces game loops, graphics programming, and event handling. | ✅ Completed | 100/100 |

### Circle 3: Systems Programming ✅
| Project | Language | Description | Status | Grade |
|---------|----------|-------------|--------|-------|
| **[minishell](https://github.com/asta24326/Minishell_croissant)** | C + Bash | Recreation of bash shell in a group of 2 students. Implements command parsing, pipes, redirections (`>`, `>>`, `<`), environment variables, builtins (echo, cd, pwd, export, unset, env, exit), signals handling, and process execution. | ✅ Completed | 101/100 |
| **[Philosophers](https://github.com/asta24326/Philosophers)** | C | Multithreading and synchronization project simulating the Dining Philosophers problem. Uses pthreads, mutexes, and timers to prevent deadlocks and starvation. Each philosopher is a thread sharing resources (forks) with timing constraints for eating, sleeping, and thinking. | ✅ Completed | 100/100 |

### Circle 4: Networks & 3D Graphics 🎯
| Project | Language | Description | Status |
|---------|----------|-------------|--------|
| **[net_practice](https://github.com/asta24326/Net_practice)** | C | Network configuration exercise teaching IP addressing, subnetting, routing, and network masks. Interactive simulation of network troubleshooting and configuration without actual networking code. | ✅ Completed | 100/100 |
| **[cub3d](https://github.com/asta24326/Cub3D)** | C | Raycasting game engine similar to Wolfenstein 3D using MiniLibX. Renders 3D environments from 2D maps with textures, sprites, collision detection, and player movement. Introduces 3D mathematics and rendering techniques. | ✅ Completed | 110/100 |
| **cpp_modules_00_04** | C++ | Introduction to C++ and Object-Oriented Programming covering classes, inheritance, polymorphism, templates, and STL containers. Five modules progressively teaching C++ fundamentals after C mastery. | 🔄 **In Progress** |

### Circle 5: Web & Advanced C++ 📅
| Project | Language | Description | Status |
|---------|----------|-------------|--------|
| **cpp_modules_05_09** | C++ | Advanced C++ concepts including exceptions, type casting, templates, containers, iterators, and algorithms. Builds upon previous modules with more complex patterns and modern C++ features. | 📅 Planned |
| **inception** | Docker | System administration project using Docker containers. Sets up multiple services (WordPress, MariaDB, Nginx) in isolated containers with Docker Compose, focusing on virtualization, networking, and service orchestration | 📅 Planned |
| **web_serv** | C++ | HTTP/1.1 web server implementation from scratch. Handles GET, POST, DELETE methods, CGI, cookies, sessions, and file uploads. Includes configuration parsing and non-blocking I/O. | 📅 Planned |

### Circle 6: Final Project 📅
| Project | Language | Description | Status |
|---------|----------|-------------|--------|
| **ft_transcendence** | Full Stack | Final project - full-stack web application with real-time features. Typically includes user authentication, database, WebSocket communication, game implementation (like Pong), and modern web technologies (React, Django, PostgreSQL, Docker). | 📅 Planned |

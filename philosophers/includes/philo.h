/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:15:07 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/25 19:58:29 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		// malloc/free
#include <stdio.h>		// printf
#include <unistd.h>		// write/usleep
#include <stdbool.h>	// true/false
#include <pthread.h>	// mutex/init destroy lock unlock / threads/create/join/detach
#include <sys/time.h>	// gettimeofday
#include <limits.h>		// int_max

/* ===> macros' <=== */
typedef pthread_mutex_t t_mutex; // setting short name for mutex struct

/* ===> structures <=== */

// codes for gettime
typedef enum	e_timecode
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}	t_timecode;

// OPCODE for mutex handling
typedef enum	e_mtx_opc
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}	t_mtx_opc;

// opcodes for thread handling
typedef enum	e_thred_opc
{
	CREATE,
	JOIN,
	DETACH,
}	t_thred_opc;

typedef	enum	e_ph_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKES_FIRST_FORK,
	TAKES_SECOND_FORK,
	DIED,
}	t_ph_status;

// prototypes for compiler
typedef struct s_db t_db;

// Forks
typedef struct	s_fork
{
	t_mutex		fork;
	int			fork_id;// for debuggind
}	t_fork;

// Philos
typedef struct s_ph
{
	int			ph_indx;
	int			ph_id;
	long		meal_count;
	long		last_meal_time; // time passed from last meal(in micro seconds)
	bool		is_full;
	pthread_t	thread_id; // each philosopher is a thread
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_db		*db;
}	t_ph;

// Main struct container of a data
typedef struct s_db
{
	int			philos_amount;	// amount of philosophers
	long		time_die;
	long		time_eat;
	long		time_sleep;
	long		meals_limit;
	long		round_start;
	bool		round_stop;		// if someone will die
	bool		all_phs_ready;	// for sync of philos
	t_mutex		host_mutex;		// round supervisor, to avoid races
	t_mutex		write_mutex;	// to write safely???
	t_fork		*forks; 		// array for forks
	t_ph		*philos;		// array for philosophers
}	t_db;


/* ===> Functions prototypes <=== */

// 1.parse.c
void 	ft_parse(t_db *database, char **av);
// static functions
//static long	ft_atol_philo(const char *nptr);

// 2.utils.c TODO
void	ft_error_exit(char *error_msg);

// 3.db_init.c
void	ft_db_init(t_db *db);
// static functions
// static void	ft_philo_init(t_db *db);
// static void	ft_set_forks(t_db *db, t_ph *philo, t_fork *fork);

// 4.mutex_handle.c
void	ft_mutex_handle(t_mutex *mutex, t_mtx_opc opcode);

// 5.thread_handle.c
void	ft_thread_handle(pthread_t *thread, void *(* func)(void *),
				void *data, t_thrdopc opcode);

// 6.round_init.c

// 7.get_set_mutex.c
void	ft_set_bool(t_mutex *mutex, bool *curr_value, bool new_value);
bool	ft_get_bool(t_mutex *mutex, bool *curr_value);
void	ft_set_long(t_mutex *mutex, long *curr_value, long new_value);
long	ft_get_long(t_mutex *mutex, long *curr_value);

// 8.sync.c
void	ft_wait_all_philos(t_db *db);

// 9.get_time.c
long	ft_get_time(t_timecode time_type);

// 10.custom_sleep.c
void	ft_custom_usleep(long given_time, t_db *db);
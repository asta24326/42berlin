/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:15:07 by asharafe          #+#    #+#             */
/*   Updated: 2026/01/29 20:43:15 by aidarsharaf      ###   ########.fr       */
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

// for status write funciton macro
#define DEBUG_MODE	0

// setting short name for mutex struct
typedef pthread_mutex_t t_mutex;

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

// for status writes
typedef	enum	e_status_opc
{
	EATING,
	SLEEPING,
	THINKING,
	TAKES_FIRST_FORK,
	TAKES_SECOND_FORK,
	DIED,
}	t_status_opc;

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
	int			ph_indx; // real index in array(starts from 0, 1 ..)
	int			ph_id;	// name for statuses (starts from 1, 2 ..)
	long		meal_count;
	long		last_meal_time; // time passed from last meal(in micro seconds)
	bool		is_full;
	pthread_t	thread_id; // each philosopher is a thread
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_mutex		philo_mutex;  // to safely update last_meal_time, cus monitor will also check it constantly 
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
	long		phls_running_amnt;	// to count running philos
	bool		round_stop;			// if someone will die
	bool		all_phs_ready;		// for sync of philos
	pthread_t	monitor_thread;		// searchong fro death
	t_mutex		host_mutex;			// round supervisor, to avoid races
	t_mutex		status_mtx;			// to write status safely???
	t_fork		*forks; 			// array for forks
	t_ph		*philos;			// array for philosophers
}	t_db;


/* ===> Functions prototypes <=== */

//	1.parse.c
void 	ft_parse(t_db *database, char **av);
//	static functions:
//		static long	ft_atol_philo(const char *nptr);

//	2.utils.c TODO
void	ft_error_exit(char *error_msg);
void	ft_clean(t_db *db);

//	3.db_init.c
void	ft_db_init(t_db *db);
//	static functions:
//		static void	ft_philo_init(t_db *db);
//		static void	ft_set_forks(t_db *db, t_ph *philo, t_fork *fork);

//	4.mutex_handle.c
void	ft_mutex_handle(t_mutex *mutex, t_mtx_opc opcode);

//	5.thread_handle.c
void	ft_thread_handle(pthread_t *thread, void *(* func)(void *),
				void *data, t_thred_opc opcode);

//	6.round.c
void	ft_round_init(t_db *db);
void	*ft_round_run(void *data);
bool	ft_round_finished(t_db *db);

//	7.get_set_mutex.c
void	ft_set_bool(t_mutex *mutex, bool *curr_value, bool new_value);
bool	ft_get_bool(t_mutex *mutex, bool *curr_value);
void	ft_set_long(t_mutex *mutex, long *curr_value, long new_value);
long	ft_get_long(t_mutex *mutex, long *curr_value);

//	8.sync.c
void	ft_wait_all_philos(t_db *db);
bool	ft_all_philos_running(t_mutex *mutex, long *threads, long philo_amount);
void	ft_increase_long(t_mutex *mutex, long *value);

//	9.get_time.c
long	ft_get_time(t_timecode time_type);

//	10.custom_sleep.c
void	ft_custom_usleep(long given_time, t_db *db);

//	11.write_status.c
void	ft_write_status(t_status_opc status, t_ph *philo, bool debug);
//	static functions:
//		static void	ft_wr_st_debug(t_status_opc status, t_ph *philo, long time)

// 12.philo_processes.c
void	ft_eating(t_ph *philo);
void	ft_thinking(t_ph *philo);
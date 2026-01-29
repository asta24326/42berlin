#include "../includes/philo.h"

void	*ft_round_monitor(void *data)
{
	t_db	*db;
	int		i;

	db = (t_db *)data;// casting input as t_db struct pointer

	// make sure all philos running
	// spinlock till all threads are running
	while (!ft_all_philos_running(&db->monitor_thread, &db->phls_running_amnt,
			db->philos_amount))
		;

	// 
	while (!ft_round_finished(db))
	{
		i = -1;
		while(++i < db->philos_amount && !ft_round_finished(db))
		{
			if (ft_philo_died(db->philos + i)) // TODO
			{
				ft_set_bool(&db->host_mutex, &db->round_stop, true);
				ft_write_status(DIED, db->philos + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}

/*
	how we check:

	is last_meal - last_meal == is > time_to_die?
	or
	maybe philo is full?
*/
static bool	ft_philo_died(t_ph *philo)
{
	long	timestamp;
	long	time_to_die;
	long	last_meal_time;

	if (ft_get_bool(&philo->philo_mutex, &philo->is_full))
		return (false);

	last_meal_time = ft_get_long(&philo->philo_mutex, &philo->last_meal_time);
	time_to_die = philo->db->time_die / 1000;
	timestamp = ft_get_time(MILLISECONDS) - last_meal_time;
	
	if (timestamp > time_to_die)
		return (true);
	return (false);
}

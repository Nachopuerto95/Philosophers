/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:53:09 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/03/18 18:41:25 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# define EATING "EATING"
# define SLEEPING "SLEEPING"
# define THINKING "THINKING"
# define DIED "DIED"
# define FORK_1 "FORK_1"
# define FORK_2 "FORK_2"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					philos_nb;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	bool				end_sim;
	bool				threads_rdy;
	time_t				start_sim;
	pthread_mutex_t		write_mtx;
	pthread_t			god;
	t_philo				**philos;
	pthread_mutex_t		table_mutex;
}				t_table;

typedef struct s_philo
{
	int							id;
	int							meals;
	int							must_eat;
	pthread_t					thread_id;
	pthread_mutex_t				right_fork;
	pthread_mutex_t				*left_fork;
	time_t						last_meal;
	t_table						*table;
	pthread_mutex_t				philo_mutex;
}						t_philo;

void		init_simulation(t_table *table);
int			parse_args(char **argv);
t_table		*init_table(int argc, char **argv);
void		init_threads(t_table	*table);

time_t		get_time(void);
void		philo_sleep(t_table *table, int time);

void		*philo_pre_rutine(void *data);
void		*one_philo_routine(void *data);
void		philo_routine(t_philo *philo, pthread_mutex_t *first_fork,
				pthread_mutex_t *second_fork);
void		*monitoring(void *data);
int			all_philos_ate(t_table *table);
int			has_eaten(t_philo *philo);

void		write_status(char *status, t_philo *philo);
int			break_routine(t_table *table);
void		destroy_mutexes(t_table *table);
int			is_simulation_end(t_table *table);
time_t		get_now_time(t_table *table);
int			is_philo_alive(t_philo *philo);

void		*ft_calloc(size_t nmemb, size_t size);
long		ft_atol(const char *str);
int			ft_strncmp(char *s1, char *s2, unsigned int n);

#endif

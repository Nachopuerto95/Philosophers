NAME = philo
SRC = main.c parsing.c ft_calloc.c init.c ft_strncmp.c threads_functions.c time.c write_status.c control_mutexes.c simulation_check.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:	
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
all: $(NAME)
re: fclean all	
.PHONY: clean fclean all re
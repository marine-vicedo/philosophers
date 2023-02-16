NAME := philo

CC := cc
CFLAGS := -Wall -Wextra -Werror -I ./include

SRC =  main.c init.c routine.c simulation.c monitor.c take_forks.c utils.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -g -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) $(OBJ) -pthread -g -fsanitize=thread -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

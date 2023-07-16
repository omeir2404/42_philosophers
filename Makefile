NAME = philo
SOURCES = main.c extras.c init.c actions.c threads.c 

OBJECTS	=	$(SOURCES:.c=.o)
CC	=	gcc -g -pthread -fsanitize=address
# CFLAGS = -Wall -pthread -Wextra -Werror -g
all:		$(NAME)


$(NAME):	$(OBJECTS)
			$(CC) $(OBJECTS) -o $(NAME)

clean:		
			rm -f $(OBJECTS)

$(LIBFT):

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
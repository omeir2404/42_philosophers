NAME = philo
SOURCES = main.c extras.c init.c actions.c threads.c extra_2.c

OBJECTS	=	$(SOURCES:.c=.o)
CC	=	gcc -pthread -g 
CFLAGS = -Wall -Wextra -Werror
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
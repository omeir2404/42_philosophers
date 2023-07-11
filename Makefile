NAME = philo
SOURCES = main.c extras.c 

OBJECTS	=	$(SOURCES:.c=.o)
CC	=	gcc -g
# CFLAGS = -Wall -Wextra -Werror -g
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
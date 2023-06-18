NAME	=	identify

SRCS	=	main.cpp
	
OBJS	=	$(SRCS:.cpp=.o)

CPP		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

%.o:		%.cpp
			$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(FLAGS) -o $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
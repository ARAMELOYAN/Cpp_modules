NAME = Phonebook

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = UnnecessaryViolence

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(SRCS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = No,\ you\ need\ form\ 28B,\ not\ 28C...

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

INCLS = $(wildcard *.hpp)

RM = rm -rf

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o: $(INCLS) $(SRCS)
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

.PHONY: all clean fclean re

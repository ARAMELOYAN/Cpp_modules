NAME = BTC

SRCS = $(wildcard *.cpp)

TMPL = $(wildcard *.tpp)

OBJS = $(SRCS:.cpp=.o)

INCLS = $(wildcard *.hpp)

RM = rm -rf

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o: $(INCLS) $(SRCS)
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLS) $(TMPL)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

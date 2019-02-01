NAME	=	games
CXX		=	g++
FLAGS	=	-std=c++11 -Wall -Wextra
DIR		=	./
SRCS	=	main.cpp game.cpp
OBJC	=	$(SRCS:.cpp=.o)
OBJS	=	$(addprefix $(DIR), $(OBJC))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) -o $(NAME) $(OBJC) -lncurses
	@echo "$(NAME) ready"

$(DIR)%.o: $(DIR)%.cpp
	@$(CXX) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "objects $(NAME) deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

NAME	=	compare
LIBR	=	libstat.a
CMPL	=	g++
SRLB	=	cmp_dec.cpp
DIRC	=	./
SRCS	=	main.cpp
OBLB	=	$(SRLB:.cpp=.o)
OBJC	=	$(SRCS:.cpp=.o)
OBJS	=	$(addprefix $(DIRC), $(OBJC) $(OBLB))
LBLK	=	-L. -lstat
INCL	=	$(addprefix -I, ./)

all: $(NAME)

$(LIBR): $(OBJS)
	@ar rc $(LIBR) $(OBLB)
	@ranlib $(LIBR)
	@echo "$(LIBR) ready"

$(NAME): $(LIBR)
	@$(CMPL) -o $(NAME) $(OBJC) $(LBLK)
	@echo "$(NAME) ready"

$(DIRC)%.o: $(DIRC)%.cpp
	@$(CMPL) $(INCL) -o $@ -c $<

clean:
	@rm -f $(OBJC) $(OBLB)
	@echo "all objects deleted"

fclean: clean
	@rm -f $(NAME) $(LIBR)
	@echo "$(NAME) and $(LIBR) deleted"

re: fclean all
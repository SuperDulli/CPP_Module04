CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Wshadow

NAME	= polymorphism
CLASSES	= Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES))
SRCS	= main.cpp $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(NAME).dSYM

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

show:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

debug: fclean
debug: CXXFLAGS := $(CXXFLAGS) -g
debug: all

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

$(NAME): $(OBJS) $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all clean fclean re show debug leaks

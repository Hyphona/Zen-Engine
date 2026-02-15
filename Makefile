NAME	:= zen_engine.a
CFLAGS	:= -Wall -Werror -Wextra

HEADERS	:= -I ./include -I ./src/include

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(SRCS:.c=.o)

all: $(NAME) clean

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "[Zen Engine] Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@mkdir ./build
	@ar -rcs ./build/$(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@printf "[Zen Engine] Cleaned .o files\n"

fclean: clean
	@rm -f ./build/$(NAME)
	@printf "[Zen Engine] Deleted $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
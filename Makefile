NAME	:= zen_engine.a
CFLAGS	:= -Wall -Werror -Wextra

HEADERS	:= -I ./include

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(SRCS:.c=.o)

all: $(NAME) clean

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "[Zen Engine] Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@[ -d ./build ] || mkdir -p ./build
	@ar -rcs ./build/$(NAME) $(OBJS)
	@printf "[Zen Engine] ./build/$(NAME) has been built\n"

clean:
	@rm -f $(OBJS)
	@printf "[Zen Engine] Cleaned .o files\n"

fclean:
	@rm -f ./build/$(NAME)
	@printf "[Zen Engine] Deleted ./build/$(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
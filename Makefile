NAME	:= zen_engine.a
CFLAGS	:= -Wall -Werror -Wextra

HEADERS	:= -I ./include

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(SRCS:.c=.o)

all: $(NAME) clean

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "[Zen Engine] Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@if [ ! -d ./build ]; then mkdir -p ./build && printf "[Zen Engine] Created ./build directory\n"; fi
	@ar -rcs ./build/$(NAME) $(OBJS)
	@printf "[Zen Engine] ./build/$(NAME) has been built\n"

clean:
	@rm -f $(OBJS)
	@printf "[Zen Engine] Cleaned .o files\n"

fclean:
	@if [ -f ./build/$(NAME) ]; then rm -f ./build/$(NAME) && printf "[Zen Engine] Deleted ./build/$(NAME)\n"; fi
	@if [ -d ./build/ ]; then rm -d ./build && printf "[Zen Engine] Deleted ./build directory\n"; fi

re: fclean all

.PHONY: all clean fclean re
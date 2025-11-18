CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Normal version
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# Bonus version
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ---------------- Rules ----------------
all: $(OBJS)

bonus: $(BONUS_OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus

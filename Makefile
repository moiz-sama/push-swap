SRCS =	ft_check_args.c ft_strjoin_and_split.c ft_split.c \
    	ft_atoi.c linkd_list.c rules_a.c rules_b.c ft_sort.c \
        push_to_a_from_b.c ft_sort_3_5.c push_swap_main.c

BONUS = main_bonus.c ft_check_args_bonus.c ft_strjoin_and_split.c \
		ft_split_bonus.c ft_atoi_bonus.c linked_list_bonus.c \
		get_next_line.c get_next_line_utils.c rules_a_b_bonus.c \
		rules_a_bonus.c rules_b_bonus.c

OBJS = $(SRCS:.c=.o)
OBJB = $(BONUS:.c=.o)

NAME = push_swap
BonusName = checker

CFLAGS = -Wall -Wextra -Werror

CC = cc


all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(OBJB) $(BonusName)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJB) : $(BONUS)
	$(CC) $(CFLAGS) -c  $(BONUS)

$(BonusName) : $(OBJB) 
	$(CC) $(CFLAGS) $(OBJB) -o $(BonusName)

clean :
	rm -f $(OBJS) $(OBJB)

fclean : clean
	rm -f $(NAME) $(BonusName)

re : fclean all

.PHONY: bonus
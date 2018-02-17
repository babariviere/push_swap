NAME_CHK=checker
NAME_PS=push_swap

SRC_CHK=src/checker.c
SRC_PS=src/push_swap.c
SRC_NAME=stack.c stack_op.c stack_chk.c args.c instr.c\
		 sort.c stack_hlp.c instr_apply.c stack_fnd.c\
		 instr_hlp.c
SRC=$(addprefix src/, $(SRC_NAME))

OBJ_CHK=obj/checker.o
OBJ_PS=obj/push_swap.o
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))

CC=clang
INC=-Iinclude -Ilibft/include
LIB=-Llibft -lft
CFLAGS=-Wall -Werror -Wextra -g $(INC)

all: $(NAME_CHK) $(NAME_PS)

$(NAME_CHK): $(OBJ) $(OBJ_CHK)
	@make -C libft
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(OBJ_CHK) $(LIB)

$(NAME_PS): $(OBJ) $(OBJ_PS)
	@make -C libft
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(OBJ_PS) $(LIB)

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf obj
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME_CHK)
	@rm -rf $(NAME_PS)
	@make -C libft fclean

re: fclean all

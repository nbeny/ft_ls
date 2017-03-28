NAME	=	ft_ls

N_INC	=	ft_ls.h
N_SRC	=	ft_check.c	ft_core.c\
		ft_memrep.c

CC	=	gcc
CC_FLAG	=	-Wall -Wextra -Werror

T_SRC	=	./src/
T_INC	=	./includes/
T_OBJ	=	./obj/
T_LFT	=	libft/
T_PTF	=	ft_printf/

I_INC	=	./includes/
I_LFT	=	./libft/includes
I_PFT	=	./ft_printf/includes
L_LFT	=	-L ./libft/ -lft
L_PFT	=	-L ./ft_printf/ -lftprintf

CL_N	=	\033[0m
CL_R	=	\033[31m
CL_V	=	\033[32m
CL_J	=	\033[33m
CL_B	=	\033[34m
CL_C	=	\033[36m

CL_NS	=	\033[0;4m
CL_RS	=	\033[31;4m
CL_VS	=	\033[32;4m
CL_JS	=	\033[33;4m
CL_BS	=	\033[34;4m
CL_CS	=	\033[36;4m

CL_NG	=	\033[0;1m
CL_RG	=	\033[31;1m
CL_VG	=	\033[32;1m
CL_JG	=	\033[33;1m
CL_BG	=	\033[34;1m
CL_CG	=	\033[36;1m

SRC	=	$(addprefix $(T_SRC), $(N_SRC))
OBJ	=	$(addprefix $(T_OBJ), $(N_OBJ))
INC	=	$(addprefix -I, $(I_INC) $(I_LFT) $(I_PFT))

N_OBJ	=	$(N_SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo ">$(CL_V)Build: $(CL_VG)libft$(CL_N)\n"
	@make -C $(T_LFT)
	@echo ">$(CL_V)Build: $(CL_VG)ft_printf$(CL_N)\n"
	@make -C $(T_PFT)
	@echo ">$(CL_V)Build: $(CL_VG)$(NAME)$(CL_N)\n"
	@$(CC) $(CC_FLAG) -o $(NAME) $(OBJ) $(INC) $(L_LFT)

$(T_OBJ)%.o: $(T_SRC)%.c
	@echo "$(CL_V)>Creat: Objects files..$(CL_N)"
	@mkdir -p $(T_OBJ)
	@$(CC) $(CC_FLAG) -o $@ -c $^ $(INC)

clean:
	@echo "$(CL_R)>clean: $(CL_B)$(NAME) objects$(CL_N)\n"
	@rm -rf $(T_OBJ)
	@echo "$(CL_R)>clean: $(CL_B)libft objects$(CL_N)\n"
	@make -C $(T_LFT) clean
	@echo "$(CL_R)>clean: $(CL_B)printf objects$(CL_N)\n"
	@make -C $(T_PFT) clean

fclean: clean
	@echo "$(CL_R)>Delete: $(CL_B)$(NAME)$(CL_N)\n"
	@rm -f $(NAME)
	@echo "$(CL_R)>Delete: $(CL_B)libft$(CL_N)\n"
	@make -C $(T_LFT) fclean
	@echo "$(CL_R)>Delete: $(CL_B)ft_printf$(CL_N)\n"
	@make -C $(T_PFT) fclean

re: fclean all

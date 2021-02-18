# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 18:39:56 by mqueguin          #+#    #+#              #
#    Updated: 2021/02/18 11:56:08 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
END		=	\x1b[0m
BOLD	=	\x1b[1m
UNDER	=	\x1b[4m
RED		=	\x1b[31m
GREEN	=	\x1b[32m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m
PURPLE	=	\x1b[35m
CYAN	=	\x1b[36m
WHITE	=	\x1b[37m


OBJ_DIR 	=	obj/

SRC_DIR 	=	srcs/

LIB_DIR 	=	libft/

PRINTF_H	=	-I includes/ft_printf.h

PRINTF_BONUS_H	=	-I includes_bonus/ft_printf_bonus.h

LIBFT_H		= 	-I libft/libft.h

SRCS	 	=	ft_printf.c\
				ft_printf_utils.c\
				ft_treat_flags.c\
				ft_treat_width.c\
				ft_treat_char.c\
				ft_treat_string.c\
				ft_treat_pointer.c\
				ft_itoa_base_ull.c\
				ft_treat_int.c\
				ft_treat_u_int.c\
				ft_treat_hexa.c

SRCS_BONUS	=	srcs_bonus/ft_printf_bonus.c\
				srcs_bonus/ft_printf_utils_bonus.c\
				srcs_bonus/ft_treat_flags_bonus.c\
				srcs_bonus/ft_treat_width_bonus.c\
				srcs_bonus/ft_treat_char_bonus.c\
				srcs_bonus/ft_treat_string_bonus.c\
				srcs_bonus/ft_treat_pointer_bonus.c\
				srcs_bonus/ft_itoa_base_ull_bonus.c\
				srcs_bonus/ft_treat_int_bonus.c\
				srcs_bonus/ft_treat_int_second_bonus.c\
				srcs_bonus/ft_treat_u_int_bonus.c\
				srcs_bonus/ft_treat_hexa_bonus.c

NAME 		=	libftprintf.a

LIBFT_A 	=	libft.a

CC			=	gcc -Wall -Wextra -Werror $(PRINTF_H) $(LIBFT_H) -c -o

CC_BONUS	=	gcc -Wall -Wextra -Werror $(PRINTF_BONUS_H) $(LIBFT_H) -c

CFIND		=	$(SRCS:%=$(SRC_DIR)%)

OFILE		=	$(SRCS:%.c=%.o)

OFILE_BONUS	=	$(SRCS_BONUS:%.c=%.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@echo "$(GREEN)\t\t\t\t########################################"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####            $(BOLD)$(CYAN)FT_PRINTF$(END)$(GREEN)           ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t####                                ####"
		@echo "\t\t\t\t########################################\n\n$(END)"
		@mkdir -p $(OBJ_DIR)
		@echo "$(BLUE)Create:$(END) ft_printf Object directory $(GREEN)$(BOLD)[OK]$(END)"

$(NAME): $(OBJ)
		@echo "\n\n\t\t$(BOLD)====================== $(GREEN)COMPILATION LIBFT... $(END)$(BOLD)====================$(END)\t\t\n\n"
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo "$(BOLD)$(GREEN)\n\t\t\t-------------------- FT_PRINTF COMPLETE --------------------"

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo "$(BOLD)$(GREEN)[GOOD]$(END) Create: $(@:obj/%=%)"
		@$(CC) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

bonus:	
		@echo "$(BOLD)$(CYAN)\n\t\t\t-------------------- Bonus Compilation... --------------------$(END)"
		@make -C $(LIB_DIR)
		@$(CC_BONUS) srcs_bonus/*.c
		@mv *.o srcs_bonus
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(OFILE_BONUS)
		@ranlib $(NAME)
		@echo "$(BOLD)$(GREEN)\n\t\t\t-------------------- BONUS COMPLETE --------------------$(END)"


clean:
		@/bin/rm -rf $(OBJ_DIR)
		@rm -rf srcs_bonus/*.o
		@make -C $(LIB_DIR) clean
		@echo "Cleaned ft_printf object files"

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo "$(BOLD)$(RED)\t\t\t-_-_-_-_-_-_-_-_-_-_ Cleaned $(NAME) _-_-_-_-_-_-_-_-_-_-$(END)"

re: fclean all

.PHONY: all clean flcean re bonus

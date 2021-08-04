FSRC	:=	map_parser.c
MSRC	:=	so_long.c
TSRC	:=	tests.c test_is_map.c

SRC_DIR :=	sources
INC_DIR :=	headers
OBJ_DIR :=	objects
TST_DIR	:=	tests

INCLS   :=	$(INC_DIR)

MSRCS	:=	$(addprefix $(SRC_DIR)/,$(MSRC))
MOBJS	:=	$(MSRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FSRCS	:=	$(addprefix $(SRC_DIR)/,$(FSRC))
FOBJS	:=	$(FSRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TSRCS	:=	$(addprefix $(TST_DIR)/,$(TSRC))

CC		:=	clang

CFLAGS	+=	-Wall -Wextra -Werror -pedantic
IFLAGS	+=	-I.
LFLAGS	+=	-L.
TFLAGS	+=	-fsanitize=address -g3
MFLAGS	+=	-lmlx_Linux -lXext -lX11 -lft
OFLAGS	+=	-O3 -pthread

RM		:=	rm -rf

NAME	:=	so_long

MLX_DIR	:=	minilibx

LFT_DIR	:=	libft


all:		obj mlx lft $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ $(IFLAGS)/$(INCLS) $(IFLAGS)/$(MLX_DIR) $(IFLAGS)/$(LFT_DIR)

$(NAME):	$(FOBJS) $(MOBJS)
			$(CC) $(FOBJS) $(MOBJS) $(LFLAGS)/$(MLX_DIR) $(LFLAGS)/$(LFT_DIR) $(MFLAGS) -o $(NAME)

clean:
			$(MAKE) -C $(LFT_DIR) clean
			$(RM) $(OBJS) $(OBJ_DIR)

fclean: 	clean
			$(MAKE) -C $(LFT_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all

mlx:
			$(MAKE) -C $(MLX_DIR)

lft:
			$(MAKE) -C $(LFT_DIR)

obj:
			mkdir -p $(OBJ_DIR)

test:		OFLAGS=$(TFLAGS)

test:		fclean obj mlx lft $(FOBJS)
			$(CC) $(TFLAGS) $(FOBJS) $(TSRCS) $(IFLAGS)/$(TST_DIR) $(LFLAGS)/$(MLX_DIR) $(LFLAGS)/$(LFT_DIR) $(MFLAGS) -o tests.out
			./tests.out

.PHONY: 	all clean fclean re obj tests mlx lft

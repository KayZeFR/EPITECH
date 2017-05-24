/*
** bistromathique.h for bistromathique in /home/ghikh_r/rendu/Piscine_C_bistromathique
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 19 09:45:35 2015 Raphael Ghikh
** Last update Mon Oct 19 09:49:24 2015 Raphael Ghikh
*/

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define SYNTAXE_ERROR_MSG "syntax error"

char *eval_expr(char *base, char *ops, char *expr, unsigned int size);

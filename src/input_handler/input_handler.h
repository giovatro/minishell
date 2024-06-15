/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:04:25 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/07 11:04:29 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

# include "msh.h"

int				input_handler(char *input, t_msh *msh);

/*-----  TOKENIZER ----*/
int				ft_tokenize_input(char *input, t_msh *msh);
t_token			*ft_init_token(int type, char *value, char quotes);
t_token_list	*ft_add_token_list(t_token_list *head, t_token *token);
void			ft_print_token_list(t_token_list *token_list);
void			ft_print_token(t_token *token);
int				set_status(int status, char quotes);

/*----- LEXER FUNCTIONS -----*/
t_token			*ft_lexer(t_lexer *lexer);
t_lexer			*ft_init_lexer(char *input);
void			ft_lexer_advance(t_lexer *lexer);
t_token			*ft_lexer_advance_with_token(t_lexer *lexer, t_token *token);
t_token			*ft_get_string(t_lexer *lexer);
t_token			*ft_get_word(t_lexer *lexer);
t_token			*ft_get_pipe(t_lexer *lexer);
t_token			*ft_get_less_than(t_lexer *lexer);
t_token			*ft_get_greater_than(t_lexer *lexer);

/*----- LEXER UTILS -----*/
char			*ft_char_to_str(t_lexer *lexer);
char			*ft_process_chars(t_lexer *lexer, char *value);
int				ft_count_the_same(t_lexer *lexer, char symbol);
char			*ft_str_repeat(char c, int count);
void			*ft_realloc(void *ptr, size_t size);
int				ft_is_extended(int c);
void			ft_less_than_helper(t_lexer *lexer,
					char *value, t_token **token);
void			ft_greater_than_helper(t_lexer *lexer,
					char *value, t_token **token);

/*----- CLEANING FUNCTIONS ----*/
void			free_data(t_msh *msh);
void			ft_free_token_list(t_token_list *head);
void			ft_free_lexer(t_lexer *lexer);

#endif

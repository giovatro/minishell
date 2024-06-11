/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:32:44 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/09 11:32:45 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "msh.h"

int		var_expander(t_msh *msh, t_token_list **token_lst);
char	*var_expander_heredoc(t_msh *msh, char *str);
bool	is_next_char_a_sep(char c);
bool	var_between_quotes(char *str, int i);

// utils
char	*get_new_token_string(char *oldstr, char *var_value,
			int newstr_size, int index);
void	copy_var_value(char *new_str, char *var_value, int *j);
int		check_if_var(t_token_list **token_lst);
bool	is_var_compliant(char c);
int		var_length(char *str);
char	*identify_var(char *str);
void	free_ptr(void *ptr);

// recover
char	*recover_val(t_token *token, char *str, t_msh *msh);

// replace
int		replace_var(t_token_list **token_list, char *var_value, int index);
char	*replace_str_heredoc(char *str, char *var_value, int index);

// handle quote
int		handle_quotes(t_msh *msh);
bool	quotes_in_string(char *str);
int		remove_quotes(t_token_list **token_list);
int		count_len(char *str, int count, int i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:29:47 by tluanamn          #+#    #+#             */
/*   Updated: 2024/03/01 10:29:48 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "msh.h"

typedef struct s_lexer
{
	char			*input;
	unsigned char	c;
	unsigned int	i;
}	t_lexer;

typedef struct s_token
{
	enum
	{
		STRING,
		WORD,
		PIPE,
		REDIR_IN,
		REDIR_HERE_DOC,
		REDIR_OUT,
		REDIR_APPEND,
		NOT_TO_HANDLE,
		VAR,
		DEFAULT,
		SQUOTE,
		DQUOTE
	} e_type;
	char	*value;
	int		position;
	bool	var_exists;
	bool	join;
	int		status;
}	t_token;

typedef struct s_token_list
{
	t_token				*token;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list;

typedef struct s_command
{
	char	**args;
	char	*input;
	char	*output;
	int		append;
}	t_cmd;

typedef struct s_msh
{
	t_token_list	*token_list;
	t_cmd			*command;
	char			**envp;
	char			**paths;
	char			*home;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				pid;
	bool			heredoc;
	int				exit_status;
}	t_msh;

#endif

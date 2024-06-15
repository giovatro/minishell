/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:31:01 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/29 09:31:02 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/ioctl.h>

# include "../libft/libft.h"
# include "colour.h"
# include "structure.h"
# include "initialise.h"
# include "input_handler.h"
# include "write_msg.h"
# include "error.h"
# include "utils.h"
# include "executor.h"
# include "builtins.h"
# include "expander.h"

extern int	g_signal;

#endif

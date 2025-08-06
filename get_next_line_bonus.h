/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.h									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/10/31 20:31:09 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2024/10/31 20:31:09 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_buf
{
	char	*sub_buf;
	char	*ptr;
	size_t	available;
}			t_buf;

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strndup(const char *s, int n);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif

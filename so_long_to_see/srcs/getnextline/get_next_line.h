/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:22:54 by aperrone          #+#    #+#             */
/*   Updated: 2022/01/24 19:45:17 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchar(char *str, char c);
char	*ft_res(int fd, char *saved_str);
char	*ft_strjoin(char *saved_str, char *buffer);
size_t	ft_strlen(char *str);
char	*ft_get_line(char *saved_str);
char	*ft_save(char *saved_str);

#endif

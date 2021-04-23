#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (struct s_list *)malloc(sizeof(t_list));
	if (new)
	{
		new -> content = content;
		new -> next = NULL;
	}
	return (new);
}

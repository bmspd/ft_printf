#include "../includes/ft_printf.h"

static size_t	nbrlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*reverse(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	if (str[i] == '-')
		i++;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

static char	*forming_number(char *str, size_t i, size_t len, unsigned int n)
{
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (i < len)
	{
		str[i++] = (n % 10) + 48;
		n = n / 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = nbrlen(n);
	i = 0;
	if (n < 0)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str = forming_number(str, i, len, n);
	return ((reverse(str)));
}

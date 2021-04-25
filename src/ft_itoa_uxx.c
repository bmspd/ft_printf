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
		n = n / 16;
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
	unsigned int	temp;

	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (i < len)
	{
		temp = n % 16;
		if (temp > 9)
			str[i++] = temp + 55;
		else
			str[i++] = temp + 48;
		n = n / 16;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_uxx(unsigned int n)
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
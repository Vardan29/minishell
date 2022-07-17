
int	is_alpha(unsigned char ch)
{
	return ((ch >= 'A' && ch <= 'Z')
		|| (ch >= 'a' && ch <= 'z'));
}

int	contains(char *str, char ch)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ch)
			return (1);
	}
	return (0);
}

int	is_valid_export_key(char *key)
{	
	int	i;

	i = 0;
	if (!is_alpha(key[0]) && key[0] != '_')
		return (0);
	while (key[++i])
	{
		if (contains("!@#$%^&*()-+[]\\|{};:.><,/?.", key[i]))
			return (0);
	}
	return (1);
}
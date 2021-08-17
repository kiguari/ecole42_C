char		*ft_strchr(const char *s, int c)
{
	while (*((char *)s) != (char)c && *((char *)s) != '\0')
		s++;
	if (*((char *)s) == '\0' && (char)c != '\0')
		return (NULL);
	else
		return ((char *)s);
}
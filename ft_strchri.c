int   ft_strchri(char *str, char c)
{
  int count;

  count = 0;
  while(str[count] != c)
  {
    count++;
  }
  return(count);
}

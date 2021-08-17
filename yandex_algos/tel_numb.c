#include <unistd.h>
#include <stdio.h>

size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_make_nam(char *old, char *new)
{
    int i = 0;
    int flag = 0;
    int k = 0;
    int num_size;
    char tmp[12];
    int j = 12;
    int flag_2 = 0;

    while(old[i])
    {
        while(old[i] == '-' || old[i] == '(' || old[i] == ')' || old[i] == '+')
            i++;
        if((old[i] >= '0' && old[i] <= '6') || old[i] == '9')
            flag_2++;
        if((old[i] == '7' || old[i] == '8') && flag == 0 && flag_2 == 0)
        {
            tmp[k] = '7';
            flag++;
            k++;
            i++;
        }
        while(old[i] == '-' || old[i] == '(' || old[i] == ')' || old[i] == '+')
            i++;
        tmp[k] = old[i];
        i++;
        k++;
    }
    tmp[k] = '\0';
    num_size = ft_strlen(tmp);
    if(num_size == 7 || num_size == 8)
    {
        j = 4;
        new[0] = '7';
        new[1] = '4';
        new[2] = '9';
        new[3] = '5';
        
        k = 0;
        if(num_size == 8)
            k = 1;
        while(tmp[k])
        {
           new[j] = tmp[k];
           j++;
           k++;
        }
    }
    else
    {
        j = 0;
        k = 0;
        while(tmp[k])
        {
           new[j] = tmp[k];
           j++;
           k++;
        }
    }
}

int main()
{
    char num1[50];
    char num2[50];
    char num3[50];
    char num4[50];
    char out_num1[12];
    char out_num2[12];
    char out_num3[12];
    char out_num4[12];
    int i = 0;
    int j = 0;
    int flag = 0;
    scanf("%s %s %s %s", num1, num2, num3, num4);
    ft_make_nam(num1, out_num1);
    ft_make_nam(num2, out_num2);
    ft_make_nam(num3, out_num3);
    ft_make_nam(num4, out_num4);

    while(out_num1[i])
    {
        if(out_num1[i] != out_num2[j])
        {
            printf("%s\n", "NO");
            flag = 1;
            break;
        }
        i++;
        j++;
    }
    if(flag == 0)
        printf("%s\n", "YES");
    flag = 0;
    i = 0;
    j = 0;
    while(out_num1[i])
    {
        if(out_num1[i] != out_num3[j])
        {
            printf("%s\n", "NO");
            flag = 1;
            break;
        }
        i++;
        j++;
    }
    if(flag == 0)
        printf("%s\n", "YES");
    flag = 0;
    i = 0;
    j = 0;
    while(out_num1[i])
    {
        if(out_num1[i] != out_num4[j])
        {
            printf("%s\n", "NO");
            flag = 1;
            break;
        }
        i++;
        j++;
    }
    if(flag == 0)
        printf("%s\n", "YES");
    return(0);
}

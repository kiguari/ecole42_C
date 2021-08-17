# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "get_next_line.c"
# include "get_next_line_utils.c"
//# include "get_next_line_bonus.h"
//# include "get_next_line_bonus.c"
//# include "get_next_line_utils_bonus.c"
// int main(void)
// {
// 	int fd;
// 	char *line;
// 	int c;

// 	fd = open("text.txt", O_RDONLY); // fd = open(0, O_RDONLY);
// 	c = 1;
// 	while (c > 0)
// 	{
// 		c = get_next_line(fd, &line);  //c = get_next_line(0, &line);
// 		printf("%d || %s\n", c, line); //printf("%d %s\n", get_next_line(0, &line), line);
// 		free(line);
// 	}
// }

//int main(void)
//{
//    int fd;
//    char *line;
//    int c;
//
//    fd = open("text.txt", O_RDONLY); // fd = open(0, O_RDONLY);
//    c = 1;
//    while (c > 0)
//    {
//        c = get_next_line(fd, &line);  //c = get_next_line(0, &line);
//        printf("%d || %s\n", c, line); //printf("%d %s\n", get_next_line(0, &line), line);
//        free(line);
//    }
//}

//int  main()
//{
//  int fd, a;
//  char *line;
//  //fd = open("text.txt", O_RDONLY);
//  if ((fd = open("text.txt", O_RDONLY)) == -1)
//  {
//		printf("cannot open file\n");
//		return(0);
//  }
//  while ((a = get_next_line(fd, &line) > -1))
//  {
//	//printf("1");
//    //printf("%d\n", a);
//    //printf("%s\n", line);
//	printf("%d || %s\n", a, line);
//	if (a == 0)
//		break;
//    free(line);
//  }
//  a = get_next_line(fd, &line);
//  printf("%d || %s\n", a, line);
//  return (0);
//}
//int main()
//{
//	int             fd;
//	int             i;
//	int             j;
//	char    		*line = 0;
//	//char			*lineadress[66];
//
//
//	j = 1;
//	fd = open("text.txt", O_RDONLY);
//	// if (!(fd = open("test.txt", O_RDONLY)))
//	// {
//	// 	printf("\nError in open\n");
//	// 	return (0);
//	// }
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("|%s\n", line);
//		free(line);
//		j++;
//	}
//	printf("|%s\n", line);
//	free(line);
//	close(fd);
//
//	if (i == -1)
//		printf ("\nError in Fonction - Returned -1\n");
//	else if (j == 9)
//		printf("\nRight number of lines\n");
//	else if (j != 9)
//		printf("\nNot Good - Wrong Number Of Lines\n");
//	j = 1;
//}


//  int main(void)
//  {
//      int fd1;
//      //int fd2;
//      char *line;
//      int c;
//      int i;

//      fd1 = open("text.txt", O_RDONLY); // fd = open(0, O_RDONLY);
//      //fd2 = open("text2.txt", O_RDONLY);
//      //c = 1;
//      while (c < 3)
//      {
//          i = get_next_line(fd1, &line);  //c = get_next_line(0, &line);
//          printf("%d || %d || %s\n", i, c, line); //printf("%d %s\n", get_next_line(0, &line), line);
//          c++;
//          //free(line);
//      }
//     while (c < 6)
//     {
//         i = get_next_line(fd2, &line);  //c = get_next_line(0, &line);
//         printf("%d || %d || %s\n", i, c, line); //printf("%d %s\n", get_next_line(0, &line), line);
//         c++;
//         //free(line);
//     }
//     while (c < 9)
//     {
//         i = get_next_line(fd2, &line);  //c = get_next_line(0, &line);
//         printf("%d || %d || %s\n", i, c, line); //printf("%d %s\n", get_next_line(0, &line), line);
//         c++;
//         //free(line);
//     }
//  }

//int main(void)
//{
//    int fd;
//    char *line;
//    int rval;
//    fd = open("text2.txt", O_RDONLY);
//    while ((rval = get_next_line(fd, &line)))
//        write(1, line, ft_strlen(line));
//    return (0);
//}

//  int main(void)
//  {
//      int fd;
//      char *line;
//      int rval;
//      fd = open("text2.txt", O_RDONLY);
//      while ((rval = get_next_line(fd, &line) > 0))
//      {
//          //printf("%s", line);
//          write(1, line, ft_strlen(line));
//          //free(line);
//      }
//      //free(line);
//      return (0);
//  }

int  main()
{
int fd, a;
char *line;
//fd = open("text.txt", O_RDONLY);
fd = 0;//open("text2.txt", O_RDONLY);
while ((a = get_next_line(fd, &line) > 0))
// while ((a = get_next_line(fd, (char**)0xfff7) > 0)) //уничтожить любой, самый защищенный G.N.L. 
{
   //printf("1");
  //printf("%d\n", a);
  //printf("%s\n", line);
   printf("%d || %s\n", a, line);
}
//a = get_next_line(fd, &line);
printf("%d || %s\n", a, line);
return (0);
}

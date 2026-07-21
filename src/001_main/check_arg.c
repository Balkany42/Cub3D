

int check_arg(int argc, char**argv)
{
    int len_arg;

    if(argc != 2)
        return (printf("Incorrect number of arguments detected"));
    if(argv[1][0] == '.' || check_hidden_file_in_path(argv[1][0]))
        return (printf("Argument is a hidden file"));
    len_arg = ft_strlen(argv[1]);
    if (len_arg < 5) // Ne détecte pas dans les path
        return(printf("Incorrect map file detected"));
    len_arg = len_arg - 4;
    if (ft_strncmp((argv[1] + len_arg), ".cub", 4))
        return (printf("Incorrect extension detected"));
}
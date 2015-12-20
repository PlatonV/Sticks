void	init(t_double_list **lst)
{
	g_intent = (char*)malloc(list_size(lst));
}

int	verificare_tura(t_double_list *ls)
{
	int index = 0;
	while (ls)
	{
		g_intent[index++] = ls->value % 4 == 1;
		ls = ls->next;
	}
}

void	init(t_double_list **lst)
{
	g_intent = (char*)malloc(list_size(lst));
}

void	verificare_tura(t_double_list *ls)
{
	int index;
	
	index = 1;
	g_intent[0] = 0;
	while (ls->next)
	{
		g_intent[index++] = ls->value % 4 == 1;
		ls = ls->next;
	}
}

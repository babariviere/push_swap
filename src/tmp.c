static int	find_median(int *data, int idx, int len)
{
	int		low;
	int		high;
	int		median;
	int		tmp_len;

	low = data[idx];
	high = data[idx];
	median = idx;
	tmp_len = len;
	while (len--)
	{
		if (data[idx] > high)
			high = data[idx];
		else if (data[idx] < low)
			low = data[idx];
		idx--;
	}
	idx = median;
	median = low;
	while (tmp_len--)
	{
		if (low < data[idx] && data[idx] < high)
			median = data[idx];
		idx--;
	}
	return (median);
}
static int	stack_lower(t_stack *st)
{
	int		low;
	int		idx;

	idx = st->len;
	low = idx - 1;
	while (idx-- > 0)
	{
		if (st->data[idx] < st->data[low])
			low = idx;
	}
	return (low);
}

static void	selection_sort_top(t_stack_hld *hld, int low_val)
{
	while (1)
	{
		if (ST_TOP(hld->a) > ST_TOPN(hld->a))
			apply_instr_and_save(hld, INSTR_SA);
		if (ST_TOP(hld->b) < ST_TOPN(hld->b))
			apply_instr_and_save(hld, INSTR_SB);
		if (ST_TOP(hld->a) == low_val)
			break ;
		apply_instr_and_save(hld, INSTR_RA);
		if (ST_TOP(hld->a) == low_val)
			break ;
	}
	apply_instr_and_save(hld, INSTR_PB);
}

static void	selection_sort_down(t_stack_hld *hld, int low_val)
{
	while (1)
	{
		if (ST_TOP(hld->a) > ST_TOPN(hld->a))
			apply_instr_and_save(hld, INSTR_SA);
		if (ST_TOP(hld->b) < ST_TOPN(hld->b))
			apply_instr_and_save(hld, INSTR_SB);
		if (ST_TOP(hld->a) == low_val)
			break ;
		apply_instr_and_save(hld, INSTR_RRA);
		if (ST_TOP(hld->a) == low_val)
			break ;
	}
	apply_instr_and_save(hld, INSTR_PB);
}

static void	selection_sort(t_stack_hld *hld)
{
	int		low;

	while (!stack_is_sort(hld->a))
	{
		low = stack_lower(hld->a);
		if (((int)hld->a->len - low) > low)
			selection_sort_down(hld, hld->a->data[low]);
		else
			selection_sort_top(hld, hld->a->data[low]);
		if (ST_TOP(hld->b) < ST_TOPN(hld->b))
			apply_instr_and_save(hld, INSTR_SB);
		if (ST_TOP(hld->a) > ST_TOPN(hld->a))
			apply_instr_and_save(hld, INSTR_SA);
	}
	while (hld->b->len > 0)
	{
		apply_instr_and_save(hld, INSTR_PA);
		if (ST_TOP(hld->a) > ST_TOPN(hld->a))
			apply_instr_and_save(hld, INSTR_SA);
	}
}



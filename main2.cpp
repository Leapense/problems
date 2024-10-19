#include <cstdio>
#define MAXN 2000
typedef struct
{
	int rn;
	int cn;
} corner;
int n, count;
corner ct[MAXN + 2][MAXN + 2];
int cor[MAXN + 2], coc[MAXN + 2];
int b[MAXN + 2][MAXN + 2];		   // input
int sols[MAXN * MAXN][4];		   // solution
int mcount, msols[MAXN * MAXN][4]; // best solution found
void flip_corner(int r, int c)	   // if (r,c) is a corner, make it not
{								   // otherwise, vice versa.
	int p;
	p = 0;
	while (1)
	{
		if (ct[r][p].cn == c)
		{
			ct[r][p].cn = ct[r][c].cn;
			cor[r]--;
			break;
		}
		if (ct[r][p].cn > c)
		{
			ct[r][c].cn = ct[r][p].cn;
			ct[r][p].cn = c;
			cor[r]++;
			break;
		}
		p = ct[r][p].cn;
	}
	p = 0;
	while (1)
	{
		if (ct[p][c].rn == r)
		{
			ct[p][c].rn = ct[r][c].rn;
			coc[c]--;
			break;
		}
		if (ct[p][c].rn > r)
		{
			ct[r][c].rn = ct[p][c].rn;
			ct[p][c].rn = r;
			coc[c]++;
			break;
		}
		p = ct[p][c].rn;
	}
}

void init_ct() // initializing corner table
{
	int i, j;
	for (i = 1; i <= n + 1; i++)
	{
		ct[0][i].rn = n + 2;
		ct[0][i].cn = i + 1;
		ct[i][0].rn = i + 1;
		ct[i][0].cn = n + 2;
		cor[i] = 0;
		coc[i] = 0;
	}
	for (i = 1; i <= n + 1; i++)
		for (j = 1; j <= n + 1; j++)
		{
			if ((b[i][j] + b[i - 1][j] + b[i][j - 1] + b[i - 1][j - 1]) % 2)
			{
				flip_corner(i, j);
			}
		}
	count = 0;
}
void add_to_sol(int c1, int c2, int r1, int r2)
{
	flip_corner(r1, c1);
	flip_corner(r2, c1);
	flip_corner(r1, c2);
	flip_corner(r2, c2);
	if (c1 > c2)
		c1 ^= c2 ^= c1 ^= c2;
	if (r1 > r2)
		r1 ^= r2 ^= r1 ^= r2;
	c2--;
	r2--;
	sols[count][0] = c1;
	sols[count][1] = c2;
	sols[count][2] = r1;
	sols[count][3] = r2;
	count++;
}
int links[MAXN + 2], link[MAXN + 2][MAXN + 2]; // maximal matching algorithm
int match[MAXN + 2], islinked[MAXN + 2];
int traveled[MAXN + 2];
int path[MAXN + 2], pathlen;
int found;
void dfs(int k)
{
	int i, v;
	for (i = 0; i < links[k]; i++)
	{
		v = link[k][i];
		if (!traveled[v])
		{
			if (match[v] == -1)
			{
				path[pathlen] = v;
				pathlen++;
				found = 1;
				return;
			}
			else
			{
				path[pathlen] = v;
				pathlen++;
				traveled[v] = 1;
				path[pathlen] = match[v];
				pathlen++;
				dfs(match[v]);
				if (found)
					return;
				pathlen -= 2;
			}
		}
	}
}

void matching(int elems)
{
	int i, flag, last;
	for (i = 0; i < elems; i++)
	{
		match[i] = -1;
	}
	do
	{
		for (i = 0; i < elems; i++)
		{
			traveled[i] = 0;
		}
		flag = 0;
		for (i = 0; i < elems; i++)
		{
			if (match[i] == -1 && !traveled[i])
			{
				found = 0;
				traveled[i] = 1;
				path[0] = i;
				pathlen = 1;
				dfs(i);
				if (found)
				{
					for (i = 0; i < pathlen; i++)
					{
						if (i % 2 == 0)
						{
							match[path[i]] = path[i + 1];
						}
						else
						{
							match[path[i]] = path[i - 1];
						}
					}
					flag = 1;
				}
			}
		}
	} while (flag);
	last = -1;
	for (i = 0; i < elems; i++)
	{
		if (match[i] != -1)
		{
			islinked[i] = 1;
		}
		else
		{
			islinked[i] = 0;
			if (last == -1)
			{
				last = i;
			}
			else
			{
				match[last] = i;
				match[i] = last;
				last = -1;
			}
		}
	}
}
void destroy_row(int r) // removing all corners in the row
{
	int cols;
	int col[MAXN + 2];
	int p, q, i, j;
	int min, minp;
	p = 0;
	cols = 0;
	while (ct[r][p].cn < n + 2)
	{
		p = ct[r][p].cn;
		col[cols] = p;
		cols++;
	}
	for (i = 0; i < cols; i++)
		links[i] = 0;
	for (i = 0; i < cols - 1; i++)
	// Could the pair of columns be destroyed with a rectangle of
	// 4 corners?
	{
		for (j = i + 1; j < cols; j++)
		{
			p = ct[0][col[i]].rn;
			q = ct[0][col[j]].rn;
			while (p < n + 2 && q < n + 2)
			{
				if (p > q)
				{
					q = ct[q][col[j]].rn;
				}
				else if (p < q)
				{
					p = ct[p][col[i]].rn;
				}
				else
				{
					if (p != r)
					{
						link[i][links[i]] = j;
						links[i]++;
						link[j][links[j]] = i;
						links[j]++;
						break;
					}
					p = ct[p][col[i]].rn;
					q = ct[q][col[j]].rn;
				}
			}
		}
	}
	matching(cols); // Maximum matching
	for (i = 0; i < cols; i++)
	{
		if (match[i] > i)
		{
			if (islinked[i]) // Destroying matched pairs
			{
				p = ct[0][col[i]].rn;
				q = ct[0][col[match[i]]].rn;
				min = n + 2;
				while (p < n + 2 && q < n + 2)
				{
					if (p > q)
					{
						q = ct[q][col[match[i]]].rn;
					}
					else if (p < q)
					{
						p = ct[p][col[i]].rn;
					}
					else
					{
						if (p != r)
						{
							if (min > cor[p])
							{
								min = cor[p];
								minp = p;
							}
						}
						p = ct[p][col[i]].rn;
						q = ct[q][col[match[i]]].rn;
					} // prefers the row that contains least column
				}
				add_to_sol(col[i], col[match[i]], r, minp);
			}
		}
	}
	for (i = 0; i < cols; i++)
	{
		if (match[i] > i)
		{
			if (!islinked[i]) // not matched pairs
			{
				min = n + 1;
				p = ct[0][col[i]].rn;
				while (p < n + 2)
				{
					if (cor[p] < min && p != r)
					{
						min = cor[p];
						minp = p;
					}
					p = ct[p][col[i]].rn;
				}
				p = ct[0][col[match[i]]].rn;
				while (p < n + 2)
				{
					if (cor[p] < min && p != r)
					{
						min = cor[p];
						minp = p;
					}
					p = ct[p][col[match[i]]].rn;
				}
				add_to_sol(col[i], col[match[i]], r, minp);
			}
		}
	}
}
void destroy_col(int c)
{
	int rows;
	int row[MAXN + 2];
	int p, q, i, j;
	int min, minp;
	p = 0;
	rows = 0;
	while (ct[p][c].rn < n + 2)
	{
		p = ct[p][c].rn;
		row[rows] = p;
		rows++;
	}
	for (i = 0; i < rows; i++)
		links[i] = 0;
	for (i = 0; i < rows - 1; i++)
	{
		for (j = i + 1; j < rows; j++)
		{
			p = ct[row[i]][0].cn;
			q = ct[row[j]][0].cn;
			while (p < n + 2 && q < n + 2)
			{
				if (p > q)
				{
					q = ct[row[j]][q].cn;
				}
				else if (p < q)
				{
					p = ct[row[i]][p].cn;
				}
				else
				{
					if (p != c)
					{
						link[i][links[i]] = j;
						links[i]++;
						link[j][links[j]] = i;
						links[j]++;
						break;
					}
					p = ct[row[i]][p].cn;
					q = ct[row[j]][q].cn;
				}
			}
		}
	}
	matching(rows);
	for (i = 0; i < rows; i++)
	{
		if (match[i] > i)
		{
			if (islinked[i])
			{
				p = ct[row[i]][0].cn;
				q = ct[row[match[i]]][0].cn;
				min = n + 2;
				while (p < n + 2 && q < n + 2)
				{
					if (p > q)
					{
						q = ct[row[match[i]]][q].cn;
					}
					else if (p < q)
					{
						p = ct[row[i]][p].cn;
					}
					else
					{
						if (p != c)
						{
							if (min > coc[p])
							{
								min = coc[p];
								minp = p;
							}
						}
						p = ct[row[i]][p].cn;
						q = ct[row[match[i]]][q].cn;
					}
				}
				add_to_sol(c, minp, row[i], row[match[i]]);
			}
		}
	}
	for (i = 0; i < rows; i++)
	{
		if (match[i] > i)
		{
			if (!islinked[i])
			{
				min = n + 1;
				p = ct[row[i]][0].cn;
				while (p < n + 2)
				{
					if (coc[p] < min && p != c)
					{
						min = coc[p];
						minp = p;
					}
					p = ct[row[i]][p].cn;
				}
				p = ct[row[match[i]]][0].cn;
				while (p < n + 2)
				{
					if (coc[p] < min && p != c)
					{
						min = coc[p];
						minp = p;
					}
					p = ct[row[match[i]]][p].cn;
				}
				add_to_sol(c, minp, row[i], row[match[i]]);
			}
		}
	}
}
void update_sol() // updating the best solution
{
	int i, j;
	if (mcount > count)
	{
		mcount = count;
		for (i = 0; i < mcount; i++)
			for (j = 0; j < 4; j++)
				msols[i][j] = sols[i][j];
	}
}
void delete_min_row_or_col()
{
	int mins, minp, i, isrow;
	init_ct();
	while (1)
	{
		mins = n + 1;
		for (i = 1; i <= n + 1; i++)
		{
			if (mins > cor[i] && cor[i])
			{
				mins = cor[i];
				minp = i;
				isrow = 1;
			}
			if (mins > coc[i] && coc[i])
			{
				mins = coc[i];
				minp = i;
				isrow = 0;
			}
		}
		if (mins == n + 1)
			break;
		if (isrow)
		{
			destroy_row(minp);
		}
		else
		{
			destroy_col(minp);
		}
	}
	update_sol();
}
void delete_one_by_one()
{
	int i;
	init_ct();
	for (i = 1; i <= n + 1; i++) // destroying the top row first
	{
		if (cor[i] != 0)
			destroy_row(i);
	}
	update_sol();
	init_ct();
	for (i = 1; i <= n + 1; i++) // the bottom row
	{
		if (coc[i] != 0)
			destroy_col(i);
	}
	update_sol();
	init_ct();
	for (i = n + 1; i >= 1; i--) // the left column
	{
		if (cor[i] != 0)
			destroy_row(i);
	}
	update_sol();
	init_ct();
	for (i = n + 1; i >= 1; i--) // the right column
	{
		if (coc[i] != 0)
			destroy_col(i);
	}
	update_sol();
}
void read_data()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &b[i + 1][j + 1]);
		}
	}
	for (i = 0; i <= n + 1; i++)
	{
		b[i][0] = 0;
		b[i][n + 1] = 0;
		b[0][i] = 0;
		b[n + 1][i] = 0;
	}
	mcount = 0x7fffffffl;
}
void print(char *ID)
{
	int i;
	printf("#FILE xor %s\n", ID);
	printf("%d\n", count);
	for (i = 0; i < mcount; i++)
	{
		printf("%d %d %d %d\n", msols[i][2], msols[i][3], msols[i][0],
			   msols[i][1]);
	}
	printf("%d\n", mcount);
}
int main(int argc, char **argv)
{
	read_data();
	delete_min_row_or_col();
	delete_one_by_one();
	print(argv[1]);
	return 0;
}
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

std::vector<int> converttrinrynum(int x)
{
	std::vector<int> characts;
	characts[0] = x % 3;

	int y = (x - characts[0]) / 3;
	characts[1] = y % 3;

	int z = (y - characts[1]) / 3;
	characts[2] = z % 3;

	int w = (z - characts[2]) / 3;
	characts[3] = w % 3;

	return characts;
}


int main()
{
	cout << "Input height then width" << endl;
	int setcount = 0;
	int m,n;
	cin >> m >> n;

	int setgridtrinrynum [m][n];

	cout << "Input shape, then number, then color, then fill" << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int shape, number, color, fill;
			cin >> shape >> number >> color >> fill;

			int trinrynum;
			trinrynum = (27 * shape) + (9 * number) + (3 * color) + (fill);

			setgridtrinrynum[i][j] = trinrynum;

		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (k == i)
				{
					continue;
				}
				else
				{
					for (int l = 0; l < n; l++)
					{
						if (l == j)
						{
							continue;
						}
						else
						{
							int trinrynum1 = setgridtrinrynum[i][j];
							int trinrynum2 = setgridtrinrynum[k][l];

							std::vector<int> characts1;
							std::vector<int> characts2;

							characts1 = converttrinrynum(trinrynum1);
							characts2 = converttrinrynum(trinrynum2);

							int needshape, neednumber, needcolor, needfill;

							int needtrinrynum;

							for (int p = 0; p < 4; p++)
							{
								if (characts1[p] == characts2[p])
								{
									needtrinrynum = needtrinrynum + (characts1[p] * (pow(3, p)));
								}
								else 
								{
									needtrinrynum  = needtrinrynum + ((3 - (characts1[p] + characts2[p])) *  (pow(3, p)));
								}
							}

							for (int r = 0; r < m; r++)
							{
								if (r == i)
								{
									continue;
								}
								if (r == k)
								{
									continue;
								}
								else
								{
									for (int s = 0; s < n; s++)
									{
										if (s == j)
										{
											continue;
										}
										if (s == l)
										{
											continue;
										}
										else
										{
											if (setgridtrinrynum[r][s] == needtrinrynum)
											{
												setcount = setcount + 1;
											}
										}
									}
								}
							}

						}
					}

				}
			}

		}
	}

	cout << "The number of sets is " << (setcount / 6);

}

#include <iostream>
#include <vector>

void binary_add(std::vector<int> &a, std::vector<int> &b)
{
	std::vector<int> c(int(a.size())+1);
	int carry_bit = 0;
	int i = 0;
	for(i = 0; i < a.size(); i++)
	{
		c[i] = (a[i] + b[i] + carry_bit) % 2;
		carry_bit = (a[i] + b[i] + carry_bit) / 2;
	}
	c[i + 1] = carry_bit;
	for(int i{0}; i < int(c.size());i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int n{0};
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int i{0}; i < n; i++)
		std::cin >> a[i];
	for(int i{0}; i < n; i++)
		std::cin >> b[i];

	binary_add(a,b);
    return 0;
}
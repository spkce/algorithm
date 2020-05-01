//最大公约数：辗转相除法
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
//最小共倍数：a*b / 最大公约数
int lcm(int a, int b)
{
	return a * b / gcd(a, b)
}
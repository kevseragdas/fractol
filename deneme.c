//int main()
//{
//	t_complex z;
//	t_complex c;
//	int i;
//	double tmp_real;

//	z.real = 0;
//	z.im = 0;

//	c.real = 0.25 ;
//	c.im = 0.4;

//	i = 42;
//	while(i)
//	{
//		tmp_real = (z.real * z.real) - (z.im * z.im);
//		z.im = 2*(z.im * z.real);
//		z.real = tmp_real;
//		z.real = z.real + c.real;
//		z.im = z.im + c.im;
//		i--;
//		printf("iteration :%d\n real:%f\n imaginary:%f\n\n",i,z.real,z.im);
//	}
//}

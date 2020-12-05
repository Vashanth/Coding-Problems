int digitsInFactorial(int N)
{
    double sum=1.0;
    for(int i=1;i<=N;i++)
    sum+=log10(i);
    return sum;
}

log10^k = logx!
k = log(1*2*3*...*x)+1 = (log1+log2+log3+...logx)+1
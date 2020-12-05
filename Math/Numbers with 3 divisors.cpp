int exactly3Divisors(int N)
{
    int count=0;
    for(int i=2;i<=sqrt(N);i++)
    {
        int x = i*i;
        if(isPrime(i) && x<=N)
        count++;
    }
    return count;
}

// prime number sqaures will have only 3 divisors
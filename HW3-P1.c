int isPrime(int num) {
	int divider = 0;
	if(num < 2)
		return 0;
	for(divider=2; divider<=num/2;++divider) {
		if(!(num%divider)) /* equals 0 */
			return 0;
	}
	return 1;
}

int goldbach(int num, int *p1, int *p2) {
	/* initializing with the smallest prime number */
	int n1=num-2;
	if(num%2)  /* odd number */
		return 0;
	while(n1 > 2) {
		if(isPrime(n1) && isPrime(num-n1)) {
			*p1 = n1;
			*p2 = num - n1;
			return 1;
		}
		--n1;
	}
	return 0;
}

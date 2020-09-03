void init(int bin[]) {
	int i;
	for (i = 0; i < LEN; ++i)
		bin[i] = 0;
}

int dec2bin(int dec, int bin[]) {
	int i;
	if(dec < 0 || dec > 255)
		return -1;
	init(bin);
	for(i = 0; dec > 0 && i < LEN; ++i, dec /= 2)
		bin[LEN - i - 1] = dec % 2;
	return dec == 0;
}

int bin2dec(int bin[]) {
	int dec = 0, i, pow = 1;
	for (	i = 0; i < LEN; ++i, pow *= 2)
		dec += pow * bin[LEN - i - 1];
	return dec;
}

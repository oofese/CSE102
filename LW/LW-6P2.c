char* append(char str1[], char str2[]) {
	char *ptr = str1;
    /* move ptr at the end of str1 */
    for(;*ptr;++ptr);
    while ((*ptr++ = *str2++));
    return str1;
}



int roman(int num, char romanstr[]) {
	int decimalRep[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char * romanRep[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int i = 0;
	if(num < 1)
		return 0;

	/* init roman string */
    romanstr[0] = '\0';

    /* roman numerals cannot represent numbers < 1 */
    while (num){
    	/* divide num to decimalRep from bigger to lower */
		/* continue until num < decimalRep[i]d */
        while (num / decimalRep[i]) {
            /* append the roman representation of decimalRep[i] to romanstr */
            append(romanstr, romanRep[i]);
            num -= decimalRep[i];
        }
        ++i;
    }
	return 1;
}


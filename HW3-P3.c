int charge(int cardType, int* monthlyUse, double* balance) {
	double tempBalance = *balance;
	if(cardType<1 || cardType>3)
		return -2;
	if(*monthlyUse > 0) {
		--(*monthlyUse);
	} else {
		switch(cardType) {
			case 0:
				tempBalance -= 2.3;
				break;
			case 1:
				tempBalance -= 1.15;
				break;
			case 2:
				tempBalance -= 1.65;
				break;
		}
		if(tempBalance < 0)
			return -1;
		*balance = tempBalance;
	}
	return 0;
}

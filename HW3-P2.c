int dispenseChange(double paid, double due, int *tl1, int *krs50, int *krs25, int *krs10, int *krs5, int *krs1) {
	int dispense = (paid - due) * 100; /* convert to kurus */
	/* dispense requires smaller kurus than 1 or paid < due */
	if(!compareDouble(paid-due, dispense/100.0) || paid < 0 || due < 0 || dispense < 0)
		return 0;
	*tl1 = dispense/100;
	dispense -= *tl1 * 100;
	*krs50 = dispense/50;
	dispense -= *krs50*50;
	*krs25 = dispense/25;
	dispense -= *krs25*25;
	*krs10 = dispense/10;
	dispense -= *krs10*10;
	*krs5 = dispense/5;
	dispense -= *krs5*5;
	*krs1 = dispense;
	return 1;
}

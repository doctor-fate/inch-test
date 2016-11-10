int maxarray(void *base, unsigned long nel, unsigned long width, int(*compare)(void *a, void *b)) {
	char *am = base;
	void *p = am;
	int i, max;
	max = 0;
	for (i = 0; i < nel - 1; ++i, am += width) {
		if (compare(am, p) > 0) {
			p = am;
			max = i;
		}
	}

	return (max);
}
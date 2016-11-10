#include "elem.h"

struct Elem *searchlist(struct Elem *list, int k) {
	typedef struct Elem* ST;
	ST am = list;
	for (;;) {
	repeat:
		if (am->tag == 2 && am->value.list != list && am->value.list != 0 && searchlist(am->value.list, k) != 0) {
			am = am->value.list;
			goto repeat;
		}
		if (am->tag == 0 && k == am->value.i)
			return am;
		if (am->tail == 0)
			return 0;
		am = am->tail;
	}
}
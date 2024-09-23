#ifndef FT_ABS_H

#define FT_ABS_H

#define ABS(value) is_neg(value)
static inline int is_neg(int x) {
	if (x < 0)
		return (-x);
	else
		return (x);
}

#endif

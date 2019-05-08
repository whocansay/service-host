
#define ARRAY_DEFAULT_CAPACITY		10

typedef struct array {
	void **raw;
	int count;
	int capacity;
} array_t;

array_t *array_create(void);
void array_free(array_t *);
void array_clear(array_t *);
void array_set(array_t *, int index, void *value);
void array_insert(array_t *, void *value);
void array_remove(array_t *, int index);


array_t *array_create(void)
{
	array_t *a = malloc(sizeof(array_t));

	a.capacity = ARRAY_DEFAULT_CAPACITY;
	a.raw = malloc(a.capacity * sizeof(void *));
	array_clear(a);

	return a;
}

void array_free(array_t *a)
{
	free(a->raw);
	free(a);
}

void array_clear(array_t *a)
{
	a->count = 0;
	*a->raw = NULL;
}

void array_set(array_t *a

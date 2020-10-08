void accumulate(const void *base, size_t n, size_t elem_size,
BinaryFunc fn, const void *init, void *result) {

memcpy(result, init, elem_size); // initilaize result
for (size_t i = 0; i < n; i++) { // do successive adds and use the callback repeatedly 
const void *next = (char *) base + i * elem_size;
fn(result, next, result);
}

}






static void multiply_two_numbers(void *partial, const void *next, void
*result) {
	
	int* a = (int *)partial;
	int* b = (const int *)next;
	
	
	(int *)result = (*a) * (*b);
	
}


int int_array_product(const int array[], size_t n) {
	int identity = 1, product;
accumulate(array, n, sizeof(int),multiply_two_numbers, &identity, &product);
	
	return product;
}
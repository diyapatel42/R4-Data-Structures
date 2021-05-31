/**
 * -------------------------
 * Student Name: Diya Patel
 * Student ID: 170894570
 * Student email: pate9457@mylaurier.ca
 * -------------------------
 */
 # include <stdio.h>

/**
 * --------------------------------------------------------
 * Parameters:
 * 		None
 * returns:
 * 		None
 * Description:
 * 		Function to learn about pointers
 * 		Learn about x,&x*(&x),ptr,*ptr,&ptr,sizeof(x),sizeof(ptr)
 * 		using integer and double data types
 * ----------------------------------------------------------
 */
void learn_pointers1() {
	int x = 10, *ptr1 = &x;
	double y = 10.5;
	double *ptr2 = &y;
	//declaring pointer
	//ptrl points to x, stores memory address.


	printf("int x = 10, *ptr1 = &x;\n");
	printf("Printing x = %d\n", x);
	printf("Printing &x in hex = %p and in decimal = %lu\n", &x, (unsigned long) &x);

	printf("Printing *(&x) = %d\n", *(&x)); // dereference; go to memory address x and get me the value of x.
	printf("Printing sizeof(x) = %d\n", sizeof(x));

	printf("Printing *ptr1 = %d\n", *ptr1);
	printf("Printing ptr1 in hex = %p and in decimal = %lu\n", ptr1, (unsigned long) ptr1);

	printf("Printing &ptr1 in hex = %p and in decimal = %lu\n", &ptr1, (unsigned long) &ptr1);

	printf("Printing sizeof(ptr1) = %d\n", sizeof(ptr1)); // can be different from one machine to another
	printf("Printing sizeof(*ptr1) = %d\n", sizeof(*ptr1));

	printf("\n");

	printf("double y = 10.5, *ptr2 = &y;\n");
	printf("Printing y = %.2lf\n", y);
	printf("Printing &y in hex = %p and in decimal = %lu\n", &y, (unsigned long) &y);

	printf("Printing *(&y) = %.2lf\n", *(&y)); // dereference; go to memory address x and get me the value of x.
	printf("Printing sizeof(y) = %d\n", sizeof(y));

	printf("Printing *ptr2 = %.2lf\n", *ptr2);
	printf("Printing ptr2 in hex = %p and in decimal = %lu\n", ptr2, (unsigned long) ptr2);

	printf("Printing &ptr2 in hex = %p and in decimal = %lu\n", &ptr2, (unsigned long) &ptr2);

	printf("Printing sizeof(ptr2) = %d\n", sizeof(ptr2)); // fixed
	printf("Printing sizeof(*ptr2) = %d\n", sizeof(*ptr2));//can change the data pointed tos size.


	return;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		None
 * returns:
 * 		None
 * Description:
 * 		Function to learn about pointers and arrays
 * ----------------------------------------------------------
 */
void learn_pointers2() {
	int x[3] = {10, 20, 30};
	int *ptr1 = x;//pointer points to array since an array we dont need &

	printf("x[3] = { 10, 20, 30 }, *ptr1 = x;\n");
	printf("Printing x[0] = %d\n", x[0]);
	printf("Printing x = %lu\n",  (unsigned long) x);
	printf("Printing &x in hex = %p and in decimal = %lu\n", &x, (unsigned long) &x); // dereference; go to memory address x and get me the value of x.
	printf("Printing sizeof(x) = %d\n", sizeof(x));

	printf("Printing *ptr1 = %d\n", *ptr1);
	printf("Printing ptr1 in hex = %p and in decimal = %lu\n", ptr1, (unsigned long) ptr1);

	printf("Printing &ptr1 in hex = %p and in decimal = %lu\n", &ptr1, (unsigned long) &ptr1);

	printf("Printing sizeof(ptr1) = %d\n", sizeof(ptr1)); // can be different from one machine to another
	printf("Printing sizeof(*ptr1) = %d\n", sizeof(*ptr1));

	printf("\n");

	printf("ptr1[1] = %d\n", ptr1[1]);
	printf("*(ptr1 + 2) = %d\n", *(ptr1 + 2));
	printf("*(x + 2) = %d\n", *(x + 2));
	ptr1++;
	printf("Printing *ptr1 after ptr1++ = %d\n", *ptr1);
	ptr1--;
	printf("Printing *ptr1 after ptr1-- = %d\n", *ptr1);
	ptr1 = &x[2];
	printf("Printing *ptr1 after ptr1=&x[2]; = %d\n", *ptr1);
	(*ptr1)++;
	printf("Printing *ptr1 after (*ptr1)++; = %d\n", *ptr1);
	printf("\n");

	return;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		num1 (int)
 * 		num2 (int)
 * returns:
 * 		None
 * Description:
 * 		Two integers are passed by value. The function attempts to swap
 * 		without using pointers. Mission fails.
 * ----------------------------------------------------------
 */
void swap1(int num1, int num2) {
	int temp;
	temp = num1;
	num1 = num2;
	num2= temp;
	return;// in c we can only return one value and not multiple values so we do not returna nd need pointers.
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		num1 (int)
 * 		num2 (int)
 * returns:
 * 		None
 * Description:
 * 		Two integers are passed by reference. The function attempts to swap
 * 		using pointers. Mission succeed.
 * ----------------------------------------------------------
 */
//x = 10;
//y = 20;
//int *ptr1= &x, *ptr2 = &y;
//swap2(ptr1, pyr2) num1 points to x and num 2 points to 2.
//swap2(&x, &y)
void swap2(int *num1, int *num2) {
	int temp;

	temp = *num1; //* changes value and not the pointer
	*num1 = *num2;
	*num2 = temp;
	return;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		num1 (int)
 * 		num2 (int)
 * returns:
 * 		None
 * Description:
 * 		Two pointers are passed by reference.
 * 		The function attempts to swap the two pointers.
 * ----------------------------------------------------------
 */
void swap3(int **r1, int **r2) {
	int *temp;
	temp = *r1;
	*r1 = *r2;
	*r2 = temp;
	return;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		array (int*)
 * 		size (const int)
 * returns:
 * 		None
 * Description:
 * 		Reverses an array
 * ----------------------------------------------------------
 */
void reverse_array(int *array, const int size) {
	if(array == NULL){//doesn't point anywhere.
		printf("Error(reverse_array): NULL pointer\n");

	}
	if(size<=0){
		printf("Error(reverse_array): invalid size\n");
	}

	int i,temp[size];
	for(i=0; i<size;i++){
		temp[i] = array[size-i-1]; // copy from end and put from start;
	}
	for(i=0; i<size;i++){
		array[i] = temp[i]; // copy array now into og array;
	}


	return; // since array is a pointer changes will be reflected.
}


/**
 * --------------------------------------------------------
 * Parameters:
 * 		var1 (void*)
 * 		var2 (void*)
 * 		mode (char)
 * returns:
 * 		None
 * Description:
 * 		Generic swap by reference function.
 * 		Supports three modes:
 * 		'i': to swap integers
 * 		'c': to swap characters
 * 		'f': to swap floats
 * 		prints an error message for unsupported modes
 * ----------------------------------------------------------
 */
void swap4(void *var1, void *var2, char mode) {
	if(mode == 'i'){
		int temp;
		temp = *(int*) var1;
		*(int*) var1 = *(int*)var2;
		*(int*) var2 = temp;

	}else if(mode == 'f'){
		float temp;
		temp = *(float*) var1;
		*(float*) var1 = *(float*)var2;
		*(float*) var2 = temp;

	}else if( mode == 'c'){
		char temp;
		temp = *(char*) var1;
		*(char*) var1 = *(char*)var2;
		*(char*) var2 = temp;

	}else{
		printf("Error(swap4): unsupported mode\n");

	}

	return;
}

/**
 * --------------------------------------------------------
 * Parameters:
 * 		array (int*): an array of integers
 * 		size (const int): size of given array
 * 		ptr (*int[2]): an array of two pointers
 * returns:
 * 		None
 * Description:
 * 		Finds the maximum and minimum values of an array
 * 		Reference to max value is stored at first element in pointer array
 * 		Reference to min value is stored at second element in pointer array
 * ----------------------------------------------------------
 */
void find_max_min(int *array, const int size, int *ptr[2]) {
	int i, max = 0, min = 0;
	for(i = 0; i<size;i++){
		if(array[i]>array[max]){
			max = i;
		}
		if(array[i]<array[min]){
			min = i;
		}
	}
	ptr[0] = &array[max];
	ptr[1] = &array[min];


	return;
}

#include "Arrays.h"

// ----------------------------------- Helper/private function definitions -------------------------------------------------
	
/*	Definition:
*		Doubles the size of the given Array objects dynamic array
*	Parameters:
*		None
*	Returns:
*		None
*/
void Arrays::double_the_size() {

	// allocate the new dynamic array
	int* temp = new int[this->size * 2];

	// copy over all the elements to the new dynamic array
	for (int x = 0; x < this->size; x++) {
		temp[x] = this->array_ptr[x];
	}

	// set the new size
	this->size = this->size * 2;

	// clean the old array
	delete[] this->array_ptr;

	// assign the new array to the array_ptr
	this->array_ptr = temp;
}

/*	Definition:
*		Swaps two values in the array given two indexes
*	Parameters:
*		int first: first index
*		int second: second index
*	Returns:
*		None
*/
void Arrays::swap_values(int first, int second) {

	int temp = this->array_ptr[first];
	this->array_ptr[first] = this->array_ptr[second];
	this->array_ptr[second] = temp;
}

/*	Definition:
*		Implements binary search. Using recursions (Not that memory efficeint. O(n) space complexity !!)
*	Parameters:
*		int value: value needed to be searched
*		int low: index of the low pointer
*		int high: index of the high pointer
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::binary_search_recursive(int value, int low, int high) {
	
	while (low <= high) {

		int mid = (low + high) / 2;

		if (value == this->array_ptr[mid]) {
			return mid;
		}
		else if (value < this->array_ptr[mid]) {
			return binary_search_recursive(value, low, mid - 1);
		}
		else { // case where value > this->array_ptr[mid]
			return binary_search_recursive(value, mid + 1, high);
		}
	}

	return -1;
}

/*	Definition:
*		Implements sum of all the elements in the array using recursions (Not that memory efficeint. O(n) space complexity !!)
*	Parameters:
*		int end_index: index of the last element of the array
*	Returns:
*		sum of all the elements
*/
int Arrays::sum_recursive(int end_index) {

	if (end_index > 0) {
		return 0;
	}
	else {
		return this->array_ptr[end_index] + sum_recursive(end_index - 1);
	}
}

// -------------------------------------------------------------------------------------------------------------------------


/*	definition of default constructor
*	create an array of size 10.
*	length set to 0
*/
Arrays::Arrays() {

	this->array_ptr = new int[10];
	this->size = 10;
	this->length = 0;
}

/*	defintion of parameterized constructor
	Parameters:
		int size: size of the array
	Returns: None
*/
Arrays::Arrays(int size) {

	this->array_ptr = new int[size];
	this->size = size;
	this->length = 0;
}

/*	defintion of copy constructor
	Parameters:
		Arrays& array_: Reference to another Arrays class (Creates a deep copy  of the object)
	Returns: 
		None
*/
Arrays::Arrays(Arrays& array_) {

	this->array_ptr = new int[array_.size];
	this->size = array_.size;
	this->length = array_.length;

	if (this->array_ptr != nullptr) {

		// copy all the elements to this object (Deep copy part)
		for (int x = 0; x < array_.length; x++) {

			this->array_ptr[x] = array_.array_ptr[x];
		}
	}
}

/*	defintion Arrays class destructor
	Parameters:
		None
	Returns:
		None
*/
Arrays::~Arrays() {
	
	// Deallocate the memory for the dynamic array
	delete[] this->array_ptr;
}

/*	Definition of get_length
*	Parameters:
*		None
*	Returns:
*		current length of the array
*/
int Arrays::get_length() {
	
	return this->length;
}

/*	Definition of get_size
*	Parameters:
*		None
*	Returns:
*		current size of the array
*/
int Arrays::get_size() {

	return this->size;
}

/*	Definition of Display function for Arrays class
*	Parameters:
*		None
*	Returns:
*		None
*/
void Arrays::display() {

	for (int x = 0; x < this->length; x++) {
		cout << this->array_ptr[x] << " ";
	}

	cout << endl;
}

/*	Definition:
*		Adds the given element to the end of the array.
*		If the array is full we double the size	
*	Parameters:
*		int element: element needed to be added
*	Returns:
*		None
*/
void Arrays::append(int element) {

	// if the array is already full double the size
	if (this->length >= this->size) {

		double_the_size();
	}

	// append the new element
	this->array_ptr[this->length] = element;

	// increment the length
	this->length++;
	
}

/*	Definition:
*		inserts an element to a given index
*		If the array is full we double the size
*	Parameters:
*		int element: element needed to be added
*		int index: index of where the element goes (index starts from 0)
*	Returns:
*		None
*/
void Arrays::insert(int element, int index) {

	if (index >= 0 && index <= this->length) {

		// if the array is already full double the size
		if (this->length >= this->size) {
			double_the_size();
		}

		// move the elements to the right to make space for the new element
		for (int x = this->length; x > index; x--) {
			this->array_ptr[x] = this->array_ptr[x - 1];
		}

		// add the new element to the given index
		this->array_ptr[index] = element;

		// increment the current length
		this->length++;
	}
}

/*	Definition:
*		deletes an element from a given index
*	Parameters:
*		int index: index of where the element should be deleted (index starts from 0)
*	Returns:
*		None
*/
void Arrays::delete_(int index) {

	if (index >= 0 && index < this->length) {

		// move all the elements towards the index
		for (int x = index; x < this->length - 1; x++) {
			this->array_ptr[x] = this->array_ptr[x + 1];
		}

		// decrement the length
		this->length--;
	}
}

/*	Definition:
*		Implements linear search
*	Parameters:
*		int value: value needed to be searched
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::linear_search(int value) {

	for (int x = 0; x < this->length; x++) {

		if (value == this->array_ptr[x]) {
			return x;
		}
	}

	return -1;
}

/*	Definition:
*		Implements linear search with transpoistion. I.e searched value will be moved one index to the right when its found
*	Parameters:
*		int value: value needed to be searched
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::linear_search_transposition(int value) {

	for (int x = 0; x < this->length; x++) {

		if (value == this->array_ptr[x]) {

			if (x == 0) { // if found as the first elements return 0.
				return 0;
			}
			else { // found somewhere else, move the element one index to the left and return that index

				swap_values(x, x - 1);
				return x - 1;
			}
		}
	}

	return -1;
}

/*	Definition:
*		Implements linear search with move to front. I.e searched value will be moved 0th index when its found
*	Parameters:
*		int value: value needed to be searched
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::linear_search_move_front(int value) {

	for (int x = 0; x < this->length; x++) {

		if (value == this->array_ptr[x]) {

			swap_values(0, x);
			return 0;
		}
	}

	return -1;
}

/*	Definition:
*		Implements binary search.
*	Parameters:
*		int value: value needed to be searched
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::binary_search(int value) {

	int low = 0, high = this->length - 1;

	while (low <= high) {

		int mid = (low + high) / 2;

		if (value == this->array_ptr[mid]) {
			return mid;
		}
		else if (value < this->array_ptr[mid]) {
			high = mid - 1;
		}
		else { // case where value is greater than this->array_prt[mid]
			low = mid + 1;
		}
	}

	return -1;
}

/*	Definition:
*		Implements interface to call binary-search_iterative function.
*	Parameters:
*		int value: value needed to be searched
*	Returns:
*		int index: return the index of the found value. Returns -1 if not found
*/
int Arrays::binary_search_recursive(int value) {

	return binary_search_recursive(value, 0, this->length - 1);
}

/*	Definition:
*		returns the value at given index.
*	Parameters:
*		int index: value needed retrieved
*	Returns:
*		int index: return the value at the index. Returns -1 if not found
*/
int Arrays::get(int index) {

	if (index >= 0 && index < this->length) {
		return this->array_ptr[index];
	}
}

/*	Definition:
*		sets given value at the given index.
*	Parameters:
*		int index: where the value need to be stored
*		int value: value passed by the user
*	Returns:
*		None
*/
void Arrays::set(int index, int value) {

	if (index >= 0 && index < this->length) {
		this->array_ptr[index] = value;
	}
}

/*	Definition:
*		Finds the maximum value in the array.
*	Parameters:
*		None
*	Returns:
*		maximum value
*/
int Arrays::max() {

	int max = this->array_ptr[0];

	for (int x = 1; x < this->length; x++) {

		if (max < this->array_ptr[x]) {
			max = this->array_ptr[x];
		}
	}

	return max;
}

/*	Definition:
*		Finds the minimum value in the array.
*	Parameters:
*		None
*	Returns:
*		minimum value
*/
int Arrays::min() {

	int min = this->array_ptr[0];

	for (int x = 1; x < this->length; x++) {

		if (min > this->array_ptr[x]) {
			min = this->array_ptr[x];
		}
	}

	return min;
}

/*	Definition:
*		calculates the sum of the all the elements in the array.
*	Parameters:
*		None
*	Returns:
*		sum of all elements
*/
int Arrays::sum() {

	int sum = 0;

	for (int x = 0; x < this->length; x++) {
		sum += this->array_ptr[x];
	}

	return sum;
}

/*	Definition:
*		Implements interface to call sum_recursive function.
*	Parameters:
*		None
*	Returns:
*		sum of all the elements
*/
int Arrays::sum_recursive() {

	return sum_recursive(this->length - 1);
}

/*	Definition:
*		Calculates the average of the elements in the array.
*	Parameters:
*		None
*	Returns:
*		average of the elements
*/
double Arrays::average() {

	try {
		return (double)this->sum() / this->length;
	}
	catch (...) {
		throw "Division by zero ";
	}	
}

/*	Definition:
*		Reverses the array using a temporary array.
*	Parameters:
*		None
*	Returns:
*		None
*/
void Arrays::reverse_array_auxialiay() {

	// create a temporary array
	int* temp_array = new int[this->length];

	// Copy all the elements in reverse to the temporary array
	for (int x = this->length - 1, y = 0; x >= 0; x--, y++) {
		
		temp_array[y] = this->array_ptr[x];
	}

	// Copy all the elements from the temp_array to the orignal array
	for (int x = 0; x < this->length; x++) {

		this->array_ptr[x] = temp_array[x];
	}

	// Deallocate the temporary array
	delete[] temp_array;
}

/*	Definition:
*		Reverses the array using two pointer technique.
*	Parameters:
*		None
*	Returns:
*		None
*/
void Arrays::reverse_array_two_pointer() {

	for (int x = 0, y = this->length - 1; x < y; x++, y--) {

		this->swap_values(x, y);
	}
}

/*	Definition:
*		Moves elements in the array to the left user defined times
*	Parameters:
*		int times: how many times elements should be moved to the left
*	Returns:
*		None
*/
void Arrays::left_shift(int times) {

	// check if shift is not greater than number of elements preset
	// if greater than the elements we can not shift
	if (times > this->length) {

		return;
	}

	for (int x = 0, y = times; y < this->length; x++, y++) {

		// reuse set function to move the value
		this->set(x, this->array_ptr[y]);

		// set zero to shifted value
		this->set(y, 0);
	}	
}

/*	Definition:
*		Moves elements in the array to the right user defined times
*	Parameters:
*		int times: how many times elements should be moved to the right
*	Returns:
*		None
*/
void Arrays::right_shift(int times) {

	// check if shift is not greater than number of elements preset
	// if greater than the elements we can not shift
	if (times > this->length) {

		return;
	}

	for (int x = (this->length - 1) - times, y = this->length - 1; x >= 0; x--, y--) {

		// reuse set function to move the value
		this->set(y, this->array_ptr[x]);
	}

	// add righshifted times of zeros starting from the begining of the array
	for (int x = 0; x < times; x++) {

		this->set(x, 0);
	}
}

/*	Definition:
*		Checks the array is sorted (in ascending order)
*	Parameters:
*		None
*	Returns:
*		None
*/
bool Arrays::is_array_sorted() {

	for (int x = 0; x < this->length - 1; x++) {
		
		if (this->array_ptr[x] > this->array_ptr[x + 1]) {

			return false;
		}
	}

	return true;
}

/*	Definition:
*		Inserts an element to the array if the array is sorted (in ascending order)
*	Parameters:
*		int element: Element needed to be inserted to the array
*	Returns:
*		None
*/
void Arrays::insert_to_sorted_array(int element) {
	
	// check if the array is sorted
	if (!this->is_array_sorted()) {
		
		return;
	}
		
	// if the array is full increase its size
	if (this->length >= this->size) {

		this->double_the_size();
	}

	int x = this->length - 1;

	// move elements to the right until we find the right postion
	while (element < this->array_ptr[x] && x >= 0) {

		this->array_ptr[x + 1] = this->array_ptr[x];
		x--;
		cout << "x: " << x << endl;
	}

	// insert the element
	this->array_ptr[x + 1] = element;

	// increment the length
	this->length++;
}

/*	Definition:
*		Move all the negative elements in the array to the left 
*	Parameters:
*		None
*	Returns:
*		None
*/
void Arrays::move_negatives_to_left() {

	int x = 0, y = this->length - 1;

	while (x < y) {

		// loop x pointer until finds a positive number
		while (this->array_ptr[x] < 0) { x++; }

		// loop y pointer until finds a negative number
		while (this->array_ptr[y] >= 0) { y++; }

		// when positive on the left and negative on the right is found swap them
		if (x < y) {

			this->swap_values(x, y);
		}
	}
}

/*	Definition:
*		Merge user given array and this array (Both arrays must be sorted)
*	Parameters:
*		Arrays* array_: pointer to the user given Array object
*	Returns:
*		Returns a pointer to the resulting array. Returns nullptr if failed
*/
Arrays* Arrays::merge_sorted_arrays(Arrays* array_) {

	//check if both arrays are sorted (in ascending order)
	if (!(this->is_array_sorted() && array_->is_array_sorted())) {

		return nullptr;
	}

	int i = 0, j = 0;

	// create a new Arrays object
	Arrays* new_array = new Arrays(this->length + array_->length);

	while (i < this->length && j < array_->length) {

		if (this->array_ptr[i] < array_->array_ptr[j]) {

			new_array->append(this->array_ptr[i]);
			i++;
		}
		else {

			new_array->append(array_->array_ptr[j]);
			j++;
		}
	}

	// copy over remaining elements of this array
	for (; i < this->length; i++) {

		new_array->append(this->array_ptr[i]);
	}

	// copy over remaining elements of the given array
	for (; j < array_->array_ptr[j]; j++) {

		new_array->append(array_->array_ptr[j]);
	}

	return new_array;
}

/*	Definition:
*		Merge user given array to this array (Both arrays must be sorted)
*		Arrays wont merge if one of them is unsorted
*	Parameters:
*		Arrays* array_: pointer to the user given Array object
*	Returns:
*		None
*/
void Arrays::merge_sorted_array(Arrays* array_) {

	if (!(this->is_array_sorted() && array_->is_array_sorted())) {

		return;
	}

	int i = 0, j = 0, k = 0;

	// allocate a temporary array to hold final result
	int* merged_array = new int[this->length + array_->length];

	while (i < this->length && j < array_->length) {

		if (this->array_ptr[i] < array_->array_ptr[j]) {

			merged_array[k] = this->array_ptr[i];
			i++;
			k++;
		}
		else {

			merged_array[k] = array_->array_ptr[j];
			j++;
			k++;
		}
	}

	// copy remaninig elements of this array
	for (; i < this->length; i++) {

		merged_array[k] = this->array_ptr[i];
		k++;
	}

	// copy remaining elements of array_
	for (; j < array_->length; j++) {

		merged_array[k] = array_->array_ptr[j];
		k++;
	}

	// deallocate the old array
	delete[] this->array_ptr;

	// point array pointer of the this array to the merged_array
	this->array_ptr = merged_array;

	// set new length and the size
	this->size = this->length = (this->length + array_->length);
}

/*	Definition:
*		Checks if an element exist in the array
*	Parameters:
*		int element: element needs to be checked
*	Returns:
*		None
*/
bool Arrays::element_exists(int element) {

	for (int x = 0; x < this->length; x++) {

		if (element == this->array_ptr[x]) {

			return true;
		}
	}

	return false;
}

/*	Definition:
*		Finds union of two unsorted arrays. This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::union_unsorted_arrays(Arrays* array_) {

	// Copy all the elements of this array to the resulting using copy constructor
	Arrays* resulting_array = new Arrays(*this);

	// Compare all the elements in the passed in array and copy only unique ones
	for (int x = 0; x < array_->get_length(); x++) {

		if (!this->element_exists(array_->array_ptr[x])) {

			resulting_array->append(array_->array_ptr[x]);
		}
	}

	return resulting_array;
}

/*	Definition:
*		Finds union of two sorted arrays. This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*		Returns a nullptr if one of the array is not sorted
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::union_sorted_arrays(Arrays* array_) {

	// Check if both arrays are sorted
	if (!(this->is_array_sorted() && array_->is_array_sorted())) {

		return nullptr;
	}

	// Create a new Arrays object to store the result
	Arrays* resulting_array = new Arrays();

	int i = 0, j = 0;

	while (i < this->length && j < array_->length) {

		if (this->array_ptr[i] < array_->array_ptr[j]) {

			resulting_array->append(this->array_ptr[i]);
			i++;
		}
		else if (this->array_ptr[i] > array_->array_ptr[j]) {

			resulting_array->append(array_->array_ptr[j]);
			j++;
		}
		else {

			resulting_array->append(this->array_ptr[i]);
			i++;
			j++;
		}
	}

	// Copy left over elements of this array
	for (; i < this->length; i++) {

		resulting_array->append(this->array_ptr[i]);
	}

	// Copy left over elements of arrays_ array
	for (; j < array_->length; j++) {

		resulting_array->append(array_->array_ptr[j]);
	}

	return resulting_array;
}

/*	Definition:
*		Finds intersection of two unsorted arrays. This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::intersection_unsorted_arrays(Arrays* array_) {

	// Resulting Arrays object to hold the results
	Arrays* resulting_array = new Arrays();

	for (int x = 0; x < this->length; x++) {

		if (array_->element_exists(this->array_ptr[x])) {

			resulting_array->append(this->array_ptr[x]);
		}
	}

	return resulting_array;
}

/*	Definition:
*		Finds intersection of two sorted arrays. This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*		Returns a nullptr if one of the array is not sorted
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::intersection_sorted_arrays(Arrays* array_) {

	if (!(this->is_array_sorted() && array_->is_array_sorted())) {

		return nullptr;
	}

	// Resulting Arrays to hold the results
	Arrays* resulting_array = new Arrays();

	int i = 0, j = 0;

	while (i < this->length && j < array_->length) {

		if (this->array_ptr[i] < array_->array_ptr[j]) {

			i++;
		}
		else if (this->array_ptr[i] > array_->array_ptr[j]) {

			j++;
		}
		else {

			resulting_array->append(this->array_ptr[i]);
			i++;
			j++;
		}
	}

	return resulting_array;
}

/*	Definition:
*		Finds difference of two unsorted arrays (this_array - user_given). This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::difference_unsorted_arrays(Arrays* array_) {

	// Resulting array to hold the results
	Arrays* resulting_array = new Arrays();

	for (int x = 0; x < this->length; x++) {

		if (!array_->element_exists(this->array_ptr[x])) {

			resulting_array->append(this->array_ptr[x]);
		}
	}

	return resulting_array;
}

/*	Definition:
*		Finds difference of two sorted arrays (this_array - user_given). This array and user given array object
*	Parameters:
*		Arrays* array_: user passed in Arrays object
*	Returns:
*		Pointer to the resulting Arrays object
*		Retuns nullptr if one of the arrays are not sorted
*	Assumption:
*		Arrays only consists of unique elements (Does not contain duplicates)
*/
Arrays* Arrays::difference_sorted_arrays(Arrays* array_) {

	if (!(this->is_array_sorted() && array_->is_array_sorted())) {

		return nullptr;
	}

	// Resulting Arrays_ object to hold the results
	Arrays* resulting_array = new Arrays();

	int i = 0, j = 0;

	while (i < this->length && j < array_->length) {

		if (this->array_ptr[i] < array_->array_ptr[j]) {

			resulting_array->append(this->array_ptr[i]);
			i++;
		}
		else if (this->array_ptr[i] > array_->array_ptr[j]) {

			j++;
		}
		else {

			i++;
			j++;
		}
	}

	// Copy remaining elements of the this array
	for (; i < this->length; i++) {

		resulting_array->array_ptr[i];
	}

	return resulting_array;
}
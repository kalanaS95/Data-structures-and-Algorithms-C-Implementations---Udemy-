// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Arrays.h"

int main()
{
	// object created in the stack !!
	Arrays myarray(1);

	myarray.append(2);
	myarray.append(3);
	myarray.append(4);
	myarray.append(5);
	myarray.insert(8, 4);
	myarray.insert(10, 5);

	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	myarray.display();

	/*
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	cout << "Element found at index (Linear Search): " << myarray.linear_search(3) << endl;
	cout << "New array looks like: " << endl;
	myarray.display();

	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	cout << "Element found at index (Linear Search - Transposition): " << myarray.linear_search_transposition(3) << endl;
	cout << "New array looks like: " << endl;
	myarray.display();
	
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	cout << "Element found at index (Linear Search - Move to front): " << myarray.linear_search_move_front(99) << endl;
	cout << "New array looks like: " << endl;
	myarray.display();
	
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	cout << "Element found at index (Binary search iterative): " << myarray.binary_search(6) << endl;
	cout << "New array looks like: " << endl;
	myarray.display();
	
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	cout << "Element found at index (Binary search recursive): " << myarray.binary_search_recursive(1) << endl;
	cout << "New array looks like: " << endl;
	myarray.display();
	
	cout << "Reveresed array (using auxiliary method): " << endl;
	myarray.reverse_array_auxialiay();
	myarray.display();
	
	cout << "Reveresed array (two pointer method): " << endl;
	myarray.reverse_array_two_pointer();
	myarray.display();
	
	cout << "After left shifting array by 2 times: " << endl;
	myarray.left_shift(3);
	myarray.display();
	
	cout << "After right shifting array by 2 times: " << endl;
	myarray.right_shift(6);
	myarray.display();

	cout << "Is array sorted ?: " << myarray.is_array_sorted() << endl;
	
	myarray.insert_to_sorted_array(9);
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	myarray.display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	new_array.display();
	Arrays* merged_array = myarray.merge_sorted_arrays(&new_array);

	if (merged_array == nullptr) { 
		throw "nullptr exception. Probably one of the arrays are unsorted"; 
	}

	cout << "\n Merged array: " << endl;
	cout << "Length: " << merged_array->get_length() << " Size: " << merged_array->get_size() << endl;
	merged_array->display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	myarray.merge_sorted_array(&new_array);

	cout << "\n After merging: " << endl;
	cout << "Length: " << myarray.get_length() << " Size: " << myarray.get_size() << endl;
	myarray.display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.union_unsorted_arrays(&new_array);

	cout << "\n Union of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.union_sorted_arrays(&new_array);

	cout << "\n Union of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	
	
	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.intersection_unsorted_arrays(&new_array);

	cout << "\n intersection of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.intersection_sorted_arrays(&new_array);

	cout << "\n intersection of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.difference_unsorted_arrays(&new_array);

	cout << "\n Difference of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	

	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.difference_sorted_arrays(&new_array);

	cout << "\n Difference of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
	*/
	
	Arrays new_array(10);
	for (int x = 0; x < 10; x++) {
		new_array.append(x * 2);
	}

	cout << "\nSecond array: " << endl;
	cout << "Length: " << new_array.get_length() << " Size: " << new_array.get_size() << endl;
	new_array.display();

	Arrays* resulting_array = myarray.union_unsorted_arrays(&new_array);

	cout << "\n intersection of two arrays: " << endl;
	cout << "Length: " << resulting_array->get_length() << " Size: " << resulting_array->get_size() << endl;
	resulting_array->display();
}


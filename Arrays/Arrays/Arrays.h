#pragma once
#include <iostream>
using namespace std;

class Arrays {

private:
	int* array_ptr;
	int size;
	int length;
	void double_the_size();
	void swap_values(int first, int second);
	int binary_search_recursive(int value, int low, int high);
	int sum_recursive(int end_index);

public:
	Arrays(); // default constructor
	Arrays(int size); // parameterized constructor
	/* 
		copy constructor (always takes a reference to an object). Called when object is created and initialized at the same time (e.g. Arrays arr1 = arr) 
		copy constructor is not called when using =, we need to use operator overloading for that
	*/
	Arrays(Arrays& array_);
	~Arrays();
	int get_length();
	int get_size();
	void display();
	void append(int element);
	void insert(int element, int index);
	void delete_(int index);
	int linear_search(int value);
	int linear_search_transposition(int value);
	int linear_search_move_front(int value);
	int binary_search(int value);
	int binary_search_recursive(int value);
	int get(int index);
	void set(int index, int value);
	int max();
	int min();
	int sum();
	int sum_recursive();
	double average();
	void reverse_array_auxialiay();
	void reverse_array_two_pointer();
	void left_shift(int times);
	void right_shift(int times);
	bool is_array_sorted();
	void insert_to_sorted_array(int element);
	void move_negatives_to_left();
	Arrays* merge_sorted_arrays(Arrays* array_);
	void merge_sorted_array(Arrays* array_);
	bool element_exists(int element);
	Arrays* union_unsorted_arrays(Arrays* array_); // double check this logic again !!!! 
	Arrays* union_sorted_arrays(Arrays* array_);
	Arrays* intersection_unsorted_arrays(Arrays* array_);
	Arrays* intersection_sorted_arrays(Arrays* array_);
	Arrays* difference_unsorted_arrays(Arrays* array_);
	Arrays* difference_sorted_arrays(Arrays* array_);
};
There are several methods to sort an unordered array.
The 2 I like most are selection sort and insertion sort. 
No particular reason, I just the way they work and they make intuitive sense to me. 

Selection Sort:
	Works by selecting the first element in the array. 
	It then makes a pass over every other element in the array. 
	Once it has completed a pass of the array one of two things will happen:
		If it is not the lowest number in the array:
			It will swap places with the one that is
		If it is the lowest number in the array:
			It will stay where it is
	
	It will then select the second element in the array, pass over every element infront of it
	(the lowest number is already at the start)
	Then swap places with the second lowest (if there is one) or stay in place.

	This will repeat until it does a pass that requires no adjustments. 


Insertion Sort:
	This works by comparing the first 2 numbers in the array, checking if the first entry is 
	lower than the second. If it is not the elements will swap places.

	It will then compare the second and 3 arrays, if the next array is greater than the previous one
	then it will stay in place
	If it is lower then it will compare then it will continue to compare decending elements until it is greater than
	the element it is comparing itself to. 

	This will continue until all elements are sorted. 

#include "my_string.h"

char* my_strncpy (char* destination, const char* source, size_t num)
{
	char* initial = destination;

	//While values can be copied and the num limit isn't reached, loops.
	while (!!*source && num > 0) {
		//The value is copied from the source to the destination.
		*destination = *source;

		source++;
		destination++;
		num--;
	}

	//Appends the rest of the destination with null characters until limit is reached.
	while (num > 0) {
		*destination = 0;

		destination++;
		num--;
	}

	return initial;
}

char* my_strchr (char* str, int character)
{
	//If the character is null, the end of the string needs to be returned.
	if (!character) {
		while (*str)
			str++;

		return str;
	}	

	//Loops until the character is found.
	while (!!*str && *str != character)
		str++;
	
	//If the character is never found, a null pointer is returned.
	if (!*str)
		return 0;

	return str;
}

void* my_memmove (void* destination, const void* source, size_t num)
{

	//Casting to char pointers because chars are a single byte.
	char* dest = (char*) destination;
	char* src = (char*) source;
	char temp[num];
	
	//Stores current values in an array.
	for(int i = 0; i < num; i++)
		temp[i] = src[i];

	//Adds values into the new location.
	for(int i = 0; i < num; i++)
		dest[i] = temp[i];

	return destination;
}

char* my_strncat (char* destination, const char* source, size_t num)
{
	char* dest = destination;

	while (*dest)
		dest++;

	//Loops while the source has characters to concat and the limit isn't reached.
	while (*source && num) {
		//The value is copied from the source to the destination.
		*dest = *source;

		dest++;
		source++;
		num--;
	}
	
	//Last character is a null character.
	*dest = 0;
	return destination;
}

int my_strncmp (const char* str1, const char* str2, size_t num)
{
	//Loops while both strings have values and the limit isn't reached.
    	while (*str1 && *str2 && num > 0) {
		int difference = *str1 - *str2;

		//If a difference is found between the current characters, the program stops.
		if (difference != 0)
			return difference;

		str1++;
		str2++;
		num--;
	}

	//If both strings have been similar till the limit has been reached, they are equal.
	if (num == 0)
		return 0;

	//If string1 or string2 still exist and the other is terminated, an inequality exists.
	if (*str1) {
		return (int) *str1;
	}

	if (*str2) {
		return (int) *str2;
	}

	return 0;
}

int my_strcmp (const char* str1, const char* str2)
{
	//Loops while both strings have values.
	while (*str1 && *str2) {
		int difference = *str1 - *str2;

		if (difference != 0)
			return difference;

		str1++;
		str2++;
	}

	//If string1 or string2 still exist and the other is terminated, an inequality exists.
	if (*str1) {
		return (int) *str1;
	}

	if (*str2) {
		return (int) *str2;
	}

	return 0;
}

char* my_strrchr (char* str, int character)
{
	char* ptr;

	//Loops through the entire string.
	while (*str) {
		//Keeps track of last matching value found.
		if (*str == character)
			ptr = str;

		str++;
	}
	
	//If the character is a terminating character, points to the end of the string.
	if (*str == character)
		return str;

	//If the pointer equal the desired character, a match hasn't been found.
	if (*ptr != character) {
		return 0;
	}

	return ptr;
}

char* my_strstr (char* str1, const char* str2)
{

	//If the second string doesn't exist, the first string contains it.
	if (!*str2)
		return str1;

	int locating = 0;
	const char* storage = str2;
	char* location;

	//Loops while the first string has characters.
	while (*str1) {
		//If all characters in the second string have been found, the beginning location is returned.
		if (!!locating && !*str2)
			return location;

		//If a substring was being found but doesn't work in current iteration, variables reset.
		else if (!!locating && *str1 != *str2) {
			locating = 0;
			str2 = storage;
		}

		//If a substring is being found and the current iteration works, continue.
		else if (!!locating)
			str2++;

		//If the current iteration is the same as the beginning of the second string, starts searching.
		//The location is also stored for return purposes.
		else if (*str1 == *str2) {
			locating = 1;
			location = str1;
			str2++;
		}

		str1++;
	}

	//Checks for the last character due to terminating characters.
	if (!!locating && !*str2)
		return location;

	return 0;
}

#include "LK_prompt.h"

/**
 * _strlen - Calculate the length of a string
 * @s: The string to be measured
 *
 * Return: Length of the string
 */
size_t _strlen(const char *s)
{
	size_t len;

	for (len = 0; s && *s != '\0'; ++len, ++s)
		;

	return (len);
}

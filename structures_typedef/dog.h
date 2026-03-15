#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A new type describing a dog
 * @name: First member, name of the dog (string)
 * @age: Second member, age of the dog (float)
 * @owner: Third member, owner of the dog (string)
 *
 * Description: This structure stores basic information about a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif

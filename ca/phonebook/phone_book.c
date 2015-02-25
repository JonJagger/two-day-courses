#include "phone_book.h"
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_NAME_LEN 32

struct phone_book_name
{
    char letters[MAX_PHONE_NAME_LEN + 1];
};

typedef struct phone_book_name phone_book_name;

static phone_book_name make_phone_book_name(const char * letters)
{
    phone_book_name name;
    strncpy(name.letters, letters, MAX_PHONE_NAME_LEN);
    name.letters[MAX_PHONE_NAME_LEN] = '\0';
    return name;
}

static int phone_book_name_compare(const phone_book_name * lhs,
                                   const phone_book_name * rhs)
{
    return strcmp(lhs->letters, rhs->letters);    
}

//--------------------------------------------------

#define MAX_PHONE_NUMBER_LEN 32

struct phone_book_number
{
    char digits[MAX_PHONE_NUMBER_LEN + 1];
};

typedef struct phone_book_number phone_book_number;

struct phone_book_entry
{
    phone_book_name name;
    phone_book_number number;
};

typedef struct phone_book_entry phone_book_entry;

static phone_book_number make_phone_book_number(const char * digits)
{
    phone_book_number number;
    strncpy(number.digits, digits, MAX_PHONE_NUMBER_LEN);
    number.digits[MAX_PHONE_NUMBER_LEN] = '\0';
    return number;
}

static size_t min_size_t(size_t lhs, size_t rhs)
{
    return lhs < rhs ? lhs : rhs;
}

static int phone_book_number_compare(const phone_book_number * lhs,
                                     const phone_book_number * rhs)
{
    // by restricting the string comparison to the length of
    // the shorter string we make bsearch find
    // numbers that are prefixes of other numbers.
    // This does not compromise the phone book as long
    // as we never allow it to contain numbers that are
    // prefixes of other numbers. 
    // Example: 123 is a prefix of 1234 and so if 1234
    // is a number already in the phone book we must not
    // be allowed to add the number 123 to it. Similarly
    // if 123 is already in the phone book we must not be
    // allowed to add the number 1234 since that too would
    // create a number that was a prefix of another number;
    // a number that was "unreachable"
    const size_t min_length = min_size_t(strlen(lhs->digits), strlen(rhs->digits));
    return strncmp(lhs->digits, rhs->digits, min_length);
}

//--------------------------------------------------

struct phone_book
{
	size_t max_size;
	phone_book_entry * entries;
	phone_book_entry ** name_index;
    phone_book_entry ** number_index;
	size_t index_size;
};

phone_book * phone_book_create(size_t max_size)
{
    if (max_size == 0) 
        return NULL;

	phone_book * created = malloc(sizeof *created);
	*created = 
        (phone_book)
	    { 
	    	.max_size = max_size,
		    .entries = calloc(max_size, sizeof(phone_book_entry)),
    		.name_index = malloc(max_size * sizeof(phone_book_entry *)),
	    	.number_index = malloc(max_size * sizeof(phone_book_entry *)),
            .index_size = 0,
    	};

	return created;
}

//--------------------------------------------------

void phone_book_destroy(phone_book * destroy)
{
    free(destroy->number_index);
	free(destroy->name_index);
	free(destroy->entries);
	free(destroy);
}

//--------------------------------------------------

static phone_book_entry make_phone_entry(const char * name, const char * number)
{
    return  (phone_book_entry)
            {
                .name = make_phone_book_name(name),
                .number = make_phone_book_number(number),
            };
}

//--------------------------------------------------

static int phone_book_indexed_compare_name(const void * lhs, const void * rhs)
{
	const phone_book_entry * const * const lhs_entry = lhs;
	const phone_book_entry * const * const rhs_entry = rhs;
    return phone_book_name_compare(&(*lhs_entry)->name, &(*rhs_entry)->name);
}

static void phone_book_name_sort(phone_book * pb)
{
	qsort
    (
        pb->name_index, 
        pb->index_size, 
	    sizeof(phone_book_entry *), 
	    phone_book_indexed_compare_name
    );
}

static 
phone_book_entry * * 
    phone_book_find_entry_by_name(const phone_book * pb, 
                                  const char * name)
{
	phone_book_entry * index = 
        &(phone_book_entry)
        { 
            .name = make_phone_book_name(name), 
            .number.digits[0] = '\0',
        };

    phone_book_name_sort((phone_book *)pb);

	return bsearch
        (
            &index, 
			pb->name_index, 
			pb->index_size, 
			sizeof(phone_book_entry *), 
			phone_book_indexed_compare_name
        );
}

const char * phone_book_find_number(const phone_book * pb, const char * name)
{
    phone_book_entry * * found =
        phone_book_find_entry_by_name(pb, name);

    return found ? (*found)->number.digits : NULL;
}

void phone_book_print_by_name(const phone_book * pb, 
                              void print(const char * name, const char * number))
{
    phone_book_name_sort((phone_book *)pb);
	for (size_t at = 0; at != pb->index_size; at++)
	{
		const phone_book_entry * entry = pb->name_index[at];
		print(entry->name.letters, entry->number.digits);
	}
}

//-----------------------------------------------

static int phone_book_indexed_compare_number(
    const void * lhs_entry, const void * rhs_entry)
{
	const phone_book_entry * const * const lhs = lhs_entry;
	const phone_book_entry * const * const rhs = rhs_entry;
    return phone_book_number_compare(&(*lhs)->number, &(*rhs)->number);
}

static void phone_book_number_sort(phone_book * pb)
{
    qsort
    (
        pb->number_index, 
    	pb->index_size, 
	   	sizeof(phone_book_entry *), 
	   	phone_book_indexed_compare_number
    );
}

static
phone_book_entry * * 
    phone_book_find_entry_by_number(const phone_book * pb, 
                                    const char * number)
{  
    phone_book_entry * index = 
        &(phone_book_entry)
        { 
            .name.letters[0] = '\0',
            .number = make_phone_book_number(number),
        };

    phone_book_number_sort((phone_book *)pb);

	return
		bsearch
        (
            &index, 
			pb->number_index, 
			pb->index_size, 
			sizeof(phone_book_entry *), 
			phone_book_indexed_compare_number
        );
}

const char * phone_book_find_name(const phone_book * pb, const char * number)
{
    phone_book_entry * const * found = 
        phone_book_find_entry_by_number(pb, number);        

    return found ? (*found)->name.letters : NULL;
}

//-----------------------------------------------

static phone_book_entry * next_unused_entry(phone_book * pb)
{
    //TODO: start at pb->index_size
    size_t at = 0;
    while (at != pb->max_size && pb->entries[at].number.digits[0] != '\0')
        at++;
    return at != pb->max_size ? &pb->entries[at] : NULL;
}

bool phone_book_add(phone_book * pb, const char * name, const char * number)
{
    if (phone_book_find_entry_by_number(pb, number))
        return false;

    phone_book_entry * found = next_unused_entry(pb);
    if (found)
    {    
        *found = make_phone_entry(name, number);
	    const size_t at = pb->index_size;
    	pb->name_index[at] = found;
        pb->number_index[at] = found;
	    pb->index_size++;
    }
    return true;
}

//--------------------------------------------------

void phone_book_print_by_number(const phone_book * pb, 
                              void print(const char * name, const char * number))
{
    phone_book_number_sort((phone_book *)pb);
    for (size_t at = 0; at != pb->index_size; at++)
    {
        const phone_book_entry * entry = pb->number_index[at];
        print(entry->name.letters, entry->number.digits);
    }
}

//--------------------------------------------------

bool phone_book_remove(phone_book * pb, const char * number)
{
    phone_book_entry * * found = 
        phone_book_find_entry_by_number(pb, number);  

    if (found)
    {
        const char * name = (*found)->name.letters;

        // mark the entry as unused
        (*found)->number.digits[0] = '\0';
        // remove the ptr from the number index
        phone_book_entry * * end_number = 
            pb->number_index + pb->index_size;
        size_t byte_count = (end_number - found) * sizeof *found;
        memmove(found, found + 1, byte_count); 

        // remove from name_index too
        found = phone_book_find_entry_by_name(pb, name);
        //assert( found );
        phone_book_entry * * end_name =
            pb->name_index + pb->index_size;
        byte_count = (end_name - found) * sizeof *found;
        memmove(found, found + 1, byte_count);     

        pb->index_size--;        
    }
    return found;
}

//--------------------------------------------------

#ifdef DEBUG
#include <stdio.h>
void phone_book_dump(const phone_book * pb)
{
    printf("max_size==%zd\n", pb->max_size);
    printf("index_size==%zd\n", pb->index_size);

    //printf("name_index_is_stale==%s\n", pb->name_index_is_stale ? "true" : "false");
    for (size_t at = 0; at != pb->index_size; at++)
    {
        const size_t pos = (size_t)(pb->name_index[at] - pb->entries);
        printf("name_index[%zd]==%zd --> ", at, pos);
        const phone_book_entry * pbe = &pb->entries[pos];
        printf("number(%s) , name(%s)\n", pbe->number.digits, pbe->name.letters);
    }   

    //printf("number_index_is_stale==%s\n", pb->name_index_is_stale ? "true" : "false");
    for (size_t at = 0; at != pb->index_size; at++)
    {
        const size_t pos = (size_t)(pb->number_index[at] - pb->entries);
        printf("number_index[%zd]==%zd --> ", at, pos);
        const phone_book_entry * pbe = &pb->entries[pos];
        printf("number(%s) , name(%s)\n", pbe->number.digits, pbe->name.letters);
    } 
    printf("-------------------------\n");
}
#endif


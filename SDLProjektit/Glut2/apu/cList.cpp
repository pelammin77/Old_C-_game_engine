#include "cList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
cList::cList()
{
  // this->make_list(10, true);
    //ctor
}

cList::~cList()
{
   this->free_list();
}


void cList::make_list(int size, bool growable)
{
    if(size< 1) return;

    this->names = (char**) malloc(sizeof(char*) * size);
	this->items = (void**) malloc(sizeof(void*) * size);
	this->item_count = 0;
	this->current_max_size = size;
	this->growable = growable;
    this->list_full = false;
}


int cList::add_item(void *item, char *name)
{


    char *new_name;
    int name_length;

    if(list_full)
    {
		if( growable )
			list_grow();
		else
			return -1;
	}

    names[this->item_count] = NULL;
    if(name != NULL)
	{
		name_length = strlen(name);
		new_name = (char*) malloc(sizeof(char) * name_length + 1);
		strncpy(new_name, name, name_length);
		this->names[item_count] = new_name;
	}

    this->items[item_count] = item;
	item_count++;

	if(current_max_size == item_count) list_full = true;

	return this->item_count-1;
}

void cList::list_grow()
{

    cList grow_list ;
    grow_list.make_list(this->current_max_size*2, true);
    	for(int i=0; i<this->current_max_size; i++)
		add_item( this->items[i] , this->names[i]);

    this->names = grow_list.names;
	this->items = grow_list.items;
	this->item_count = grow_list.item_count;
	this->current_max_size = grow_list.current_max_size;
	this->growable = grow_list.growable;
    // grow_list.free_list();
  //  delete &grow_list;

}



void cList::print_list()
{


	int i;

	printf("count: %i/%i\n", this->item_count, this->current_max_size);

	for(i=0; i < this->item_count; i++)
	{
		printf("list[%i]: %s\n", i, this->names[i]);
	}


}

void cList::print_items()
{
	for( int i=0; i < this->item_count; i++)
	{
		printf("%s\n", this->names[i]);
	}
}

int cList::find(char *name_to_find)
{
  int i = 0;

	for(i=0; i < this->item_count; i++)
	{
		if(strncmp(this->names[i], name_to_find, strlen(name_to_find)) == 0)
			return i;
	}



   return -1;
}

void* cList::get_item(void *item_to_find)
{


	for(int i=0; i < this->item_count; i++)
	{
		if(this->items[i] == item_to_find)
			return this->items[i];
	}

	return NULL;


}
void* cList::get_name(char *name_to_find)
{
	for(int i=0; i < this->item_count; i++)
	{
		if(strncmp(this->names[i], name_to_find, strlen(name_to_find)) == 0)
			return this->items[i];
	}

	return NULL;
}


void* cList::get_index(int indx)
{
    	if(indx < this->item_count)
		return this->items[indx];


	return NULL;
}




void cList::free_list()
{
    this->delete_all();
	free(this->names);
	free(this->items);
}



void cList::delete_all()
{


	for( int i= this->item_count-1; i>=0; i--)
		delete_index(i);


}


void cList::delete_index(int indx)
{


	//remove item
	if(this->names[indx] != NULL)
		free(this->names[indx]);

	//restructure
	for(int j=indx; j < this->item_count-1; j++)
	{
		this->names[j] = this->names[j+1];
		this->items[j] = this->items[j+1];
	}

	this->item_count--;

	return;
}


void cList::delete_item(void *item)
{

	for( int i=0; i < this->item_count; i++)
	{
		if( this->items[i] == item )
			this->delete_index( i);
	}
}
void cList::delete_name(char *name)
{

	//int j;
	//char remove = 0;

	//	int length_name = strlen(name);
	int item_name;

	if(name == NULL)
		return;

	for(int i=0; i < this->item_count; i++)
	{
		item_name = strlen(name);

		if( name != NULL && (strncmp(this->names[i], name, strlen(name)) == 0) )
			this->delete_index(i);
	}



}





//-----------------------------------------------------------------------------------------------------------------------------------------


void cList::test_list() // ei toteutettu
{







}










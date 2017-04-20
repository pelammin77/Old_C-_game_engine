#ifndef CLIST_H
#define CLIST_H


class cList
{
    public:
        cList();
        virtual ~cList();
        //metods


void make_list( int size, bool growable);
int add_item( void *item, char *name);
void list_grow();
void print_items();
void* get_name( char *name_to_find);
void* get_index( int indx);
void* get_item( void *item_to_find);
const int get_max_size() const {return current_max_size;}
const int get_item_count() const {return item_count;}
int find( char *name_to_find);
void delete_index( int indx);
void delete_name( char *name);
void delete_item(void *item);
void delete_all();
void print_list();
void free_list();

void test_list();

    protected:
    private:

    int item_count;
	int current_max_size;
	bool growable;
    bool list_full;
	void **items;
	char **names;



};

#endif // CLIST_H

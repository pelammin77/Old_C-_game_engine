#ifndef COBJLOADER_H
#define COBJLOADER_H
#include <stdio.h>
#include"OBJStruckture.h"



#define OBJ_FILENAME_LENGTH 500
#define MATERIAL_NAME_SIZE 255
#define OBJ_LINE_SIZE 500
#define MAX_VERTEX_COUNT 4




class cObjLoader
{
    public:
        cObjLoader();
        virtual ~cObjLoader();
        int load_file(char *filename);
        int parse_file();
        void draw_model();

    protected:
    private:
    void make_lists();
   obj_vector* obj_psrse_vector();
   int convert_to_list_index(int max, int indx);
   void convert_to_list_vertex(int max, int *i_v);
   int  obj_parse_vertex_index(int *vertex_index, int *texture_index, int *normal_index);
   obj_face* obj_parse_face();
    obj_plane* obj_parse_plane();

     obj_vector *vector;
    int current_material;
    char *current_token;

   FILE *Obj_scene_file;
    obj_growable_scene_data data;

	char current_line[OBJ_LINE_SIZE];
	int line_number ;
};

#endif // COBJLOADER_H

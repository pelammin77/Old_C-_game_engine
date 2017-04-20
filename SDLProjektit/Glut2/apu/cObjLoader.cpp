#include "cObjLoader.h"
#include<string.h>
#include<string>
#include"apu/helpFunctions.h"


#define WHITESPACE " \t\n\r"

cObjLoader::cObjLoader()
{
     current_material = -1;
	 *current_token = NULL;
     line_number = 0;
     make_lists();
}

cObjLoader::~cObjLoader()
{
    *current_token = NULL;

      if(this->Obj_scene_file) fclose(this->Obj_scene_file);
    //dtor
}
void cObjLoader::make_lists()
{
    data.face_list.make_list(10,true);
    data.light_disc_list.make_list(10,true);
    data.light_point_list.make_list(10,true);
    data.light_quad_list.make_list(10,true);
    data.material_list.make_list(10,true);
    data.plane_list.make_list(10,true);
    data.sphere_list.make_list(10,true);
    data.vertex_list.make_list(10,true);
    data.vertex_normal_list.make_list(10,true);
    data.vertex_texture_list.make_list(10,true);


}





int cObjLoader::load_file(char *filename)
{
       this->Obj_scene_file = fopen( filename, "r");
	if(this->Obj_scene_file == 0) return -1; //jos tiedosto ei aukea palautetaan -1

     // luodaan malli ja lisätää




    return 0;// jos onnistui palautetaan nolla

}

obj_vector* cObjLoader::obj_psrse_vector()
{
   obj_vector *v = (obj_vector*)malloc(sizeof(obj_vector));

   v->e[0] = atof(strtok(NULL, WHITESPACE));
   v->e[1] = atof(strtok(NULL, WHITESPACE));
    v->e[2] = atof(strtok(NULL, WHITESPACE));
   return v;
}


int cObjLoader::obj_parse_vertex_index(int *vertex_index, int *texture_index, int *normal_index)
{
     int vertex_count = 0;
    char *temp_str;
	char *token;



	while( (token = strtok(NULL, WHITESPACE)) != NULL)
	{
	    if(texture_index != NULL)
			texture_index[vertex_count] = 0;
		if(normal_index != NULL)
		normal_index[vertex_count] = 0;

		vertex_index[vertex_count] = atoi( token );

		if(contains(token, "//"))  //normal only
		{
			temp_str = strchr(token, '/');
			temp_str++;
			normal_index[vertex_count] = atoi( ++temp_str );
		}

	else if(contains(token, "/"))
		{
			temp_str = strchr(token, '/');
			texture_index[vertex_count] = atoi( ++temp_str );

			if(contains(temp_str, "/"))
			{
				temp_str = strchr(temp_str, '/');
				normal_index[vertex_count] = atoi( ++temp_str );
			}
		}

		vertex_count++;
	}

 return vertex_count;
}



obj_face* cObjLoader::obj_parse_face()
{
    obj_face *f = (obj_face*)malloc(sizeof(obj_face));
    int vertex_count = obj_parse_vertex_index(f->vertex_index, f->texture_index, f->normal_index);

    this->convert_to_list_vertex(data.vertex_list.get_item_count(), f->vertex_index);
	this->convert_to_list_vertex(data.vertex_texture_list.get_item_count(), f->texture_index);
	this->convert_to_list_vertex(data.vertex_normal_list.get_item_count(), f->normal_index);

     //pasitaan face koodi tähän


   f->vertex_count = vertex_count;
    return f;

}

obj_plane* cObjLoader::obj_parse_plane()
{
    int temp_indices[MAX_VERTEX_COUNT];

    obj_plane *plane = (obj_plane*) malloc(sizeof(obj_plane));
    this->obj_parse_vertex_index(temp_indices,plane->texture_index,NULL);
    this->convert_to_list_vertex(data.vertex_texture_list.get_item_count(), plane->texture_index);


return plane;
}
int cObjLoader::convert_to_list_index(int max, int indx)
{

if(indx == 0)
		return -1;

	if(indx < 0)
		return max + indx;

	return indx - 1;
}

void cObjLoader::convert_to_list_vertex(int max, int *i_v)
{

for(int i=0; i<MAX_VERTEX_COUNT; i++)
		i_v[i] = convert_to_list_index(max, i_v[i]);
}






int cObjLoader::parse_file()
{

  while( fgets(current_line, OBJ_LINE_SIZE, this->Obj_scene_file) )
	{
		current_token = strtok( current_line, " \t\n\r");
		line_number++;
         std::string token = current_token;
		//skip comments
		if( current_token == NULL || current_token[0] == '#')
			continue;

            	else if (token == "v")
            	{
                data.vertex_list.add_item(this->obj_psrse_vector(),NULL);
            	}

                 else if(token == "vn")
                 {
                     data.vertex_normal_list.add_item(this->obj_psrse_vector(),NULL);
                 }

                else if(token == "vt")
                {
                    data.vertex_texture_list.add_item(this->obj_psrse_vector(), NULL);
                }

	}

  return 0;
}







void cObjLoader::draw_model()
{

}


#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Vectors */
typedef float vec3_t[3];
typedef float vec4_t[4];

/* Vertex */
struct obj_vertex_t
{
  vec4_t xyzw;
};

/* Texture coordinates */
struct obj_texCoord_t
{
  vec3_t uvw;
};

/* Normal vector */
struct obj_normal_t
{
  vec3_t ijk;
};

/* Polygon */
struct obj_face_t
{
  GLenum type;        /* primitive type */
  int num_elems;      /* number of vertices */

  int *vert_indices;  /* vertex indices */
  int *uvw_indices;   /* texture coordinate indices */
  int *norm_indices ; /* normal vector indices */
};


/* OBJ model structure */
struct obj_model_t
{
  int num_verts;                     /* number of vertices */
  int num_texCoords;                 /* number of texture coords. */
  int num_normals;                   /* number of normal vectors */
  int num_faces;                     /* number of polygons */

  int has_texCoords;                 /* has texture coordinates? */
  int has_normals;                   /* has normal vectors? */

  struct obj_vertex_t *vertices;     /* vertex list */
  struct obj_texCoord_t *texCoords;  /* tex. coord. list */
  struct obj_normal_t *normals;      /* normal vector list */
  struct obj_face_t *faces;          /* model's polygons */
};



struct obj_model_t objfile;

void deleteOBJModel(struct obj_model_t *mdl)
{
   int i;
   if(mdl)
   {
       if(mdl->vertices)
       {
           free( mdl->vertices);
           mdl->vertices = NULL;
       }



      if (mdl->texCoords)
	{
	  free (mdl->texCoords);
	  mdl->texCoords = NULL;
	}

      if (mdl->normals)
	{
	  free (mdl->normals);
	  mdl->normals = NULL;
	}

      if (mdl->faces)
	{
	  for (i = 0; i < mdl->num_faces; ++i)
	    {
	      if (mdl->faces[i].vert_indices)
		free (mdl->faces[i].vert_indices);

	      if (mdl->faces[i].uvw_indices)
		free (mdl->faces[i].uvw_indices);

	      if (mdl->faces[i].norm_indices)
		free (mdl->faces[i].norm_indices);
	    }

	  free (mdl->faces);
	  mdl->faces = NULL;
	}


   }
}



int createNewObjModel(struct obj_model_t *mdl)
{
     if (mdl->num_verts)
    {
      mdl->vertices = (struct obj_vertex_t *)
	malloc (sizeof (struct obj_vertex_t) * mdl->num_verts);
      if (!mdl->vertices)
	return 1;
    }

  if (mdl->num_texCoords)
    {
      mdl->texCoords = (struct obj_texCoord_t *)
	malloc (sizeof (struct obj_texCoord_t) * mdl->num_texCoords);
      if (!mdl->texCoords)
	return 1;
    }

  if (mdl->num_normals)
    {
      mdl->normals = (struct obj_normal_t *)
	malloc (sizeof (struct obj_normal_t) * mdl->num_normals);
      if (!mdl->normals)
	return 1;
    }

  if (mdl->num_faces)
    {
      mdl->faces = (struct obj_face_t *)
	calloc (mdl->num_faces, sizeof (struct obj_face_t));
      if (!mdl->faces)
	return 1;
    }



return 0;
}
void firstOBJCheck()
{




}

void readOBJModel()
{

}

void drawOBJModel()
{

}




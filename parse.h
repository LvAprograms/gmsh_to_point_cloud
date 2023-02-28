
#ifndef __parse_h__
#define __parse_h__

typedef struct _p_CellPartition *CellPartition;
typedef struct _p_Mesh *Mesh;

struct _p_CellPartition {
  double cmin[3], cmax[3];
  int *cell_list;
  int ncell;
};

struct _p_Mesh {
  CellPartition *partition;
  double *vert; // pointer to the current vertex
  int *cell;  // pointer to the current cell
  int nvert,ncell, coor_dim, points_per_cell; // number of vertices/cells, dimension of coordinates (1, 2, 3?), and points per cell
  int npartition; // number of partitions the gmsh mesh is to be divided into
};

void CellPartitionCreate(CellPartition *_c);
void CellPartitionDestroy(CellPartition *_c);
void MeshCreate(Mesh *_m);
void MeshDestroy(Mesh *_m);
void MeshView(Mesh m);
void parse_mesh(const char filename[], Mesh *m);
void parse_field(Mesh m, const char filename[], char ftypevoid, void **_data);


#endif

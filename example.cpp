#if 0
c++ -o example example.cpp trimesh.cpp -Wall -Wno-sign-compare -Woverloaded-virtual -O1 -g
#endif

#include <iostream>
#include "trimesh.h"

/*
$ ./example
neighbors of vertex 0:  2 1
neighbors of vertex 1:  0 2 3
neighbors of vertex 2:  3 1 0
neighbors of vertex 3:  1 2
*/

int main( int argc, char* argv[] )
{
    std::vector< trimesh::triangle_t > triangles;
    
    // ... fill triangles ...
    triangles.resize( 2 );
    triangles[0].v[0] = 0;
    triangles[0].v[1] = 1;
    triangles[0].v[2] = 2;
    triangles[1].v[0] = 2;
    triangles[1].v[1] = 1;
    triangles[1].v[2] = 3;
    const int kNumVertices = 4;
    
    std::vector< trimesh::edge_t > edges;
    trimesh::unordered_edges_from_triangles( triangles.size(), &triangles[0], edges );
    
    trimesh::trimesh_t mesh;
    mesh.build( kNumVertices, triangles.size(), &triangles[0], edges.size(), &edges[0] );
    
    // Use 'mesh' to walk the connectivity.
    std::vector< trimesh::index_t > neighs;
    for( int vi = 0; vi < kNumVertices; ++vi )
    {
        mesh.vertex_vertex_neighbors( vi, neighs );
        
        std::cout << "neighbors of vertex " << vi << ": ";
        for( int i = 0; i < neighs.size(); ++i )
        {
            std::cout << ' ' << neighs.at(i);
        }
        std::cout << '\n';
    }
    
    return 0;
}

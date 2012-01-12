#ifndef __trimesh_types_h__
#define __trimesh_types_h__

namespace trimesh
{
    typedef long index_t;
    
    struct edge_t
    {
        index_t v[2];
        
        index_t& start() { return v[0]; }
        const index_t& start() const { return v[0]; }
        
        index_t& end() { return v[1]; }
        const index_t& end() const { return v[1]; }
        
        edge_t()
        {
            v[0] = v[1] = -1;
        }
    };
    
    struct triangle_t
    {
        index_t v[3];
        
        index_t& i() { return v[0]; }
        const index_t& i() const { return v[0]; }
        
        index_t& j() { return v[1]; }
        const index_t& j() const { return v[1]; }
        
        index_t& k() { return v[2]; }
        const index_t& k() const { return v[2]; }
        
        triangle_t()
        {
            v[0] = v[1] = v[2] = -1;
        }
    };
}

#endif /* __trimesh_types_h__ */

/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "model_utils.hpp"

void gCalculateTangentBiTangent(sEntityModelVertex &_v1,
                                sEntityModelVertex &_v2,
                                sEntityModelVertex &_v3)
{
    glm::vec3 delta_pos1 = _v2.position - _v1.position;
    glm::vec3 delta_pos2 = _v3.position - _v1.position;

    glm::vec2 delta_uv1 = _v2.texcoord - _v1.texcoord;
    glm::vec2 delta_uv2 = _v3.texcoord - _v1.texcoord;

    float r = 1.0 / (delta_uv1.x * delta_uv2.y - delta_uv1.y * delta_uv2.x);
    _v1.tangent = (delta_pos1 * delta_uv2.y - delta_pos2 * delta_uv1.y) * r;
    _v1.bitangent = (delta_pos2 * delta_uv1.x - delta_pos1 * delta_uv2.x) * r;

    _v2.tangent = _v1.tangent;
    _v2.bitangent = _v1.bitangent;
    _v3.tangent = _v1.tangent;
    _v3.bitangent = _v1.bitangent;
}


/*
#include "Vector4D.h"


struct Triangle
{
    unsigned short  index[3];
};


void CalculateTangentArray(long vertexCount, const Point3D *vertex, const Vector3D *normal,
        const Point2D *texcoord, long triangleCount, const Triangle *triangle, Vector4D *tangent)
{
    Vector3D *tan1 = new Vector3D[vertexCount * 2];
    Vector3D *tan2 = tan1 + vertexCount;
    ZeroMemory(tan1, vertexCount * sizeof(Vector3D) * 2);

    for (long a = 0; a < triangleCount; a++)
    {
        long i1 = triangle->index[0];
        long i2 = triangle->index[1];
        long i3 = triangle->index[2];

        const Point3D& v1 = vertex[i1];
        const Point3D& v2 = vertex[i2];
        const Point3D& v3 = vertex[i3];

        const Point2D& w1 = texcoord[i1];
        const Point2D& w2 = texcoord[i2];
        const Point2D& w3 = texcoord[i3];

        float x1 = v2.x - v1.x;
        float x2 = v3.x - v1.x;
        float y1 = v2.y - v1.y;
        float y2 = v3.y - v1.y;
        float z1 = v2.z - v1.z;
        float z2 = v3.z - v1.z;

        float s1 = w2.x - w1.x;
        float s2 = w3.x - w1.x;
        float t1 = w2.y - w1.y;
        float t2 = w3.y - w1.y;

        float r = 1.0F / (s1 * t2 - s2 * t1);
        Vector3D sdir((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r,
                (t2 * z1 - t1 * z2) * r);
        Vector3D tdir((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r,
                (s1 * z2 - s2 * z1) * r);

        tan1[i1] += sdir;
        tan1[i2] += sdir;
        tan1[i3] += sdir;

        tan2[i1] += tdir;
        tan2[i2] += tdir;
        tan2[i3] += tdir;

        triangle++;
    }

    for (long a = 0; a < vertexCount; a++)
    {
        const Vector3D& n = normal[a];
        const Vector3D& t = tan1[a];

        // Gram-Schmidt orthogonalize
        tangent[a] = (t - n * Dot(n, t)).Normalize();

        // Calculate handedness
        tangent[a].w = (Dot(Cross(n, t), tan2[a]) < 0.0F) ? -1.0F : 1.0F;
    }

    delete[] tan1;
}
*/

/*
ModelVertex calcTangentBitangent(uint vertexIndex) {
    ModelVertex v = srcVertices[vertexIndex];

    vec3 tangent = vec3(0);
    vec3 bitangent = vec3(0);
    uint trianglesIncluded = 0;

    // Find the triangles that use v
    //  * Loop over every triangle (i + 3)
    for (uint i = 0; i < numIndices; i += 3) {
        uint index0 = indices[i];
        uint index1 = indices[i+1];
        uint index2 = indices[i+2];

        // Only perform the calculation if one of the indices
        // matches our vertexIndex
        if (index0 == vertexIndex || index1 == vertexIndex || index2 == vertexIndex) {
            ModelVertex v0 = srcVertices[index0];
            ModelVertex v1 = srcVertices[index1];
            ModelVertex v2 = srcVertices[index2];

            vec3 pos0 = getPos(v0);
            vec3 pos1 = getPos(v1);
            vec3 pos2 = getPos(v2);

            vec2 uv0 = getUV(v0);
            vec2 uv1 = getUV(v1);
            vec2 uv2 = getUV(v2);

            vec3 delta_pos1 = pos1 - pos0;
            vec3 delta_pos2 = pos2 - pos0;

            vec2 delta_uv1 = uv1 - uv0;
            vec2 delta_uv2 = uv2 - uv0;

            float r = 1.0 / (delta_uv1.x * delta_uv2.y - delta_uv1.y * delta_uv2.x);
            tangent += (delta_pos1 * delta_uv2.y - delta_pos2 * delta_uv1.y) * r;
            bitangent += (delta_pos2 * delta_uv1.x - delta_pos1 * delta_uv2.x) * r;
            trianglesIncluded += 1;
        }

    }

    // Average the tangent and bitangents
    if (trianglesIncluded > 0)
    {
        tangent /= trianglesIncluded;
        bitangent /= trianglesIncluded;
        tangent = normalize(tangent);
        bitangent = normalize(bitangent);
    }

    // Save the results
    v.tx = tangent.x;
    v.ty = tangent.y;
    v.tz = tangent.z;
    v.bx = bitangent.x;
    v.by = bitangent.y;
    v.bz = bitangent.z;

    return v;
}
*/

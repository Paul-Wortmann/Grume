

#include "libMath.hpp"

vec3 planeLineIntersection(vec3 _planePoint, vec3 _planeNormal, vec3 _linePoint, vec3 _lineDirection)
{
    vec3    ld    = _lineDirection;
    ld.normalize();
    float32 pnDld = _planeNormal.dot(ld);

    if (pnDld == 0)
    {
        return vec3(0.0f, 0.0f, 0.0f);
    }
    
    float64 t = (_planeNormal.dot(_planePoint) - _planeNormal.dot(_linePoint)) / pnDld;
    
    vec3 ldSt = ld * t;
    vec3 lpPld = _linePoint + ldSt;
    
    return lpPld;
}
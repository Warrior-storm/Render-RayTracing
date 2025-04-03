#include "Cilindro.h"
#include "Vector.h"
#include <math.h>

int hit_Cilindro(Cilindro C, Ray r, float *t, Vector3 *normal) {
    Vector3 oc = rest3(r.origen, C.base);
    Vector3 ca = norm3(C.axis);
    float ca_dot_d = dot3(ca, r.direccion);
    float ca_dot_oc = dot3(ca, oc);
    Vector3 a = rest3(r.direccion, Esc3(ca, ca_dot_d));
    Vector3 b = rest3(oc, Esc3(ca, ca_dot_oc));
    float a_dot_a = dot3(a, a);
    float a_dot_b = dot3(a, b);
    float b_dot_b = dot3(b, b);
    float radius2 = C.radius * C.radius;
    float discriminant = a_dot_b * a_dot_b - a_dot_a * (b_dot_b - radius2);

    if (discriminant > 0.0) {
        float sqrt_discriminant = sqrt(discriminant);
        float t0 = (-a_dot_b - sqrt_discriminant) / a_dot_a;
        float t1 = (-a_dot_b + sqrt_discriminant) / a_dot_a;

        if (t0 > 0.0) {
            *t = t0;
        } else if (t1 > 0.0) {
            *t = t1;
        } else {
            return 0;
        }

        Vector3 hit_point = rayo(r, *t);
        Vector3 hit_point_base = rest3(hit_point, C.base);
        float projection_length = dot3(hit_point_base, ca);
        if (projection_length < 0.0 || projection_length > C.height) {
            return 0;
        }

        Vector3 hit_point_axis = sum3(C.base, Esc3(ca, projection_length));
        *normal = norm3(rest3(hit_point, hit_point_axis));
        return 1;
    }

    return 0;
}
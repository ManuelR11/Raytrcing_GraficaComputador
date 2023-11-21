#include "cube.h"

Cube::Cube(const glm::vec3& center, float side, const Material& mat)
        : center(center), side(side), Object(mat) {}

Intersect Cube::rayIntersect(const glm::vec3& rayOrigin, const glm::vec3& rayDirection) const {

    // Calcular planos del cubo
    glm::vec3 x_min = center + glm::vec3(-side/2, 0, 0);
    glm::vec3 x_max = center + glm::vec3(side/2, 0, 0);
    glm::vec3 y_min = center + glm::vec3(0, -side/2, 0);
    glm::vec3 y_max = center + glm::vec3(0, side/2, 0);
    glm::vec3 z_min = center + glm::vec3(0, 0, -side/2);
    glm::vec3 z_max = center + glm::vec3(0, 0, side/2);

    // Calcular intersecciones con planos
    float t_x_min = (x_min.x - rayOrigin.x) / rayDirection.x;
    float t_x_max = (x_max.x - rayOrigin.x) / rayDirection.x;
    float t_y_min = (y_min.y - rayOrigin.y) / rayDirection.y;
    float t_y_max = (y_max.y - rayOrigin.y) / rayDirection.y;
    float t_z_min = (z_min.z - rayOrigin.z) / rayDirection.z;
    float t_z_max = (z_max.z - rayOrigin.z) / rayDirection.z;

    // Encontrar distancia mínima
    float t_min = fmax(fmax(fmin(t_x_min, t_x_max), fmin(t_y_min, t_y_max)), fmin(t_z_min, t_z_max));
    float t_max = fmin(fmin(fmax(t_x_min, t_x_max), fmax(t_y_min, t_y_max)), fmax(t_z_min, t_z_max));

    // Comprobar si hay intersección
    if (t_max < 0 || t_min > t_max) {
        return Intersect{false};
    }

    // Calcular intersección
    glm::vec3 point = rayOrigin + t_min * rayDirection;

    // Calcular normal
    glm::vec3 normal;
    if (t_x_min > t_min) normal = glm::vec3(-1, 0, 0);
    else if (t_x_max < t_min) normal = glm::vec3(1, 0, 0);
    else if (t_y_min > t_min) normal = glm::vec3(0, -1, 0);
    else if (t_y_max < t_min) normal = glm::vec3(0, 1, 0);
    else if (t_z_min > t_min) normal = glm::vec3(0, 0, -1);
    else if (t_z_max < t_min) normal = glm::vec3(0, 0, 1);


    return Intersect{true, t_min, point, normal};
}


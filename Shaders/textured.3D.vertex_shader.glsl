#version 330 core

in vec3 vertex_position;
in vec2 vertex_texture_coordinate;
in vec3 vertex_normal;

out vec2 interpolated_texture_coordinate;
out vec3 normal;
out vec3 fragment_position; 

uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;

uniform mat4 camera;
uniform mat4 projection;

void main()
{
    //    -- VERTEX SHADER --
    mat4 model = translation * rotation * scale;
    vec4 vertex_position_transformed = projection * camera * model * vec4(vertex_position.xyz, 1.0);

    gl_Position                     = vertex_position_transformed;
    interpolated_texture_coordinate = vertex_texture_coordinate;
    normal                          = (model * vec4(vertex_normal, 1.0)).xyz;
    fragment_position               = (model * vec4(vertex_position, 1.0)).xyz;
}

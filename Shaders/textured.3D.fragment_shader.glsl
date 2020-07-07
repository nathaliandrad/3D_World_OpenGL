#version 330 core

in vec2 interpolated_texture_coordinate;
in vec3 normal;
in vec3 fragment_position;

uniform sampler2D image;
uniform vec3 light_position;
uniform vec3 light_color;
uniform vec3 light_color_grey;

out vec4 fragment_color;

void main()
{
    //      -- FRAGMENT SHADER --   
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    
    vec3 normal_normalized          = normalize(normal);
    vec3 light_direction_normalized = normalize(light_position - fragment_position);
    float light_multiplier          = max(dot(normal_normalized, light_direction_normalized), 0.0);

    fragment_color =  (image_textel * vec4(light_color.xyz * light_multiplier, 1.0));

    
    
}
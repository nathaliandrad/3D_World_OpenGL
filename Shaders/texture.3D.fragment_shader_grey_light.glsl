#version 330 core

in vec2 interpolated_texture_coordinate;
in vec3 normal;
in vec3 fragment_position;

uniform sampler2D image;
uniform vec3 light_position;
uniform vec3 light_color;

out vec4 fragment_color;

void main()
{
    //      -- FRAGMENT SHADER --   
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    image_textel.g = image_textel.r;
    image_textel.b = image_textel.r;
    fragment_color =  (image_textel * 1);
    
    
}
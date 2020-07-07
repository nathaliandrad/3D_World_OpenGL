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
   fragment_color =  (image_textel * 1);
    
    
}
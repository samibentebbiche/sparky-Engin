#version 330 core

layout(location =0) out vec4 color;
uniform vec2 light_pos;

in DATA
{
	vec4 pos;
	vec4 color;

} fs_in;

void main()
{
    vec4 c = vec4(0.0f, 0.0f, 1.0f ,1.0f);
	float intencity =  1.0 / length(fs_in.pos.xy - light_pos) * 0.5 ;
	// color =  c * intencity;
	color = fs_in.color * intencity ;

}
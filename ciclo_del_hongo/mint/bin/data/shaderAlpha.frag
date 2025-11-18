OF_GLSL_SHADER_HEADER

uniform sampler2D tex0;
uniform sampler2D tex1;



in vec2 texCoordVarying;
out vec4 outputColor;



void main()
{
	
  

    vec4 in1 = texture(tex0,texCoordVarying);
    vec4 in2 = texture(tex1,texCoordVarying);
    if (in1.r<0.2) in1.a=0;
    
    outputColor = in1;
}

OF_GLSL_SHADER_HEADER

uniform sampler2D tex0;

in vec2 texCoordVarying;

out vec4 outputColor;

void main()
{
    
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
    
    
    
    vec4 fb = texture(tex0, texCoordVarying);
   
    
    
    vec4 color = vec4(1.-fb.r,1.-fb.g,1.-fb.b,fb.a);
  
    
    outputColor = color;
}

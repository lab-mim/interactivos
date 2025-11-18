
uniform float mouseX;

varying vec2 texCoordVarying;

void main()
{
    vec2 texcoord = gl_MultiTexCoord0.xy;
    texCoordVarying = vec2(texcoord.x,texcoord.y);
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    
}

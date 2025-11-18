OF_GLSL_SHADER_HEADER

// this is how we receive the texture
uniform sampler2D tex0;
uniform sampler2D tex1;
uniform vec2 resolution;

uniform float fade;
uniform float center;
uniform float gamma;

in vec2 texCoordVarying;

out vec4 outputColor;
 
void main()
{
    
    vec2 nc = texCoordVarying;
    float haf = step(nc.x,0.5);
    vec2 nc1 = (texCoordVarying*vec2(1.+center,1.));
    vec2 nc2 = nc1-vec2(center,0.);
    vec4 a = texture(tex0,mix(nc2,nc1,haf));
    float fad = abs(fade);
    //calcula edgefading
    float dist = abs(nc.x-0.5)*0.5;
    fad = smoothstep(0.,fad,dist);
    fad = pow(fad,gamma);
    vec4 wiped = vec4(a.rgb,fad);
    
    // output texture
    outputColor = vec4(wiped);
    
   // vec4 oc = texture(tex0, texCoordVarying);
    
    //outputColor = oc;
    
}


uniform sampler2DRect tex0;
uniform vec2 resolution;
varying vec2 texCoordVarying;

uniform float fade;
uniform float center;
uniform float gamma;
 
void main()
{
    
  /*  vec2 nc = texCoordVarying;
    float haf = step(nc.x,0.5);
    vec2 nc1 = (texCoordVarying*vec2(1.+center,1.));
    vec2 nc2 = nc1-vec2(center,0);
    vec4 a = texture2D(tex0,mix(nc2,nc1,haf));
    float fad = abs(fade);
    //calcula edgefading
    float dist = abs(nc.x-0.5)*0.5;
    fad = smoothstep(0.,fad,dist);
    fad = pow(fad,gamma);
    vec4 wiped = vec4(a.rgb,fad);
    
    gl_FragColor = vec4(wiped);*/
    
    vec2 nc = texCoordVarying;
    float haf = step(nc.x,1920.);
    vec2 nc1 = nc-vec2(center+240.,0.);
    vec2 nc2 = nc+vec2(center-240.,0.);
    vec4 a = texture2DRect(tex0,mix(nc1,nc2,haf));
    float fad = abs(fade);
    //float dist = abs(nc.x)*1920.;
    //fad = smoothstep(0.,fad,dist);
    //fad = pow(fad,gamma);
    
    float dist = abs(nc.x-1920.)/1920.;
    fad = smoothstep(0.,fad,dist);
    fad = pow(fad,gamma);
    vec4 wiped = vec4(a.rgb,fad);
    gl_FragColor = vec4(wiped);
    
    
}

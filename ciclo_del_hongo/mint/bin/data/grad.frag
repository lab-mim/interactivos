OF_GLSL_SHADER_HEADER

out vec4 outputColor;

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
  
    
	float r = gl_FragCoord.x / 1920.;
	float g = gl_FragCoord.y / 1024;
	float b = 1.0;
	float a = 1.0;
	outputColor = vec4(1, 0, 0, 1);
}

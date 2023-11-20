#include "stdafx.h"

#include "application/test_opengl/OpenGLExperiment.h"

//TODO This is here because it conflicts with some function Rectangle from the Windows API
#include "system/sdl_utils/drawing/Window.h"
#include "system/sdl_utils/drawing/Renderer.h"
#include "system/managers/DrawManager.h"

#include "SDL.h"
#include "GL/glew.h"
#include "GL/wglew.h"

// !!! Important: Disable the SDL rendering in Engine::Draw before running OpenGl

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// 
// FLAG TEST
// 
// Source: https://www.youtube.com/watch?v=ZrYxEF5TGaE
// 
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static int program;

// =============================================================================
static const char* shader_fragment =
{
	"uniform float time;"
	"uniform vec2 resolution;"

	"vec3 flag(vec2 uv){"
	"vec3 colW = mix(vec3(0.0), vec3(0.8, 0.1, 0.1), step(0.67, 1 - uv.y));"
	"vec3 colG = min(mix(vec3(0.0), vec3(0.1, 0.8, 0.1), step(0.33, 1 - uv.y)), mix(vec3(0.0), vec3(0.8, 0.7, 0.1), step(0.33, uv.y)));"
	"vec3 colR = mix(vec3(0.0), vec3(0.9, 0.9, 0.9), step(0.67, uv.y));"
	"return colW + colG + colR;}"

	"void main(void){"
	"vec2 position = vec2(gl_FragCoord.x / resolution.x - 0.1, gl_FragCoord.y / resolution.y - 0.1) * 1.25;"
	"vec3 col; float a = 1.0; vec3 colY; vec3 colX;"
	"float x = sin(position.x * 20.0 + time * 6.0) * sin(position.x * 5.0 + time * 3.0);"
	"position.x += sin(position.y + time * 2.0) * 0.05;"
	"position.y += sin(position.x * 2 - time * 2.0) * 0.1 + 0.02 * x;"

	"if(abs(1 - position.y) < 1.0){ if(abs(position.y) < 1.0){colY = flag(position);}}"
	"if(abs(1 - position.x) < 1.0){ if(abs(position.x) < 1.0){colX = flag(position);}}"

	"col = colY * colX;"
	"vec2 uv = gl_FragCoord/resolution;"
	"if(col == vec3(0.0)){ col = vec3(0.2, 0.4, 0.8) + 0.15 * cos(time + uv.yxy + vec3(0,2,4));}"
	"else {col -= 0.4 * (x * 0.5 + 0.5);}"
	"gl_FragColor = vec4(col, a);}"
};

namespace OpenGl
{
// =============================================================================
void InitFlagTest()
{
	auto window = g_DrawManager->GetWindow().GetSDLWindow();
	SDL_GL_CreateContext(window);

	glewInit();

	glClearColor(0.f, 0.f, 0.f, 1.f);

	program = glCreateProgram();

	int shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader, 1, &shader_fragment, 0);
	glCompileShader(shader);
	glAttachShader(program, shader);

	glLinkProgram(program);
	glUseProgram(program);
}

// =============================================================================
void DrawFlagTest()
{
	float t = SDL_GetTicks() / 500.0;

	int timeLocation = glGetUniformLocation(program, "time");
	glUniform1f(timeLocation, t);

	int resolution = glGetUniformLocation(program, "resolution");
	glUniform2f(resolution, 1280, 720);

	glRecti(-1, -1, 1, 1);

	auto window = g_DrawManager->GetWindow().GetSDLWindow();
	SDL_GL_SwapWindow(window);
}
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// 
// TRIANGLE TEST
// 
// Source: https://www.youtube.com/watch?v=OR4fNpBjmq8&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2&index=3
// 
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//// =============================================================================
//static unsigned int CompileShader(unsigned int type, const std::string& source)
//{
//	unsigned int id = glCreateShader(type);
//	const char* src = source.c_str();
//	glShaderSource(id, 1, &src, nullptr);
//	glCompileShader(id);
//
//	int result;
//	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//	if (result == GL_FALSE)
//	{
//		int length;
//		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//		char* message = (char*)alloca(length * sizeof(char));
//		glGetShaderInfoLog(id, length, &length, message);
//		glDeleteShader(id);
//		return 0;
//	}
//
//	return id;
//}
//
//// =============================================================================
//static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//{
//	unsigned int program = glCreateProgram();
//	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fs);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vs);
//	glDeleteShader(fs);
//
//	return program;
//}

namespace OpenGl
{
// =============================================================================
void InitTriangleTest()
{
	auto window = g_DrawManager->GetWindow().GetSDLWindow();
	SDL_GL_CreateContext(window);

	glewInit();

	glClearColor(0.f, 0.f, 0.f, 1.f);
}

// =============================================================================
void DrawTriangleTest()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	{
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
	}
	glEnd();

	auto window = g_DrawManager->GetWindow().GetSDLWindow();
	SDL_GL_SwapWindow(window);
}
} // !namespace OpenGl